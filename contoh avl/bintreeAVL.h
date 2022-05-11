#ifndef BINTREE_H
#define BINTREE_H

#include <stdlib.h>
#include "boolean.h"
#include <time.h>

#define Nil NULL
#define Id(P) (P)->id
#define Left(P) (P)->left
#define Right(P) (P)->right
#define Nama(P) (P)->nama
#define Height(P) (P)->height

typedef int infoid;
typedef char infonama[50];
typedef struct tElmtNode *address;
typedef struct tElmtNode {
	infoid id;
	address left;
	address right;
	infonama nama;
	int height;
} ElmtNode;

//typedef struct {
//    address root;
//}BinTree;

typedef address BinTree;
//typedef address ListOfNode;

BinTree Alokasi(infoid id, infonama nama);
/* Menghasilkan  address hasil alokasi sebuah  Node 	*/
/* Jika alokasi berhasil, maka  address tidak NIl   	*/
/* Info(P)=X, Left(P)=Nil,Right(P)=Nil, dan Count(P)=0 	*/
/* Jika alokasi gagal mengembalikan Nil  		*/

boolean IsEmptyTree(BinTree T);
/* Mengembalikan true jika pohon kosong */

void CreateEmpty(BinTree *T);
/* Membuat  Tree   kosong  */

infoid GetAkar(BinTree P);
/* Mengirimkan nilai Akar pohon biner P */

BinTree GetLeft(address P);
/* Mengirimkan anak kiri pohon biner P  */

BinTree GetRight(address P);
/* Mengirimkan anak kanan pohon biner P  */

/* ******** KONSTRUKTOR ************ */
BinTree CreateTree(infoid id, infonama nama, address L, address R);
/* Menghasilkan sebuah pohon Biner dari A, L, dan R jika Alokasi berhasil */
/* Menghasilkan pohon kosong Nil, jika alokasi gagal 			  */

/* ************* TRAVERSAL   ************* */

void PrintPreorder(BinTree P);
/* I.S  : P terdefinisi   					    */
/* F.S  : semua simpul P sudah diproses secara Preorder; akar, kiri */
/*        kanan (dengan Proses (P)) 				    */

void PrintInorder(BinTree P);
/* I.S  : P terdefinisi   					    */
/* F.S  : semua simpul P sudah diproses secara Inorder; kiri, akar  */
/*        kanan (dengan Proses (P)) 				    */

void PrintPostorder(BinTree P);
/* I.S  : P terdefinisi   					    */
/* F.S  : semua simpul P sudah diproses secara Postorder; kiri,     */    
/* 	  kanan, akar (dengan Proses (P)) 			    */

/* ********* OPERASI LAIN ********* */
//void AddDaun(BinTree *T, infoid id, infonama nama);
BinTree AddDaun (BinTree node, infoid id, infonama nama);
/* I.S   : P boleh kosong 	*/
/* F.S   : P bertambah simpulnya, dengan X sbg simpul daun terkiri */  		

BinTree DeleteNode(BinTree T, int id);
/* I.S   : P tidak kosong 	*/
/* F.S   : P dihapus   daun terkirinya, dan didealokasi dengan X adalah  */
/*         info yang semula disimpan pada daun terkiri yang dihapus      */

void findPrint(BinTree T, infoid id);

BinTree SearchNode(BinTree T, infoid id);
/*I.S	: diketahui suatu tree namun tidak diketahui ada atau tidaknya suatu node
  F.S	: diketahuinya ada atau tidaknya suatu node juga alamatnya*/
  
void DestructTree(address T);

int getHeight(BinTree T);
int getBalance(BinTree T);
int max(int a, int b);
BinTree leftRotate(BinTree x);
BinTree rightRotate(BinTree y);
void delay(double detik);

#endif
