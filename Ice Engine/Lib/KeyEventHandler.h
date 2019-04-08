#pragma once
#ifndef EVENTTYPE_H
#define EVENTTYPE_H
#include "SFML/Graphics.hpp"
#include "EventDispacher.h"

class EventDispacher;
enum EventType
{
	MoveUp,
	MoveDown,
	MoveLeft,
	MoveRight,
	LeftReleased,
	RightReleased,
	UpReleased,
	DownReleased,
	RotateRight,
	RotateLeft,
	Update
};
struct Event {
	int Type;
	int obj1, obj2;
};


class KeyEventHandler
{
public:
	
	virtual void HandleEvents(const Event &theEvent) = 0;

	KeyEventHandler* GetNextHandler(void) { return _nextHandler; }
	void SetNextHandler(KeyEventHandler *next) { _nextHandler = next; }

	KeyEventHandler();

protected:
	void SendEvent(int eventType, int arg1 = 0, int arg2 = 0);

private:
	KeyEventHandler *_nextHandler;
	EventDispacher *dispatch; 
};

#endif