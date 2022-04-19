/*
Program : Queue.c
Author : 211524003, Annisa Dinda Gantini
Kelas : 1A
Deskripsi: Header file dari prototype Queue linked list
Tanggal : 16 Maret 2022
*/

#include "boolean.h"
#include "Queue.h"
#include <stdio.h>
#include <conio.h>

//Prototype Queue/ primitif Queue dengan pointer
//Konstruktor
void CreateQueue(Queue *Q){
	HEAD(*Q) = nil;
	TAIL(*Q) = nil;
}
address Alokasi(int x){
	address P;
	P = (address) malloc (sizeof(ElmQueue));
	if(P!=nil){
		info(P) = x;
		next(P) = nil;
	}
	return P;
}
void DeAlokasi(address P){
	free(P);
}

//Operasi Queue
void AddQue(Queue *Q, int X){
	address Padd;
	Padd = Alokasi(X);
	if(Padd!=nil){
		if((HEAD(*Q)==nil)&&(TAIL(*Q)==nil)){
			//Queue kosong
			HEAD(*Q) = Padd;
			TAIL(*Q) = Padd;
		}else{
			//Queue tidak kosong
			next(TAIL(*Q)) = Padd;
			TAIL(*Q) = Padd;
		}
	}
}
void DelQue(Queue *Q, int *y){
	address Pdel;
	Pdel = HEAD(*Q);
	*y = info(HEAD(*Q));
	HEAD(*Q) = next(HEAD(*Q));
	DeAlokasi(Pdel);
}

//Operasi I/O terhadap Queue
void CetakQueue(Queue Q){
	ElmQueue *current;
	if(!IsQueueEmpty(Q)){
		current = HEAD(Q);
		printf("%d",info(current));
		while(current!=TAIL(Q)){
			current = next(current);
			printf("-%d", info(current));
		}
		printf("\n");
	}else{
		printf("Attempt to print empty queue failed.\n");
	}
}
//Operasi boolean dan relasi terhadap Queue
boolean IsQueueEmpty(Queue Q){
	return((HEAD(Q)==nil)&&(TAIL(Q)==nil));
}
boolean CariElemenQueue(Queue Q, int X){
	address P;
 	boolean Found;
 	/* Algoritma */
 	P = HEAD(Q);
 	Found = false;
 	while ((P != nil) && (!Found)) {
 		if (X == info(P)) {
 			Found = true;
 			return true;
 		} else {
 			P = next(P);
 		}
 	}
 	return false;
}
/* mengirim true jika elemen x ada pada Q,
dan false jika x tidak ditemukan pada Q
skema pencarian dengan boolean
*/
