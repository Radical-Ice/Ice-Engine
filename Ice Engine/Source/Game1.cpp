
#include "Game1.h"
#include <string>
const static TCHAR szWindowClass[] = _T("IceEngine");
void Game1::StartGame() {
	

	AudioFiles = { "Assets/GunShot.wav","Assets/PewPew.wav" };
	MusicFile = { "Assets/EngineBG.ogg" };
	AllocConsole();
	freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);

	IceEngine iceEngine;

	iceEngine.InitGraphics();

	iceEngine.DoChecks(szWindowClass);
	iceEngine.LoadSound(AudioFiles);
	iceEngine.LoadMusic(MusicFile, 0, 100, false);
	//iceEngine.RegisterWindow(hInstance, szWindowClass, nCmdShow, szTitle);
	
	GameObject background = new GameObject(&iceEngine.sceneNode);

	SpriteComponent backgroundSprite(&iceEngine.mainWindow, "Assets/background.png", background.m_Transform);

	background.m_Transform->m_Position = { 0,0 };
	background.m_Transform->m_Scale = { 2,2 };
	background.m_Transform->m_Rotation = { 0 };
	background.components.push_back(&backgroundSprite);
	
	GameObject background2 = new GameObject(&iceEngine.sceneNode);

	SpriteComponent backgroundSprite2(&iceEngine.mainWindow, "Assets/background.png", background2.m_Transform);
	background2.m_Transform->m_Position = { 961*2,0 };
	background2.m_Transform->m_Scale = { 2,2 };
	background2.m_Transform->m_Rotation = { 0 };
	background2.components.push_back(&backgroundSprite2);
	//sf::Font font;
	//std::string score = "Score";
	//sf::Text text;
	
	//text.setString(score);
	//text.setPosition(100, 100);


	//for (int i = 0; i < 10; i++) {
		GameObject dog(&iceEngine.sceneNode);
		SpriteComponent scDog(&iceEngine.mainWindow, "Assets/1.png", dog.m_Transform);

		dog.m_Transform->m_Position = { 1024,0 };
		dog.m_Transform->m_Scale = { .3f,.3f };

		dog.m_Transform->m_Rotation = { 0 };
		dog.components.push_back(&scDog);

		PhysicsComponent pcDog(&scDog, &iceEngine.physEngine);
		pcDog.tag = 2;
		pcDog.mass = 0.0f;
		pcDog.gravityAffected = false;
		dog.components.push_back(&pcDog);

	//}


	GameObject Platform2(&iceEngine.sceneNode);
	SpriteComponent scPlatform2(&iceEngine.mainWindow, "Assets/1.png", Platform2.m_Transform);

	Platform2.m_Transform->m_Position = { 1024,500 };
	Platform2.m_Transform->m_Scale = { .3f,.3f };

	Platform2.m_Transform->m_Rotation = { 0 };
	Platform2.components.push_back(&scPlatform2);

	PhysicsComponent pcPlatform2(&scPlatform2, &iceEngine.physEngine);
	pcPlatform2.tag = 2;
	pcPlatform2.mass = 0.0f;
	pcPlatform2.gravityAffected = false;
	Platform2.components.push_back(&pcPlatform2);

	 sf::Font font;
	if (!font.loadFromFile("Assets/ARIALI.TTF")) {
		std::cout << "did not load font";
	}
	score = 0;
	std::string scoreTxt = "Score  ";
	scoreTxt.append(std::to_string(score));
	sf::Text text(scoreTxt, font);
	text.setPosition(iceEngine.mainWindow.getView().getSize().x / 2, 50);
	iceEngine.texts.push_back(&text);

	GameObject Platform(&iceEngine.sceneNode);
	SpriteComponent scPlatform(&iceEngine.mainWindow, "Assets/cat.png", Platform.m_Transform);

	Platform.m_Transform->m_Position = { 312,550 };
	Platform.m_Transform->m_Scale = { 1.0f,.3f };

	Platform.m_Transform->m_Rotation = { 0 };
	Platform.components.push_back(&scPlatform);

	PhysicsComponent pcPlatform(&scPlatform, &iceEngine.physEngine);
	pcPlatform.mass = 0.0f;
	pcPlatform.gravityAffected = false;
	Platform.components.push_back(&pcPlatform);
	static sf::Text GameOver("You Died", font);
	GameOver.setFillColor(sf::Color::Black);
	GameOver.setCharacterSize(100);
	GameOver.setPosition(iceEngine.mainWindow.getView().getSize().x / 2-200, iceEngine.mainWindow.getView().getSize().y / 2-100);
	class backgroundEvents : public KeyEventHandler {
	public:
		sf::Text* text;
		SpriteComponent* objref;	
		SpriteComponent* objref2;
		SpriteComponent* objref3;
		SpriteComponent* objref4;
		IceEngine* iceRef;
		int*score;
		bool* gameOver;
		int vanishCounter=1;
		bool drawOnce = false;
		backgroundEvents::backgroundEvents(SpriteComponent* obj, SpriteComponent* obj2, SpriteComponent* obj3, SpriteComponent* obj4, IceEngine* iceEngine,int* scr,sf::Text* txt,bool* gOver) {
			objref = obj;
			objref2 = obj2;
			objref3 = obj3;
			objref4 = obj4;
			iceRef = iceEngine;
			score = scr;
			text = txt;
			gameOver = gOver;



		}
		void HandleEvents(const Event &e) {
			switch (e.Type) {

			case Update:
				if (*gameOver) {
					if (!drawOnce) {
						iceRef->texts.push_back(&GameOver);
						drawOnce = true;
					}
					break;
				}
				if (vanishCounter % 4 == 0) {
					vanishCounter++;

				}
				if (objref->sprite.getPosition().x < -961 * 2) {
					objref->sprite.setPosition(961 * 2, 0);
				}
				objref->sprite.move(-4, 0);
				if (objref2->sprite.getPosition().x < -961 * 2) {
					objref2->sprite.setPosition(961 * 2, 0);
				}
				objref2->sprite.move(-4, 0);
				objref3->sprite.move(-8, 0);
				objref4->sprite.move(-8, 0);
				if (objref3->sprite.getPosition().x + objref3->sprite.getGlobalBounds().width < 0) {
					int temp = rand() % iceRef->mainWindow.getSize().y/2;
					std::cout << temp;
					objref3->sprite.setPosition(iceRef->mainWindow.getSize().x, temp);
					objref4->sprite.setPosition(iceRef->mainWindow.getSize().x, temp+iceRef->mainWindow.getSize().y/2);
					*score = *score + 1;
					std::cout << *score;
					std::string scoreTxt = "Score  ";
					scoreTxt.append(std::to_string(*score));
					text->setString(scoreTxt);
				}
				break;
			case Collided:
				if (e.obj1 == 1 && e.obj2 == 0) {
					vanishCounter++;
					break;
				}
			}
		}
	}backgroundScript(&backgroundSprite, &backgroundSprite2, &scPlatform2, &scDog, &iceEngine,&score,&text,&gameOver);
	//GameObject testObj(&iceEngine.sceneNode);

	

	//std::cout << "~~[ Initializing SpriteComponents ]~~" << std::endl;
	
	//MainEvents test;

	/*
	GameObject aestObj4(&iceEngine.sceneNode);
	SpriteComponent asc4(&iceEngine.mainWindow, "Assets/cat.png", aestObj4.m_Transform);

	aestObj4.m_Transform->m_Position = { 100,50 };
	aestObj4.m_Transform->m_Scale = { .3f,.3f };
	aestObj4.m_Transform->m_Rotation = { 0 };
	aestObj4.components.push_back(&asc4);

	PhysicsComponent pc4(&asc4, &iceEngine.physEngine);
	aestObj4.components.push_back(&pc4);
	pc4.gravityAffected = false;
	*/

	
	
	

	
	

	GameObject testObj = new GameObject(&iceEngine.sceneNode);
	SpriteComponent sc(&iceEngine.mainWindow, "Assets/cat.png", testObj.m_Transform);

	testObj.m_Transform->m_Position = { 512,50 };
	testObj.m_Transform->m_Scale = { .3f,.3f };
	testObj.m_Transform->m_Rotation = { 0 };
	testObj.components.push_back(&sc);

	PhysicsComponent pc(&sc, &iceEngine.physEngine);
	pc.tag = 1;//player
	testObj.components.push_back(&pc);
	
	pc.mass = 1;
	//pc.gravityAffected = false;
	class MainEvents : public KeyEventHandler {
	public:
		SpriteComponent* objref;
		PhysicsComponent* pcref;
		IceEngine* iceRef;
		Vector2 force = { 0,-100 };
		Vector2 forceX = { 10,0 };
		bool left = false;
		bool right = false;
		bool* gameOver;
		MainEvents::MainEvents(SpriteComponent* obj, PhysicsComponent* pc, IceEngine* iceEngine, bool* gOver) {
			objref = obj;
			pcref = pc;
			iceRef = iceEngine;
			gameOver = gOver;
		}
		void HandleEvents(const Event &e) {
			switch (e.Type) {
			case MoveUp:
				cout << "up" << endl;

				pcref->AddForce(force);
				break;
			case MoveDown:
				cout << "down" << endl;
				iceRef->Play_Sound(1, 100, false);
				break;
			case MoveLeft:
				cout << "left" << endl;
				left = true;
				//objref->sprite.move(-5, 0);
				break;
			case MoveRight:
				cout << "right" << endl;
				right = true;
				//objref->sprite.move(5, 0);
				break;
			case LeftReleased:
				
				left = false;
				break;
			case RightReleased:
				right = false;
				break;
			case Collided:
				if (e.obj1 == 1 && e.obj2 == 2) {
					std::cout << "hit a dog";
				}
			case Update:
				//	cout << "mains update" << endl;
				if (left) {
					pcref->AddForce(forceX*-1);
					//objref->sprite.move(-3, 0);
					//Vector2 movement;
					//movement.x = -1;
					//pcref->AddForce( movement);
				}
				if (right) {
					//objref->sprite.move(3, 0);
					pcref->AddForce(forceX*1);
				}
				if (objref->sprite.getPosition().y > 1000|| objref->sprite.getPosition().y <-200|| objref->sprite.getPosition().x > 1024 || objref->sprite.getPosition().x < -200) {
					*gameOver = true;
				}
				if (*gameOver) {
					objref->sprite.setScale(0,0);
				}
				break;
			default:

				break;
			}
		}
	}test(&sc, &pc, &iceEngine,&gameOver);
	
	
