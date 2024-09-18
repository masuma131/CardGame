# SEP200 - Assignment 1: Card Game

## Description
This project simulates the popular card game "21" in C++. The game allows players to play without physical cards and includes additional features that are not available with real cards, such as random card draws, "attack" cards, and "dependent" cards that add complexity to the game.

## Features
- Simulates the card game "21"
- Supports two game modes: 
  - **Low-definition mode:** All cards have integer values
  - **High-definition mode:** Attack cards have decimal (floating point) values for more granularity
- Two types of cards:
  - **Attack Cards:** Randomly drawn cards with a positive value
  - **Dependent Cards:** Cards that subtract from the total score to increase complexity
- Two types of players:
  - **Youth Player:** Has attack cards based on age, ranging from 0 to half the player's age
  - **Adult Player:** Has attack cards ranging from 1 to 15 in low-definition mode or decimal values in high-definition mode
- Player customization and management:
  - Players have names, cash, and card lists
  - Players can bet within a given range
  - Players can add or remove cards dynamically

## Requirements
- The objective is to get the sum of the cards as close to 21 as possible without going over.
- The game can be played by two players at a time.
- Players can bet an amount between the specified range before each game.
- Each player has a list of dependent cards that are always integers.
- The mode of the game (low or high definition) is determined at compile time.

## Player Class Features
Each player has the following attributes and methods:
- **Attributes:**
  - Name
  - Cash ($1000.00 starting cash)
  - Dependent cards (integer values)
- **Methods:**
  - Create players with default or custom names
  - Add dependent cards (either individually or as a list)
  - Get the total of dependent cards
  - Add or subtract cash
  - Clean up memory before destruction

### Youth Player
In addition to the general player attributes, the youth player:
- Has a hard-coded name ("Noah")
- Age is input from the user (range: 4-18)
- Attack cards are based on age and have a value between 0 and age/2
- Can create youth players with custom name and age

### Adult Player
In addition to the general player attributes, the adult player:
- Attack cards have a value between 1 and 15 in low-definition mode
- Can create adult players with custom name and attack cards

## Operators Overridden
- `==`, `<`, `>`: For comparing points between players
- `<<`, `>>`: For adding or removing cash from a player

### Classes and Design
In addition to the general player attributes, the youth player:
- **Base Player Class:** Contains common properties and functions for all players.
- **Youth Player Class:** Inherits from Base Player, with additional features like age-specific attack cards.
- **Adult Player Class:** Inherits from Base Player with standard attack cards.
- **CardGame Class:** Manages the flow of the game between two players.

## How to Play
1. **Input**:
   - The user inputs the youth player's age.
   - Both players are prompted to make a bet within a range (e.g., $10 to $300).
   - Players are prompted to add dependent and attack cards.
   - The game keeps track of players' points, compares them, and checks if any player has exceeded 21.
2. **Win Conditions**:
   - If a player goes over 21, they are disqualified.
   - The player closest to 21 wins the round.
  
### Usage
- Clone the repository.
- Compile the code in your preferred C++ environment.
- Run the game and follow the on-screen instructions to play.

### Testing
The game supports both low-definition (integer values) and high-definition (decimal values) modes. Ensure to test both modes by modifying the game mode at compile-time and running various card draw scenarios.
