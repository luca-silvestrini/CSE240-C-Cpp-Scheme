/*
 * twenty.c
 *
 *  Created on: Feb 26, 2024
 *      Author: Lucas
 */
#include <stdio.h>
#include <string.h>
#include "bst.h"

// Bool definition for player's guess, (T if correct, F if wrong)
typedef enum {F = 0,T = 1} Bool;

// Creates a BST tree for the game
struct node* createGameTree()
{
	struct node* root = NULL;

	root = insert(root, 100, "Does it grow underground?", "");
	insert(root, 50, "Is it long in shape?", "");
	insert(root, 25, "Is it orange in color?", "");
	insert(root, 15, "", "It's a carrot!");
	insert(root, 35, "", "It's a parsnip!");
	insert(root, 75, "Is it red in color?", "");
	insert(root, 65, "", "It's a radish!");
	insert(root, 85, "", "It's a potato!");
	insert(root, 150, "Does it grow on a tree?", "");
	insert(root, 125, "Is it red in color?", "");
	insert(root, 115, "", "It's an apple!");
	insert(root, 135, "", "It's a peach!");
	insert(root, 175, "Is it red in color?", "");
	insert(root, 165, "", "It's a tomato!");
	insert(root, 185, "", "It's a pea!");

	return root;
}

//		Function Statements
void playTwentyQuestions(struct node* root);

//		Function Definitions
void playTwentyQuestions(struct node* root)
{
	struct node* current = root;
	char answer;

	Bool done = F;
	while (!done)
	{
		if(current->question != "") // If no question, then go straight to guess
		{
		printf("%s\n", current->question); // Asks question
		printf("y/n: ");
		scanf(" %c", &answer); // Stores answer ('y' or 'n')
		}

		if (answer == 'y')
		{
			if(current->left == NULL) // If leaf node, then computer guesses answer
			{
				printf("%s\n", current->guess); // Tells user the guess
				printf("y/n: ");
                scanf(" %c", &answer); // User gives responds if guess is correct
                if(answer == 'y')
                	printf("I win!\n");
                else
                	printf("You win!\n");
                done = T; // Break out of while loop
			}
			else // Left node if answer is yes and not leaf node
			{
				current = current->left;
			}
		}
		else
		{
			if(current->right == NULL) // If leaf node, then computer guess answer
			{
				printf("%s\n", current->guess); // Tells user the guess
				printf("y/n: ");
				scanf(" %c", &answer); // User responds if guess is correct
				if(answer == 'y')
                	printf("I win!\n");
                else
                	printf("You win!\n");
                done = T; // Break out of while loop
			}
			else // Right node if answer is no and not leaf node
			{
				current = current->right;
			}
		}
	}
}

int main()
{
	struct node* gameTree = createGameTree();

	char c;
		// Print welcome statement and then begins game
		printf("Welcome! Press 'q' to quit or any other key to continue:\n");
		scanf("%c", &c);

		// Game loop
		while(c != 'q')
		{
			//play twenty questions
			playTwentyQuestions(gameTree);
			// Asks to play again
			printf("Press 'q' to quit or any other key to continue:\n");
					scanf(" %c", &c);
		}
		// End
		printf("Bye Bye!");
}

