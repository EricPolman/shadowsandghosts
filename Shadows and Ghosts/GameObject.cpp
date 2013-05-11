#include "StdAfx.h"
#include "GameObject.h"


GameObject::GameObject(string texture)
{
	m_rotation = m_position = sf::Vector3f(0,0,0);
	m_scale = sf::Vector3f(1,1,1);

	m_textureString = texture;
	m_texture = ImageManager::getInstance()->m_images[texture];
}


GameObject::~GameObject(void)
{
}

void GameObject::update(float fDeltaTime)
{
	
}

void GameObject::draw()
{
	glPushMatrix();
	glTranslatef(m_position.x, m_position.y, m_position.z);
	glRotatef(m_rotation.x, 1.0, 0, 0);
	glRotatef(m_rotation.y, 0.0, 1.0, 0);
	glRotatef(m_rotation.z, 0.0, 0, 1.0);
	glScalef(m_scale.x, m_scale.y, m_scale.z);

	m_model.draw();
	
	glPopMatrix();
}

void GameObject::move(float x, float y, float z)
{
	m_position += sf::Vector3f(x,y,z);
}

void GameObject::scale(float x, float y, float z)
{
	m_scale = sf::Vector3f(x * m_scale.x ,y * m_scale.y ,z * m_scale.z);
}

void GameObject::rotate(float x, float y, float z)
{
	m_rotation += sf::Vector3f(x,y,z);
}