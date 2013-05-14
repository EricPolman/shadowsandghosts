#include "stdafx.h"
#include <iostream>
#include "Game.h"
#include <btBulletDynamicsCommon.h>

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

void checkBullet()
{
	btBroadphaseInterface* broadphase = new btDbvtBroadphase();
 
	btDefaultCollisionConfiguration* collisionConfiguration = new btDefaultCollisionConfiguration();
    btCollisionDispatcher* dispatcher = new btCollisionDispatcher(collisionConfiguration);
 
    btSequentialImpulseConstraintSolver* solver = new btSequentialImpulseConstraintSolver;
 
    btDiscreteDynamicsWorld* dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher,broadphase,solver,collisionConfiguration);
 
    dynamicsWorld->setGravity(btVector3(0,-10,0));
 
 
    btCollisionShape* groundShape = new btStaticPlaneShape(btVector3(0,1,0),1);
 
    btCollisionShape* fallShape = new btSphereShape(1);
 
 
    btDefaultMotionState* groundMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,-1,0)));
    btRigidBody::btRigidBodyConstructionInfo
                groundRigidBodyCI(0,groundMotionState,groundShape,btVector3(0,0,0));
    btRigidBody* groundRigidBody = new btRigidBody(groundRigidBodyCI);
    dynamicsWorld->addRigidBody(groundRigidBody);
 
 
    btDefaultMotionState* fallMotionState =
                new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,50,0)));
    btScalar mass = 1;
    btVector3 fallInertia(0,0,0);
    fallShape->calculateLocalInertia(mass,fallInertia);
    btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(mass,fallMotionState,fallShape,fallInertia);
    btRigidBody* fallRigidBody = new btRigidBody(fallRigidBodyCI);
    dynamicsWorld->addRigidBody(fallRigidBody);
 
 
    for (int i=0 ; i<300 ; i++) {
		dynamicsWorld->stepSimulation(1/60.f,10);
 
        btTransform trans;
        fallRigidBody->getMotionState()->getWorldTransform(trans);
 
        std::cout << "sphere height: " << trans.getOrigin().getY() << std::endl;
	}
 
    dynamicsWorld->removeRigidBody(fallRigidBody);
    delete fallRigidBody->getMotionState();
    delete fallRigidBody;
 
    dynamicsWorld->removeRigidBody(groundRigidBody);
    delete groundRigidBody->getMotionState();
    delete groundRigidBody;
 
 
    delete fallShape;
 
    delete groundShape;
 
 
    delete dynamicsWorld;
    delete solver;
    delete collisionConfiguration;
    delete dispatcher;
    delete broadphase;
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
	checkBullet();

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