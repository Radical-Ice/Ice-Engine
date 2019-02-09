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
#include <iostream>

class IceEngine {
private:
	SplashScreen splashScreen;
	SceneGraph sceneNode;
	WNDCLASSEX wcex;
	Checking *checker;
	AIComponent ai;
	AudioComp audio;
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
	MSG msg;
	
	void InitEngine();
	void InitGraphics();
	void LoadSTexture();
	///<summary>Add all req audio file in your game</summary>
	void LoadSound(std::vector<std::string>);
	void SFML_Window();
	void DoChecks(LPCSTR szWindowClass);
	//int RegisterWindow(HINSTANCE hInstance, LPCSTR szWindowClass,int nCmdShow,LPCSTR szTitle);
	sf::Texture texture;
	sf::RenderWindow mainWindow;
	sf::Sprite sprite;
	sf::Event event;
	sf::Time elapsed;
	sf::Texture text2;
};