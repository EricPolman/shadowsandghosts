#include "StdAfx.h"
#include "GameObjectManager.h"


GameObjectManager::GameObjectManager(void)
{
}


GameObjectManager::~GameObjectManager(void)
{
	instanceFlag = false;
	for(std::vector<GameObject*>::iterator i = m_gameObjects.begin(); i != m_gameObjects.end(); ++i)
	{
		m_gameObjects.erase(i);
	}
}

bool GameObjectManager::instanceFlag = false;
GameObjectManager* GameObjectManager::single = NULL;
GameObjectManager* GameObjectManager::getInstance()
{
    if(! instanceFlag)
    {
        single = new GameObjectManager();
        instanceFlag = true;
        return single;
    }
    else
    {
        return single;
    }
}

void GameObjectManager::update(float fDeltaTime)
{
	for(std::vector<GameObject*>::iterator i = m_gameObjects.begin(); i != m_gameObjects.end(); ++i){
		(*i)->rotate(fDeltaTime * 40, fDeltaTime * 40, fDeltaTime * 40);
	}
}

void GameObjectManager::draw()
{
	for(std::vector<GameObject*>::iterator i = m_gameObjects.begin(); i != m_gameObjects.end(); ++i){
		(*i)->draw();
	}	
}

void GameObjectManager::add(GameObject* newGameObject)
{
	m_gameObjects.push_back(newGameObject);
}