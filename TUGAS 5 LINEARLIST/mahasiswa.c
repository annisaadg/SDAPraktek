/*
 Program : mahasiswa.c
 Author : 211524003, Annisa Dinda Gantini
 Kelas : 1A
 Deskripsi: Header file dari list mahasiswa
 Tanggal : 9/3/2022
*/

#include "boolean.h"
#include "mahasiswa.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

/* Prototype Linear List */
/* Konstruktor membentuk List */
void CreateList(List *L){
	First(*L) = Nil;
}
Mahasiswa CreateMahasiswa(char *nama, int tb){
	Mahasiswa M;
 	M.nama = nama;
 	M.tb = tb;
 	return M;
}

/* Destruktor/Dealokator: */
address Alokasi(Mahasiswa X){
 	Mahasiswa(*P) = (Mahasiswa *)malloc(sizeof(Mahasiswa));
 	if(P != Nil){
  		Nama(P) = X.nama;
  		TinggiBadan(P) = X.tb;
  		Next(P) = Nil;
 	}
 	return P;
}
void DeAlokasi(address *P){
	Next(*P) = Nil;
 	free(*P);
}

/** { KELOMPOK OPERASI Cek Elemen (VALIDATOR) } **/
boolean isListEmpty(List L){
	return(First(L) == Nil);
}
boolean isValid(Mahasiswa M){
	return(M.nama != Nil && M.tb > 0);
}
boolean isEqual(Mahasiswa X, Mahasiswa Y){
	return ((X.tb == Y.tb) && (strcmp(X.nama, Y.nama) == 0));
}

/** { GETTER/SETTER } **/
char* GetName(Mahasiswa M){
	return M.nama;
}
void SetName(Mahasiswa *M, char *nama){
	(*M).nama = nama;
}
int GetTb(Mahasiswa M){
	return M.tb;
}
void SetTb(Mahasiswa *M, int tb){
	(*M).tb = tb;
}

/** {KELOMPOK Interaksi operasi linear list} **/

/**Penambahann Elemen Berdasarkan Nilai**/
void InsVFirst (List *L, Mahasiswa X){
	address P = Alokasi(X);
 	if(P != Nil){
  		InsAFirst(&(*L), P);
 	}
}
void InsVLast (List *L, Mahasiswa X){
	address P = Alokasi(X);
 	address Last;
 	if(P != Nil){
  		InsALast(&(*L), P);
 	}
}
void InsVAfter (List *L, Mahasiswa X, Mahasiswa Y){
	address Pnew = Alokasi(X);
    address P = Search(*L, Y);
    Mahasiswa M;
    M.nama = Nama(P);
    M.tb = TinggiBadan(P);
    if (Pnew != Nil && isEqual(M, Y))
    {
        Next(Pnew) = Next(P);
        Next(P) = Pnew;
    }
}
void InsertSort(List *L, Mahasiswa X){
	address P = First(*L);
 	address Prec = Nil;
 	Mahasiswa Y;
 	while((P != Nil) && strcmp(Nama(P), X.nama) < 0){
 		Prec = P;
  		P = Next(P);
  		Y.nama = Nama(Prec);
  		Y.tb = TinggiBadan(Prec);
 	}
 	if(Prec == Nil){
  		InsVFirst(&(*L), X);
 	}
 	else{
  		InsVAfter(&(*L), X, Y);
 	}
}

/**Penambahann Elemen Berdasarkan Address**/
void InsAFirst(List *L, address P){
	Next(P) = First(*L);
 	First(*L) = P;
}
void InsALast(List *L, address P){
 	address Last;
 
 	Last = First(*L);
 	if(First(*L) == Nil){
  		InsAFirst(&(*L), P);
 	}else{
  		while(Next(Last) != Nil){
   			Last = Next(Last);
  		}
  		InsAAfter(&(*L), P, Last);
 	}
}
void InsAAfter (List * L, address P, address Prec){
	Next(P) = Next(Prec);
 	Next(Prec) = P;
}

