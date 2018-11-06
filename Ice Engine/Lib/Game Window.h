#pragma once
#include "../Lib/Checks.h"

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
<<<<<<< HEAD

	
	
=======
	TCHAR Action[] = _T("Pressed ");
	TCHAR Button[] = _T("Press Here");
	POINT pt;
	static POINTS ptsBegin;
	LPRECT rect = new RECT{ 25,20,100,100 };
	LPRECT rect2 = new RECT{ 50,50,150,100 };
>>>>>>> 839ef15a3c3fa597a5f33eaa6aa6c50953a8c5c4
	switch (message)
	{

	case WM_CHAR:
		//if (wParam == 97) {	
			myBool = true;
			value = (LPCSTR)&wParam;
			storedKey = (string)value;
			toPrint = &storedKey[0];
			InvalidateRect(hWnd, rect, 1);
		//	PostMessage(hWnd, WM_PAINT, 0, 0);
			//MessageBox(hWnd, (LPCTSTR)"You just pushed me!", (LPCTSTR) "My Program!", MB_OK | MB_ICONEXCLAMATION);
			

		//}
		break;
	case WM_KEYDOWN:
		break;
	case WM_PAINT :
		hdc = BeginPaint(hWnd, &ps);
		MoveToEx(hdc, 100, 100, 0); 
		LineTo(hdc, 150, 150); 
		LineTo(hdc, 300, 150); 
		// Application is laid out.

		//Printing Greetings
		TextOut(hdc,5, 5,greeting, _tcslen(greeting));
<<<<<<< HEAD
		if (myBool) {	
			SetTextColor(hdc,RGB(255,0,0));
			DrawText(hdc, toPrint, 1, rect, DT_LEFT);
	
=======
		DrawText(hdc, Button, _tcslen(Button), rect2, DT_TOP);
		//TextOut(hdc, 35, 35, greeting, _tcslen(greeting));
		if (myBool) {			
			DrawText(hdc, Action, _tcslen(Action), rect, DT_LEFT);
>>>>>>> 839ef15a3c3fa597a5f33eaa6aa6c50953a8c5c4
		}
		//bool PtInRect(rect, VK_MBUTTON);
		//~~~~~~~~~~~~~~~~~~~

		EndPaint(hWnd, &ps);
		break;
	case WM_MOUSEMOVE:
		ptsBegin = MAKEPOINTS(lParam);
		break;

	case WM_LBUTTONDOWN:
		pt.x = ptsBegin.x;
		pt.y = ptsBegin.y;
		if (PtInRect(rect2, pt))
		{
			cout << "Pressed" << endl;
			myBool = true;
			InvalidateRect(hWnd, rect, 1);
		}
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
