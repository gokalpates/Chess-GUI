#pragma once

#include "SFML.hpp"
#include "Board.h"
#include "Square.h"

enum File
{
	//OOB stands for out of board.
	OOB = -1, A, B, C, D, E, F, G, H
};

class Notation
{
	//Overloading necessary functions.
	friend bool operator==(const Notation& lhs, const Notation& rhs);
public:
	Notation(File file,unsigned int rank);
	Notation();

	//Getters.
	File getFile() const;
	unsigned int getRank() const;
	Notation getNotation() const;

	//Returns a vector that represents that notation point.
	sf::Vector2f getNotationPosition() const;
	static Notation getNotationOfGivenPoint(sf::Vector2f position);

	//Setters.
	void setFile(File file);
	void setRank(unsigned int rank);

	bool isValid() const;
	static Notation invalidNotationStart();

private:
	File file;
	unsigned int rank;
};