/**Pengurangan Elemen Berdasarkan Nilai**/
void DelVFirst (List *L, Mahasiswa *M){
	address P;
 	DelAFirst(L, &P);
 	(*M).nama = Nama(P);
 	(*M).tb = TinggiBadan(P);
 	DeAlokasi(&P);
}
void DelP (List *L, Mahasiswa M){
	address P, Prec;
 	P = Search(*L,M);
 	if(P == First(*L)){
  		DelAFirst(L,&P);
 	}else{
  		Prec = SearchPrec(*L,M);
  		DelAAfter(L,&P,Prec);
 	}
}
void DelVLast (List *L, Mahasiswa *M){
	address P;
 	DelALast(L,&P);
 	(*M).nama = Nama(P);
 	(*M).tb = TinggiBadan(P);
 	DeAlokasi(&P);
}
void DelVAfter (List *L, namaMhs *N, namaMhs M, tinggiBadan *X){
	if(!isListEmpty(*L)) {
        address P = SearchNama(*L, M), pDel = Next(P);
        *N = Nama(pDel);
        *X = TinggiBadan(pDel);
        Next(P) = Next(pDel);
        DeAlokasi(&pDel); 
    }
}
void DelAll (List *L){
	Mahasiswa X;
 	while(!isListEmpty(*L)){ 
 		DelVFirst(L, &X);
 	}
}
void DelEqual(address head){
	address P = head;
	address next;
	
	if (P == Nil) {
		return;
	}
	
	while (Next(P) != Nil) {
		if (strcmp(Nama(P), Nama(Next(P))) == 0) {
			next = Next(Next(P));
			free(Next(P));
			Next(P) = next;
		} else {
			P = Next(P);
		}
	}
}
/**Pengurangan Elemen Berdasarkan Address**/
void DelAFirst (List *L, address * P){
	*P = First(*L);
 	if(Next(*P) != Nil){
  		First(*L) = Next(*P);
  		Next(*P) = Nil;
 	}else{
  		CreateList(&(*L));
 	}
}
void DelALast (List *L, address * P){
	address Last, PrecLast;
 	Last = First(*L);
 	PrecLast = Nil;
 	while(Next(Last) != Nil){
  		PrecLast = Last;
  		Last = Next(Last);
 	}
 	*P = Last;
 	if(PrecLast == Nil){
  		First(*L) = Nil;
 	}else{
  		Next(PrecLast) = Nil;
 	}
}
void DelAAfter (List * L, address * Pdel, address Prec){
	*Pdel = Next(Prec);
 	Next(Prec) = Next(*Pdel);
 	Next(*Pdel) = Nil;
}
/*Menampilkan Elemen*/
void PrintMahasiswa(Mahasiswa M){
	printf("(%s, %d) ", GetName(M), GetTb(M));
	printf("\n");
}
void PrintInfo (List L){
	int i=0;
 	address P = First(L);
 	Mahasiswa M;
 	if(isListEmpty(L)){
  		printf("{}");
 	}
 	else{
  		printf("{\n");
  		do{
   			M.nama = Nama(P);
   			M.tb = TinggiBadan(P);
   			PrintMahasiswa(M);
   			P = Next(P);
   			i++;
  		}while(P != Nil);
  		printf("}");
 	}
}

/** KELOMPOK OPERASI LAIN TERHADAP TYPE **/
/* Operasi pencarian */
address Search (List L, Mahasiswa X){
	address P;
 	boolean found; 
 	P = First(L);
 	found = false;
 	while((P != Nil) && (!found)){
  		if((strcmp(Nama(P), X.nama)) == 0 && TinggiBadan(P) == X.tb){
   			found = true;
  		}
  		else{
   			P = Next(P);
  		}
 	}
 	return P;
}
address SearchNama (List L, namaMhs N){
	while(First(L) != Nil) {
        if(Nama(First(L)) == N) {
            return First(L);
        }
        First(L) = Next(First(L));
    }
    return Nil;
}
address SearchPrec (List L, Mahasiswa X){
	address P;
 	boolean found;
 	P = First(L);
 	found = false;
 	if(P == Nil){
  		return Nil;
 	}else{
  		while((Next(P) != Nil) && !found){
   			if(X.nama == Nama(Next(P)) && X.tb == TinggiBadan(Next(P))){
    			found = true;
   			}else{
    			P = Next(P);
   			}
  		}
 	}
 	if(Next(P) == Nil){
  		return Nil;
 	}else{
  		return P;
 	}
}

int NbElmt (List L){
	address P;
 	int N = 0;
 	if(!isListEmpty(L)){
  		P = First(L);
  		do{
   			N++;
   			P = Next(P);
  		}while(P != Nil);
 	}
 	return N;
}
List NewList (List L, int Tb){

	List result;
    boolean error = false;
    address P;
    address X;
    Mahasiswa M;

    CreateList(&result);
    P = First(L);
 
    while(!error && P != Nil) {
    	M.nama = Nama(P);
  		M.tb = TinggiBadan(P);
        X = Alokasi(M);
        
        if (X == Nil) {
            error = true;
        } else if (TinggiBadan(P) > Tb) {
            InsALast(&result, X);
            P = Next(P);
        }else{
        	P = Next(P);
  		}
	}

    if (error) {
        DelAll(&result);
    }
    return result;
}
