/*
 * RPS.c
 *
 *  Created on: Jan 30, 2024
 *      Author: Lucas
 */
#include <stdio.h>
#include <stdlib.h>

// Universal player input
char playerInput;

// 		Function statements
void playRPSGame();
char getPlayerMove();
char getComputerMove();

// 		Function definitions
// Plays the classic Rock, Paper, Scissors game
void playRPSGame()
{
	// Gets player move
	playerInput = getPlayerMove();
	// Gets computer move
	char computerMove = getComputerMove();

	// Determines victor based on players move
	// Player chose rock
	if(playerInput == 'r' && computerMove == 's')
	{
		printf("You win!\n");
	}
	else if(playerInput == 'r' && computerMove == 'p')
	{
		printf("Computer wins!\n");
	}
	// Player chose scissors
	else if(playerInput == 's' && computerMove == 'p')
	{
		printf("You wins!\n");
	}
	else if(playerInput == 's' && computerMove == 'r')
	{
		printf("Computer wins!\n");
	}
	// Player chose paper
	else if(playerInput == 'p' && computerMove == 'r')
	{
		printf("You wins!\n");
	}
	else if(playerInput == 'p' && computerMove == 's')
	{
		printf("Computer wins!\n");
	}
	else
	{
		printf("You Tied!\n");
	}
}

// Asks player for input, checks if it is valid,
// then stores to playerInput
char getPlayerMove()
{
	char input;

	// Loop until a valid input is provided
	while (1) {
		printf("Enter your move (r for rock, p for paper, s for scissors): ");

		// Use scanf to read a character from the standard input
        scanf(" %c", &input);

        // Check if the input is valid
        if (input == 'r' || input == 'p' || input == 's')
        {
            return input; // Exit the loop if the input is valid
        } else {
            printf("Invalid move. ");
        }
	}
	// Returns valid input (r, p, s)
	return input;
}

// Uses rand() to generate a random move (r, p, s)
char getComputerMove()
{
	// Generates random number between 1 and 3
	int randomNum = (rand() % 3) + 1;
	char computerMove;

	// Determines move of computer based on randomNum
	if(randomNum == 1)
	{
		computerMove = 'r';
	}
	else if(randomNum == 2)
	{
		computerMove = 'p';
	}
	else
	{
		computerMove = 's';
	}

	return computerMove;
}

int main()
{
	// Print welcome statement and then begins game
	printf("Welcome to Rock, Paper, Scissors! Press"
			"'q' to quit or any other key to continue:\n");
	scanf("%c", &playerInput);

	// Game loop
	while(playerInput != 'q')
	{
		playRPSGame();

		// Asks to play again
		printf("Press 'q' to quit or any other key to continue:\n");
				scanf(" %c", &playerInput);
	}
	// End
	printf("Bye Bye!");
}

