#include "MenuState.h"
#include "PlayState.h"
#include <iostream>


MenuState MenuState::m_MenuState;

MenuState::MenuState()
{	
}

void MenuState::init(GameStateManager* gsm)
{
	this->gsm = gsm;

	//Set background sprite;
	this->bgRect.setFillColor(sf::Color::Color(128, 128, 128, 255));
	this->bgRect.setSize(sf::Vector2f(SCREENWIDTH, SCREENHEIGHT));

}

void MenuState::handleEvents(sf::Event event)
{
	switch (event.type)
	{
	case sf::Event::KeyPressed:
		switch (event.key.code)
		{
		case sf::Keyboard::S:
			this->gsm->pushGameState(PlayState::Instance());
			break;
		}
		break;
	}
}

void MenuState::draw()
{
	this->gsm->getSFMLI()->drawRectangle(this->bgRect);
}

void MenuState::update(double dt)
{
}

void MenuState::pause()
{
}

void MenuState::resume()
{
}

void MenuState::cleanup()
{
}


MenuState::~MenuState()
{
}
