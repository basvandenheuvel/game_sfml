#include "TGUIInitializer.h"


TGUIInitializer::TGUIInitializer()
{
}

void TGUIInitializer::init(sf::RenderWindow* window, sf::Font* font, std::string confPath)
{
	//Create tgui object
	this->gui = new tgui::Gui(*window);

	//Set font (same as SFML)
	this->gui->setGlobalFont(*font);

	//Set path to tgui conf
	this->confPath = confPath;
}

void TGUIInitializer::draw()
{
	this->gui->draw();
}

tgui::Button::Ptr TGUIInitializer::createButton(int width, int height, double x, double y, std::string text, tgui::ClickableWidget::ClickableWidgetCallbacks callback, int callbackId)
{
	tgui::Button::Ptr button(*this->gui);
	button->load(this->confPath);
	button->setSize(width, height);
	button->setPosition(x, y);
	button->setText(text);
	button->bindCallback(callback);
	button->setCallbackId(callbackId);

	return button;
}

tgui::Gui* TGUIInitializer::getTGUI()
{
	return this->gui;
}

TGUIInitializer::~TGUIInitializer()
{
	delete this->gui;
}
