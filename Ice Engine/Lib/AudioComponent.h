#pragma once
#include "SFML/Audio.hpp"
#include <Windows.h>
#include <string>
#include <tchar.h>

class AudioComp
{	
private:
	sf::SoundBuffer SoundBuffer;
	sf::Sound Sound;
	
public:
	void LoadSound(std::string Filename);
	void PlayAudio(int Volume, bool Is_Looping);
	void SoundPause_Unpause(bool);
};