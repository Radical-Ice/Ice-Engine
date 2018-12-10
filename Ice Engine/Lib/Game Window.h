#pragma once
#include <string>
#include <vector>
#include "..\Lib\InputProcesser.h"

using namespace std;
//Global variables
static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//LPCSTR toPrint = "Press Some Buttons :-) ";
//bool myBool = 0;
//LPCSTR value = "test";

 static LPRECT rect = new RECT{ 110,0,1000,1000 };
//string storedKey = "a";

static TCHAR greeting[] = _T("Hello, World!");
static TCHAR T_Press[] = _T("Pressed : ");
static TCHAR Button[] = _T("Press Here");
static TCHAR ClearLast[] = _T("clear last line");
static TCHAR ColorB[] = _T("Make Lines Blue");
static TCHAR ColorBL[] = _T("Make Lines Black");

	const int arraySize = 100;
	static HGDIOBJ original = NULL;
	static PAINTSTRUCT ps;
	static HDC hdc;
static InputProcesser input;


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
		input.ProcessInput(wParam);
		InvalidateRect(hWnd, rect, 1);
		break;
		//For Painting Main Window
	case WM_PAINT :
		//Paint Begins here
		hdc = BeginPaint(hWnd, &ps);

		input.arrayofRects.push_back( RECT{ 0,20,110,50 });
		input.arrayofRects.push_back( RECT{ 0,60,110,100 });
		input.arrayofRects.push_back( RECT{ 0,110,110,150 });

		FillRect(hdc, &input.arrayofRects[0], (HBRUSH)(COLOR_WINDOW + 2));
		FillRect(hdc, &input.arrayofRects[1], (HBRUSH)(COLOR_WINDOW + 3));
		SetDCBrushColor(hdc, RGB(0, 255, 0));
		FillRect(hdc, &input.arrayofRects[2], (HBRUSH)(COLOR_WINDOW+ 3));
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

		DrawText(hdc, input.toPrint, _tcslen(input.toPrint), rect, DT_LEFT);
		original = SelectObject(hdc, GetStockObject(DC_PEN));
		switch (input.color)
		{
		case 1:
			SelectObject(hdc, GetStockObject(BLACK_PEN));
			break;
		case 2:
			SetDCPenColor(hdc, RGB(255, 0, 0));
			break;
		}


		//For first time run
		if (input.myBool) {
			SetTextColor(hdc, RGB(255, 0, 0));
			DrawText(hdc, input.toPrint, _tcslen(input.toPrint), rect, DT_LEFT);
			if (input.readyToDrawLine)
			{
				
				MoveToEx(hdc, input.storedPointBeginX, input.storedPointBeginY, NULL);
				LineTo(hdc, input.storedPointEndX, input.storedPointEndY);
				
				input.pointsBeginX.push_back(input.storedPointBeginX);
				input.pointsBeginY.push_back(input.storedPointBeginY);
				input.pointsEndX.push_back(input.storedPointEndX);
				input.pointsEndY.push_back(input.storedPointEndY);
			}
		}
		//deletes twice cuase apparently it takes the inital click on the button as a line
		if (input.deleteline == true)
		{
			input.pointsBeginX.pop_back();
			input.pointsBeginX.pop_back();
			input.pointsBeginY.pop_back();
			input.pointsBeginY.pop_back();
			input.pointsEndX.pop_back();
			input.pointsEndX.pop_back();
			input.pointsEndY.pop_back();
			input.pointsEndY.pop_back();
			input.deleteline = false;
			
		}

		for (int i = 0; i < input.pointsBeginX.size(); i++)
		{
			input.pointsBeginX[i];
			input.pointsBeginY[i];
			input.pointsEndX[i];
			input.pointsEndY[i];
			MoveToEx(hdc, input.pointsBeginX[i], input.pointsBeginY[i], NULL);
			LineTo(hdc, input.pointsEndX[i], input.pointsEndY[i]);
		}

		//Paint ends here
		EndPaint(hWnd, &ps);
		break;
		//For getting mouse coord per sec
	case WM_MOUSEMOVE:
		input.MouseMove(lParam);
		break;
		//On left click draw coord.
	case WM_LBUTTONDOWN:
		input.LeftMouseDown();
		
		break;
		//On left click up
	case WM_LBUTTONUP:
		input.LeftMouseUp();
		InvalidateRect(hWnd, rect, 1);
		break;
		//On right click draw coord.
	case WM_RBUTTONDOWN:
		input.RightButtonDown();
		
		InvalidateRect(hWnd, rect, 1);
		break;
	
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
