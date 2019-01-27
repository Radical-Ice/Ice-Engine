
//Authors: James Bews, Jatin Kumar, Dennis Nguyen
#include "IceEngine.h"

#define DIV 1024
// Global variables  
// The main window class name.  
static TCHAR szWindowClass[] = _T("win32app");
static TCHAR szTitle[] = _T("Win32 Guided Tour Application");
// The string that appears in the application's title bar.  


//HINSTANCE hInst;
//~~~~Main Window With Console Enabled~~~~~
int CALLBACK WinMain(                             
	_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow

)
{
	AllocConsole();
	freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);

	IceEngine iceEngine;
	iceEngine.DoChecks(szWindowClass);	
	iceEngine.RegisterWindow(hInstance, szWindowClass, nCmdShow, szTitle);
	iceEngine.InitEngine();
	


	//hInst = hInstance; // Store instance handle in our global variable  
	return (int)iceEngine.msg.wParam;
}

