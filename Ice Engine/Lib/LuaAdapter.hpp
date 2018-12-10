/*
* Copyright (c) 2015-2018 JlnWntr (jlnwntr@gmail.com)
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#ifndef LUA_ADAPTER_H
#define LUA_ADAPTER_H

#include <iostream>
#include <string>
#include "lua.hpp"

#define LUA_PREFIX "Lua > "
class LuaTable;

class LuaAdapter {

public:
  /**
  * Default constructor
  * (Calls Init().)
  * @param lua (re-)uses an existing lua_state.
  * (See for example testCFunction() in test.cpp)
  */
  LuaAdapter(lua_State *const lua = nullptr)
      : Lua{lua}, debug{false}, single{(lua) ? false : true} {
    this->Init();
  }

  /**
  * This constructor inits lua and loads a .lua-file directly.
  * @param filename .lua-file to load
  */
  LuaAdapter(const std::string &filename)
      : Lua{nullptr}, debug{false}, single{true} {
    this->Load(filename);
  }

  /**
  * Destructor
  */
  ~LuaAdapter() { this->Close(); }

  /**
  * Initialize Lua and all its libs
  * Does NOT load any lua sourcefile
  * LuaAdapter calls this internally when the constructor is called
  * with a lua file-argument
  * @return true on success, false on error
  */
  bool Init() {
    if (this->Lua) {
      return true;
    }
    this->Lua = luaL_newstate();
    if (!this->Lua) {
      return false;
    }
    luaL_openlibs(this->Lua);
    return true;
  }

  /**
  * Loads a *.lua-sourcefile  *
  * @param filename lua file to load
  * @return true on success, false on error
  */
  bool Load(const std::string &filename){return Load(filename.c_str());}
  bool Load(const char *filename) {
    this->Init();
    if (!this->Lua) {
      if(this->debug)
        std::cerr << LUA_PREFIX
                << "Error: Lua-state invalid. Call init() first!\n";
      return false;
    }
    if (!(luaL_loadfile(this->Lua, filename) == 0)){
      if(debug){
         std::cerr << LUA_PREFIX << "Error. Could not load '";
         std::cerr << filename << "'.\n";
      }
      return false;
    }
    const int pcall{lua_pcall(this->Lua, 0, 0, 0)};
    if (pcall == 0)
      return true;

    if(debug){
        std::cerr << LUA_PREFIX << "Error in Lua-file ";
        std::cerr << lua_tostring(this->Lua, -1);
        std::cerr << "\n";
    }
    return false;
  }

  /**
  * Gets the value of a global variable.
  * @param name of the variable inside loaded lua state
  * @param r value is saved in this variable
  * @return true on success, false on error
  */
  template <typename R> bool Get(const char *name, R &r) {

    if (!this->Lua || !name)
      return false;

    switch (lua_getglobal(this->Lua, name)) {
    case LUA_TNUMBER:
      if (lua_isinteger(this->Lua, -1)) {
        if
          constexpr(std::is_same_v<R, int>)
          r = lua_tointeger(this->Lua, -1);
      } else if
        constexpr(std::is_same_v<double, R> || std::is_same_v<R, float>)
        r = lua_tonumber(this->Lua, -1);
    break;
    case LUA_TBOOLEAN:
      if
        constexpr(std::is_same_v<R, bool>)
        r = lua_toboolean(this->Lua, -1);
    break;
    case LUA_TSTRING:
      if
        constexpr(std::is_same_v<R, std::string>) r =
            lua_tostring(this->Lua, -1);
    break;
    default:
      return false;
      break;
    }
    if (this->debug)
      std::cout << LUA_PREFIX << "got '" << name << "' = '" << r << "' \n";
    lua_pop(this->Lua, 1);
    return true;
  }

  /**
  * Sets the value of a global lua-variable.
  * @param name of the variable
  * @param a the var's value
  * @return true on success, false on error
  */
  template <typename A> bool Set(const char *name, const A a) {
    if (!this->Lua || !name)
      return false;

    if (this->Push(a) == true) {
      lua_setglobal(this->Lua, name);

      if (this->debug)
        std::cout << LUA_PREFIX << "set '" << name << "' = '" << a << "' \n";
      return true;
    }
    return false;
  }

  /**
  * Execute any string
  * @param string to execute, for example "test = io.read()"
  * @return true on success, false on error
  */
  bool DoString(const char *string) {
      return luaL_dostring(this->Lua, string);
  }

  /**
  * Push data on the lua stack.
  * @param a variable to push
  * @return true on success, false on error
  */
  template <typename A> bool Push(A a) {
    if (!this->Lua)
      return false;
    if
      constexpr(std::is_same_v<A, int>)
      lua_pushinteger(this->Lua, a);
    else if
      constexpr(std::is_same_v<A, float> || std::is_same_v<A, double>)
      lua_pushnumber(this->Lua, a);
    else if
      constexpr(std::is_same_v<A, bool>)
      lua_pushboolean(this->Lua, a);
    else if
      constexpr(std::is_same_v<A, std::string>)
      lua_pushlstring(this->Lua, a.c_str(), a.length());
    else
      return false;
    return true;
  }

  /**
  * Resets Lua's internal stack
  * @return true on success, false on error
  */
  bool Flush() {
    if ((!this->Lua))
      return false;

    lua_settop(this->Lua, 0);
    return true;
  }

  /**
  * After calling this function,
  * lua-adapter will print out debug-information
  * for each function call.
  * @param on true to activate debug-mode
  */
  void Debug(bool on = true) { this->debug = on; }

  /**
  * Return the current debugging-state
  * @return true if debug-mode is activated, false if not
  */
  bool GetDebug() const { return this->debug; }

  /**
  * Pops i entries from Lua's internal stack
  * @param i number of entries
  */
  void Pop(signed short int i = 1) { lua_pop(this->Lua, i); }

  /**
  * Gets the stack position
  * @return the stack position
  */
  int GetTop() const { return lua_gettop(this->Lua); }

  /**
  * Gets the value type of the current stack position
  * (LUA_TNIL (0), LUA_TNUMBER, LUA_TBOOLEAN, LUA_TSTRING, LUA_TTABLE,
  *  LUA_TFUNCTION, LUA_TUSERDATA, LUA_TTHREAD, and LUA_TLIGHTUSERDATA.)
  * [https://www.lua.org/manual/5.3/manual.html#lua_type]
  * @return the type
  */
  int GetType() const { return lua_type(this->Lua, 0); }

  /**
  * Returns the current lua_State which is used in this adapter
  * This is necessary,
  * because you need this state for LuaFunctions or  LuaTables.
  * @return the current lua_State
  */
  lua_State *const GetLuaState() const { return this->Lua; }

  /**
  * "Closes" the loaded *.lua-sourcefile
  * This function is called by the destructor of this class!
  * */
  void Close() {
    if ((!this->Lua) || (!this->single))
      return;
    lua_close(this->Lua);
    this->Lua = nullptr;
  }

private:
  lua_State *Lua;
  bool debug;
  bool single;
};
#endif
