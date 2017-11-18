#include "MapLoader.h"

MapLoader::MapLoader(std::string mapName) {

	std::string location = "Maps/" + mapName;

	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(location.c_str());

	if (result) {
		map = doc.child("Map");

		mapLoading.mapName = map.first_attribute().value();
		std::cout << "Loading Map : " << mapLoading.mapName << std::endl;

		//Mojo
		loadTileSheets();		
		loadLayers();
	}
	else {
		std::cout << "ERROR Failed to load map" << std::endl;
	}
}

void MapLoader::loadTileSheets() {

	for (pugi::xml_node tSheet = map.child("TileSheets").first_child(); tSheet; 
		tSheet = tSheet.next_sibling("TileSheet")) {

		TileSheet test(tSheet);
		mapLoading.tileSheets[test.SheetID] = test;

		if (tSheet.next_sibling() == NULL)
			break;
	}
}

void MapLoader::loadLayers() {

	//For each layer..
	for (pugi::xml_node tile = map.child("Layers").child("Layer"); tile;
		tile = tile.next_sibling()) {

		Layer nLayer(tile);
	}
}