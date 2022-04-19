/*
Program : Bandara.h
Author : 211524003, Annisa Dinda Gantini
Kelas : 1A
Deskripsi: Header Bandara 
Tanggal : 31 Maret 2022
*/
#ifndef _BANDARA_H
#define _BANDARA_H
#include "boolean.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//pendefinisian pointer
#define nil NULL
#define info(P) (P)->info
#define nama(P) (P)->info.nama
#define koper(P) (P)->info.koper
#define arrival(P) (P)->info.arrival
#define longque(P) (P)->info.longque
#define finish(P) (P)->info.finish
#define next(P) (P)->next
#define HEAD(Q) (Q).HEAD
#define TAIL(Q) (Q).TAIL

//Pembentukan tipe Queue
typedef struct{
	char nama[12];
	int koper; //timesize
	int arrival;
	int longque;
	int finish;
} Bandara;
typedef struct tElmQueue *address;
typedef struct tElmQueue{
	Bandara info;
	address next;
}ElmQueue;
typedef struct{
	address HEAD;
	address TAIL;
}Queue;

//Prototype Queue/ primitif Queue dengan pointer
//Konstruktor
void CreateQueue(Queue *Q);
/* I.S : Q terdefinisi tidak diketahui isinya
F.S : Q diinisialisasi dengan HEAD(Q)=nil, TAIL(Q)=nil
*/
address Alokasi(Bandara x);
/* mengirim sebuah address jika alokasi type Queue berhasil */
void DeAlokasi(address P);
/* P direlease dari memori */
void updateTime(Bandara *M, Queue Q);
/* Update waktu antrian yang masuk 
*/
//Operasi Queue
void AddQue(Queue *Q, Bandara X);
/* I.S : Q terdefinisi sembarang mungkin kosong
F.S : Q bertambah sebuah elemen bernilai X dibelakang
proses : HEAD (Q) merupakan elemen terakhir dari Q
*/
void DelQue(Queue *Q, Bandara*y);
/* I.S : Q terdefinisi sembarang tidak kosong
F.S : Q berkurang satu elemen didepan disimpan pada y
proses : y=info(HEAD), HEAD(Q) = next(HEAD(Q))
DeAlokasi elemen pertama

*/
//Operasi I/O terhadap Queue
void CetakQueue(Queue Q);
/* I.S : Q terdefinisi sembarang tidak kosong
F.S : elemen Queue dicetak dilayar
*/
//Operasi boolean dan relasi terhadap Queue
boolean IsQueueEmpty(Queue Q);
/* Mengirim true jika Queue kosong HEAD(Q)=nil
false sebaliknya */

#endif
