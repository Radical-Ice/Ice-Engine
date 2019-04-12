#pragma once
#include "IceEngine.h"
#include "SpriteComponent.h"
#include "PhysicsComponent.h"
#include <stdio.h>

class Game1{
public:
#define DIV 1024
	// Global variables  
	// The main window class name.  
	
	// The string that appears in the application's title bar.  
	std::vector<std::string> AudioFiles;
	std::vector<std::string> MusicFile;
	void StartGame(IceEngine &_IceEngine);
	int score = 0;
	bool gameOver = false;
};