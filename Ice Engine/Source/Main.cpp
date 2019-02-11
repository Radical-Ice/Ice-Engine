
//Authors: James Bews, Jatin Kumar, Dennis Nguyen
#include "IceEngine.h"
#include "SpriteComponent.h"
#define DIV 1024
// Global variables  
// The main window class name.  
static TCHAR szWindowClass[] = _T("IceEngine");
// The string that appears in the application's title bar.  
std::vector<std::string> AudioFiles;
std::vector<std::string> MusicFile;

//HINSTANCE hInst;
//~~~~Main Window With Console Enabled~~~~~
int main()
{	
	AudioFiles = {"Assets/GunShot.wav","Assets/PewPew.wav"};
	MusicFile = {"Assets/EngineBG.ogg"};

	AllocConsole();
	freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);

	IceEngine iceEngine;
	
	iceEngine.InitGraphics();
	
	iceEngine.DoChecks(szWindowClass);
	iceEngine.LoadSound(AudioFiles);


	iceEngine.LoadMusic(MusicFile, 0, 100, false);


	//iceEngine.RegisterWindow(hInstance, szWindowClass, nCmdShow, szTitle);
	GameObject testObj(&iceEngine.sceneNode);
	std::cout << "~~[ Initializing SpriteComponents ]~~" << std::endl;
	SpriteComponent sc(&iceEngine.mainWindow, "Assets/cat.png",testObj.m_Transform);
	
	testObj.m_Transform->m_Position = { 512,384 };
	testObj.m_Transform->m_Scale = { .3f,.3f };
	testObj.m_Transform->m_Rotation = { 0 };
	testObj.components.push_back(&sc);

	GameObject testObj2(&testObj);
	SpriteComponent sc2(&iceEngine.mainWindow, "Assets/SplashScreen.jpg",testObj2.m_Transform, &sc);
	testObj2.m_Transform->m_Position = { 50,100 };
	testObj2.m_Transform->m_Rotation = { 0 };
	testObj2.components.push_back(&sc2);

	GameObject testObj3(&testObj2);
	SpriteComponent sc3(&iceEngine.mainWindow, "Assets/SplashScreen.jpg", testObj3.m_Transform, &sc2);
	testObj3.m_Transform->m_Position = { 50,100 };
	testObj3.m_Transform->m_Rotation = { 0 };
	testObj3.components.push_back(&sc3);


	std::cout << "~~[ SpriteComponents Loading Complete! ]~~" << std::endl;
	iceEngine.PlayMusic();
	iceEngine.InitEngine();
	return 0;
}

