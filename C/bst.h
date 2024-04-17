/*
 * bst.h
 *
 *  Created on: Feb 26, 2024
 *      Author: Lucas
 */

#ifndef BST_H_
#define BST_H_

struct node
{
	int data;
	char* question;
	char* guess;
	struct node* left;
	struct node* right;
};

struct node* insert(struct node* root, int num, char* question, char* answer);

#endif /* BST_H_ */
