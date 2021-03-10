#pragma once

#include <iostream>
#include <vector>

#include "SFML.hpp"
#include "Piece.h"

enum Side
{
	White, Black
};

class PieceSetManager : public sf::Drawable
{
public:
	PieceSetManager(Side side);

	//Getters.
	Piece& getPieceAtGivenNotation(Notation notation);
	//Helpful functions.
	bool isThereAnyPieceAtGivenNotation(Notation notation) const;
	void deletePieceAtGivenNotation(Notation notation);

private:
	//Overriding draw function from sf::Drawable class.
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	//Hardcoded utility function to start positions.
	void initialiseWhitePieces();
	void initialiseBlackPieces();

	//Color of set.
	Side side;

	//Pieces container.
	std::vector<Piece> pieceSet;
};

