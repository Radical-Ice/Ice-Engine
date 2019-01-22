#pragma once
#include "../Lib/Checking.h"
#include "../Lib/Game Window.h"
#include "../Lib/ScriptComponent.h"

class IceEngine {
private:
	
	WNDCLASSEX wcex;
	Checking *checker;
	ScriptComponent scriptComponent;//temp to show lua code
	const DWORDLONG diskSpaceNeed = 300;
	const DWORDLONG physicalRAMNeed = 5;
	const DWORDLONG virtualRAMNeed = 5;

public:
	MSG msg;
	void InitEngine();
	void DoChecks(LPCSTR szWindowClass);
	int RegisterWindow(HINSTANCE hInstance, LPCSTR szWindowClass,int nCmdShow,LPCSTR szTitle);
};