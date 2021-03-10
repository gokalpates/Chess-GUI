#include "Player.h"

Player::Player(Side side):
	playerSide(side),
	pieceSet(side)
{
}

void Player::play(PieceSetManager& oppositePlayerPieceSet)
{
	//Creating two notation for a selected piece and square to move that piece.
	Notation selectedPiece, selectedDropSquare;

	//To prevent to move a piece to its same square we need to check if two notation is same.
	bool illegalMove = true;
	while (illegalMove == true)
	{
		//To prevent to select empty square, we need to check it if selected square has a piece.
		bool isSelectedValid = false;
		while (isSelectedValid == false)
		{
			selectedPiece = selectPiece();
			//Checking if square has a piece.
			if (pieceSet.isThereAnyPieceAtGivenNotation(selectedPiece) == true)
				isSelectedValid = true;
		}
		selectedDropSquare = selectDropSquare();
		//Checking if two notation is same.
		if (selectedPiece != selectedDropSquare)
			illegalMove = false;

		if (pieceSet.isThereAnyPieceAtGivenNotation(selectedDropSquare))
			illegalMove = true;
	}
		//If there is an opposite piece on drop square then take it and erase it from opponent's set.
		if (oppositePlayerPieceSet.isThereAnyPieceAtGivenNotation(selectedDropSquare))
		{
			oppositePlayerPieceSet.deletePieceAtGivenNotation(selectedDropSquare);
		}
	
	movePiece(selectedPiece, selectedDropSquare);
}

PieceSetManager& Player::getPlayerSet()
{
	return pieceSet;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(pieceSet);
}

void Player::movePiece(Notation from, Notation to)
{
	pieceSet.getPieceAtGivenNotation(from).moveTo(to);
}

Notation Player::selectPiece() const
{
	Notation mouseHoverNotation, selectedSquare;
	bool selected = false;
	while (selected == false)
	{
		mouseHoverNotation = Notation::getNotationOfGivenPoint(this->getMousePosition());
		if (isMouseClicked())
		{
			selectedSquare = mouseHoverNotation;
			selected = true;
		}
	}

	return selectedSquare;
}

Notation Player::selectDropSquare() const
{
	Notation mouseHoverNotation, releasedSquare;
	bool released = false;
	while (released == false)
	{
		mouseHoverNotation = Notation::getNotationOfGivenPoint(this->getMousePosition());
		if (!isMouseClicked())
		{
			releasedSquare = mouseHoverNotation;
			released = true;
		}
	}

	return releasedSquare;
}

bool Player::isMouseClicked() const
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		return true;
	return false;
}

sf::Vector2f Player::getMousePosition() const
{
	return (sf::Vector2f)sf::Mouse::getPosition();
}
