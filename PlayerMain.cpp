//PlayerMain.cpp - main program for the card player

#include<iostream>

#include "CardGame.h"

using namespace std;

int main(void) {
    CardGameAdapter* cGame = cardGame();//MW: runs the templated cardGame through a pointer to a non-templated base class.
    //    Polymorphism is beautiful!
    cGame->run();
    delete cGame;
    return 0;
}