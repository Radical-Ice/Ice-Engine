
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

//HINSTANCE hInst;
//~~~~Main Window With Console Enabled~~~~~
int main()
{
	AudioFiles = {"Assets/GunShot.wav","Assets/PewPew.wav","Assets/EngineBG.wav"};
	AllocConsole();
	freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);

	IceEngine iceEngine;
	
	iceEngine.InitGraphics();
	
	iceEngine.DoChecks(szWindowClass);
	iceEngine.LoadSound(AudioFiles);
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
	testObj2.m_Transform->m_Position = { 50,100 };
	testObj2.m_Transform->m_Rotation = { 0 };
	testObj2.components.push_back(&sc2);

	GameObject testObj3(&testObj2);
	SpriteComponent sc3(&iceEngine.mainWindow, "Assets/SplashScreen.jpg", testObj3.m_Transform, &sc2);
	testObj3.m_Transform->m_Position = { 50,100 };
	testObj3.m_Transform->m_Rotation = { 0 };
	testObj3.components.push_back(&sc3);


	std::cout << "~~[ SpriteComponents Loading Complete! ]~~" << std::endl;
	iceEngine.InitEngine();
	return 0;
}

