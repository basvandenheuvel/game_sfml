#include "PlayState.h"
#include <iostream>

PlayState PlayState::m_PlayState;

PlayState::PlayState()
{
}

void PlayState::init(GameStateManager* gsm)
{
	this->gsm = gsm;

	//Set background sprite;
	this->bgRect.setFillColor(sf::Color::Color(255, 255, 235, 255));
	this->bgRect.setSize(sf::Vector2f(SCREENWIDTH, SCREENHEIGHT));
}

void PlayState::handleEvents(sf::Event event)
{
	switch (event.type)
	{
	/*case sf::Event::KeyPressed:
		switch (event.key.code)
		{
		case sf::Keyboard::Space:
			break;
		}
		break;*/
	}
}

void PlayState::handleCallbacks()
{

}

void PlayState::draw()
{
	this->gsm->getSFMLI()->drawRectangle(this->bgRect);
}

void PlayState::update(double dt)
{
}

void PlayState::pause()
{
}

void PlayState::resume()
{
}

void PlayState::cleanup()
{
}

PlayState::~PlayState()
{
}
