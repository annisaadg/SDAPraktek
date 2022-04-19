/*
 Header File untuk Non Binary Tree
 Author  : Lukmannul Hakim Firdaus
 Created At  : 07-04-2022 
*/

#include <stdio.h>
#ifndef NBTREE_H
#define nil NULL
#include <malloc.h>
#define Nama(P) (P)->nama
#define Jabatan(P) (P)->jabatan

typedef struct nbTreeNode *nbAddr;


typedef struct nbTreeNode{ 
  char nama[50];
  char jabatan[50];
  nbAddr parent;
  nbAddr fs; //First child 
  nbAddr nb; //Next brother nbAddr parent; 
} nbTreeNode;

typedef struct { 
  nbAddr root; 
} nbTree;


//Creator
void InitTree(nbTree *t);

nbAddr AlokasiNode(char* name, char* jabatan, nbAddr parent, nbAddr fchild, nbAddr nbrother);

//insert node ke tree
nbAddr InsertNode(nbTree t, char name, char* jabatan, nbAddr parent);


#endif
