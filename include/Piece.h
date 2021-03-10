#pragma once

#include <iostream>
#include <filesystem>

#include "SFML.hpp"
#include "Notation.h"

enum PieceType
{
	WKing, WQueen, WBishop, WKnight, WRook, WPawn,
	BKing, BQueen, BBishop, BKnight, BRook, BPawn
};

class Piece : public sf::Drawable
{
public:
	//Constructor.

	//Do not use first constructor in code use more explicit ones.
	Piece();
	Piece(PieceType type);
	Piece(PieceType type, Notation notation);

	//Move function. Use this for move pieces.
	void moveTo(Notation notation);

	//Setters.
	void setPosition(sf::Vector2f position);
	void setPosition(float xPosition, float yPosition);
	void setPosition(Notation notation);

	//Getters.
	sf::Vector2f getPosition() const;
	Notation getNotation() const;
	PieceType getPieceType() const;
	static const std::filesystem::path getTexturePath();

private:
	//Overriding draw function from sf::Drawable class.
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	//Texture path.
	static const std::filesystem::path texturePath;
	//Texture size. All of them are 200px to 200px.
	static const sf::Vector2f pieceTextureSize;
	//Texture position based on piece type.
	sf::Vector2f pieceTexturePosition;
	//Rectangle shape to render piece texture.
	sf::RectangleShape piece;
	//Piece type.
	PieceType type;
	//Piece position in notation form.
	Notation notation;
};

