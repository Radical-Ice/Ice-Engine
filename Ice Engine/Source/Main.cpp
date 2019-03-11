
//Authors: James Bews, Jatin Kumar, Dennis Nguyen
#include "IceEngine.h"
#include "SpriteComponent.h"
#include "PhysicsComponent.h"
<<<<<<< HEAD
#include "tinyxml2.h"
#include <stdio.h>
=======
>>>>>>> Lua+SFML+DirectX
#define DIV 1024
// Global variables  
// The main window class name.  
static TCHAR szWindowClass[] = _T("IceEngine");
// The string that appears in the application's title bar.  
std::vector<std::string> AudioFiles;
std::vector<std::string> MusicFile;
//HINSTANCE hInst;
//~~~~Main Window With Console Enabled~~~~~


///For ints and strings
bool example_4()
{
	static const char* xml =
		"<information>"
		"	<attributeApproach v='2' />"
		"	<textApproach>"
		"		<v>2</v>"
		"	</textApproach>"
		"</information>";

	tinyxml2::XMLDocument doc;
	doc.Parse(xml);

	int v0 = 0;
	int v1 = 0;

	tinyxml2::XMLElement* attributeApproachElement = doc.FirstChildElement()->FirstChildElement("attributeApproach");
	attributeApproachElement->QueryIntAttribute("v", &v0);

	tinyxml2:: XMLElement* textApproachElement = doc.FirstChildElement()->FirstChildElement("textApproach");
	textApproachElement->FirstChildElement("v")->QueryIntText(&v1);

	printf("Both values are the same: %d and %d\n", v0, v1);

	return !doc.Error() && (v0 == v1);
}

int example_3()
{
	tinyxml2::XMLDocument doc;
	const char* name = "Assets/testXML.xml";
	doc.LoadFile(name);
	tinyxml2::XMLElement* titleElement = doc.FirstChildElement("PLAY")->FirstChildElement("TITLE");
	const char* title = titleElement->GetText();
	printf("Name of play (1): %s\n", title);

	tinyxml2::XMLText* textNode = titleElement->FirstChild()->ToText();
	title = textNode->Value();
	printf("Name of play (2): %s\n", title);

	return doc.ErrorID();
}

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

<<<<<<< HEAD
	example_3();
	example_4();
=======
	
>>>>>>> Lua+SFML+DirectX
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

