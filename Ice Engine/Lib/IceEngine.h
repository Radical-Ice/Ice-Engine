#pragma once
#include "SFML/Graphics.hpp"
#include "Checking.h"
#include "Game Window.h"
#include "ScriptComponent.h"
#include "SplashScreen.h"
class IceEngine {
private:
	SplashScreen splashScreen;
	WNDCLASSEX wcex;
	Checking *checker;
	ScriptComponent scriptComponent;//temp to show lua code
	const DWORDLONG diskSpaceNeed = 300;
	const DWORDLONG physicalRAMNeed = 5;
	const DWORDLONG virtualRAMNeed = 5;

public:
	MSG msg;
	void InitEngine();
	void DoChecks(LPCSTR szWindowClass);
	int RegisterWindow(HINSTANCE hInstance, LPCSTR szWindowClass,int nCmdShow,LPCSTR szTitle);
	sf::Texture texture;
	sf::RenderWindow mainWindow;
};