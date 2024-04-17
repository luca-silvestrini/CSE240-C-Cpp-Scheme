/*
 * game.cpp
 *
 *  Created on: Mar 8, 2024
 *      Author: Lucas
 */

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cmath>

using namespace std;

// Acts as the user who plays the guessing game
class Player
{
public:
	Player(){}
	Player(string nm, int ng): name(nm), num_guesses(ng){}
	Player getPlayer();
	string getName(){return name;}
	int getGuesses(){return num_guesses;}
	void setName(string &nm){name = nm;}
	void setGuesses(int ng){num_guesses = ng;};
private:
	string name;
	int num_guesses = 0;
};

class LeaderBoard
{
public:
	LeaderBoard();
	//void insertPlayer(Player player);
	void saveLeaders();
	void readLeaders();
	void updateLeaders(Player &player);
	void printLeaders();
private:
	static const int NUM_LEADERS = 5;
	Player leaders[NUM_LEADERS];
};

// Default Constructor for LeaderBoard class
LeaderBoard::LeaderBoard()
{
	//Initializes leader array with empty Player objects
	for(int i = 0; i < NUM_LEADERS; i++)
		leaders[i] = Player("", 0);
}

// Updates leaders ranking from best (0) to worst (4)
// takes object Player as an input
void LeaderBoard::updateLeaders(Player &player)
{
	// Inserting new player in top5 starts as false, or -1
	int insertIndex = -1;

	for(int i = 0; i < 5; i++)
	{
		// If player has a lower guess count, replace at that index
		// Or, if spot is empty, insert player at that index
		if(player.getGuesses() < leaders[i].getGuesses() || leaders[i].getGuesses() == 0)
		{
			insertIndex = i;
			break;
		}
	}

	// Shift players down a spot, and inserting new player at index
	if(insertIndex != -1) // If inserting player is not false
	{
		for(int i = 4; i > insertIndex; i--)
		{
			leaders[i] = leaders[i-1];
		}
		leaders[insertIndex] = player;
	}
}

// Creates a text file and saves the names and guess counts into it.
void LeaderBoard::saveLeaders()
{
	ofstream file("leaderboard.txt");

	// Prints the leader's name and guess counts onto the text file
	for(int i = 0; i < NUM_LEADERS; i++)
	{
		file << leaders[i].getName() << " " << leaders[i].getGuesses() << "\n";
	}
	file.close();
}

// Opens, scans, and inserts the saved leaders to the leaders array
void LeaderBoard::readLeaders()
{
	ifstream file("leaderboard.txt");

	if(file == NULL)
		return;

	// Scans and inserts the leaders' name and guess counts into the leaders array
	for(int i = 0; i < NUM_LEADERS; i++)
	{
		string name;
		int guesses;
		file >> name >> guesses;
		leaders[i].setName(name);
		leaders[i].setGuesses(guesses);
	}
	file.close();
}

// Prints the leaders in descending order
void LeaderBoard::printLeaders()
{
	cout << "Here are the current leaders:" << endl << endl;

	for (int i = 0; i < NUM_LEADERS; i++)
	{
		cout << leaders[i].getName() << " made " << leaders[i].getGuesses() << " guesses" << endl;

		if (leaders[i + 1].getGuesses() == 0) // Stops printing if there's no next player
			break;
	}
	cout << endl;

}

// Plays Guessing Game, generates number to guess, prompts user for guess until True
void playGuessingGame(LeaderBoard &leaderboard)
{
	srand(static_cast<unsigned int>(time(NULL)));
	int numberToGuess = rand()%91 + 10;
    double squareRoot = sqrt(numberToGuess);

    string playerName;
    cout << "Please enter your name to start: ";
    cin >> playerName;

    int guesses = 0;
    cout << squareRoot << " is the square root of what number? ";

    bool done = false;
    while(!done)
    {
    	int guess;
    	cout << "Guess a value between 10 and 100: ";
    	cin >> guess;
    	guesses++;

    	if (guess < numberToGuess)
    	{
    		cout << "Too low, guess again.\n";
    		guesses++;
    	}
    	else if (guess > numberToGuess)
    	{
    		cout << "Too high, guess again.\n";
    		guesses++;
    	}
    	else
    	{
    		done = true;
    		guesses++;
    	}
    }

    Player curPlayer(playerName, guesses);
    leaderboard.updateLeaders(curPlayer);

	// Prints game ending, including guess count and leaders
    cout << "You got it, baby!\n";
    cout << "You made " << curPlayer.getGuesses() << " guesses.\n";

    leaderboard.printLeaders();
}

int main()
{
	LeaderBoard leaderboard;
	leaderboard.readLeaders();
	char c;

	cout << "Welcome! Press 'q' to quit or any other key to continue:\n";
	cin >> c;

	bool game_over = false;

	while(c != 'q')
	{
			playGuessingGame(leaderboard);
			leaderboard.saveLeaders();
			cout << "Press 'q' to quit or any other key to continue:\n";
			cin >> c;
	}
	cout << "Bye Bye!";
}


