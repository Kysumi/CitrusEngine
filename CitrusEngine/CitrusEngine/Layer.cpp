#include "Layer.h"

Layer::Layer(pugi::xml_node lNode) {	

	LayerId = lNode.attribute("Id").value();
	
	_isVisible = (bool)lNode.attribute("Visible").value();
	_tileSize = Stripper::strip(lNode.child("Dimensions").attribute("TileSize").value());
	_layerSize = Stripper::strip(lNode.child("Dimensions").attribute("LayerSize").value());

	_description =lNode.child("Description").value();


	std::cout << "Loading layer: " << LayerId << std::endl;

	//Resize tile map
	_tileMap.resize(_layerSize.x);
	for (size_t i = 0; i < _tileMap.size(); i++)
		_tileMap[i].resize(_layerSize.y);

	int y = 0;//y grid cords
	std::string curTileSheet;//Used for the tiles

	for (pugi::xml_node tile = lNode.child("TileArray").child("Row"); tile;
		tile = tile.next_sibling()) {

		int x = 0;

		for (pugi::xml_node xTile = tile.first_child(); xTile != NULL; 
			xTile = xTile.next_sibling()) {

			std::cout << xTile.name() << std::endl;

			if ((std::string)xTile.name() == "TileSheet")
				curTileSheet = xTile.first_attribute().value();
			else if ((std::string)xTile.name() == "Null")
			{
				//Handle the nullsss
				for (size_t i = 0; i < std::atoi(xTile.first_attribute().value()); i++)
					_tileMap[x++][y] = Tile();
			}
			else {

				Tile meme(xTile, curTileSheet);

				_tileMap[x++][y] = meme;
				
				if (xTile.next_sibling() == NULL)
					break;
			}
		}

		if (tile.next_sibling() == NULL)
			break;
		y++;
	}
}
