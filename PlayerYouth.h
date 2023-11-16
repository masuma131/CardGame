//PlayerYouth.h - class for the player youth

#ifndef _PLAYERYOUTH_H_
#define _PLAYERYOUTH_H_

#include "Player.h"

template <class T>
class PlayerYouth : public PlayerBase<T>
{
std::vector <T> attackCards;
public:
	PlayerYouth() : PlayerBase<T>() {};
	PlayerYouth(const std::string& name) : PlayerBase<T>(name) {
		attackCards.clear();
	}
	//The youth player can be created from another youth player.
	PlayerYouth(const PlayerYouth& player) : PlayerBase<T>(player) {
		attackCards = player.attackCards;
	}

	//using copy assignment from the base class
	PlayerYouth<T>& operator=(const PlayerYouth<T>& player) {
		if (*this != player) {
			//using the double equal operator from the base base
			PlayerBase<T>::operator==(player);
			attackCards = player.attackCards;
		}
		return *this;
	}

	void GetAttackCards(int numAttackCards) {
		std::vector <T> attackCardsYouth;//need to check this
		for (int j = 0; j < numAttackCards; j++) {
			if (typeid(T) == typeid(double)) {
				double attackCard = (rand() % 10001 + 1) / 1000.0; // generate a random number between 1000 and 10000, then divide by 1000 to get a value between 1.000 and 10.000
				attackCard = floor(attackCard * 1000) / 1000.0; // round down to 3 decimal places
				attackCardsYouth.push_back(attackCard);
				this->AddAttackCards(attackCardsYouth);
			}
			else {
				int attackCard = (rand() % 10) + 1;; // generate a random number between 1000 and 10000, then divide by 1000 to get a value between 1.000 and 10.000
				attackCardsYouth.push_back(attackCard);
				this->AddAttackCards(attackCardsYouth); 
			}
		
		}
		//test
		/*for (int l = 0; l < attackCardsYouth.size(); l++) {
			std::cout << attackCardsYouth[l] << std::endl;
		}*/
	}

	void GetAAttackCard() {
		if(typeid(T) == typeid(double)) {
			double attackCard = (rand() % 10001 + 1) / 1000.0; // generate a random number between 1000 and 10000, then divide by 1000 to get a value between 1.000 and 10.000
			attackCard = floor(attackCard * 1000) / 1000.0; // round down to 3 decimal places
			this->AddAttackCard(attackCard);
			//test
			//std::cout << attackCard << std::endl;
		}
		else {
			int attackCard = (rand() % 10) + 1; 
			this->AddAttackCard(attackCard);
			//test
		//	std::cout << attackCard << std::endl;
		}
	}

	//adding attack cards
	void AddAttackCards(std::vector<T> cards) {
		attackCards.clear();
		attackCards = cards;
	}
	
	//adding a attack card
	void AddAttackCard(T card) {
		attackCards.push_back(card);
	}

	T SumAttackCards() {
		T total = 0;
		for (int i = 0; i < attackCards.size(); i++) {
			total += attackCards[i];
		}
		return total;
	}

	T SumCards() {
		T total = 0;
		total = SumAttackCards() - PlayerBase<T>::SumDependentCards();
		return total;
	}

	~PlayerYouth() {};
};

#endif //_PLAYERYOUTH_H_
