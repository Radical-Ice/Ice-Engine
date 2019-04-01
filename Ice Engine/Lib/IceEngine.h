#pragma once
#include "SFML/Graphics.hpp"
#include "Checking.h"
#include "Game Window.h"
#include "ScriptComponent.h"
#include "SplashScreen.h"
#include "SceneGraph.h"
#include "AIComponent.h"
#include "SFML/Audio.hpp"
#include "AudioComponent.h"
#include "PhysicsEngine.h"
#include "KeyEventHandler.h"
#include "tinyxml2.h"

#include "SFML/Window.hpp"

class IceEngine {
private:
	SplashScreen splashScreen;
	AudioComp Audio;
	WNDCLASSEX wcex;
	Checking *checker;
	AIComponent ai;
	
	ScriptComponent scriptComponent;//temp to show lua code
	const DWORDLONG diskSpaceNeed = 300;
	const DWORDLONG physicalRAMNeed = 5;
	const DWORDLONG virtualRAMNeed = 5;
	enum engineState {
		SplashScreen, 
		nextScreen
	};
	engineState state = SplashScreen;
	sf::Clock clock;	
public:
	PhysicsEngine physEngine;
	SceneGraph sceneNode;
	MSG msg;
	void InitEngine();
	void InitGraphics();
	void LoadSTexture();
	void LoadSound(std::vector<std::string> Files);
	void Play_Sound(int, float, bool);
	void SFML_Window();
	void LoadMusic(std::vector<std::string> Files, int Index, float Volume, bool IsLooping);
	void LoadScene(const char* fileName);
	void IceEngine::PlayMusic();
	void DoChecks(LPCSTR szWindowClass);
	//int RegisterWindow(HINSTANCE hInstance, LPCSTR szWindowClass,int nCmdShow,LPCSTR szTitle);
	sf::RenderWindow mainWindow;
	sf::Event event;
	sf::Time elapsed;


};
