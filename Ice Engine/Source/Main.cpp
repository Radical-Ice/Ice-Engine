
//Authors: James Bews, Jatin Kumar, Dennis Nguyen
#include "IceEngine.h"
#include "SpriteComponent.h"
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
	iceEngine.InitGraphics();
	iceEngine.DoChecks(szWindowClass);	
	//iceEngine.RegisterWindow(hInstance, szWindowClass, nCmdShow, szTitle);
	GameObject testObj(&iceEngine.sceneNode);

	SpriteComponent sc(&iceEngine.mainWindow, "Assets/cat.png",testObj.m_Transform);
	
	testObj.m_Transform->m_Position = { 512,384 };
	testObj.m_Transform->m_Scale = { .3f,.3f };
	testObj.m_Transform->m_Rotation = { 0 };
	testObj.components.push_back(&sc);

	GameObject testObj2(&testObj);

	SpriteComponent sc2(&iceEngine.mainWindow, "Assets/SplashScreen.jpg",testObj2.m_Transform, &sc.sprite);
	testObj2.m_Transform->m_Position = { 50,100 };
	testObj2.m_Transform->m_Rotation = { 0 };
	testObj2.components.push_back(&sc2);

	iceEngine.InitEngine();


	//hInst = hInstance; // Store instance handle in our global variable  
	return (int)iceEngine.msg.wParam;
}

