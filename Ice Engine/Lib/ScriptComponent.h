#pragma once

#ifndef LUA_ADAPTER_H
#include "../Lib/LuaAdapter.hpp"
#endif
#include "../Lib/LuaTable.hpp"
#ifndef LUA_FUNCTION_H
#include "../Lib/LuaFunction.hpp"
#endif

class ScriptComponent {
public:
	static int test_function(lua_State *L);
	LuaAdapter lua{ "Lib/test.lua" };
	LuaFunction luaFunction{ lua };
	int five = 5;
	void runScript();
};


