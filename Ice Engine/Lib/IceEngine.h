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
#include "SFML/System/Vector2.hpp"

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
		GameScreen,
		nextScreen
	};

	enum  Key {
		Unknown = -1, A = 0, B, C,
		D, E, F, G,
		H, I, J, K,
		L, M, N, O,
		P, Q, R, S,
		T, U, V, W,
		X, Y, Z, Num0,
		Num1, Num2, Num3, Num4,
		Num5, Num6, Num7, Num8,
		Num9, Escape, LControl, LShift,
		LAlt, LSystem, RControl, RShift,
		RAlt, RSystem, Menu, LBracket,
		RBracket, Semicolon, Comma, Period,
		Quote, Slash, Backslash, Tilde,
		Equal, Hyphen, Space, Enter,
		Backspace, Tab, PageUp, PageDown,
		End, Home, Insert, Delete,
		Add, Subtract, Multiply, Divide,
		Left, Right, Up, Down,
		Numpad0, Numpad1, Numpad2, Numpad3,
		Numpad4, Numpad5, Numpad6, Numpad7,
		Numpad8, Numpad9, F1, F2,
		F3, F4, F5, F6,
		F7, F8, F9, F10,
		F11, F12, F13, F14,
		F15, Pause, KeyCount, Dash = Hyphen,
		BackSpace = Backspace, BackSlash = Backslash, SemiColon = Semicolon, Return = Enter
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