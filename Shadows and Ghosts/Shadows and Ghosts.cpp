// Shadows and Ghosts.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

static int g_windowWidth = 800; 
static int g_windowHeight = 600;

void drawCube(){
	glBegin(GL_QUADS);
		glColor3f(1,0,0);
		glNormal3f(0, 0, -1);
		glVertex3f(-50.f, -50.f, -50.f);
		glVertex3f(-50.f,  50.f, -50.f);
		glVertex3f( 50.f,  50.f, -50.f);
		glVertex3f( 50.f, -50.f, -50.f);
		
		glColor3f(0,1,0);
		glNormal3f(0, 0, 1);
		glVertex3f(-50.f, -50.f, 50.f);
		glVertex3f(-50.f,  50.f, 50.f);
		glVertex3f( 50.f,  50.f, 50.f);
		glVertex3f( 50.f, -50.f, 50.f);
		
		glColor3f(0,0,1);
		glNormal3f(-1, 0, 0);
		glVertex3f(-50.f, -50.f, -50.f);
		glVertex3f(-50.f,  50.f, -50.f);
		glVertex3f(-50.f,  50.f,  50.f);
		glVertex3f(-50.f, -50.f,  50.f);
		
		glColor3f(1,0,1);
		glNormal3f(1, 0, 0);
		glVertex3f(50.f, -50.f, -50.f);
		glVertex3f(50.f,  50.f, -50.f);
		glVertex3f(50.f,  50.f,  50.f);
		glVertex3f(50.f, -50.f,  50.f);
		
		glColor3f(1,1,0);
		glNormal3f(0, -1, 0);
		glVertex3f(-50.f, -50.f,  50.f);
		glVertex3f(-50.f, -50.f, -50.f);
		glVertex3f( 50.f, -50.f, -50.f);
		glVertex3f( 50.f, -50.f,  50.f);
		
		glColor3f(0,1,1);
		glNormal3f(0, 1, 0);
		glVertex3f(-50.f, 50.f,  50.f);
		glVertex3f(-50.f, 50.f, -50.f);
		glVertex3f( 50.f, 50.f, -50.f);
		glVertex3f( 50.f, 50.f,  50.f);
	glEnd();
}

void positionAndRotate(float xPos, float yPos, float zPos, float xAngle, float yAngle, float zAngle){
	glPushMatrix();
	
	glTranslatef(xPos, yPos, zPos);
	glRotatef(xAngle, 1.0f, 0, 0);
	glRotatef(yAngle, 0, 1.0f, 0);
	glRotatef(zAngle, 0, 0, 1.0f);

	drawCube();

	glPopMatrix();
}

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
	gluPerspective(60.f, 1.33f, 0.01f, 500.f);

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
		
		positionAndRotate(0, 0, -200, elapsedTime * 10, elapsedTime * 25, elapsedTime * 20);
		
		window.display();
    }
    return 0;
}