#include "../Lib/Checks.h"
#include "../Lib/Game Window.h"

// Global variables  
// The main window class name.  
static TCHAR szWindowClass[] = _T("win32app");

// The string that appears in the application's title bar.  
static TCHAR szTitle[] = _T("Win32 Guided Tour Application");

HINSTANCE hInst;

// Forward declarations of functions included in this code module:  

//~~~Requirements~~~
const DWORDLONG diskSpaceNeed = 300;
const DWORDLONG physicalRAMNeed = 5;
const DWORDLONG virtualRAMNeed = 5;
//~~~~~~~~~~~~~~~~~

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
	
	//~~~Check For Multipl Instance~~~~
	if (!IsOnlyInstance(szWindowClass)) {
		cout << "Not the only instance" << endl;
		system("pause");
		return 1;
	}
	cout << "the only instance" << endl;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	//~~~Check For Storage~~~~~~~~~~~~~~~ 
	CheckMemory(physicalRAMNeed, virtualRAMNeed);
	if (!CheckStorage(diskSpaceNeed)) {
		cout << "not enough disk space" << endl;
		system("pause");
		return 1;
	}
	cout << "enough disk space" << endl;
	//~~~Check For Storage~~~~~~~~~~~~~~ 

	//~~For CPU Info~~~~~~~~~~~~~~~~~~~~
	SYSTEM_INFO siSysInfo;
	GetSystemInfo(&siSysInfo);
	//For CPU Name
	ReadCPUName();

	cout << "Processor Architecture : " << siSysInfo.wProcessorArchitecture << endl;
	cout << "Processor Speed : " << ReadCPUSpeed();
	
	//~~~For Memory Info~~~~~~~~~~~~~~~~
	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);
	cout << "\nTotal System Memory: " << (statex.ullTotalPhys / 1024) / 1024 << "MB" << endl;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	
	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("Ice Engine"),
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