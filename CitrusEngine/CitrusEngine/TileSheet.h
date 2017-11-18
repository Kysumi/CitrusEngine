#pragma once
#ifndef TILESHEET_H
#define TILESHEET_H

#include "pugixml.hpp"
#include "SFML\Graphics.hpp"
#include "strippper.h"
#include <iostream>

class TileSheet
{
public:
	TileSheet();
	TileSheet(pugi::xml_node node);

	std::string SheetID;
	void AddTexture(sf::Texture* t) {_sprites.push_back(t); };
	sf::Texture * GetTexture(int id) {return _sprites[id]; };
	std::string * GetImageSource() {return &_imageSource; };
	sf::Vector2f * GetTileSize() {return &_tileSize; };

private:
	std::string _imageSource;
	sf::Vector2f _tileSize;
	sf::Vector2f _sheetSize;
	sf::Vector2f _margin;
	sf::Vector2f _spacing;
	std::vector<sf::Texture*> _sprites;
};


#endif // !TILESHEET_H