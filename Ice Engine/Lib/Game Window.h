#pragma once
#include "../Lib/Checks.h"

//Global variables
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


LPCSTR toPrint = "unchanged";
bool myBool = 0;
//	::SetWindowPos(hWnd, 0, 0, 0, 600, 300, SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER);
//Window Layout

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR greeting[] = _T("Hello, World!");

	LPRECT rect = new RECT{ 0,0,100,100 };
	switch (message)
	{

	case WM_CHAR:
		if (wParam == 97) {	
			myBool = true;
			InvalidateRect(hWnd, rect, 1);
		//	PostMessage(hWnd, WM_PAINT, 0, 0);
			//MessageBox(hWnd, (LPCTSTR)"You just pushed me!", (LPCTSTR) "My Program!", MB_OK | MB_ICONEXCLAMATION);
			

		}
		break;
	case WM_KEYDOWN:
	case WM_PAINT :
		hdc = BeginPaint(hWnd, &ps);
		MoveToEx(hdc, 100, 100, 0); 
		LineTo(hdc, 150, 150); 
		LineTo(hdc, 300, 150); 
		// Application is laid out.

		//Printing Greetings
		TextOut(hdc,5, 5,greeting, _tcslen(greeting));
		if (myBool) {			
			DrawText(hdc, "string", 6, rect, DT_LEFT);
	
		}
		//~~~~~~~~~~~~~~~~~~~

		EndPaint(hWnd, &ps);
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
