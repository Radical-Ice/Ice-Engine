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
#include "KeyEventHandler.h"

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
	SceneGraph sceneNode;
	MSG msg;
	void InitEngine();
	void InitGraphics();
	void LoadSTexture();
	void LoadSound(std::vector<std::string> Files);
	void Play_Sound(int, float, bool);

	void LoadMusic(std::vector<std::string> Files, int, float, bool);
	void PlayMusic();
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

class MoveEvents : public KeyEventHandler {
public:

	void HandleEvents(const Event &e) {
		switch (e.Type) {
		case MoveUp:
			cout << "up" << endl;
			break;
		case MoveDown:
			cout << "down" << endl;
			break;
		case MoveLeft:
			cout << "left" << endl;
			break;
		case MoveRight:
			cout << "right" << endl;
			break;
		default:
			break;
		}
	}
};

class RotateEvents : public KeyEventHandler {

public:
	void HandleEvents(const Event &e) {
		switch (e.Type) {
		case RotateRight:
			cout << "RR" << endl;
			break;
		case RotateLeft:
			cout << "RL" << endl;
			break;
		}
	}
};