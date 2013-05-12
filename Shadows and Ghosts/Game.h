#pragma once
#include "GameObjectManager.h"

class Game
{
public:
	Game(void);
	~Game(void);

	void update(float fDeltaTime);
	void draw();
};

