//PlayerAdult.h - class for the player adult

#ifndef _PLAYERADULT_H_
#define _PLAYERADULT_H_

#include "Player.h"

template <class T>
class PlayerAdult : public PlayerBase<T>
{
	std::vector <T> attackCards;
public:
		PlayerAdult() {};

		PlayerAdult(const std::string & name) : PlayerBase<T>(name) {
		attackCards.clear();
		}
		//The youth player can be created from another youth player.
		PlayerAdult(const PlayerAdult & player) : PlayerBase<T>(player) {
			attackCards = player.attackCards;
		}

		//using copy assignment from the base class

		PlayerAdult<T>& operator=(const PlayerAdult<T>&player) {
			if (*this != player) {
				//using the double equal operator from the base base
				PlayerBase<T>::operator==(player);
				attackCards = player.attackCards;
			}
			return *this;
		}

		//adding attack cards
		void AddAttackCards(std::vector<T> cards) {
			attackCards.clear();
			attackCards = cards;
		}

		void GetAttackCards(int numAttackCards) {
			std::vector <T> attackCardsAdult;//need to check this
			for (int j = 0; j < numAttackCards; j++) {
				if (typeid(T) == typeid(double)) {
					double attackCard = (rand() % 14001 + 1000) / 1000.0; // generate a random number between 1000 and 10000, then divide by 1000 to get a value between 1.000 and 10.000
					attackCard = floor(attackCard * 1000) / 1000.0;
					attackCardsAdult.push_back(attackCard);
					this->AddAttackCards(attackCardsAdult);
				}
				else {
					int attackCard = (rand() % 15) + 1;
					attackCardsAdult.push_back(attackCard);
					this->AddAttackCards(attackCardsAdult);
				}
			}
			//test
			/*for (int l = 0; l < attackCardsAdult.size(); l++) {
				std::cout << attackCardsAdult[l] << std::endl;
			}*/
		}

		void GetAAttackCard() {
			if(typeid(T) == typeid(double)) {
				double attackCard = (rand() % 14001 + 1000) / 1000.0; // generate a random number between 1000 and 15000, then divide by 1000 to get a value between 1.000 and 15.000
				attackCard = floor(attackCard * 1000) / 1000.0;
				this->AddAttackCard(attackCard);
				std::cout << attackCard << std::endl;
			}
			else { 
				int attackCard = (rand() % 15) + 1; 
				this->AddAttackCard(attackCard);
				//test
			//	std::cout << attackCard << std::endl;
			}
		 
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

		~PlayerAdult() {};
	};

#endif //_PLAYERADULT_H_