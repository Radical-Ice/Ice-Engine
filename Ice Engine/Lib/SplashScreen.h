#pragma once
#include "SFML/Graphics.hpp"
#include <Windows.h>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;

class SplashScreen
{
public:
	SplashScreen();
	sf::Texture SSTexture;
	void Show(sf::RenderWindow& window);




	~SplashScreen();
};

