#include "Notation.h"

Notation::Notation(File argFile, unsigned int argRank) :
	file(argFile), rank(argRank) {}

Notation::Notation()
{
	this->file = Notation::invalidNotationStart().getFile();
	this->rank = Notation::invalidNotationStart().getRank();
}

sf::Vector2f Notation::getNotationPosition() const
{
	return sf::Vector2f(file * Square::getEdgeLength(), Board::getBoardHeight() - (rank * Square::getEdgeLength()));
}

Notation Notation::getNotationOfGivenPoint(sf::Vector2f position)
{
	//If point is out of board, then return invalid notation. 
	if (position.x < 0.f || position.x > Board::getBoardWidth())
	{
		return Notation(OOB, 0); //Returning invalid Notation.
	}
	else if (position.y < 0.f || position.y > Board::getBoardHeight())
	{
		return Notation(OOB, 0); //Returning invalid notation.
	}
	else
	{
		//Calculate file.
		int positionX = (int)(position.x), positionY = (int)(position.y);
		File file = (File)((int)(positionX / Square::getEdgeLength()));
		
		//Calculate rank.
		//We will do same thing but at the end, we will subtract the calculated value from 9 to take complement.
		unsigned int rank = 8u - ((unsigned int)(positionY / Square::getEdgeLength()));

		return Notation(file,rank);
	}
}

File Notation::getFile() const
{
	return file;
}

unsigned int Notation::getRank() const
{
	return rank;
}

Notation Notation::getNotation() const
{
	return Notation(file,rank);
}

void Notation::setFile(File file)
{
	this->file = file;
}

void Notation::setRank(unsigned int rank)
{
	this->rank = rank;
}

bool Notation::isValid() const
{
	//Check rank if its valid.
	if ((file == OOB))
	{
		return false;
	}
	else if (rank < 1u || 8u < rank)
	{
		return false;
	}
	//Else
	return true;
}

Notation Notation::invalidNotationStart()
{
	return Notation(A,0);
}

bool operator==(const Notation& lhs, const Notation& rhs)
{
	if ((lhs.file == rhs.file) && (lhs.rank == rhs.rank))
		return true;
	return false;
}
