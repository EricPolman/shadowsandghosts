#include "StdAfx.h"
#include "InputManager.h"


InputManager::InputManager(void)
{
}


InputManager::~InputManager(void)
{
	instanceFlag = false;
}

bool InputManager::instanceFlag = false;
InputManager* InputManager::single = NULL;
InputManager* InputManager::getInstance()
{
    if(! instanceFlag)
    {
        single = new InputManager();
        instanceFlag = true;
        return single;
    }
    else
    {
        return single;
    }
}

void InputManager::update(float fDeltaTime)
{
	for(int k = 0; k < sf::Keyboard::KeyCount; k++){
		m_oldKeyboardState[k] = sf::Keyboard::isKeyPressed((sf::Keyboard::Key)k);
	}
	for(int m = 0; m < sf::Mouse::ButtonCount; m++){
		m_oldMouseState[m] = sf::Keyboard::isKeyPressed((sf::Keyboard::Key)m);
	}
}

bool InputManager::isKeyDown(sf::Keyboard::Key key)
{
	if(sf::Keyboard::isKeyPressed(key))
		return true;

	return false;
}

bool InputManager::isKeyPressed(sf::Keyboard::Key key)
{
	if(sf::Keyboard::isKeyPressed(key) && !m_oldKeyboardState[key])
		return true;

	return false;
}

bool InputManager::isKeyReleased(sf::Keyboard::Key key)
{
	if(!sf::Keyboard::isKeyPressed(key) && m_oldKeyboardState[key])
		return true;

	return false;
}
	
bool InputManager::isButtonDown(sf::Mouse::Button button)
{
	if(sf::Mouse::isButtonPressed(button))
		return true;

	return false;
}

bool InputManager::isButtonPressed(sf::Mouse::Button button)
{
	if(sf::Mouse::isButtonPressed(button) && !m_oldMouseState[button])
		return true;

	return false;
}

bool InputManager::isButtonReleased(sf::Mouse::Button button)
{
	if(!sf::Mouse::isButtonPressed(button) && m_oldMouseState[button])
		return true;

	return false;
}

sf::Vector2i getMousePosition(){
	return sf::Mouse::getPosition();
}

sf::Vector2i getRelativeMousePosition(sf::RenderWindow& window){
	return sf::Mouse::getPosition(window);
}