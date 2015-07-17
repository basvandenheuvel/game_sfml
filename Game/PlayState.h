#pragma once
#include "Header_loader.h"
#include "IGameState.h"
#include "GameStateManager.h"
#include "MapLoader.h"

class PlayState :
	public IGameState
{
private:
	sf::RectangleShape bgRect;

public:
	PlayState();
	virtual ~PlayState();


	static PlayState m_PlayState;
	static PlayState* Instance() {
		return &m_PlayState;
	};

	void init(GameStateManager *gsm);

	void pause();
	void resume();
	void handleEvents(sf::Event event);
	void handleCallbacks();
	void update(double dt);
	void draw();
	void cleanup();
};

