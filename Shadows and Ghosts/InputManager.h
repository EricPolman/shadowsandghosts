#pragma once
#include <map>

class InputManager
{
public:
	~InputManager(void);
	static InputManager* getInstance(void);

	void update(float fDeltaTime);
	bool isKeyDown(sf::Keyboard::Key);
	bool isKeyPressed(sf::Keyboard::Key);
	bool isKeyReleased(sf::Keyboard::Key);
	
	bool isButtonDown(sf::Mouse::Button);
	bool isButtonPressed(sf::Mouse::Button);
	bool isButtonReleased(sf::Mouse::Button);
	
	sf::Vector2i getMousePosition();
	sf::Vector2i getRelativePosition(sf::RenderWindow& window);
private:
	static bool instanceFlag;
	static InputManager *single;
	InputManager(void);

	bool m_oldKeyboardState[sf::Keyboard::KeyCount];
	bool m_oldMouseState[sf::Mouse::ButtonCount];
};

