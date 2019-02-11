#pragma once
#ifndef EVENTDISPACHER_H
#define EVENTDISPACHER_H
#include "KeyEventHandler.h"

class KeyEventHandler;
class EventDispacher
{
	static EventDispacher* Instance;
	EventDispacher();
public:
	void RegisterHandler(KeyEventHandler *device); //adds new object as listener
	void SendEvent(int eventType, int arg1 = 0, int arg2 = 0);

	static EventDispacher* get() {
		if (!Instance)
			Instance = new EventDispacher();

		return Instance;
	}

private:
	KeyEventHandler *_deviceList;

};


#endif