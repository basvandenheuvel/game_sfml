#pragma once
#include "Header_loader.h"

class MapLoader
{
private:
public:
	MapLoader();
	virtual ~MapLoader();

	bool loadMap(std::string map);
};

