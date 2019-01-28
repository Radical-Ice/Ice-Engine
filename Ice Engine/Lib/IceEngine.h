#pragma once
#include "SFML/Graphics.hpp"
#include "Checking.h"
#include "Game Window.h"
#include "ScriptComponent.h"
#include "SplashScreen.h"
#include <thread>
#include <chrono>
using namespace std;
class IceEngine {
private:
	SplashScreen splashScreen;
	WNDCLASSEX wcex;
	Checking *checker;
	ScriptComponent scriptComponent;//temp to show lua code
	const DWORDLONG diskSpaceNeed = 300;
	const DWORDLONG physicalRAMNeed = 5;
	const DWORDLONG virtualRAMNeed = 5;
	SplashScreen sp;

public:
	MSG msg;
	void InitEngine();
	void DoChecks(LPCSTR szWindowClass);
	void LoadTexture(sf::RenderWindow& );
	void CreateSplashWindow();
	void CreateMainWindow();
	int RegisterWindow(HINSTANCE hInstance, LPCSTR szWindowClass,int nCmdShow,LPCSTR szTitle);
	sf::Texture texture;
	//sf::Texture SStexture;
	sf::RenderWindow mainWindow;
	sf::RenderWindow SplashScreen;
	sf::Sprite sprite;
	sf::Sprite sprite2;
	sf::Event event;
	sf::Clock clock;
	sf::Time time;
};
