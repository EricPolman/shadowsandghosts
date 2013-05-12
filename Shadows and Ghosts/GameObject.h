#pragma once
#include "ImageManager.h"
#include "Model.h"

class GameObject
{
public:
	GameObject(string);
	~GameObject(void);

	void update(float);
	void draw();

	string m_sName;

	string m_textureString;
	sf::Image* m_texture;

	sf::Vector3f m_position;
	sf::Vector3f m_rotation;
	sf::Vector3f m_scale;
	
	void move(float x, float y, float z);
	void scale(float x, float y, float z);
	void rotate(float pitch, float yaw, float roll);

	Model m_model;
};

