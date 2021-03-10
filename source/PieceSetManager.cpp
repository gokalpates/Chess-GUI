#include "PieceSetManager.h"

PieceSetManager::PieceSetManager(Side argSide):
	side(argSide)
{
	//If it is white, then these pieces as white. 
	if (argSide == White)
	{
		initialiseWhitePieces();
	}
	else //Otherwise, black.
	{
		initialiseBlackPieces();
	}
}

Piece& PieceSetManager::getPieceAtGivenNotation(Notation notation)
{
	for (auto& i : pieceSet)
		if (i.getNotation() == notation)
			return i;
}

bool PieceSetManager::isThereAnyPieceAtGivenNotation(Notation notation) const
{
	for (auto& i : pieceSet)
		if (i.getNotation() == notation)
			return true;
	return false;
}

void PieceSetManager::deletePieceAtGivenNotation(Notation notation)
{
	for (size_t i = 0; i < pieceSet.size(); i++)
	{
		if (this->pieceSet.at(i).getNotation() == notation)
			this->pieceSet.erase(this->pieceSet.begin() + i);
	}
}

void PieceSetManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto& i : pieceSet)
	{
		target.draw(i);
	}
}

void PieceSetManager::initialiseWhitePieces()
{
	pieceSet.emplace_back(Piece(WRook, Notation(A, 1)));
	pieceSet.emplace_back(Piece(WKnight, Notation(B, 1)));
	pieceSet.emplace_back(Piece(WBishop, Notation(C, 1)));
	pieceSet.emplace_back(Piece(WQueen, Notation(D, 1)));
	pieceSet.emplace_back(Piece(WKing, Notation(E, 1)));
	pieceSet.emplace_back(Piece(WBishop, Notation(F, 1)));
	pieceSet.emplace_back(Piece(WKnight, Notation(G, 1)));
	pieceSet.emplace_back(Piece(WRook, Notation(H, 1)));
	pieceSet.emplace_back(Piece(WPawn,Notation(A, 2)));
	pieceSet.emplace_back(Piece(WPawn, Notation(B, 2)));
	pieceSet.emplace_back(Piece(WPawn, Notation(C, 2)));
	pieceSet.emplace_back(Piece(WPawn, Notation(D, 2)));
	pieceSet.emplace_back(Piece(WPawn, Notation(E, 2)));
	pieceSet.emplace_back(Piece(WPawn, Notation(F, 2)));
	pieceSet.emplace_back(Piece(WPawn, Notation(G, 2)));
	pieceSet.emplace_back(Piece(WPawn, Notation(H, 2)));
}

void PieceSetManager::initialiseBlackPieces()
{
	pieceSet.emplace_back(Piece(BRook, Notation(A, 8)));
	pieceSet.emplace_back(Piece(BKnight, Notation(B, 8)));
	pieceSet.emplace_back(Piece(BBishop, Notation(C, 8)));
	pieceSet.emplace_back(Piece(BQueen, Notation(D, 8)));
	pieceSet.emplace_back(Piece(BKing, Notation(E, 8)));
	pieceSet.emplace_back(Piece(BBishop, Notation(F, 8)));
	pieceSet.emplace_back(Piece(BKnight, Notation(G, 8)));
	pieceSet.emplace_back(Piece(BRook, Notation(H, 8)));
	pieceSet.emplace_back(Piece(BPawn, Notation(A, 7)));
	pieceSet.emplace_back(Piece(BPawn, Notation(B, 7)));
	pieceSet.emplace_back(Piece(BPawn, Notation(C, 7)));
	pieceSet.emplace_back(Piece(BPawn, Notation(D, 7)));
	pieceSet.emplace_back(Piece(BPawn, Notation(E, 7)));
	pieceSet.emplace_back(Piece(BPawn, Notation(F, 7)));
	pieceSet.emplace_back(Piece(BPawn, Notation(G, 7)));
	pieceSet.emplace_back(Piece(BPawn, Notation(H, 7)));
}
