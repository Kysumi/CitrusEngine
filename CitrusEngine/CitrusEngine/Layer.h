#pragma once
#ifndef LAYER_H
#define LAYER_H

#include "pugixml.hpp"
#include <vector>
#include <SFML\Graphics.hpp>
#include "strippper.h"
#include <iostream>
#include "Tile.h"

class Layer
{

public:
	Layer(pugi::xml_node lNode);

	std::string LayerId;

private:
	bool _isVisible;
	std::string _description;
	sf::Vector2f _layerSize;
	sf::Vector2f _tileSize;
	
	std::vector<std::vector<Tile>> _tileMap;
};

#endif // !LAYER_H