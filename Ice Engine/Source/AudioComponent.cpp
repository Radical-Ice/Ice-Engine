#include "AudioComponent.h"

void AudioComp::LoadSound(std::string Filename)
{
	LPCSTR File = Filename.c_str();
	if (!SoundBuffer.loadFromFile(Filename))
	{
		MessageBox(NULL, (File), ("Failed to load Wav file ->"), NULL);
	}
	//Sound->setBuffer(*SoundBuffer);
}
///<summary>Need Volume and Looping Condition</summary>
void AudioComp::PlayAudio(float Volume, bool Is_Looping)
{
	Sound.setBuffer(SoundBuffer);
	Sound.setVolume(Volume);
	Sound.setLoop(Is_Looping);
	Sound.play();
}

void AudioComp::SoundPause_Unpause(bool Condition)
{
	if (Condition)
	{
		Sound.pause();
	}
	else
	{
		Sound.play();
	}
}
void AudioComp::LoadMusic(std::vector<std::string> FileName, int Index, float Volume, bool IsLooping)
{
	LPCSTR File = FileName[Index].c_str();
	if(!Music.openFromFile(FileName[Index]))
	{
		MessageBox(NULL, (File), ("Failed to load Music file ->"), NULL);
	}
	Music.setVolume(Volume);
	Music.setLoop(IsLooping);
}

void AudioComp::PlayMusic()
{
	Music.play();
}

void AudioComp::Load_Sounds_From_Files(std::vector<std::string> Filenames)
{
	LPCSTR File = Filenames[x].c_str();
	for each (auto var in Filenames)
	{
		if (SoundBuffer.loadFromFile(Filenames[x]))
		{
			A_Sounds.push_back(SoundBuffer);
			x++;
		}
		else {
			MessageBox(NULL, (File), ("Failed to load Wav file ->"), NULL);
		}
		
	}
}

void AudioComp::Play_Sound_From_Loaded_Files(int index, float Volume, bool IsLooped)
{
	Sound.setBuffer(A_Sounds[index]);
	Sound.setVolume(Volume);
	Sound.setLoop(IsLooped);
	Sound.play();
}