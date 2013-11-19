#ifndef HEXGRID_HPP_
#define HEXGRID_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

class HexGrid {
public:

	HexGrid(int height, int width, float radius, sf::Color color);
	void draw(sf::RenderWindow &App);

private:

	sf::CircleShape hexagon;
    sf::Color defColor;
    sf::FloatRect hexBounds;
    sf::Event event;
	int defHeight;
    int defWidth;
	int hexNumber;
	int yRow;
	float defRadius;
	float xPos;
	float yPos;

};

#endif
