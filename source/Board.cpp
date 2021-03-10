#include "Board.h"

const unsigned int Board::fileNumber = 8u;
const unsigned int Board::rankNumber = 8u;

Board::Board()
{
	//Allocate size of 64 squares.
	squares.reserve(64u);

	//Creating a sample square to change and store it in vector at every iteration of loops.
	Square sampleSquare;
	sf::Color squareColor;

	//Creating board and handling squares.
	for (size_t i = 0; i < rankNumber; i++)
	{
		//Determine leftmost (a file) color in every rank.
		if (i % 2 == 0)
		{
			squareColor = sf::Color::White;
		}
		else
		{
			squareColor = sf::Color(205, 133, 63, 255); // This rgba value represents a brownish color.
		}
		for (size_t j = 0; j < fileNumber; j++)
		{
			//Pass square attributes.
			sampleSquare.setPosition(sf::Vector2f(j * sampleSquare.getEdgeLength(), i * sampleSquare.getEdgeLength()));
			sampleSquare.setColor(squareColor);
			//Change square color in every file.
			if (squareColor == sf::Color::White)
			{
				squareColor = sf::Color(205, 133, 63, 255);
			}
			else
			{
				squareColor = sf::Color::White;
			}
			//Store in vector.
			squares.push_back(sampleSquare);
		}
	}
}

float Board::getBoardWidth()
{
	return fileNumber * Square::getEdgeLength(); // 8 times edge length is equals to width.
}

float Board::getBoardHeight()
{
	return rankNumber * Square::getEdgeLength(); // 8 times edge length is equals to height.
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//Drawing squares one by one.
	for (auto& i : squares)
	{
		target.draw(i.getRectangleShape());
	}
}
