
//Authors: James Bews, Jatin Kumar, Dennis Nguyen
#include "IceEngine.h"
#include <thread>

#define DIV 1024
// Global variables  
// The main window class name.  

static TCHAR szWindowClass[] = _T("IceEngine Console");
static TCHAR szTitle[] = _T("IceEngnie");
std::vector<std::string> AudioFiles;
// The string that appears in the application's title bar.  


//HINSTANCE hInst;
//~~~~Main Window With Console Enabled~~~~~
int main()                          
	/*_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
	
)*/
{
	//AllocConsole();
	//freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
	AudioFiles = { "Assets/PewPew.wav", "Assets/GunShot.wav" };//Will move to game comp
	IceEngine iceEngine;
	iceEngine.LoadSound(AudioFiles);
	iceEngine.LoadSTexture();
	iceEngine.InitGraphics();
	
	cout << "Init Graphics" << endl;
	iceEngine.DoChecks(szWindowClass);	
	//iceEngine.RegisterWindow(hInstance, szWindowClass, nCmdShow, szTitle);
	iceEngine.InitEngine();
	//hInst = hInstance; // Store instance handle in our global variable  
	return 0;
}

