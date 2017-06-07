#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Player.h"
#include "Box.h"

Application2D::Application2D()
{

}

Application2D::~Application2D()
{

}


bool Application2D::startup()
{
	m_2dRenderer = new aie::Renderer2D();
	input = aie::Input::getInstance();

	collisionManager = new CollisionManager(&gameObjArray);

	m_playerTexture = new aie::Texture("./textures/player.png");
	m_boxTexture = new aie::Texture("./textures/box.png");
	m_boxStartTexture = new aie::Texture("./textures/boxStart.png");

	cameraPos.x = 500.0f;
	cameraPos.y = 500.0f;

	Player* player = new Player(m_playerTexture, Vector2(500, 500));
	Box* box = new Box(m_boxTexture, Vector2(800, -300));
	Box* boxStart = new Box(m_boxStartTexture, Vector2(500, 0));

	gameObjArray.Push(player);
	gameObjArray.Push(boxStart);
	gameObjArray.Push(box);

	for (int i = 0; i < gameObjArray.getSize(); i++)
	{
		gameObjArray[i]->startup();
	}

	return true;
}

void Application2D::shutdown()
{
	

}

void Application2D::update(float deltaTime)
{


	if (deltaTime > 0.01f)
	{
		deltaTime = 0.01f;
	}

	collisionManager->UpdateCollisions();

	for (int i = 0; i < gameObjArray.getSize(); i++)
	{
		gameObjArray[i]->update(deltaTime);
	}

	//move camera after all objects have moved
	Vector2 vecBetween = gameObjArray[0]->getPosition() - cameraPos;
	
	if (vecBetween.magnitude() > 50.0f)
	{
		cameraPos += vecBetween * deltaTime * 5.0f;
	}

	collisionManager->UpdateCollisions();
}
	
void Application2D::draw()
{

	
	clearScreen();

	m_2dRenderer->setCameraPos(cameraPos.x - getWindowWidth() * 0.5, cameraPos.y - getWindowHeight() * 0.5 - 300);


	m_2dRenderer->begin();

	for (int i = 0; i < gameObjArray.getSize(); i++)
	{
		gameObjArray[i]->draw(m_2dRenderer);
	}
	

	m_2dRenderer->end();
}