#include "AudioComponent.h"

void AudioComp::LoadSound(std::string Filename)
{
	LPCSTR File = Filename.c_str();
	if (!SoundBuffer.loadFromFile(Filename))
	{
		MessageBox(NULL,
			(File),
			("Failed to load Wav file ->"),
			NULL);
	}
	//Sound->setBuffer(*SoundBuffer);
}
///<summary>Need Volume and Looping Condition</summary>
void AudioComp::PlayAudio(int Volume, bool Is_Looping)
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