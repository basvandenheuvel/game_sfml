#pragma once
#include "Header_loader.h"
#include <string>

class TGUIInitializer
{
private:
	tgui::Gui* gui;
	std::string confPath;
public:
	TGUIInitializer();
	virtual ~TGUIInitializer();

	void init(sf::RenderWindow* window, sf::Font* font, std::string confPath);
	void draw();

	tgui::Button::Ptr createButton(int width, int height, double x, double y, std::string text, tgui::ClickableWidget::ClickableWidgetCallbacks callback, int callbackId);

	tgui::Gui* getTGUI();
};

