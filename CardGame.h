
//CardGame.h - class for the card game


#ifndef _CARDGAME_H_
#define _CARDGAME_H_
#include <iostream >
#include "CardGameAdapter.h"
#include "PlayerYouth.h"
#include "PlayerAdult.h"

const int NUM = 2;

template<class T>
class CardGame :public CardGameAdapter {
	const int MAX = 21;
	int gameMode=0;//MW: 1 for low definition, 2 for high definition, this might not be needed.
	//    If you use gameMode, it is best defined as an enumeration rather than an int
	PlayerBase<T>* player[NUM];

public:
	void setMode(int mode) {//MW: Again, an enumeration is preferred
		gameMode = mode;
	}

	CardGame() {
		player[0] = new PlayerYouth<T>("Noah");
		player[1] = new PlayerAdult<T>("Kenneth");
	}

	~CardGame() {
		for (PlayerBase<T>* p : player) {
			delete p;
			p = nullptr;
		}
	}

	void run() {
		
		bool gameOver = false;
		do {
			double betAmount = 0;
			// Prompt the players for the amount they want to bet. It has to be between $10 and $300
			std::cout << "How much do you both want to bet? (min$10, max $300): $";
			std::cin >> betAmount;
			// If they enter a value below $10, set the amount to $10
			if (betAmount < 10.00) {
				betAmount = 10.00;
			}
			// If they enter a value above $300, set the amount to $300
			else if (betAmount > 300.00) {
				betAmount = 300.00;
			}
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			for (int i = 0; i < NUM; i++) {
			std::cout << std::endl;
			std::string name = player[i]->GetName();

			// Prompt the player for the number of dependent cards
			int numDependentCards;
			std::cout << name << ", how many dependent cards to you want? ";
			std::cin >> numDependentCards;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			player[i]->GetDependentCards(numDependentCards); //draw and add dependentcards

			// Prompt the player for the number of attack cards
			int numAttackCards = 0;
			std::cout << name << ", how many attack cards do you want? ";
			std::cin >> numAttackCards;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			//TO DO: The youth player has a list of attack cards which can be integral (regular mode)
			//or decimal (high definition mode). The youth player's attack cards have a value between 1 and 10 inclusive. 
			//The youth player's high definition attack cards will have values to three decimal places.
			//Use random to complete this.

			player[i]->GetAttackCards(numAttackCards); //draw attack cards and add it to the list of attack cards

			//TODO: Report the player's name and the sum of the player's cards

			std::cout << name << ", the sum of your cards is " << player[i]->SumCards() << std::endl;

			// Ask the player if (s)he wishes to add a dependent card to the existing list of dependent cards
			std::string choice;
			std::cout << "Do you want to add a dependent card? [Y,N] ";
			std::cin >> choice;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			bool retVal = false;
			do {
				if (choice == "Y" || choice == "y") {
					player[i]->GetADependentCard(); //draw a dependent card and add it to the list of dependent cards
					retVal = true;
				}
				else if (choice == "N" || choice == "n") {
					retVal = true;
				}
				else {
					std::cout << "Please enter 'y' for yes and 'n' for no.\nDo you want to add a dependent card? [Y,N] ";
					std::cin >> choice;
				}
			} while (retVal == false);

			// Report the player's name and the sum of the player's cards

			std::cout << name << ", the sum of your cards is " << player[i]->SumCards() << std::endl;

			// Ask the player if (s)he wishes to add an attack card to the existing list of attack cards
			std::string choice2;
			std::cout << "Do you want to add an attack card? [Y,N] ";
			std::cin >> choice2;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			retVal = false;
			do {
				if (choice2 == "Y" || choice2 == "y") {
					player[i]->GetAAttackCard(); //draw an attack card and add it to the list of attack cards
					retVal = true;
				}

				else if (choice2 == "N" || choice2 == "n") {//not done!
					retVal = true;
				}

				else {
					std::cout << "Please enter 'y' for yes and 'n' for no.\nDo you want to add an attack card? [Y,N] ";
					std::cin >> choice2;
				}
			} while (retVal == false);

			// Report the player's name and the sum of the player's cards

			std::cout << name << ", the sum of your cards is " << player[i]->SumCards() << std::endl;
		}
		
		//TODO: Report the name and points for each player
		std::cout << std::endl;
		for (int i = 0; i < NUM; i++) {
			std::string name = player[i]->GetName();
			std::cout << name << " has " << player[i]->SumCards() << " points." << std::endl;
		}

		std::cout << std::endl;

		bool player1_disqualified = false;
		bool player2_disqualified = false;

		//TODO: Determine a winner

		//*comparing if theu have less than 21 points
		// 
		// If a player has a sum over the limit of 21, the player is disqualified. Print the player's name, 
		// the sum of the player's cards, and a message that states this is over the limit. // Apply this test to both players
		// If just player 1 is disqualified, print player 1's name and a message that (s)he has been disqualified
		// for going over the limit. Print player 2's name and indicate that (s)he has won.

		if (player[0]->SumCards() > MAX) {
			std::cout << player[0]->GetName() << " has a sum of " << player[0]->SumCards() << ", which is over the limit." << std::endl;
			player1_disqualified = true;
		}

		if (player[1]->SumCards() > MAX) {
			std::cout << player[1]->GetName() << " has a sum of " << player[1]->SumCards() << ", which is over the limit." << std::endl;
			player2_disqualified = true;
		}

		if (player1_disqualified == true && player2_disqualified == true) {
			std::cout << "Both players are over the limit and have been disqualified." << std::endl;
		}

		if (player1_disqualified == true && player2_disqualified == false) {
			std::cout << player[0]->GetName() << " has been disqualified for going over the limit. " << std::endl;
			std::cout << player[1]->GetName() << " has won!" << std::endl;

			// Move the amount that was bet away from player 1 and towards player 2 using the << and >> operators.

			*player[0] >> betAmount;
			*player[1] << betAmount;
		}

		// If just player 2 is disqualified, print player 2's name and a message that (s)he has been disqualified
		// for going over the limit. Print player 1's name and indicate that (s)he has won.

		else if (player1_disqualified == false && player2_disqualified == true) {
			std::cout << player[1]->GetName() << " has been disqualified for going over the limit. " << std::endl;
			std::cout << player[0]->GetName() << " has won!" << std::endl;

			// Move the amount that was bet away from player 2 and towards player 1 using the << and >> operators.
			*player[1] >> betAmount;
			*player[0] << betAmount;
		}

		//*comparing if their points less than 21 and if which one is smaller or bigger to dertmine a winner
	// If player 1 and player 2 are tied, print that both players drew the same number of points and that
	// there is no winner. In doing this comparison, use the == operator.
		else if (*player[0] == *player[1]) {
			std::cout << "Both players drew the same number of points and there is no winner" << std::endl;
		}

		// If player 1 has more points than player 2, then print the name of player 1 and that (s)he has won.
		// Move the amount that was bet away from player 2 and towards player 1 using the << and >> operators.
		// In doing this comparison, use the > operator
		else if ((*player[0] > *player[1]) && !player1_disqualified) {
			std::cout << player[0]->GetName() << " has won!" << std::endl;
			//Move the amount that was bet away from player 2 and towards player 1 using the << and >> operators.
			*player[1] >> betAmount;
			*player[0] << betAmount;
		}

		// If player 2 has more points than player 1, then print the name of player 2 and that (s)he has won.
		// Move the amount that was bet away from player 1 and towards player 2 using the << and >> operators.
		// In doing this comparison, use the < operator

		else if ((*player[0] < *player[1]) && !player2_disqualified) {
			std::cout << player[1]->GetName() << " has won!" << std::endl;
			//Move the amount that was bet away from player 2 and towards player 1 using the << and >> operators
			*player[0] >> betAmount;
			*player[1] << betAmount;
		}

		//TODO: Report the name and cash for each
		std::cout << std::endl;
		for (int i = 0; i < NUM; i++) {
			std::string name = player[i]->GetName();
			std::cout << name << " has $" << player[i]->GetCash() << " dollars." << std::endl;
		}
		std::cout << std::endl;

		// TODO: Determine whether it is time to quit by checking to see if one player has run out of cash.

		for (int i = 0; i < NUM; i++) {
			if (player[i]->GetCash() <= 0) {
				gameOver = true;
			}
		}

	} while (!gameOver);

	std::cout << "The game is over." << std::endl;


	// Print out the final report for each player. Give the player's name and the player's cash. // Be sure to print the cash to two decimal places.
	for (int i = 0; i < NUM; i++) {
		std::cout << player[i]->GetName() << " has $" << std::fixed << std::setprecision(2) << player[i]->GetCash() << std::endl;
	}
	// Be sure to clean up before finishing the program.
	// used vector, no need to delete any memory here
	}
  
};

CardGameAdapter* cardGame();

#endif // _CARDGAME_H_

