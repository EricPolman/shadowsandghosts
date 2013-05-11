#include "StdAfx.h"
#include "ImageManager.h"


ImageManager::ImageManager(void)
{
}


ImageManager::~ImageManager(void)
{
	instanceFlag = false;
	for(std::map<std::string, sf::Image*>::iterator i = m_images.begin(); i != m_images.end(); ++i)
	{
		m_images.erase(i);
	}
}

bool ImageManager::instanceFlag = false;
ImageManager* ImageManager::single = NULL;
ImageManager* ImageManager::getInstance()
{
    if(! instanceFlag)
    {
        single = new ImageManager();
        instanceFlag = true;
        return single;
    }
    else
    {
        return single;
    }
}