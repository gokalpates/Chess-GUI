#include "Piece.h"

extern sf::Texture* pieceTexture;

const std::filesystem::path Piece::texturePath = "texture\\1200x400-pieces.png";
const sf::Vector2f Piece::pieceTextureSize(200.f, 200.f);

Piece::Piece() {};

Piece::Piece(PieceType type) :
	type(type)
{
	//Determine texture position.
	pieceTexturePosition.x = (type % 6) * pieceTextureSize.x;
	if (type > PieceType::WPawn)
	{
		pieceTexturePosition.y = 200.f;
	}
	else
	{
		pieceTexturePosition.y = 0.f;
	}

	//Set piece rectangle shape.
	piece.setSize(sf::Vector2f(100.f, 100.f)); // Note that, it is same value with square edgeLength. They have same size.
	piece.setTexture(pieceTexture);
	piece.setTextureRect(sf::IntRect((sf::Vector2i)pieceTexturePosition, (sf::Vector2i)pieceTextureSize));

	//Set piece position to invalid position start because of position is undefined.
	this->notation = Notation::invalidNotationStart();
	this->setPosition(this->notation);
}

Piece::Piece(PieceType type, Notation notation) :
	type(type)
{
	//Determine texture position.
	pieceTexturePosition.x = (type % 6) * pieceTextureSize.x;
	if (type > PieceType::WPawn)
	{
		pieceTexturePosition.y = 200.f;
	}
	else
	{
		pieceTexturePosition.y = 0.f;
	}

	//Set piece rectangle shape.
	piece.setSize(sf::Vector2f(100.f, 100.f)); // Note that, it is same value with square edgeLength. They have same size.
	piece.setTexture(pieceTexture);
	piece.setTextureRect(sf::IntRect((sf::Vector2i)pieceTexturePosition, (sf::Vector2i)pieceTextureSize));

	//Set piece position.
	//If it is not valid.
	if (!notation.isValid())
	{
		this->notation = Notation::invalidNotationStart();
		this->setPosition(this->notation);
	}
	else
	{
		this->notation = notation;
		this->setPosition(notation);
	}
}

void Piece::moveTo(Notation notation)
{
	if (!notation.isValid())
		return;
	this->notation = notation;
	piece.setPosition(this->notation.getNotationPosition());
}

void Piece::setPosition(sf::Vector2f position)
{
	piece.setPosition(position);
}

void Piece::setPosition(float xPosition, float yPosition)
{
	piece.setPosition(xPosition,yPosition);
}

void Piece::setPosition(Notation notation)
{
	piece.setPosition(notation.getNotationPosition());
}

sf::Vector2f Piece::getPosition() const
{
	return piece.getPosition();
}

Notation Piece::getNotation() const
{
	return notation;
}

PieceType Piece::getPieceType() const
{
	return type;
}

const std::filesystem::path Piece::getTexturePath()
{
	return texturePath;
}

void Piece::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.texture = pieceTexture;
	target.draw(piece);
}
