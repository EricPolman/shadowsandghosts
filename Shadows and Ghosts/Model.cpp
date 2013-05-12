#include "StdAfx.h"
#include "Model.h"


Model::Model(void)
{
}


Model::~Model(void)
{
}


void Model::draw()
{
	glPushMatrix();

	glBegin(GL_QUADS);
		glColor3f(1,0,0);
		glNormal3f(0, 0, -1);
		glVertex3f(-50.f, -50.f, -50.f);
		glVertex3f(-50.f,  50.f, -50.f);
		glVertex3f( 50.f,  50.f, -50.f);
		glVertex3f( 50.f, -50.f, -50.f);
		
		glColor3f(0,1,0);
		glNormal3f(0, 0, 1);
		glVertex3f( 50.f, -50.f, 50.f);
		glVertex3f( 50.f,  50.f, 50.f);
		glVertex3f(-50.f,  50.f, 50.f);
		glVertex3f(-50.f, -50.f, 50.f);
		
		glColor3f(0,0,1);
		glNormal3f(-1, 0, 0);
		glVertex3f(-50.f, -50.f,  50.f);
		glVertex3f(-50.f,  50.f,  50.f);
		glVertex3f(-50.f,  50.f, -50.f);
		glVertex3f(-50.f, -50.f, -50.f);
		
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
		
		//
		glColor3f(0,1,1);
		glNormal3f(0, 1, 0);
		glVertex3f( 50.f, 50.f,  50.f);
		glVertex3f( 50.f, 50.f, -50.f);
		glVertex3f(-50.f, 50.f, -50.f);
		glVertex3f(-50.f, 50.f,  50.f);
	glEnd();

	glPopMatrix();
}