#include "MenuScreen.h"

MenuScreen::MenuScreen() {
	running = true;
}

int MenuScreen::Run(sf::RenderWindow &window) {

	while (running)
	{
		window.clear(sf::Color::Yellow);

		window.display();
		UserInput(window);
	}
	return -1;//Exit completly
}

void MenuScreen::Update() {

}

void MenuScreen::UserInput(sf::RenderWindow &window) {

	sf::Event event;

	while (window.pollEvent(event)){

		switch (event.type)
		{
			case sf::Event::Closed:
				window.close();
				running = false;
				break;
		}
	}
}