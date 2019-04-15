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
	
	SceneGraph menuScene;
	_IceEngine.sceneNode.push_back(menuScene);
	static Game1 _game;
	
	GameObject BackgroundObj = new GameObject(&_IceEngine.sceneNode.at(0));
	SpriteComponent BackgroundIMG(&_IceEngine.mainWindow, "Assets/background.png", BackgroundObj.m_Transform);
	BackgroundObj.m_Transform->m_Position = { 0,0 };
	BackgroundObj.m_Transform->m_Scale = {2.f,2.f };
	BackgroundObj.m_Transform->m_Rotation = { 0 };
	BackgroundObj.components.push_back(&BackgroundIMG);

	GameObject StartOBJ = new GameObject(&_IceEngine.sceneNode.at(0));
	static SpriteComponent StartIMG(&_IceEngine.mainWindow, "Assets/snowflake.png", StartOBJ.m_Transform);
	StartOBJ.m_Transform->m_Position = { _IceEngine.mainWindow.getSize().x / 4.0f,_IceEngine.mainWindow.getSize().y / 4.0f };
	StartOBJ.m_Transform->m_Scale = { 1.0f,1.0f };
	StartOBJ.m_Transform->m_Rotation = { 0 };
	StartOBJ.components.push_back(&StartIMG);
	
	class MainEvents : public KeyEventHandler {
	public:
		IceEngine* iceE;
		Game1* game;
		bool doOnce=true;
		MainEvents::MainEvents(IceEngine *_IceEngine, Game1* gm) {
			iceE = _IceEngine;
			game = gm;
		}
		void HandleEvents(const Event& e) {
			sf::Vector2f mousePosF(static_cast<float>(e.obj1), static_cast<float>(e.obj2));
			switch (e.Type) {
			case MouseLeft:
				std::cout << e.obj2;
				if (doOnce&&StartIMG.sprite.getGlobalBounds().contains(mousePosF))
				{
					doOnce = false;
					iceE->sceneNode.at(0).children.clear();
					//_game.StartGame(*iceE);
					iceE->currScene = 1;
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