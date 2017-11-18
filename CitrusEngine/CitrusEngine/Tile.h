#pragma once
#ifndef TILE_H
#define TILE_H

#include "pugixml.hpp"
#include <iostream>

class Tile
{
public:
	Tile();
	Tile(pugi::xml_node tile,std::string tileSheet);
	int TileIndex;

private:
	std::string _property;
	std::string _key;
	std::string _tileSheetID;
};

#endif // !TILE_H