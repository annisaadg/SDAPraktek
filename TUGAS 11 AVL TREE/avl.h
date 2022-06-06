// C program to delete a node from AVL Tree
#ifndef avl_H
#define avl_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Nil NULL

// An AVL tree node
struct Node
{
	char nama[20];
	int id;
	struct Node *left;
	struct Node *right;
	int height;
};

// A utility function to get height of the tree
int height(struct Node *N);

// A utility function to get maximum of two integers
int max(int a, int b);

/* Helper function that allocates a new node with the given id and
	Nil left and right pointers. */
struct Node* newNode(int id, char* name);

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct Node *rightRotate(struct Node *y);

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct Node *leftRotate(struct Node *x);

// Get Balance factor of node N
int getBalance(struct Node *N);

struct Node* insert(struct Node* node, int id, char* name);

/* Given a non-empty binary search tree, return the
node with minimum id value found in that tree.
Note that the entire tree does not need to be
searched. */
struct Node * minValueNode(struct Node* node);

// Recursive function to delete a node with given id
// from subtree with given root. It returns root of
// the modified subtree.
struct Node* deleteNode(struct Node* root, int id);

struct Node* insertBST(struct Node* node, int id, char* name);

struct Node* deleteTree(struct Node* node);
void insertPegawai(struct Node* node, int id, char* nama);

struct Node* searchNode(struct Node* node, int id);

// A utility function to print preorder traversal of
// the tree.
// The function also prints height of every node
void preOrder(struct Node *root);
void printPegawaiPreorder(struct Node *root);

#endif

