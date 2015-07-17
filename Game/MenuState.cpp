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

	//Create gui layer
	this->gui = new TGUIInitializer();
	this->gui->init(this->gsm->getSFMLI()->getWindow(), this->gsm->getSFMLI()->getDefaultFont(), TGUICONFBLACK);

	//Set background sprite;
	this->bgRect.setFillColor(sf::Color::Color(128, 128, 128, 255));
	this->bgRect.setSize(sf::Vector2f(SCREENWIDTH, SCREENHEIGHT));

	//Create start button
	startButton = this->gui->createButton(100, 25, SCREENWIDTH / 2 - 50, 100, "Start game", tgui::Button::LeftMouseClicked, 11);

}

void MenuState::handleEvents(sf::Event event)
{
	switch (event.type)
	{
	case sf::Event::KeyPressed:
		switch (event.key.code)
		{
		/*case sf::Keyboard::S:
			break;*/
		}
		break;
	}
}

void MenuState::handleCallbacks()
{
	tgui::Callback callback;
	while (this->gui->getTGUI()->pollCallback(callback))
	{
		switch (callback.id)
		{
		case 11:
			this->gsm->pushGameState(PlayState::Instance());
			break;
		}
	}
}

void MenuState::draw()
{
	this->gsm->getSFMLI()->drawRectangle(this->bgRect);

	//Draw gui layer
	this->gui->draw();
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
