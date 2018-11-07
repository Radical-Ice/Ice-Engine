#pragma once
#include <string>

//Global variables
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LPCSTR toPrint = "Press Some Buttons :-) ";
bool myBool = 0;
LPCSTR value = "test";
LPRECT rect = new RECT{ 65,30,400,400 };
string storedKey = "a";
TCHAR greeting[] = _T("Hello, World!");
TCHAR T_Press[] = _T("Pressed : ");
TCHAR Button[] = _T("Press Here");
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

		//Just drawing some line
		MoveToEx(hdc, 100, 100, 0); 
		LineTo(hdc, 150, 150); 
		LineTo(hdc, 300, 150); 

		//Printing Greetings and Pressed stuff
		TextOut(hdc,5, 5,greeting, _tcslen(greeting));
		TextOut(hdc, 0, 30, T_Press, _tcslen(T_Press));
		//Setting color red to text.
		SetTextColor(hdc, RGB(255, 0, 0));
		DrawText(hdc, toPrint, _tcslen(toPrint), rect, DT_LEFT);
		//For first time run
		if (myBool) {
			SetTextColor(hdc, RGB(255, 0, 0));
			DrawText(hdc, toPrint, _tcslen(toPrint), rect, DT_LEFT);
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
		storedKey = "Left click ";
		storedKey += std::to_string(pt.x);
		storedKey +=" ";
		storedKey+= std::to_string(pt.y);
		toPrint = storedKey.c_str();
		myBool = true;
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
	
		//~~~Leave this for later 
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
		//~~~~~~
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
