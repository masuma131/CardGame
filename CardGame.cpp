//CardGame.cpp - function for the player crad game

#include "CardGame.h"

CardGameAdapter* cardGame() {
	char ldMode;
	std::cout << "Would you like to play in low definition mode? [Y/N] ";
	std::cin >> ldMode;

	CardGameAdapter* cardGame;//MW: Note that CardGameAdapter is not templated but CardGame is
	if (ldMode == 'Y' || ldMode == 'y') {
		cardGame = new CardGame<int>();
		cardGame->setMode(1);//MW: You might need to set a mode flag when you come to run the game.
		//    It is best to use an enumeration for this, not a magic number as I have here
	}
	else {
		std::cout << "You will be playing in high definition mode." << std::endl;
		cardGame = new CardGame<double>();
		cardGame->setMode(2);//MW: You might need to set a mode flag when you come to run the game.
		//    It is best to use an enumeration for this, not a magic number as I have here
	}
	return cardGame;
}