#include "stdafx.h"
#include "Game.h"

static int g_windowWidth = 800; 
static int g_windowHeight = 600;

sf::RenderWindow* window;
Game* game;

sf::Clock deltaClock;
float fElapsedTime = 0;
float fDeltaTime = 0;
sf::Time deltaTime;

void initializeWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(800,600,32), "Shadows and Ghosts");

	glClearDepth(1.f);
	glClearColor(0.f, 0.f, 0.f, 0.f);

	// Enable Z-buffer read and write
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_POLYGON_SMOOTH);
	glEnable(GL_CULL_FACE);
	glDepthMask(GL_TRUE);

	// Setup a perspective projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.f, 1.33f, 0.01f, 10000.f);
}

void updateProjection()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(60, (float)g_windowWidth / (float)g_windowHeight, 0.001, 10000.0);
	//glOrtho(-200, 200, 200, -200, 0.001, 20000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void resizeScene(int width, int height)
{
	if(height==0){
		height=1;
	}
	glViewport(0, 0, width, height);

	updateProjection();
}

int _tmain(int argc, _TCHAR* argv[])
{
	initializeWindow();

	game = new Game();
	bool running = true;

	while (running) {	
		sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                running = false;
			}
			if(event.type == sf::Event::Resized){
				g_windowWidth = event.size.width;
				g_windowHeight = event.size.height;
				resizeScene(g_windowWidth, g_windowHeight);
			}
        }

		deltaTime = deltaClock.restart();
		fDeltaTime = deltaTime.asSeconds();
		fElapsedTime += fDeltaTime;

		window->setActive(true);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		game->update(fDeltaTime);
		game->draw();
		
		window->display();
    }

	delete game;
	delete window;
	return 0;
}