#include "HexGrid.hpp"

HexGrid::HexGrid(int height, int width, float radius, sf::Color color){

	defHeight = height;
	defWidth = width;
	defRadius = radius;
	defColor = color;
	hexNumber = width * height;
	yRow = 1;
    xKeyPos = 0;
    yKeyPos = 0;

}

void HexGrid::draw(sf::RenderWindow &App){

	hexagon.setRadius(defRadius);
	hexagon.setPointCount(6);
	hexagon.setFillColor(defColor);
    hexagon.setOutlineThickness(1);
    hexagon.setOutlineColor(sf::Color::Black);

	xPos = hexagon.getRadius();
	yPos = hexagon.getRadius();

	for(int i = 1; i <= hexNumber; ++i){
		

		hexagon.setPosition(xPos, yPos);
        hexBounds = hexagon.getLocalBounds();



		if( i % defWidth == 0 && i != 0 ){
			if (yRow % 2 == 0){
                xPos = hexagon.getRadius();
                yPos += hexagon.getRadius() * 1.55;
			}
			else{
                xPos = sqrt(3) * hexagon.getRadius() + ((hexagon.getRadius() / 10) + 1.3 );
                yPos += hexagon.getRadius() * 1.55;
			}

			++yRow;
		}

		else
            xPos += sqrt(3) * hexagon.getRadius() + 0.5;

        App.draw(hexagon);

	}

}
