/*
 * bst.c
 *
 *  Created on: Feb 26, 2024
 *      Author: Lucas
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bst.h"

struct node* insert(struct node* root, int data, char* question, char* guess)
{
	// Create new node
	struct node* newNode = malloc(sizeof(struct node));
	newNode->data = data;
	newNode->question = question;
	newNode->guess = guess;
	newNode->left = newNode->right = NULL;

	// If tree is empty
	if(root == NULL)
	{
		return newNode;
	}

	// Search for new node's parent
	struct node* current = root;
	struct node* parent = root;
	while( current != NULL )
	{
		parent = current;
		if (data < current->data)
			current = current->left;
		else
			current = current->right;
	}

	// Insert node
	if (data < parent->data)
		parent->left = newNode;
	else
		parent->right = newNode;

	return newNode;
}
