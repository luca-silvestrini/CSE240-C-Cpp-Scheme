/*
 * guessGame.c
 *
 *  Created on: Feb 11, 2024
 *      Author: Lucas
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

struct Player
{
	char name[30];
	int guessCount;
};

// Bool definition for player's guess, (T if correct, F if wrong)
typedef enum {F = 0,T = 1} Bool;

// Player array that stores top five players
struct Player top5[5];

//		Function Statements
void playGuessingGame();
int getGuess();
struct Player getPlayer();
void updateTop5(struct Player player);
void saveTop5();
void readTop5();

//		Function Definitions
// Plays Guessing Game, generates number to guess, prompts user for guess until True
void playGuessingGame()
{
	// Generate a random number between 10 and 100 and find its square root
	srand((unsigned int)time(NULL)); // Seed rand with current time
	int numberToGuess = rand() % 91 + 10;
	double squareRoot = sqrt(numberToGuess);

	struct Player p1 = getPlayer(); // Initializes player for current game

	printf("%.8f is the square root of what number? ", squareRoot);

	Bool done = F;
	while (!done)
	{
		int guess = getGuess();

		if (guess < numberToGuess)
		{
			printf("Too low, guess again: ");
			p1.guessCount++;
		}
		else if (guess > numberToGuess)
		{
			printf("Too high, guess again: ");
			p1.guessCount++;
		}
		else
		{
			done = T;
			p1.guessCount++;
		}
	}
	updateTop5(p1);

	// Prints game ending, including guess count and leaderboard
	printf("You got it, baby!\n");
	printf("You made %d guesses.\n", p1.guessCount);
	printf("Here are the current leaders:\n\n");

	for(int i = 0; i < 5; i++)
	{
		printf("%s made %d guesses\n", top5[i].name, top5[i].guessCount);

		if(top5[i+1].guessCount == 0) // Stops printing if there's no next player
			break;
	}
	printf("\n");
}

// Updates top5 ranking from best (0) to worst (4)
// takes struct Player as an input
void updateTop5(struct Player player)
{
	// Inserting new player in top5 starts as false, or -1
	int insertIndex = -1;

	for(int i = 0; i < 5; i++)
	{
		// If player has a lower guess count, replace at that index
		// Or, if spot is empty, insert player at that index
		if(player.guessCount < top5[i].guessCount || top5[i].guessCount == 0)
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
			top5[i] = top5[i-1];
		}
		top5[insertIndex] = player;
	}
}

// Creates a text file and saves the names and guess counts in it.
void saveTop5()
{
	FILE *file = fopen("top5.txt", "w");

	// Prints the leaders' name and guess counts onto the text file
	for(int i = 0; i < 5; i++)
	{
		fprintf(file, "%s %d\n", top5[i].name, top5[i].guessCount);
	}
	fclose(file);
}

// Opens, scans, and inserts the saved leaders to the top5 array
void readTop5()
{
	FILE *file = fopen("top5.txt", "r");

	if(file == NULL) // If no file found, exit
	{
		return;
	}

	// Scans and inserts the leaders' name and guess counts into the top5 array
	for(int i = 0; i < 5; i++)
	{
		fscanf(file, "%s %d", top5[i].name, &top5[i].guessCount);
	}
	fclose(file);
}

// Prompts player for guess and returns it
int getGuess()
{
	printf("Guess a value between 10 and 100: ");
	int guess;
	scanf("%d", &guess);

	return guess;
}

// Initializes player and prompts user for name
struct Player getPlayer()
{
	struct Player player;

	printf("Please enter your name to start: ");
	scanf("%s", &player.name);
	player.guessCount = 0;

	return player;
}

int main()
{
	char input;
		// Print welcome statement and then begins game
		printf("Welcome! Press 'q' to quit or"
				" any other key to continue:\n");
		scanf("%c", &input);

		// Reads and recovers previous top 5, if any
		readTop5();
		// Game loop
		while(input != 'q')
		{
			playGuessingGame();
			// Saves top 5
			saveTop5();
			// Asks to play again
			printf("Press 'q' to quit or any other key to continue:\n");
					scanf(" %c", &input);
		}
		// End
		printf("Bye Bye!");
}

