/*
Program : Queue2.c
Author : 211524003 Annisa Dinda Gantini
Kelas : 1A
Deskripsi: Body Kasus Cuci Mobil 4
Tanggal : 16 Maret 2022
*/

#include "Queue2.h"

//Prototype Queue/ primitif Queue dengan pointer
//Konstruktor
void CreateQueue(Queue *Q){
	HEAD(*Q) = nil;
	TAIL(*Q) = nil;
}

address Alokasi(CuciMobil x){
	/*Kamus Lokal*/
	ElmQueue *P;
	
	/*Algoritma*/
	P = (ElmQueue*)malloc(sizeof(ElmQueue));
	if(P != nil){
		strcpy(nama(P), x.nama);
		timeSize(P) = x.timeSize;
		arrival(P) = x.arrival;
		service(P) = x.service;
		finish(P) = x.finish;
		breaktime(P) = x.breaktime;
		next(P) = nil;
		return P;
	}else{
		return nil;
	}
}

void DeAlokasi(address P){
	free(P);
}

//Operasi CuciMobil
void updateTime(CuciMobil *M, Queue Q, int finish){
	if(IsQueueEmpty(Q)){
		(*M).service = 0;
		(*M).finish = 0;	
		(*M).service = finish;
		(*M).finish = (*M).timeSize+(*M).service;
	}else{
		(*M).service = 0;
		(*M).finish = 0;	
		(*M).service = finish+ (*M).breaktime ;
		(*M).finish = (*M).timeSize+(*M).service;
	}	
}

CuciMobil jenisMobil(int jenis){
	CuciMobil X;
	switch(jenis){
		case 1:
			strcpy(X.nama,"Mobil kecil");
			X.breaktime = 1;
			X.timeSize = 20;
			
			break;
		case 2:
			strcpy(X.nama, "SUV");
			X.breaktime = 2;
			X.timeSize = 30;
			
			break;
		case 3:
			strcpy(X.nama, "SUV-2");
			X.breaktime = 4;
			X.timeSize = 45;
			
			break;
		case 4:
			strcpy(X.nama, "Mini");
			X.breaktime = 5;
			X.timeSize = 60;
			
			break;			
		case 5:
			strcpy(X.nama, "Truck-1");
			X.breaktime = 6;
			X.timeSize = 80;
			
			break;
		case 6:
			strcpy(X.nama, "Truck-2");
			X.breaktime = 8;
			X.timeSize = 100;
			
			break;
		case 7:
			strcpy(X.nama, "Truck-3");
			X.breaktime = 9;
			X.timeSize = 120;
			
			break;
		case 8:
			strcpy(X.nama, "Bus");
			X.breaktime = 10;
			X.timeSize = 125;
			break;
	}
	return X;
}

//Operasi Queue
void AddQue(Queue *Q, CuciMobil X){
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

void DelQue(Queue *Q, CuciMobil *y){
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
		printf("1] Jenis	: %s\n   Time Size	: %d\n   Arrival	: %d\n   Service	: %d\n   Finish	: %d\n\n", nama(P), timeSize(P), arrival(P), service(P), finish(P));
		P = next(P);
		while(P != nil){
			printf("%d] Jenis	: %s\n   Time Size	: %d\n   Arrival	: %d\n   Service	: %d\n   Finish	: %d\n\n",index , nama(P), timeSize(P), arrival(P), service(P), finish(P));
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
