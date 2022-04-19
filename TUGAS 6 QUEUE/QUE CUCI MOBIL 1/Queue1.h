/*
Program : Queue1.h
Author : 211524003 Annisa Dinda Gantini
Kelas : 1A
Deskripsi: Header Kasus Cuci Mobil 3
Tanggal : 15 Maret 2022
*/

#ifndef _QUEUE1_H
#define _QUEUE1_H
#include "boolean.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

//pendefinisian pointer
#define nil NULL
#define info(P) (P)->info
#define nama(P) (P)->info.nama
#define timeSize(P) (P)->info.time_size
#define arrival(P) (P)->info.arrival
#define service(P) (P)->info.service
#define finish(P) (P)->info.finish
#define next(P) (P)->next
#define HEAD(Q) (Q).HEAD
#define TAIL(Q) (Q).TAIL

//Pembentukan tipe Queue dan struct MOBIL
typedef struct tElmQueue *address;
typedef struct{
	char nama[20];
	int time_size;
	int arrival;
	int service;
	int finish;
} CuciMobil;
typedef struct tElmQueue{
	CuciMobil info;
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
address Alokasi(CuciMobil x);
/* mengirim sebuah address jika alokasi type Queue berhasil */
void DeAlokasi(address P);
/* P direlease dari memori */

//Operasi CuciMobil
CuciMobil jenisMobil(int mobil);
/* Penentuan jenis mobil berdasarkan kode dengan return CuciMobil 
*/
void updateTime(CuciMobil *M, Queue Q, int finish);
/* Update waktu antrian yang masuk 
*/

//Operasi Queue
void AddQue(Queue *Q, CuciMobil X);
/* I.S : Q terdefinisi sembarang mungkin kosong
F.S : Q bertambah sebuah elemen bernilai X dibelakang
proses : HEAD (Q) merupakan elemen terakhir dari Q
*/
void DelQue(Queue *Q, CuciMobil*y);
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
