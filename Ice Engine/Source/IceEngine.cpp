#include "IceEngine.h"


//Load Texture for Main Game Window
void IceEngine::LoadTexture(sf::RenderWindow& Window)
{
	if (!texture.loadFromFile("Assets/cat.png")) {
		MessageBox(NULL,
			_T("Failed to load CAT texture"),
			_T("-> Ice Engine.cpp"),
			NULL);
	}
	sprite2.setTexture(texture);
	sprite2.setPosition(100, 25);

}
//Splash Screen First screen
void IceEngine::CreateSplashWindow()
{
	LoadTexture(SplashScreen);
	SplashScreen.create(sf::VideoMode(1024, 768, 32), "SplashScreen");
	while (SplashScreen.isOpen())
	{
		//time = clock.restart();
		time = clock.getElapsedTime();
		while (SplashScreen.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
					SplashScreen.close();
					//mainWindow.create(sf::VideoMode(1024, 768, 32), "Main Game Window");
			}

		}
		if(time.asSeconds() <= 5.00)
		{
			SplashScreen.clear();
			SplashScreen.draw(sprite);
			SplashScreen.display();
		}
		else
		{
			SplashScreen.clear();
			SplashScreen.draw(sprite2);
			SplashScreen.display();
		}
	}
}
void IceEngine::CreateMainWindow()
{
	while (mainWindow.isOpen())
	{
		while (mainWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				mainWindow.close();
				exit(0);
			}

		}

		mainWindow.clear();
		mainWindow.draw(sprite2);
		mainWindow.display();

	}
}
void IceEngine::InitEngine() {
	
	sp.Show(SplashScreen);
	//LoadTexture(mainWindow);
	sprite.setTexture(sp.SSTexture);
	sprite.setPosition(100, 25);
	
	CreateSplashWindow();
	//CreateMainWindow();

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

	//splashScreen.Show(mainWindow);
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

