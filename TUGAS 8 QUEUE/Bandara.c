/*
Program : Bandara.c
Author : 211524003 Annisa Dinda Gantini
Kelas : 1A
Deskripsi: Body Kasus Antrian Bandara
Tanggal : 31 Maret 2022
*/

#include "Bandara.h"

//Prototype Queue/ primitif Queue dengan pointer
//Konstruktor
void CreateQueue(Queue *Q){
	HEAD(*Q) = nil;
	TAIL(*Q) = nil;
}

address Alokasi(Bandara x){
	/*Kamus Lokal*/
	ElmQueue *P;
	
	/*Algoritma*/
	P = (ElmQueue*)malloc(sizeof(ElmQueue));
	if(P != nil){
		strcpy(nama(P), x.nama);
		koper(P) = x.koper;
		arrival(P) = x.arrival;
		longque(P) = x.longque;
		finish(P) = x.finish;
		next(P) = nil;
		return P;
	}else{
		return nil;
	}
}

void DeAlokasi(address P){
	free(P);
}

//Operasi Bandara
void updateTime(Bandara *M, Queue Q){
	if(IsQueueEmpty(Q)){
		(*M).longque = 0;	
		(*M).finish = (*M).arrival+((*M).koper*3)+5;
	}else{
		(*M).longque = (*M).finish-(*M).arrival;	
		(*M).finish = (*M).finish+((*M).koper*3)+5;
	}	
}

//Operasi Queue
void AddQue(Queue *Q, Bandara X){
	address p;
	p = Alokasi(X);
	if(!IsQueueEmpty(*Q)){
		next(TAIL(*Q)) = p;
		TAIL(*Q) = next(TAIL(*Q));
	}else{
		HEAD(*Q) = p;
		TAIL(*Q) = p;
	}
}

void DelQue(Queue *Q, Bandara *y){
	address pDel;
	pDel = HEAD(*Q);
	*y = info(pDel);
	if(!next(pDel) == nil){
		HEAD(*Q) = next(pDel);
		next(pDel) = nil;
	}else{
		HEAD(*Q) = nil;
		TAIL(*Q) = nil;
	}
}


//Operasi I/O terhadap Queue
void CetakQueue(Queue Q){
	ElmQueue *P;
	int index=2;
	if(!IsQueueEmpty(Q)){
		P = HEAD(Q);
		printf("1] Nama	: %s\n   Waktu Datang : %d\n   Jumlah Koper : %d\n   Lama Antrian : %d\n   Estimasi Selesai (menit) : %d\n\n", nama(P), arrival(P), koper(P), longque(P), finish(P));
		P = next(P);
		while(P != nil){
			printf("%d] Nama	: %s\n   Waktu Datang : %d\n   Jumlah Koper : %d\n   Lama Antrian : %d\n   Estimasi Selesai (menit) : %d\n\n",index , nama(P), arrival(P), koper(P), longque(P), finish(P));
			P = next(P);
			index++;
		}
	}else{
		printf("\xaf\xaf EMPTY");
	}
}

//Operasi boolean dan relasi terhadap Queue
boolean IsQueueEmpty(Queue Q){
	if(HEAD(Q) == nil){
		return true;
	}else{
		return false;
	}
}
