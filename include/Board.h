#pragma once

#include <vector>

#include "SFML.hpp"
#include "Square.h"

class Board : public sf::Drawable
{
public:
	//Constructor.
	Board();

	//Getters.
	//They will return same value because board is square.
	static float getBoardWidth();
	static float getBoardHeight();

private:
	//Overriding draw function from sf::Drawable class.
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	//Container for 64 squares.
	std::vector<Square> squares;

	//Rank and file numbers. As you can know, it is 8.
	//But sake of clarity, storing them in static const variables. 
	static const unsigned int rankNumber, fileNumber;
};

