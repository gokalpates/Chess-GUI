#pragma once

#include "PieceSetManager.h"
#include "SFML.hpp"

class Player : public sf::Drawable
{
public:
	//Player constructor with side.
	Player(Side side);

	//Play.
	void play(PieceSetManager& oppositePlayerPieceSet);
	PieceSetManager& getPlayerSet();

private:
	//Overriding draw function from sf::Drawable class.
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	//Utility functions that will be inside play function.
	//Making a valid move.
	void movePiece(Notation from, Notation to);
	//Square that player hover mouse over and clicked on it.
	Notation selectPiece() const;
	//Square that player left holding left mouse button. 
	Notation selectDropSquare() const;

	//Input functions.
	bool isMouseClicked() const;
	sf::Vector2f getMousePosition() const;

	//Piece set, If player construct this class with white, then it is white pieces. Otherwise, black.
	PieceSetManager pieceSet;

	Side playerSide;
};

