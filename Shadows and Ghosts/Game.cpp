#include "StdAfx.h"
#include "Game.h"

static const int g_amountOfGameObjects = 35;
GameObject* gameObjects[g_amountOfGameObjects];

Game::Game(void)
{
	for(int i = 0, col = 0, row = -1; i < g_amountOfGameObjects; i++){
		col++;
		if(i % 7 == 0) {row++;col = 0;}
		GameObject* go = new GameObject("no-texture-yet");
		GameObjectManager::getInstance()->add(go);
		go->move(-600 + col * 200,-400 + row * 200,-1000);
	}
}


Game::~Game(void)
{

}

void Game::update(float fDeltaTime)
{
	GameObjectManager::getInstance()->update(fDeltaTime);
}

void Game::draw()
{
	GameObjectManager::getInstance()->draw();
}