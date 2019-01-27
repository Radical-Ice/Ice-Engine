//we know.... it's not a component 
#include "ScriptComponent.h"

void ScriptComponent::runScript() {
	LuaAdapter lua{ "Lib/test.lua" };
	LuaFunction luaFunction{ lua };
	int Return_int{ 0 };
	luaFunction.Call("Random", 0, Return_int);
	std::cout << "Random: " << Return_int << "\n";
}
