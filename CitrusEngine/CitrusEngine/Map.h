#pragma once
#ifndef MAP_H
#define MAP_H

#include "pugixml.hpp"
#include "SFML\Graphics.hpp"
#include "TileSheet.h"
#include <vector>

class Map
{
public:
	Map();

	std::map<std::string, TileSheet> tileSheets;
	std::string mapName;

private:
	

};

#endif // !TILESHEET_H
