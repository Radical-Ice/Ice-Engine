#pragma once
#include "../Lib/Checks.h"

//Global variables
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Window Layout
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR greeting[] = _T("Hello, World!");

	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		// Application is laid out.

		//Printing Greetings
		TextOut(hdc,
			5, 5,
			greeting, _tcslen(greeting));
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

	return 0;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