/*
	GameObject testObj2(&testObj);
	SpriteComponent sc2(&iceEngine.mainWindow, "Assets/SplashScreen.jpg", testObj2.m_Transform, &sc);
	testObj2.m_Transform->m_Position = { 50,50 };
	testObj2.m_Transform->m_Rotation = { 0 };
	testObj2.components.push_back(&sc2);

	GameObject testObj3(&testObj2);
	SpriteComponent sc3(&iceEngine.mainWindow, "Assets/SplashScreen.jpg", testObj3.m_Transform, &sc2);
	testObj3.m_Transform->m_Position = { 50,50 };
	testObj3.m_Transform->m_Rotation = { 0 };
	testObj3.components.push_back(&sc3);
	*/
/*
	GameObject Platform3(&iceEngine.sceneNode);
	SpriteComponent scPlatform3(&iceEngine.mainWindow, "Assets/cat.png", Platform3.m_Transform);

	Platform3.m_Transform->m_Position = { 400,550 };
	Platform3.m_Transform->m_Scale = { .3f,.3f };
	//scPlatform3.sprite.setScale(.3, .3);
	Platform3.m_Transform->m_Rotation = { 0 };
	Platform3.components.push_back(&scPlatform3);

	PhysicsComponent pcPlatform3(&scPlatform3, &iceEngine.physEngine);
	pcPlatform3.mass = 0.0f;
	pcPlatform3.gravityAffected = false;
	Platform3.components.push_back(&pcPlatform3);
	*/
	std::cout << "~~[ SpriteComponents Loading Complete! ]~~" << std::endl;
	iceEngine.PlayMusic();
	iceEngine.InitEngine();

}