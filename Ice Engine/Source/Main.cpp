<<<<<<< HEAD

#include <windows.h>  
#include <stdlib.h>  
#include <string.h>  
#include <tchar.h>  
#include <direct.h>
#include<iostream>
// Global variables  

// The main window class name.  
static TCHAR szWindowClass[] = _T("win32app");

// The string that appears in the application's title bar.  
static TCHAR szTitle[] = _T("Win32 Guided Tour Application");

HINSTANCE hInst;

// Forward declarations of functions included in this code module:  
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

bool IsOnlyInstance(LPCSTR gameTitle);
bool CheckStorage(const DWORDLONG diskSpaceNeeded);
bool CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded);
DWORD ReadCPUSpeed();														//TODO this does not work for me
const DWORDLONG diskSpaceNeed= 300;
const DWORDLONG physicalRAMNeed = 5;
const DWORDLONG virtualRAMNeed = 5;
int CALLBACK WinMain(                              //XXXXXXXXXXXXXXXXXXXXXXXXXXXX             Switch main back to WinMain for actual tests but you wont get a console output XXXXXXXXXXXXXXXXXXXXXXXXXXX
	_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
	
)
{
	AllocConsole();
	freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	if (!IsOnlyInstance(szWindowClass)) {											// is only instance or close
		std::cout << "Not the only instance"<<std::endl;
		system("pause");
		return 1;
	}
	std::cout << "the only instance"<<std::endl;
	if (!CheckStorage(diskSpaceNeed)) {
		std::cout << "not enough disk space"<<std::endl;
		system("pause");
		return 1;
	}
	std::cout << "enough disk space" << std::endl;
	CheckMemory(physicalRAMNeed, virtualRAMNeed);
	
	
	std::cout<<ReadCPUSpeed();
	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("Win32 Guided Tour"),
			NULL);

		return 1;
	}

	hInst = hInstance; // Store instance handle in our global variable  

	// The parameters to CreateWindow explained:  
	// szWindowClass: the name of the application  
	// szTitle: the text that appears in the title bar  
	// WS_OVERLAPPEDWINDOW: the type of window to create  
	// CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)  
	// 500, 100: initial size (width, length)  
	// NULL: the parent of this window  
	// NULL: this application does not have a menu bar  
	// hInstance: the first parameter from WinMain  
	// NULL: not used in this application  
	HWND hWnd = CreateWindow(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		500, 100,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (!hWnd)
	{
		MessageBox(NULL,
			_T("Call to CreateWindow failed!"),
			_T("Win32 Guided Tour"),
			NULL);

		return 1;
	}

	// The parameters to ShowWindow explained:  
	// hWnd: the value returned from CreateWindow  
	// nCmdShow: the fourth parameter from WinMain  
	ShowWindow(hWnd,
		nCmdShow);
	UpdateWindow(hWnd);

	// Main message loop:  
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

//  
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)  
//  
//  PURPOSE:  Processes messages for the main window.  
//  
//  WM_PAINT    - Paint the main window  
//  WM_DESTROY  - post a quit message and return  
//  
//  
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR greeting[] = _T("Hello, World!");

	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		// Here your application is laid out.  
		// For this introduction, we just print out "Hello, World!"  
		// in the top left corner.  
		TextOut(hdc,
			5, 5,
			greeting, _tcslen(greeting));
		// End application-specific layout section.  

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
bool IsOnlyInstance(LPCSTR gameTitle) {
	HANDLE handle = CreateMutex(NULL, TRUE, gameTitle);
	if (GetLastError() != ERROR_SUCCESS) {
		HWND hWnd = FindWindow(gameTitle, NULL);
		if (hWnd) {
			// An instance of your game is already running.
			ShowWindow(hWnd, SW_SHOWNORMAL);
			SetFocus(hWnd);
			SetForegroundWindow(hWnd);
			SetActiveWindow(hWnd);
			return false;
		}
	}
	return true;
}
bool CheckStorage(const DWORDLONG diskSpaceNeeded) {
	// Check for enough free disk space on the current disk.
	int const drive = _getdrive();
	struct _diskfree_t diskfree;
	_getdiskfree(drive, &diskfree);
	unsigned __int64 const neededClusters
	 = diskSpaceNeeded /
		(diskfree.sectors_per_cluster *
			diskfree.bytes_per_sector);
	if (diskfree.avail_clusters < neededClusters) {
		// if you get here you don’t have enough disk space!
		std::cout<<"CheckStorage Failure: Not enough physical storage.";
		return false;
	}
	return true;
}
bool CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded) {
	MEMORYSTATUSEX status;
	GlobalMemoryStatusEx(&status);
	if (status.ullTotalPhys < physicalRAMNeeded) {
		/* you don’€™t have enough physical memory. Tell the player to go get a real
		computer and give this one to his mother. */
		std::cout<<("CheckMemory Failure: Not enough physical memory.");
		return false;
	}
	std::cout << "Total Ram = ";
	std::cout << status.ullTotalPhys << std::endl;
	// Check for enough free memory.
	if (status.ullAvailVirtual < virtualRAMNeeded) {
		// you don’t have enough virtual memory available.
		// Tell the player to shut down the copy of Visual Studio running in the
		std::cout<<("CheckMemory Failure: Not enough virtual memory.");
		return false;
	}
	std::cout << "Total VRam = ";
	std::cout << status.ullAvailVirtual<<std::endl;
	char *buff = new char[virtualRAMNeeded];
	if (buff)
		delete[] buff;
	else {
		// even though there is enough memory, it isn’t available in one block, which
		
			std::cout<<("CheckMemory Failure: Not enough contiguous memory.");
		return false;
	}
	std::cout << "enough memory" << std::endl;
}
DWORD ReadCPUSpeed() {
	DWORD BufSize = sizeof(DWORD);
	DWORD dwMHz = 0;
	DWORD type = REG_DWORD;
	HKEY hKey;
	// open the key where the proc speed is hidden:
	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
		"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",
		0,
		KEY_READ,
		&hKey);
	if (lError == ERROR_SUCCESS) {
		// query the key:
		RegQueryValueEx(hKey,
			"MHz",
			NULL,
			&type,
			(LPBYTE)&dwMHz,
			&BufSize);
	}
	return dwMHz;
}
=======
//Authors: James Bews, Jatin Kumar, Dennis Nguyen
#include "../Lib/IceEngine.h"

#define DIV 1024
// Global variables  
// The main window class name.  
static TCHAR szWindowClass[] = _T("win32app");
static TCHAR szTitle[] = _T("Win32 Guided Tour Application");
// The string that appears in the application's title bar.  


//HINSTANCE hInst;
//~~~~Main Window With Console Enabled~~~~~
int CALLBACK WinMain(                             
	_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow

)
{
	AllocConsole();
	freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);

	IceEngine iceEngine;
	iceEngine.DoChecks(szWindowClass);	
	iceEngine.RegisterWindow(hInstance, szWindowClass, nCmdShow, szTitle);
	iceEngine.InitEngine();
	


	//hInst = hInstance; // Store instance handle in our global variable  
	return (int)iceEngine.msg.wParam;
}
>>>>>>> master
