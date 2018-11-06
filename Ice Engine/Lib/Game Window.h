#pragma once
#include "../Lib/Checks.h"
#include <string> 
//Global variables
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


LPCSTR toPrint = "unchanged";
bool myBool = 0;
LPCSTR value = "test";
LPRECT rect = new RECT{ 50,50,100,100 };
string storedKey = "a";
//	::SetWindowPos(hWnd, 0, 0, 0, 600, 300, SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER);
//Window Layout

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR greeting[] = _T("Hello, World!");
	TCHAR Action[] = _T("Pressed : ");
	TCHAR Button[] = _T("Press Here");
	POINT pt;
	static POINTS ptsBegin;
<<<<<<< HEAD
	LPRECT rect = new RECT{ 25,20,400,400 };
=======
	LPRECT rect = new RECT{ 70,30,100,100 };
>>>>>>> 31d4e32026b3eb1fd8179e3993204ca44412272c
	LPRECT rect2 = new RECT{ 50,50,150,100 };

	switch (message)
	{
<<<<<<< HEAD
	case WM_KEYDOWN:
	case WM_CHAR:
=======
	case WM_LBUTTONDOWN:
	case WM_RBUTTONDOWN:
	case WM_KEYDOWN:
>>>>>>> 31d4e32026b3eb1fd8179e3993204ca44412272c
		//if (wParam == 97) {	
			myBool = true;
			value = (LPCSTR)&wParam;
			storedKey = (string)value;
			toPrint = storedKey.c_str();
			InvalidateRect(hWnd, rect, 1);
<<<<<<< HEAD

=======
			cout << toPrint << endl;
>>>>>>> 31d4e32026b3eb1fd8179e3993204ca44412272c
		break;

	case WM_PAINT :
		hdc = BeginPaint(hWnd, &ps);
		MoveToEx(hdc, 100, 100, 0); 
		LineTo(hdc, 150, 150); 
		LineTo(hdc, 300, 150); 
		// Application is laid out.

		//Printing Greetings
		TextOut(hdc,5, 5,greeting, _tcslen(greeting));
		TextOut(hdc, 0, 30, Action, _tcslen(Action));

		if (myBool) {
			SetTextColor(hdc, RGB(255, 0, 0));
			DrawText(hdc, toPrint, _tcslen(toPrint), rect, DT_LEFT);
		}
		EndPaint(hWnd, &ps);
		break;
	case WM_MOUSEMOVE:
		ptsBegin = MAKEPOINTS(lParam);
		break;

<<<<<<< HEAD
	case WM_LBUTTONDOWN:
		pt.x = ptsBegin.x;
		pt.y = ptsBegin.y;
		storedKey = "Left click ";
		storedKey += std::to_string(pt.x);
		storedKey +=" ";
		storedKey+= std::to_string(pt.y);
		toPrint = storedKey.c_str();
		myBool = true;
		InvalidateRect(hWnd, rect, 1);
		
		break;
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
=======
	//case WM_LBUTTONDOWN:
	//	/*pt.x = ptsBegin.x;
	//	pt.y = ptsBegin.y;
	//	if (PtInRect(rect2, pt))
	//	{
	//		cout << "Pressed" << endl;
	//		myBool = true;
	//		InvalidateRect(hWnd, rect, 1);
	//	}*/
	//	myBool = true;
	//	value = (LPCSTR)&wParam;
	//	storedKey = (string)value;
	//	toPrint = &storedKey[0];
	//	InvalidateRect(hWnd, rect, 1);
	//	break;
>>>>>>> 31d4e32026b3eb1fd8179e3993204ca44412272c

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
