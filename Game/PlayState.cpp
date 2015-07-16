#include "PlayState.h"
#include <iostream>


PlayState PlayState::m_PlayState;

PlayState::PlayState()
{
}

void PlayState::init(GameStateManager* gsm)
{
}

void PlayState::handleEvents()
{
	/*switch (mainEvent.type)
	{
	case SDL_KEYDOWN:
		switch (mainEvent.key.keysym.sym)
		{
		default:
			break;
		}
		break;
	default:
		break;
	}*/
}

void PlayState::draw()
{
	//Draw background
	//this->gsm->getSDLI()->drawTexture(textBackground, &rectBackground, NULL);
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
