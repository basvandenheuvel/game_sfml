#include "SFMLInitializer.h"
#include <iostream>


SFMLInitializer::SFMLInitializer()
{
}

void SFMLInitializer::init(const char* title, int width, int height)
{
	//Create window
	this->window = new sf::RenderWindow(sf::VideoMode(width, height), title, sf::Style::Close);
	
	//Set font
	this->defaultFont.loadFromFile("Resources/fonts/OpenSans-Regular.ttf");
}

void SFMLInitializer::drawText(double x, double y, std::string text, sf::Color color, int size)
{
	sf::Text sfText;
	sfText.setFont(this->defaultFont);
	sfText.setString(text);
	sfText.setColor(color);
	sfText.setPosition(x, y);
	//SIZE IS IN PIXELS
	sfText.setCharacterSize(size);
	this->window->draw(sfText);
}

void SFMLInitializer::drawSprite(sf::Sprite sprite)
{
	this->window->draw(sprite);
}

void SFMLInitializer::drawRectangle(sf::RectangleShape rect)
{
	this->window->draw(rect);
}


sf::RenderWindow* SFMLInitializer::getWindow()
{
	return this->window;
}

sf::Font* SFMLInitializer::getDefaultFont()
{
	return &this->defaultFont;
}


SFMLInitializer::~SFMLInitializer()
{
	delete this->window;
}
