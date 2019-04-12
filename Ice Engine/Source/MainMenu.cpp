#include "..\Lib\MainMenu.h"



MainMenu::MainMenu()
{
	
}


MainMenu::~MainMenu()
{
}

void MainMenu::Inist()
{
	IceEngine _IceEngine;
	_IceEngine.InitGraphics();
	_IceEngine.DoChecks(szWindowClass);

	//_IceEngine.InitEngine();
	Game1 game;
	game.StartGame(_IceEngine);
}