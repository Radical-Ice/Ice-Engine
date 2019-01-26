#pragma once
#include "windows.h"
#include <string>
#include <vector>
using namespace std;
class InputProcesser {
public:
	bool myBool;
	LPCSTR value = "test";
	std::string storedKey = "a";
	LPCSTR toPrint = "Press Some Buttons :-) ";

	bool deleteline = false;
	bool readyToDrawLine = 0;
	int storedPointBeginX = 0;
	int storedPointBeginY = 0;
	int storedPointEndX = 0;
	int storedPointEndY = 0;
	std::vector <int> pointsBeginX;
	std::vector <int> pointsBeginY;
	std::vector <int> pointsEndX;
	std::vector <int> pointsEndY;
	POINTS ptsBegin;
	POINT pt;
	int color = 1;
	std::vector <RECT> arrayofRects;
	

public:
	void ProcessInput(WPARAM wparam);
	void MouseMove(LPARAM lParam);
	void LeftMouseDown();
	void LeftMouseUp();
	void RightButtonDown();
};