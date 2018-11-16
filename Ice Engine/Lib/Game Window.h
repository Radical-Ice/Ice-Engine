#pragma once
#include <string>
#include <vector>
//Global variables
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LPCSTR toPrint = "Press Some Buttons :-) ";
bool myBool = 0;
LPCSTR value = "test";
std::vector <RECT> arrayofRects;
LPRECT rect = new RECT{ 110,0,1000,1000 };
string storedKey = "a";
int storedPointBeginX = 0;
int storedPointBeginY = 0;
int storedPointEndX = 0;
int storedPointEndY = 0;
const int arraySize = 100;
int color = 1;
std::vector <int> pointsBeginX;
std::vector <int> pointsBeginY;
std::vector <int> pointsEndX;
std::vector <int> pointsEndY;
bool readyToDrawLine = 0;
bool deleteline = false;
HGDIOBJ original = NULL;
TCHAR greeting[] = _T("Hello, World!");
TCHAR T_Press[] = _T("Pressed : ");
TCHAR Button[] = _T("Press Here");
TCHAR ClearLast[] = _T("clear last line");
TCHAR ColorB[] = _T("Make Lines Blue");
TCHAR ColorBL[] = _T("Make Lines Black");
POINT pt;
PAINTSTRUCT ps;
HDC hdc;
static POINTS ptsBegin;
//~~~~~~~~~~~~~~~~~~~~~

//	::SetWindowPos(hWnd, 0, 0, 0, 600, 300, SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER);
//Window Layout

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		//For Keydown and Keydown for CHAR based(A,a,B,b...)
	case WM_CHAR:
	case WM_KEYDOWN:
			myBool = true;
			value = (LPCSTR)&wParam;
			storedKey = (string)value;
			toPrint = storedKey.c_str();
			InvalidateRect(hWnd, rect, 1);
			cout << wParam << endl;
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
		break;
		//For Painting Main Window
	case WM_PAINT :
		//Paint Begins here
		hdc = BeginPaint(hWnd, &ps);

		arrayofRects.push_back( RECT{ 0,20,110,50 });
		arrayofRects.push_back( RECT{ 0,60,110,100 });
		arrayofRects.push_back( RECT{ 0,110,110,150 });

		FillRect(hdc, &arrayofRects[0], (HBRUSH)(COLOR_WINDOW + 2));
		FillRect(hdc, &arrayofRects[1], (HBRUSH)(COLOR_WINDOW + 3));
		SetDCBrushColor(hdc, RGB(0, 255, 0));
		FillRect(hdc, &arrayofRects[2], (HBRUSH)(COLOR_WINDOW+ 3));
		//Just drawing some line
		//MoveToEx(hdc, 100, 100, 0); 
		//LineTo(hdc, 150, 150); 
		//LineTo(hdc, 300, 600); 
		
		//Printing Greetings and Pressed stuff
		//TextOut(hdc,0, 0,greeting, _tcslen(greeting));
		TextOut(hdc, 40, 0, T_Press, _tcslen(T_Press));
		//Setting color red to text.

		SetTextColor(hdc, RGB(255, 0, 0));
		TextOut(hdc, 0, 25, ClearLast, _tcslen(ClearLast));
		SetTextColor(hdc, RGB(0, 0, 255));

		TextOut(hdc, 0, 75, ColorB, _tcslen(ColorB));
		SetTextColor(hdc, RGB(255, 0, 0));


		TextOut(hdc, 0, 120, ColorBL, _tcslen(ColorBL));
		SetTextColor(hdc, RGB(255, 0, 0));

		DrawText(hdc, toPrint, _tcslen(toPrint), rect, DT_LEFT);
		original = SelectObject(hdc, GetStockObject(DC_PEN));
		switch (color)
		{
		case 1:
			SelectObject(hdc, GetStockObject(BLACK_PEN));
			break;
		case 2:
			SetDCPenColor(hdc, RGB(255, 0, 0));
			break;
		}


		//For first time run
		if (myBool) {
			SetTextColor(hdc, RGB(255, 0, 0));
			DrawText(hdc, toPrint, _tcslen(toPrint), rect, DT_LEFT);
			if (readyToDrawLine)
			{
				
				MoveToEx(hdc, storedPointBeginX, storedPointBeginY, NULL);
				LineTo(hdc, storedPointEndX, storedPointEndY);
				
				pointsBeginX.push_back(storedPointBeginX);
				pointsBeginY.push_back(storedPointBeginY);
				pointsEndX.push_back(storedPointEndX);
				pointsEndY.push_back(storedPointEndY);
			}
		}
		//deletes twice cuase apparently it takes the inital click on the button as a line
		if (deleteline == true)
		{
			pointsBeginX.pop_back();
			pointsBeginX.pop_back();
			pointsBeginY.pop_back();
			pointsBeginY.pop_back();
			pointsEndX.pop_back();
			pointsEndX.pop_back();
			pointsEndY.pop_back();
			pointsEndY.pop_back();
			cout << "clear" << endl;
			deleteline = false;
			
		}

		for (int i = 0; i < pointsBeginX.size(); i++)
		{
			cout << pointsBeginX[i] << endl;
			pointsBeginX[i];
			pointsBeginY[i];
			pointsEndX[i];
			pointsEndY[i];
			MoveToEx(hdc, pointsBeginX[i], pointsBeginY[i], NULL);
			LineTo(hdc, pointsEndX[i], pointsEndY[i]);
		}

		//Paint ends here
		EndPaint(hWnd, &ps);
		break;
		//For getting mouse coord per sec
	case WM_MOUSEMOVE:
		ptsBegin = MAKEPOINTS(lParam);
		break;
		//On left click draw coord.
	case WM_LBUTTONDOWN:
		pt.x = ptsBegin.x;
		pt.y = ptsBegin.y;

		if (PtInRect(&arrayofRects[0], pt))
		{

			if (!pointsBeginX.empty()) {
				cout << "last line cleared" << endl;
				deleteline = true;
				
			}
		}
		if (PtInRect(&arrayofRects[1], pt))
		{
			cout << "made lines blue" << endl;
			color = 2;
			
		}
		if (PtInRect(&arrayofRects[2], pt))
		{
			cout << "made lines black" << endl;
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
		break;
		//On left click up
	case WM_LBUTTONUP:
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
			InvalidateRect(hWnd, rect, 1);
		break;
		//On right click draw coord.
	case WM_RBUTTONDOWN:
		pt.x = ptsBegin.x;
		pt.y = ptsBegin.y;
		storedKey = "Right click ";
		storedKey += std::to_string(pt.x);
		storedKey += " ";
		storedKey += std::to_string(pt.y);
		toPrint = storedKey.c_str();
		myBool = true;
		InvalidateRect(hWnd, rect, 1);
		break;
	
		 
	/*case WM_LBUTTONDOWN:
		pt.x = ptsBegin.x;
		pt.y = ptsBegin.y;
		if (PtInRect(rect2, pt))
		{
			cout << "Pressed" << endl;
			myBool = true;
			InvalidateRect(hWnd, rect, 1);
		}
		myBool = true;
		value = (LPCSTR)&wParam;
		storedKey = (string)value;
		toPrint = &storedKey[0];
		InvalidateRect(hWnd, rect, 1);
		break;*/
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
