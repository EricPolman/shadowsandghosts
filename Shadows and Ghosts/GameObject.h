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
	
	void move(float, float, float);
	void scale(float, float, float);
	void rotate(float, float, float);

	Model m_model;
};

