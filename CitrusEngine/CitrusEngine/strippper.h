#pragma once
#ifndef STRIPPER_H
#define STRIPPER_H

#include "SFML\Graphics.hpp"

class Stripper
{
public:
	static sf::Vector2f strip(std::string string) {

		std::string num1 = string.substr(0, string.find_first_of('X'));
		std::string num2 = string.substr(string.find_first_of('X') + 1);

		int x = std::atoi(num1.c_str());
		int y = std::atoi(num2.c_str());

		return sf::Vector2f((float)x, (float)y);
	}

private:

};

#endif // !STRIPPER_H