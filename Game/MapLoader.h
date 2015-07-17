#pragma once
#include "Header_loader.h"
#include <rapidjson/document.h>

class MapLoader
{
private:
	int mapHeight;
	int mapWidth;
public:
	MapLoader();
	virtual ~MapLoader();

	void loadMap(std::string map);
	void extractMapInfo(rapidjson::Document& d);
	//void createTileSets(rapidjson::Value& tilesets);
};

