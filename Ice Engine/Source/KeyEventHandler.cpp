#include "KeyEventHandler.h"

KeyEventHandler::KeyEventHandler() : 
_nextHandler(0) ,
dispatch (EventDispacher::get())
{
	dispatch->RegisterHandler(this);
}

void KeyEventHandler::SendEvent(int eventType, int arg1, int arg2) {
	dispatch->SendEvent(eventType, arg1, arg2);
}

 void KeyEventHandler::HandleEvents(const Event &theEvent)
{
	 switch (theEvent.Type) {
	 case MoveUp:
		 break;
	 case MoveDown:
		 break;
	 case MoveLeft:
		 break;
	 case MoveRight:
		 break;
	 case LeftReleased:
		 break;
	 case RightReleased:
		 break;
	 case UpReleased:
		 break;
	 case DownReleased:
		 break;
	 case RotateRight:
		 break;
	 case RotateLeft:
		 break;
	 case Collided:
		 break;
	 case Update:
		 break;
	 case MouseLeft:
		 break;

	 default:
		 break;
	 }
}