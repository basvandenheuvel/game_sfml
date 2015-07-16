#include "SFMLInitializer.h"
#include <iostream>


SFMLInitializer::SFMLInitializer()
{
}

void SFMLInitializer::init(const char* title, int width, int height)
{
	//Create window
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Test", sf::Style::Close);

	//Set font
	this->defaultFont.loadFromFile("OpenSans-Regular.ttf");
}

void SFMLInitializer::drawText(double x, double y, std::string text, sf::Color color)
{
	sf::Text sfText;
	sfText.setFont(this->defaultFont);
	sfText.setString(text);
	sfText.setColor(color);
	sfText.setPosition(x, y);
	this->window->draw(sfText);
}




sf::RenderWindow* SFMLInitializer::getWindow()
{
	return this->window;
}


SFMLInitializer::~SFMLInitializer()
{
}
