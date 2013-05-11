// Shadows and Ghosts.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameObject.h"

static int g_windowWidth = 800; 
static int g_windowHeight = 600;
static const int g_amountOfGameObjects = 35;

void updateProjection(bool toggle){
	static bool usePerspective = true;

	if(toggle){
		usePerspective = !usePerspective;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if(usePerspective){
		gluPerspective(60, (float)g_windowWidth / (float)g_windowHeight, 0.001, 1000.0);
	}
	else{
		glOrtho(-200, 200, 200, -200, 0.001, 20000);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void resizeScene(int width, int height){
	if(height==0){
		height=1;
	}
	glViewport(0, 0, width, height);

	updateProjection(true);
}

int _tmain(int argc, _TCHAR* argv[])
{
	sf::RenderWindow window(sf::VideoMode(800,600,32), "Shadows and Ghosts");
    sf::Clock deltaClock;
	float elapsedTime = 0;

	glClearDepth(1.f);
	glClearColor(0.f, 0.f, 0.f, 0.f);

	// Enable Z-buffer read and write
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_POLYGON_SMOOTH);
	glDepthMask(GL_TRUE);

	// Setup a perspective projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.f, 1.33f, 0.01f, 10000.f);

	// GameObjects for testing
	GameObject* gameObjects[g_amountOfGameObjects];
	for(int i = 0, col = 0, row = -1; i < g_amountOfGameObjects; i++){
		col++;
		if(i % 7 == 0) {row++;col = 0;}
		gameObjects[i] = new GameObject("no-texture-yet");
		gameObjects[i]->move(-600 + col * 200,-400 + row * 200,-1000);
	}

	bool running = true;
	while (running) {	
		sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                running = false;
			}
			if(event.type == sf::Event::Resized){
				g_windowWidth = event.size.width;
				g_windowHeight = event.size.height;
				resizeScene(g_windowWidth, g_windowHeight);
			}
        }

		sf::Time dt = deltaClock.restart();
		float fDeltaTime = dt.asSeconds();
		elapsedTime += fDeltaTime;

		window.setActive(true);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		for(int i = 0; i < g_amountOfGameObjects; i++){
			gameObjects[i]->rotate(fDeltaTime * 40, fDeltaTime * 40, fDeltaTime * 40);
			gameObjects[i]->draw();
		}
		
		window.display();
    }
    return 0;
}