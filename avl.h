#ifndef __AVL_H__
#define __AVL_H__

#include <stdio.h>

struct Node {
	int key;
	struct Node *left;
	struct Node *right;
	int height;
};

struct Node *insertNode(struct Node *node, int key);

struct Node *deleteNode(struct Node *root, int key);

int hasElem(struct Node *root, int elem);

struct Node * replaceElem(struct Node **root, int a, int b);

void printElem(struct Node *root, FILE *out);

void freeTree(struct Node *root);

#endif