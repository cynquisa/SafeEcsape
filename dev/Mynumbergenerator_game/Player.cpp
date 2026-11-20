#include "Player.h"
#include "Input.h"
#include <iostream>
#include <string>
#include <vector>
#include "ConsoleColor.h"
#include <fstream>



Player::Player()
	:name(""), CharacterSymbol(""), numOfMatches(0), matchesWon (0)
{
}

Player::Player(std::string name, std::string CharacterSymbol, int numOfMatches, int matchesWon )
	: name(name), CharacterSymbol(CharacterSymbol), numOfMatches(numOfMatches), matchesWon(matchesWon)
{ 

}

	Player::~Player()
{
}

Player Player::createNewPlayer()

{
	system("cls");

	ConsoleColor::Print( "※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n", ConsoleColor::Ink::Green);
	ConsoleColor::Print("\n", ConsoleColor::Ink::White);
	ConsoleColor::Print("             Player Creation\n", ConsoleColor::Ink::Cyan);
	ConsoleColor::Print("\n", ConsoleColor::Ink::White);
	ConsoleColor::Print("\n", ConsoleColor::Ink::White);
	ConsoleColor::Print("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n", ConsoleColor::Ink::Green);


	std::string nameInput = Input::GetString("Enter your name please: ");
	system("cls");
	ConsoleColor::Print("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n", ConsoleColor::Ink::Purple);
	ConsoleColor::Print("\n", ConsoleColor::Ink::White);
	ConsoleColor::Print("             Choose Your Avatar\n", ConsoleColor::Ink::Cyan);
	ConsoleColor::Print("\n", ConsoleColor::Ink::White);
	ConsoleColor::Print("\n", ConsoleColor::Ink::White);
	ConsoleColor::Print("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n", ConsoleColor::Ink::Purple);


	std::vector<std::string> characterChoice;
	characterChoice.push_back("¬_¬");
	characterChoice.push_back("^_^");
	characterChoice.push_back("(*_*)");
	characterChoice.push_back("<>_<>");


	ConsoleColor::Print("\nChoose your character: \n", ConsoleColor::Ink::White);
	ConsoleColor::Print("\n", ConsoleColor::Ink::White);



	for (size_t i = 0; i < characterChoice.size(); ++i)
	{
		ConsoleColor::Print(std::to_string(i + 1) + ". Faces " + characterChoice[i] + "\n", ConsoleColor::Ink::Cyan);
	}


	int choice = Input::GetNumber("Select choice (1-4): ", 1, static_cast<int>(characterChoice.size()));

	std::string selectedSymbol = characterChoice[choice - 1];


	ConsoleColor::Print("Your player is created! Welcome,  " + nameInput + " " + selectedSymbol + "\n\n", ConsoleColor::Ink::Green);
	ConsoleColor::Print("\n", ConsoleColor::Ink::White);

	Input::Pause("Press Enter to continue...");
	return Player(nameInput, selectedSymbol, 0, 0);
}

std::string Player::getName() const
{
	return name;
}

int Player::getMatchesPlayed() const
{
	return numOfMatches;
}

int Player::getMatchesWon() const
{
	return matchesWon;
}

std::string Player::getCharacterSymbol() const
{
	return CharacterSymbol;
}

void Player::recordResult(bool won)
{
	numOfMatches++;
	if (won)
	{
		matchesWon++;
	}
	saveToFile("player_save.txt");

	std::ofstream historyFile("highscores.txt", std::ios::app);
	if (historyFile.is_open())
	{
		historyFile << name << "\n"
			<< CharacterSymbol << "\n"
			<< numOfMatches << "\n"
			<< matchesWon << "\n";
		historyFile.close();
	}
}

void Player::displayHighScore() const
{
	ConsoleColor::Print("\n========================================================== = \n", ConsoleColor::Ink::Purple);
	ConsoleColor::Print("Player Stats: ", ConsoleColor::Ink::Purple);
	ConsoleColor::Print(name, ConsoleColor::Ink::Purple);
	ConsoleColor::Print(" Avatar: ", ConsoleColor::Ink::Purple);
	ConsoleColor::Print((CharacterSymbol + "\n"), ConsoleColor::Ink::Purple);
	ConsoleColor::Print("\n========================================================== = \n", ConsoleColor::Ink::Purple);


	std::ifstream inFile("highscores.txt");
	if (inFile.is_open())
	{
		ConsoleColor::Print("\n--- All-Time High Scores-----\n", ConsoleColor::Ink::Purple);
		std::string savedName;
		std::string savedSymbol;
		int savedMatches = 0;
		int savedWins = 0;

		while (std::getline(inFile, savedName) &&
			std::getline(inFile, savedSymbol) &&
			(inFile >> savedMatches >> savedWins))
			{
			inFile.ignore();
			std::cout << savedName << " (" << savedSymbol << " ( - Games: "
				<< savedMatches << " | Safes Cracked: " << savedWins << "\n";
			}

		
		
		inFile.close();

	}
	std::cout << "Games Played: " << numOfMatches << '\n';

	std::cout << "Safes Cracked: " << matchesWon << '\n';
}

void Player::saveToFile(const std::string& filename) const
{
	std::ofstream outFile(filename);
	if (outFile.is_open())
	{
		outFile << name << "\n";
		outFile << CharacterSymbol << "\n";
		outFile << numOfMatches << "\n";
		outFile << matchesWon << "\n";
		outFile.close();

	}
}

bool Player::loadFromFile(const std::string& filename)
{
	std::ifstream inFile(filename);
	if (!inFile.is_open())
	{
		saveToFile(filename);
		return false;
	}
	std::getline(inFile, name);
	std::getline(inFile, CharacterSymbol);
	inFile >> numOfMatches >> matchesWon;
	inFile.close();
	return true;
}








/*I know that in the future I would like to give the player a choice as to somesort of symbol to 
represent themselves but for now we will only take the name and list a few game stats like number of games played and  won.
I have decide to store my character selectiion in a vector */

