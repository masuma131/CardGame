//Player.h - class for the player base class

#ifndef _PLAYER_
#define _PLAYER_

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <string>
#include <cstdlib> //for rand() and srand()
#include <ctime> //for time()
#include <numeric> //std::accumulate()
#include <typeinfo>


template <class T>
class PlayerBase
{
	std::string name;
	double cash;
	std::vector <int> dependentCards;

public:
	PlayerBase() {
		name = "";
		cash = 1000.00;
	}

	PlayerBase(const std::string& name) {
		this->name = name;
		cash = 1000.00;
	}

	PlayerBase(const PlayerBase& player) {
		*this = player;
	}

	PlayerBase& operator=(const PlayerBase& player) {
		if (*this != player) {
			name = player.name;
			cash = player.cash;
			/*for (int i = 0; i < size(dependentCards); i++) {
				dependentCards[i] = player.dependentCards[i];
			}*/
			dependentCards = player.dependentCards;
		}
		return *this;
	}

	std::string GetName() const {
		return name;
	}

	void SetName(std::string& name) {
		this->name = name;
	}

	void AddDependentCards(std::vector <int> cards) {
		dependentCards.clear();
		dependentCards = (cards);

	}

	void AddDependentCard(int card) {
		dependentCards.push_back(card);
	}

	//summing cards in the vect dependent card
	int SumDependentCards() const {
		
		int total = 0;
		for (int i = 0; i < dependentCards.size(); i++) {
			total += dependentCards[i];
		}
		//alternative
		//int sum = std::accumulate(dependentCards.begin(), dependentCards.end(), 0);

		return total;
	}

	double GetCash() {
		return cash;
	}

	void AddCash(double amount) {
		cash += amount;
	}

	void RemoveCash(double amount) {
		cash -= amount;
	}

	void GetDependentCards(int numDependentCards) {
		std::vector <int> depCards;
		for (int j = 0; j < numDependentCards; j++) {
			int depCard = (rand() % 5) + 1;
			depCards.push_back(depCard);

			this->AddDependentCards(depCards);

		}
		//test
		/*for (int l = 0; l < depCards.size(); l++) {
			std::cout << depCards[l] << std::endl;
		}*/
	}

	void GetADependentCard() {
		//draw dep card
		time_t currentTime = time(0);
		unsigned int seed = static_cast<unsigned int>(currentTime);
		srand(seed);
		int depCard = int(rand() % 5) + 1;
		//add dep card
		this->AddDependentCard(depCard);
		//test
		//std::cout << depCard << std::endl;
	}
	
	//sum card func is changing values, so this function can't be const
	bool operator== (PlayerBase& other) {
		bool retVal = false;
		if (this->SumCards() == other.SumCards()) {
			retVal = true;
		}
		return retVal;
	};

	bool operator<(PlayerBase& other){
		bool retVal = false;
		if (this->SumCards() < other.SumCards()) {
			retVal = true;
		}
		else {
			retVal = false;
		}
		//shortcut:: return SumCards() < other.SumCards(); //can't point to it as it is a pure abstruct func
		return retVal;
	}

	bool operator>(PlayerBase& other) {
		bool retVal = false;
		if (this->SumCards() > other.SumCards()) {
			retVal = true;
		}
		else {
			retVal = false;
		}
		//shortcut:: return SumCards() > other.SumCards(); //can't point to it as it is a pure abstruct func
		return retVal;
	}

	void operator<<(double amount) {
		this->AddCash(amount);
	}

	void operator>>(double amount) {
		this->RemoveCash(amount);
	}

	virtual void AddAttackCards(std::vector<T> cards) = 0;
	virtual void AddAttackCard(T cards) = 0;
	virtual T SumAttackCards() = 0;
	virtual T SumCards() = 0;
	virtual void GetAttackCards(int numAttackCards) = 0;
	virtual void GetAAttackCard() = 0;

	~PlayerBase() {
		name = "";
		cash = 0.00;
	}
};


#endif //_PLAYER_

