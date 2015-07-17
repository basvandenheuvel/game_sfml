#include "MapLoader.h"
#include <fstream>


MapLoader::MapLoader()
{
}

void MapLoader::loadMap(std::string mapString)
{
	//Create file stream
	std::ifstream stream(mapString);
	if (!stream.is_open())
	{
		std::cout << "Could not load map. File " + mapString + " could not be found!" << std::endl;
		return;
	}

	std::string total;
	std::string line;
	while (getline(stream, line))
	{
		//Add current line to total
		total += line;
	}

	//Close file stream
	stream.close();

	//Parse total string into DOM.
	rapidjson::Document d;
	d.Parse(total.c_str());

	//Extract map info
	this->extractMapInfo(d);
}

void MapLoader::extractMapInfo(rapidjson::Document& d)
{
	//Get general map information
	int mapTileHeight = d["height"].GetInt();
	int mapTileWidth = d["width"].GetInt();
	int tileHeight = d["tileheight"].GetInt();
	int tileWidth = d["tilewidth"].GetInt();

	//Calculate map width and height
	this->mapHeight = mapTileHeight * tileHeight;
	this->mapWidth = mapTileWidth * tileWidth;

	//Get and load tilesets
	rapidjson::Value& tilesets = d["tilesets"];
	//this->createTileSets(tilesets);
}

//void MapLoader::createTileSets(rapidjson::Value& tilesets)
//{
//
//}


MapLoader::~MapLoader()
{
}
