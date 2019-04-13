#include "..\Lib\MainMenu.h"



MainMenu::MainMenu()
{
	
}


MainMenu::~MainMenu()
{
}

void MainMenu::Inist()
{
	IceEngine _IceEngine;
	_IceEngine.InitGraphics();
	_IceEngine.DoChecks(szWindowClass);
	Game1 _game;
	GameObject BackgroundObj = new GameObject(&_IceEngine.sceneNode);
	SpriteComponent BackgroundIMG(&_IceEngine.mainWindow, "Assets/background.png", BackgroundObj.m_Transform);
	BackgroundObj.m_Transform->m_Position = { 0,0 };
	BackgroundObj.m_Transform->m_Scale = {2.f,2.f };
	BackgroundObj.m_Transform->m_Rotation = { 0 };
	BackgroundObj.components.push_back(&BackgroundIMG);

	GameObject StartOBJ = new GameObject(&_IceEngine.sceneNode);
	static SpriteComponent StartIMG(&_IceEngine.mainWindow, "Assets/Start.png", StartOBJ.m_Transform);
	StartOBJ.m_Transform->m_Position = { _IceEngine.mainWindow.getSize().x / 4.0f,_IceEngine.mainWindow.getSize().y / 4.0f };
	StartOBJ.m_Transform->m_Scale = { 1.0f,1.0f };
	StartOBJ.m_Transform->m_Rotation = { 0 };
	StartOBJ.components.push_back(&StartIMG);
	
	class MainEvents : public KeyEventHandler {
	public:
		IceEngine* iceE;
		Game1* game;
		MainEvents::MainEvents(IceEngine *_IceEngine, Game1* gm) {
			iceE = _IceEngine;
			game = gm;
		}
		void HandleEvents(const Event& e) {
			sf::Vector2f mousePosF(static_cast<float>(e.obj1), static_cast<float>(e.obj2));
			switch (e.Type) {
			case MouseLeft:
				
				if (StartIMG.sprite.getGlobalBounds().contains(mousePosF))
				{
					iceE->sceneNode.children.clear();
					game->StartGame(*iceE);
					break;
				}
			default:
				
				break;
			}
		}
	}test(&_IceEngine, &_game);
	_IceEngine.InitEngine();
	return;
}