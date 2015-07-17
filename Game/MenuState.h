#pragma once
#include "Header_loader.h"
#include "IGameState.h"
#include "TGUIInitializer.h"
#include "GameStateManager.h"

class MenuState :
	public IGameState
{
private:
	sf::RectangleShape bgRect;

	tgui::Button::Ptr startButton;
	
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
	void handleCallbacks();
	void update(double dt);
	void draw();
	void cleanup();
};

