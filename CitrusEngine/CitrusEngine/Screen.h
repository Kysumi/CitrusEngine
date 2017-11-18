#pragma once
#include "SFML\Graphics.hpp"

class Screen {
	
public:
	Screen();
	virtual int Run(sf::RenderWindow &window);

};