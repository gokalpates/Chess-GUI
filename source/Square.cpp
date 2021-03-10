#include "Square.h"

const float Square::edgeLength = 100.f;

Square::Square() :
	position(0.f,0.f),
	squareColor(sf::Color::Red) // Passing red value for visual debugging.
{
	square.setPosition(position.x, position.y);
	square.setSize(sf::Vector2f(edgeLength, edgeLength));
	square.setFillColor(squareColor);
}

sf::RectangleShape Square::getRectangleShape() const
{
	return square; // Return copy of rectangle shape.
}

sf::Vector2f Square::getPosition() const
{
	return position;
}

sf::Color Square::getSquareColor() const
{
	return squareColor;
}

const float Square::getEdgeLength()
{
	return edgeLength;
}

void Square::setPosition(sf::Vector2f position)
{
	this->position = position;
	square.setPosition(position);
}

void Square::setColor(sf::Color color)
{
	this->squareColor = color;
	square.setFillColor(color);
}
