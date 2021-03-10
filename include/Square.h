#pragma once

#include "SFML.hpp"

class Square
{
public:
	//Constructor
	Square();

	//Getters.
	sf::RectangleShape getRectangleShape() const;
	sf::Vector2f getPosition() const;
	sf::Color getSquareColor() const;
	static const float getEdgeLength();

	//Setters.
	void setPosition(sf::Vector2f position);
	void setColor(sf::Color color);

private:
	// Rectangle shape that describe square.
	sf::RectangleShape square;
	// Where will this square render to.
	sf::Vector2f position;
	// Square color. Black or White;
	sf::Color squareColor;
	
	// Length of the square edge.
	static const float edgeLength;
};

