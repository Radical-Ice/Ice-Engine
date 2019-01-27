#include "IceEngine.h"
SplashScreen sp;
void IceEngine::InitEngine() {
	SplashScreen.create(sf::VideoMode(1024, 768, 32), "SplashScreen");
	
	sp.Show(SplashScreen);
	//"Assets/ " for pics
	if (!texture.loadFromFile("Assets/cat.png")) {
		MessageBox(NULL,
			_T("Failed to load CAT texture"),
			_T("-> Ice Engine.cpp"),
			NULL);
	}
	/*if (!sp.SSTexture.loadFromFile("Assets/SplashScreen.jpg")) {
		MessageBox(NULL,
			_T("Failed to load SplashScreen texture"),
			_T("-> Ice Engine.cpp"),
			NULL);
	}*/
	sprite.setTexture(sp.SSTexture);
	//sprite.setTextureRect(sf::IntRect(0, 0, 500, 500));
	//sprite.setColor(sf::Color(255, 255, 255, 200));
	sprite.setPosition(100, 25);


	sprite2.setTexture(texture);
	sprite2.setPosition(100, 25);
	// Draw it
	
	while (SplashScreen.isOpen())
	{
		
		while (SplashScreen.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				SplashScreen.close();
				mainWindow.create(sf::VideoMode(1024, 768, 32), "Main Game Window");
			}
		
		}
		
		SplashScreen.clear();
		SplashScreen.draw(sprite);
		//this_thread::sleep_for(chrono::seconds(2));
		//mainWindow.draw(sprite2);
		SplashScreen.display();
	}

	while (mainWindow.isOpen())
	{
		while (mainWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				mainWindow.close();
			}

		}

		mainWindow.clear();
		mainWindow.draw(sprite2);
		//this_thread::sleep_for(chrono::seconds(2));
		//mainWindow.draw(sprite2);
		mainWindow.display();

	}

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		scriptComponent.runScript();
		//render_frame();
	}
	//cleanD3D();
}

void IceEngine::DoChecks(LPCSTR szWindowClass) {

	splashScreen.Show(mainWindow);
	checker->initChecks(szWindowClass, physicalRAMNeed, virtualRAMNeed, diskSpaceNeed);

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

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
}