#include "GameStateManager.h"
#include "IGameState.h"
#include "MenuState.h"
#include <iostream>


GameStateManager::GameStateManager()
{
}

void GameStateManager::init(const char* title, int width, int height, bool fullscreen)
{
	this->sfmlInitializer = new SFMLInitializer();
	this->sfmlInitializer->init(title, width, height);
	
	//Set menustate
	this->changeGameState(MenuState::Instance());

	this->running = true;
	this->showFps = false;
}

//Default loop methods
void GameStateManager::handleEvents()
{
	sf::Event event;
	while (this->sfmlInitializer->getWindow()->pollEvent(event))
	{

		switch (event.type)
		{
		case sf::Event::Closed:
			this->running = false;
			break;
		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
			case sf::Keyboard::Tab:
				this->showFps = !this->showFps;
				break;
			default:
				this->states.back()->handleEvents(event);
				break;
			}
			break;
		case sf::Event::MouseButtonPressed:
			switch (event.key.code)
			{
			case sf::Mouse::Left:
				break;
			case sf::Mouse::Right:
				break;
			default:
				this->states.back()->handleEvents(event);
				break;
			}
			break;
		/*case sf::Event::MouseWheelMoved:
			std::cout << event.mouseWheel.delta << std::endl;
			break;*/
		default:
			this->states.back()->handleEvents(event);
			break;
		}
	}
}

void GameStateManager::update(double delta)
{
	this->states.back()->update(delta);
}

void GameStateManager::draw()
{
	//Clear screen
	this->sfmlInitializer->getWindow()->clear();
	
	//Draw current state
	this->states.back()->draw();


	//Draw fps if requested
	if (this->showFps)
	{
		this->sfmlInitializer->drawText(5, 5, std::string("FPS: " + std::to_string(this->fps)), sf::Color::White, 16);
	}

	//Draw screen
	this->sfmlInitializer->getWindow()->display();
}


//Handle states
void GameStateManager::changeGameState(IGameState* gameState)
{
	while (!this->states.empty()) {
		this->states.back()->cleanup();
		this->states.pop_back();
	}

	this->states.push_back(gameState);
	this->states.back()->init(this);
}

void GameStateManager::pushGameState(IGameState* gameState) 
{
	if (!this->states.empty()) {
		this->states.back()->pause();
	}

	this->states.push_back(gameState);
	this->states.back()->init(this);
}

void GameStateManager::popGameState() 
{
	if (!this->states.empty()) {
		this->states.back()->cleanup();
		this->states.pop_back();
	}

	if (!this->states.empty()) {
		this->states.back()->resume();
	}
}

//Helpers
void GameStateManager::quitGame()
{
	this->running = false;
}

bool GameStateManager::getRunning()
{
	return this->running;
}

SFMLInitializer* GameStateManager:: getSFMLI()
{
	return this->sfmlInitializer;
}


void GameStateManager::setFps(int fps)
{
	this->fps = fps;
}

int GameStateManager::getFps()
{
	return this->fps;
}


GameStateManager::~GameStateManager()
{
	//While there are states on the stack, clean them up
	while (!this->states.empty()) {
		//Peek at top state and clean that state
		this->states.back()->cleanup();

		//Remove top state
		this->states.pop_back();
	}

	delete this->sfmlInitializer;
}
