#pragma once
#include "SFML/Audio.hpp"
#include <Windows.h>
#include <string>
#include <tchar.h>
#include <vector>
#include <iostream>

class AudioComp
{	
private:
	sf::SoundBuffer SoundBuffer;
	sf::Sound Sound;
	sf::Music Music;
	std::vector<sf::SoundBuffer> A_Sounds;
	int x;
	
public:
	void LoadSound(std::string Filename);
	void PlayAudio(float Volume, bool Is_Looping);
	void SoundPause_Unpause(bool);
	///<summary>Insert your vector type list of Music; Index of the file you want to play; at what volume; is it looping</summary>
	void LoadMusic(std::vector<std::string>, int, float, bool);
	void PlayMusic();
	///<summary>Insert your vector type list of sounds</summary>
	void Load_Sounds_From_Files(std::vector<std::string>);
	///<summary>Need Index of the file you want to play; At what volume; is sound Looping</summary>
	void Play_Sound_From_Loaded_Files(int, float, bool);
};