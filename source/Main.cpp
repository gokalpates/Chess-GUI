#include <iostream>
#include <thread>

#include "SFML.hpp"
#include "Board.h"
#include "Piece.h"
#include "Notation.h"
#include "PieceSetManager.h"
#include "Player.h"

//Prefer discrete GPU if it is available.
#define SFML_DEFINE_DISCRETE_GPU_PREFERENCE

//Texture for all pieces.
//The better way to do that is implementing a resource manager class, but it is unnecessary and cumbersome for this project.
//Or another way to create this texture for once is defining it as global variable like I did, but i know it is not a good programming practice.
sf::Texture* pieceTexture;

void debugExit()
{
	while (true)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			std::exit(1);
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
}

int main()
{
	sf::VideoMode mode = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(mode, "Chess",sf::Style::Fullscreen);
	sf::Event event;

	window.setPosition(sf::Vector2i(0, 0));

	window.setVerticalSyncEnabled(true);

	//Allocating texture.
	pieceTexture = new(sf::Texture);
	pieceTexture->loadFromFile(Piece::getTexturePath().string());

	Board testBoard;
	Player whitePlayer(White);
	Player blackPlayer(Black);

	std::thread threadOne(debugExit);
	unsigned int debugCounter = 0;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}
			}
		}
		//First display board and then update.

		window.clear(sf::Color(24,24,24));
		
		window.draw(testBoard);
		window.draw(whitePlayer);
		window.draw(blackPlayer);

		window.display();

		//Update here.
		if (debugCounter%2==0)
		{
			whitePlayer.play(blackPlayer.getPlayerSet());
		}
		else
		{
			blackPlayer.play(whitePlayer.getPlayerSet());
		}

		debugCounter++;
	}

	delete pieceTexture;
}