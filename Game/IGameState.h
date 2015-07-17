#pragma once
#include "Header_loader.h"
#include "GameStateManager.h"
#include "TGUIInitializer.h"

class IGameState
{
protected:
	IGameState() { }
	GameStateManager* gsm;
	TGUIInitializer* gui;
public:
	virtual void init(GameStateManager *gsm) = 0;
	virtual void cleanup() = 0;

	virtual void pause() = 0;
	virtual void resume() = 0;

	virtual void handleEvents(sf::Event event) = 0;
	virtual void handleCallbacks() = 0;
	virtual void update(double dt) = 0;
	virtual void draw() = 0;

	void tguiHandleEvent(sf::Event event) 
	{
		if (this->gui != nullptr) 
		{
			this->gui->getTGUI()->handleEvent(event);
		}
	}

	void ChangeState(GameStateManager* gsm, IGameState* state) 
	{
		gsm->changeGameState(state);
	}

	virtual ~IGameState();
};

