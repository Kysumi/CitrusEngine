#pragma once
#ifndef MENUSCREEN_H
#define MENUSCREEN_H
#include "Screen.h"

class MenuScreen : public Screen
{

public:
	MenuScreen();
	int Run(sf::RenderWindow &window);

private:
	bool running = true;

	void UserInput(sf::RenderWindow &window);
	void Update();
};


#endif // !MENUSCREEN_H
