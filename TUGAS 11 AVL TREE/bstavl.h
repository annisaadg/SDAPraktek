#ifndef bstavl_H
#define bstavl_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Nil NULL
#define Height(T) (T)->height
#define Nama(P) (P)->nama
#define Id(P) (P)->id
#define Left(P) (P)->left
#define Right(P) (P)->right
#define Root(T) (T).root

typedef struct tElmTree *address;

typedef struct tElmTree{
	int id;
	char nama[20];
	address left;
	address right;
	int height;
	address root;
}ElmTree;


typedef struct{
	address root;
}Tree;


// A utility function to get height of the tree
int heightAVL(Tree *T);

// A utility function to get maximum of two integers
int maxAVL(int a, int b);

/* Helper function that allocates a new node with the given id and
	Nil left and right pointers. */
address newNode(int item, char* name);

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
address rightRotateAVL(Tree *T);

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
address leftRotateAVL(Tree *T);

// Get Balance factor of node N
int getBalanceAVL(Tree *T);

address insertAVL(Tree *T, int id, char* name);

/* Given a non-empty binary search tree, return the
node with minimum id value found in that tree.
Note that the entire tree does not need to be
searched. */
address minValueNodeAVL(address node);

// Recursive function to delete a node with given id
// from subtree with given root. It returns root of
// the modified subtree.
address deleteNodeAVL(Tree *T, int id);

// A utility function to print preorder traversal of
// the tree.
// The function also prints height of every node
void preOrder(address root);
void postOrder(address root);


///////////////////////////////////////////////////////


// A utility function to do inorder traversal of BST
void inOrder(address root);

/* A utility function to
insert a new node with given id in
* BST */
address insert(Tree *T, int id, char* name);

/* Given a non-empty binary search
tree, return the node
with minimum id value found in
that tree. Note that the
entire tree does not need to be searched. */
address minValueNode(address node);

/* Given a binary search tree
and a id, this function
deletes the id and
returns the new root */
address deleteNode(Tree *T, int id);

#endif
