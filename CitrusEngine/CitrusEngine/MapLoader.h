#pragma once
#ifndef MAPLOAD_H
#define MAPLOAD_H

#include "pugixml.hpp"
#include <iostream>
#include <vector>
#include "TileSheet.h" //move to hpp
#include "Map.h" //move to hpp
#include "Layer.h" //move to hpp

class MapLoader
{
public:
	MapLoader(std::string mapName);

private:

	void loadTileSheets();
	void loadLayers();

	pugi::xml_node map;

	Map mapLoading;
};

#endif // MAPLOAD_H