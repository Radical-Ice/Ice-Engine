#include "InputProcesser.h"


void InputProcesser::MouseMove(LPARAM lParam) {
	ptsBegin = MAKEPOINTS(lParam);
}
void InputProcesser::RightButtonDown() {
	pt.x = ptsBegin.x;
	pt.y = ptsBegin.y;
	storedKey = "Right click ";
	storedKey += std::to_string(pt.x);
	storedKey += " ";
	storedKey += std::to_string(pt.y);
	toPrint = storedKey.c_str();
	myBool = true;
}
void InputProcesser::LeftMouseUp() {
	pt.x = ptsBegin.x;
	pt.y = ptsBegin.y;
	storedKey = "Left click up ";
	storedKey += std::to_string(pt.x);
	storedKey += " ";
	storedKey += std::to_string(pt.y);
	toPrint = storedKey.c_str();
	storedPointEndX = pt.x;
	storedPointEndY = pt.y;
	myBool = true;
	readyToDrawLine = true;
}
void InputProcesser::LeftMouseDown() {
	pt.x = ptsBegin.x;
	pt.y = ptsBegin.y;

	if (PtInRect(&arrayofRects[0], pt))
	{

		if (!pointsBeginX.empty()) {
			deleteline = true;

		}
	}
	if (PtInRect(&arrayofRects[1], pt))
	{

		color = 2;

	}
	if (PtInRect(&arrayofRects[2], pt))
	{
		color = 1;

	}
	//reset line points
	storedPointBeginX = 0;
	storedPointBeginY = 0;
	storedPointEndX = 0;
	storedPointEndY = 0;
	storedKey = "Left click ";
	storedKey += std::to_string(pt.x);
	storedKey += " ";
	storedKey += std::to_string(pt.y);
	toPrint = storedKey.c_str();
	storedPointBeginX = pt.x;
	storedPointBeginY = pt.y;
	//myBool = true;
	//InvalidateRect(hWnd, rect, 1);
}
void InputProcesser::ProcessInput(WPARAM wParam) {
	myBool = true;
	value = (LPCSTR)&wParam;
	storedKey = (std::string)value;
	toPrint = storedKey.c_str();
	
	//cout << wParam << endl;
	//For Spacial Keydowns
	if (wParam == 17)
	{
		storedKey = "Control ";
		toPrint = storedKey.c_str();
	}
	else if (wParam == 32)
	{
		storedKey = "Space ";
		toPrint = storedKey.c_str();
	}
	else if (wParam == 16)
	{
		storedKey = "Shift ";
		toPrint = storedKey.c_str();
	}
	else if (wParam == 19)
	{
		storedKey = "Space ";
		toPrint = storedKey.c_str();
	}
	else if (wParam == 20)
	{
		storedKey = "Caps Lock ";
		toPrint = storedKey.c_str();
	}
	else if (wParam == 9)
	{
		storedKey = "TAB";
		toPrint = storedKey.c_str();
	}
}