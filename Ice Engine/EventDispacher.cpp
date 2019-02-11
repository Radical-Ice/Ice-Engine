#include "EventDispacher.h"
#include <cassert>

EventDispacher* EventDispacher::Instance = nullptr;

EventDispacher::EventDispacher() :
	_deviceList(nullptr)
{
	
}

void EventDispacher::RegisterHandler(KeyEventHandler *device)
{
	device->SetNextHandler(_deviceList);
	_deviceList = device;
}

void EventDispacher::SendEvent(int eventType, int arg1, int arg2) {
	Event e;
	e.Type = eventType;
	e.obj1 = arg1;
	e.obj2 = arg2;
	KeyEventHandler * curDevice = _deviceList;

	for (; curDevice; curDevice = curDevice->GetNextHandler()) {
		assert (curDevice != curDevice->GetNextHandler());
		curDevice->HandleEvents(e);
	}
}
