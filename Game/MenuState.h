#pragma once
#include "Header_loader.h"
#include "IGameState.h"
#include "GameStateManager.h"

class MenuState :
	public IGameState
{
private:
	sf::RectangleShape bgRect;

public:
	MenuState();
	virtual ~MenuState();

	static MenuState m_MenuState;
	static MenuState* Instance() {
		return &m_MenuState;
	};

	void init(GameStateManager *gsm);
	
	void pause();
	void resume();
	void handleEvents(sf::Event event);
	void update(double dt);
	void draw();
	void cleanup();
};

