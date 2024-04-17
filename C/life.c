/*
 * life.c
 *
 *  Created on: Feb 6, 2024
 *      Author: Lucas
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Grid Size
#define GRID_SIZE 5

//		Function Statements
void playLife();
void displayGrid(int grid[GRID_SIZE][GRID_SIZE]);
void initializeGrid(int grid[GRID_SIZE][GRID_SIZE], int offsets[], int numOffsets);
void nextGeneration(int grid[GRID_SIZE][GRID_SIZE]);
int countLiveNeighbors(int grid[GRID_SIZE][GRID_SIZE], int row, int col);

//		Function Definitions
// Plays Game of Life, initializes grid, and calls helper functions
void playLife()
{
	// Game of Life grid
	int lifeGrid[GRID_SIZE][GRID_SIZE] = {
			{0,0,0,0,0},
	        {0,0,0,0,0},
	        {0,0,0,0,0},
	        {0,0,0,0,0},
	        {0,0,0,0,0}
	};

	// Get offsets for live cells from Player
	int offsets[25];
	char input[100];

	printf("Enter the offsets for the live cells:\n");
	scanf("%s", input);
		// Parse the input for individual Integers
	char *token = strtok(input, ",");
	int numOffsets = 0;
	while(token != NULL)
	{
		offsets[numOffsets++] = atoi(token);
		token = strtok(NULL, ",");
	}

		// Reduced the size of array to the number of offsets found
	int revOffsets[numOffsets];
	for(int i = 0; i < numOffsets; i++)
	{
		revOffsets[i] = offsets[i];
	}

	// Sets up grid based on offsets
	initializeGrid(lifeGrid, offsets, numOffsets);

	// Runs 7 generations of life
	for(int generation = 0; generation < 7; generation++)
	{
		printf("generation = %d:\n", generation);
		displayGrid(lifeGrid);
		nextGeneration(lifeGrid);
	}

	// Finished Game of Life
	printf("Good Life!\n");
}

// Creates new grid based on Game of Life rules, copies to lifeGrid
void nextGeneration(int grid[GRID_SIZE][GRID_SIZE])
{
	int nextGen[GRID_SIZE][GRID_SIZE]; // New grid

	for (int i = 0; i < GRID_SIZE; i++)
	{
        for (int j = 0; j < GRID_SIZE; j++)
        {
            int liveNeighbors = countLiveNeighbors(grid, i, j);
            if (grid[i][j] == 1) // Live cell
            {
                if (liveNeighbors < 2 || liveNeighbors > 3)
                {
                    nextGen[i][j] = 0; // Cell dies
                }
                else
                {
                    nextGen[i][j] = 1; // Live cell survives
                }
            }
            else // Dead cell
            {
                if (liveNeighbors == 3)
                {
                    nextGen[i][j] = 1; // Dead cell lives
                }
                else
                {
                    nextGen[i][j] = 0; // Dead cell remains dead
                }
            }
        }
    }

	// Copy next generation grid back to life grid
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            grid[i][j] = nextGen[i][j];
        }
    }
}

// Counts live cells neighboring a given cell
int countLiveNeighbors(int grid[GRID_SIZE][GRID_SIZE], int row, int col)
{
	int count = 0;
	// Scans top 3, middle 3, and bottom 3 rows
    for (int i = row - 1; i <= row + 1; i++)
    {
        for (int j = col - 1; j <= col + 1; j++)
        {
            if (i >= 0 && i < GRID_SIZE && j >= 0 && j < GRID_SIZE // Checks if is inside bounds
            		&& !(i == row && j == col)) // Checks that it's not itself
            {
                count += grid[i][j]; // Increment count if neighbor cell is alive
            }
        }
    }
    return count;
}


// Prints out life grid
void displayGrid(int grid[GRID_SIZE][GRID_SIZE])
{
	for (int i = 0; i < GRID_SIZE; i++)
	{
		for (int j = 0; j < GRID_SIZE; j++)
		{
            if (grid[i][j] == 1)
            {
                printf("*"); // Print live cell
            }
            else
            {
                printf(" "); // Print dead cell
            }
        }
        printf("\n");
    }
	printf("\n");
}

// Updates grid based on offsets
void initializeGrid(int grid[GRID_SIZE][GRID_SIZE], int offsets[], int numOffsets)
{
	for (int i = 0; i < numOffsets; i++)
	{
        int offset = offsets[i];
        int row = offset / GRID_SIZE;
        int col = offset % GRID_SIZE;
        grid[row][col] = 1; // Set live cells based on offsets
    }
}

int main()
{
	char input;
	// Print welcome statement and then begins life
	printf("Welcome! Press 'q' to quit or"
			" any other key to continue:\n");
	scanf("%c", &input);

	// Game loop
	while(input != 'q')
	{
		playLife();
		// Asks to play again
		printf("Press 'q' to quit or any other key to continue:\n");
				scanf(" %c", &input);
	}
	// End
	printf("Bye Bye!");
}
