
//Authors: James Bews, Jatin Kumar, Dennis Nguyen
#include "IceEngine.h"
#include "SpriteComponent.h"
#include "PhysicsComponent.h"
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
	MusicFile = {"Assets/EngineBG.ogg" };
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
	
	testObj.m_Transform->m_Position = { 512,50 };
	testObj.m_Transform->m_Scale = { .3f,.3f };
	testObj.m_Transform->m_Rotation = { 0 };
	testObj.components.push_back(&sc);

	PhysicsComponent pc(&sc, &iceEngine.physEngine);
	testObj.components.push_back(&pc);

	//pc.gravityAffected = false;



	/*
	GameObject aestObj4(&iceEngine.sceneNode);
	SpriteComponent asc4(&iceEngine.mainWindow, "Assets/cat.png", aestObj4.m_Transform);

	aestObj4.m_Transform->m_Position = { 100,50 };
	aestObj4.m_Transform->m_Scale = { .3f,.3f };
	aestObj4.m_Transform->m_Rotation = { 0 };
	aestObj4.components.push_back(&asc4);

	PhysicsComponent pc4(&asc4, &iceEngine.physEngine);
	aestObj4.components.push_back(&pc4);
	pc4.gravityAffected = false;
	*/



	GameObject Platform(&iceEngine.sceneNode);
	SpriteComponent scPlatform(&iceEngine.mainWindow, "Assets/cat.png", Platform.m_Transform);

	Platform.m_Transform->m_Position = { 512,550 };
	Platform.m_Transform->m_Scale = { .3f,.3f };
	Platform.m_Transform->m_Rotation = { 0 };
	Platform.components.push_back(&scPlatform);

	PhysicsComponent pcPlatform(&scPlatform, &iceEngine.physEngine);
	pcPlatform.mass = 0.0f;
	pcPlatform.gravityAffected = false;
	Platform.components.push_back(&pcPlatform);




	GameObject testObj2(&testObj);
	SpriteComponent sc2(&iceEngine.mainWindow, "Assets/SplashScreen.jpg",testObj2.m_Transform, &sc);
	testObj2.m_Transform->m_Position = { 50,50 };
	testObj2.m_Transform->m_Rotation = { 0 };
	testObj2.components.push_back(&sc2);

	GameObject testObj3(&testObj2);
	SpriteComponent sc3(&iceEngine.mainWindow, "Assets/SplashScreen.jpg", testObj3.m_Transform, &sc2);
	testObj3.m_Transform->m_Position = { 50,50 };
	testObj3.m_Transform->m_Rotation = { 0 };
	testObj3.components.push_back(&sc3);


	std::cout << "~~[ SpriteComponents Loading Complete! ]~~" << std::endl;
	iceEngine.PlayMusic();
	iceEngine.InitEngine();
	return 0;
}

