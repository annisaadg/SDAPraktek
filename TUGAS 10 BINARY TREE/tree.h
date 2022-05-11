/*
    File         	: tree.c
    Description    	: Header ADT Binary Tree
    Author    		: Kelompok A6
    Date/Version   	: 8 April 2022/1.0
    Compiler        : TDM-GCC 4.9.2
*/

#ifndef tree_H
#define tree_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"
#include "tree.h"
#define Nil NULL
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
}ElmTree;


typedef struct{
	address root;
}Tree;

void initTree(Tree *T);
void deleteTree(Tree *T);
address createNode(int id, char* nama);
address insertNode(Tree *T, int id,char* nama);
address minValueNode(address node);
address deleteNode(Tree *T, int id);
address searchNode(Tree *T, int id);
void insertPegawai(Tree *T, int id, char* nama);
void deletePegawai(Tree *T, int id);
void searchPegawai(Tree T, int id);
void preOrder(address root);
void inOrder(address root);
void postOrder(address root);
void printPegawai(address root);


#endif
