#pragma once
#include <map>

class ImageManager
{
public:
	~ImageManager(void);
	static ImageManager* getInstance(void);
	void LoadTextures(void);
	std::map<std::string, sf::Image*> m_images;

private:
	static bool instanceFlag;
	static ImageManager *single;
	ImageManager(void);
};

