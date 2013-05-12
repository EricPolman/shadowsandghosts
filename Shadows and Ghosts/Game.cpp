#include "StdAfx.h"
#include "Game.h"
#include "InputManager.h"

static const int g_amountOfGameObjects = 1;
GameObject* gameObjects[g_amountOfGameObjects];

Game::Game(void)
{
	for(int i = 0; i < g_amountOfGameObjects; i++){
		GameObject* go = new GameObject("no-texture-yet");
		GameObjectManager::getInstance()->add(go);
		go->move(0,0,-200);
	}
}


Game::~Game(void)
{

}

void Game::update(float fDeltaTime)
{
	GameObjectManager::getInstance()->update(fDeltaTime);

	InputManager::getInstance()->update(fDeltaTime);
}

void Game::draw()
{
	GameObjectManager::getInstance()->draw();
}