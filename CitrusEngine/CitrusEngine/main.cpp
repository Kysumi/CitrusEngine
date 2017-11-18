#include <iostream>
#include "SFML\Graphics.hpp"
#include "Screens.h"
#include "MapLoader.h"

int main() {

	sf::RenderWindow window(sf::VideoMode(800, 600), "Citrus Engine");
	std::vector<Screen *> screens;

	MapLoader mapLoader("testMap.tide");
	
	MenuScreen *menuS = new MenuScreen;

	screens.push_back(menuS);

	int cScreen = 0;

	while (cScreen >= 0)
	{
		cScreen = screens[cScreen]->Run(window);
	}
	
	return 0;
}