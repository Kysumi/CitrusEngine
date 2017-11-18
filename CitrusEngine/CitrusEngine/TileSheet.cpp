#include "TileSheet.h"
#include "ContentLoader.h"

TileSheet::TileSheet() {
	
}

TileSheet::TileSheet(pugi::xml_node node) {	

	SheetID = node.attribute("Id").value();
	std::cout << "TileSheet: " << SheetID << " Loaded" << std::endl;

	_imageSource = "./Maps/";
	_imageSource += node.child("ImageSource").first_child().value();
	_tileSize = Stripper::strip(node.child("Alignment").attribute("TileSize").value());
	_sheetSize = Stripper::strip(node.child("Alignment").attribute("SheetSize").value());
	_spacing = Stripper::strip(node.child("Alignment").attribute("Spacing").value());
	_margin = Stripper::strip(node.child("Alignment").attribute("Margin").value());

	ContentLoader::LoadTileSheet(this);
}

