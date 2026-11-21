#pragma once
#include <string>
#include <iostream>
#include <iostream>
class Player
{
private:
	std::string name;
	std::string CharacterSymbol;

	int numOfMatches;
	int matchesWon;
public:
	Player();

	Player(std::string name, std::string CharacterSymbol, int numOfMatches, int matchesWon);

	~Player();

	static Player createNewPlayer();

	std::string getName() const;

	std::string getCharacterSymbol() const;

	int getMatchesPlayed() const;

	int getMatchesWon() const;

	void recordResult(bool won);
	void displayHighScore() const;

	void saveToFile(const std::string& filename) const;
	bool loadFromFile(const std::string& filename);

};
