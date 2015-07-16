#pragma once
#include "Header_loader.h"
#include <string>

class SFMLInitializer
{
private:
	sf::RenderWindow* window;
	sf::Font defaultFont;

public:
	SFMLInitializer();
	virtual ~SFMLInitializer();

	void init(const char* title, int width, int height);
	void drawText(double x, double y, std::string text, sf::Color color);

	sf::RenderWindow* getWindow();

};

