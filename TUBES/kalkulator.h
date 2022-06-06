/** Nama File : kalkulator.h
 *  Deskripsi : Header File Kalkulator
 *  Oleh      : -Zacky Faishal Abror
 *				-Annisa Dinda Gantini
*				-Dhafin Rizqi Fadhilah
 *  Tanggal   : 
 */

#ifndef KALKULATOR_H
#define KALKULATOR_H
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define nil NULL
#define info(p) (p)->node
#define prev(p) p->prev
#define top(s) (s).top

/*ADT FOR STACK*/
typedef char info[100];	//menyimpan string inputan pemain

typedef struct tElmtNode *Tnode;
typedef struct tElmtNode{
    info MathExpression;
    Tnode left;
    Tnode right;
}ElmtNode;

typedef struct telmstack *address;
typedef struct telmstack{
    Tnode node;
    address prev;
}tabStack;

typedef struct{
    address top;
}stack;

//ADT FOR TREE
typedef Tnode RootTree;

struct Token
{
    info token;
};

/* Membuat sebuath stack kosong
 * I.S. : Stack belum dibuat
 * F.S. : Stack sudah dibuat
 */
void createstack(stack *s);

/* Membuat sebuath tree kosong
 * I.S. : Tree belum dibuat
 * F.S. : Tree sudah dibuat
 */
void createTree(RootTree *node);

/* Menyediakan tempat sebuah penyimpanan
 * I.S. : Alokasi telah belum tersedia
 * F.S. : Alokasi sudah tersedia
 */
address alokasi (info x);

/* Mengubah nilai infix menjadi postfix
 * I.S. : Data masih berupa infix
 * F.S. : Data sudah berbentuk postfix
 */
void pushTree(stack *s, info x, Tnode left, Tnode right);
//void dealokasi (address p);

/* Memasukan data ke dalam stack
 * I.S. : data belum dimasukan ke dalam stack
 * F.S. : Data sudah dimasukkan ke dalam stack
 */
void push (stack *s, info x);

/* Mengeluarkan data dari dalam stack
 * I.S. : data belum dikeluarkan dari dalam stack
 * F.S. : Data sudah dikeluarkan dari dalam stack
 */
void pop (stack *s, address *x);

/* Mengecek apakah stack itu kosong atau tidak 
 * I.S. : Stack kosong belum terdefinisi
 * F.S. : Mengembalikan nilai true ketika stack kosong
 */
boolean IsEmptyStack(stack s);

/* Mengubah nilai infix menjadi postfix
 * I.S. : Data masih berupa infix
 * F.S. : Data sudah berbentuk postfix
 */
void toPostfix (info text, stack s, info *hasil);

/* Mengidentifikasi prioritas dari sebuah operasi
 * I.S. : Operasi belum ada tingkatan prioritas
 * F.S. : Nilai kembalian sesuai dengan definisi
 */
int priority( info x);

/* Untuk mengecek apakah inputan berupa operator atau bukan 
 * I.S. : Pengecekan belum dilakukan
 * F.S. : Mengembalikan nilai true ketika terdefinisi operator
 */
boolean isoperator (info element);
//boolean symop( char x);

/* Memmbuat sebuah tree untuk melakukan operasi
 * I.S. : Tree operasi belum terdefinisi
 * F.S. : Tree operasi sudah terdefinisi
 */
void buildTree(stack s,Tnode *node, info text);
//void Inorder(Tnode node);

/* Menghitung hasil dari bentuk tree
 * I.S. : Operasi Matematika belum terhitung
 * F.S. : mengembalikan hasil dari operasi matematika
 */
int calculate (Tnode root);

/* Mengecek sebuah data valid atau tidak 
 * I.S. : Data belum terdefinisi falid
 * F.S. : Mengembalikan nilai true ketika data valid
 */
boolean isequal(info token,info operator);
#endif


