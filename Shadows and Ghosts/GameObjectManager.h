#pragma once
#include <vector>
#include "GameObject.h"

class GameObjectManager
{
public:
	~GameObjectManager(void);
	static GameObjectManager* getInstance(void);

	void add(GameObject* newGameObject);
	void draw();
	void update(float fDeltaTime);

	std::vector<GameObject*> m_gameObjects;

private:
	static bool instanceFlag;
	static GameObjectManager *single;
	GameObjectManager(void);
};