#include "IceEngine.h"


void IceEngine::InitGraphics() {
	mainWindow.create(sf::VideoMode(1024, 768, 32), "Meow");
	if (state == SplashScreen)
		splashScreen.Show(mainWindow);
	mainWindow.display();
}
void IceEngine::InitEngine() {
	
	//"Assets/ " for pics
	if (!texture.loadFromFile("Assets/cat.png")) {
		MessageBox(NULL,
			_T("Failed to load CAT texture"),
			_T("-> Ice Engine.cpp"),
			NULL);
	}
	// Create a sprite
	
	sprite.setTexture(texture);
	
	sprite.setPosition(100, 25);
	// Draw it
	
	while (mainWindow.isOpen())
	{
		elapsed = clock.restart();
		while (mainWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				mainWindow.close();
		}
		sceneNode.Update();
		mainWindow.clear();
		mainWindow.draw(sprite);
		if(state==SplashScreen)
			splashScreen.Show(mainWindow);
		mainWindow.display();
	}
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		scriptComponent.runScript();
	}
	//cleanD3D();
}

void IceEngine::DoChecks(LPCSTR szWindowClass) {
	MessageBox(NULL,
		_T("doing checks"),
		_T("-> Ice Engine.cpp"),
		NULL);
	checker->initChecks(szWindowClass, physicalRAMNeed, virtualRAMNeed, diskSpaceNeed);
	state = nextScreen;
}
int IceEngine::RegisterWindow(HINSTANCE hInstance,LPCSTR szWindowClass, int nCmdShow, LPCSTR szTitle) {
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
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("Ice Engine"),
			NULL);
		return 1;
	}
	
	HWND hWnd = CreateWindow(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		1000, 1000,
		NULL,
		NULL,
		hInstance,
		NULL
	);
	//initD3D(hWnd);
	if (!hWnd)
	{
		MessageBox(NULL,
			_T("Call to CreateWindow failed!"),
			_T("Win32 Guided Tour"),
			NULL);

		return 1;
	}

	//ShowWindow(hWnd, nCmdShow);
	//UpdateWindow(hWnd);
}