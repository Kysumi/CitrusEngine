#include "Tile.h"

Tile::Tile()
{
}

Tile::Tile(pugi::xml_node tile,std::string tileSheet) {
	_tileSheetID = tileSheet;
	TileIndex = (int)tile.attribute("Index").value();

}

