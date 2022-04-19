/*
Program : list.c
Author : 211524003, Annisa Dinda Gantini
Kelas : 1A
Deskripsi: Header file dari prototype linear linked list
Tanggal : 8/3/2022
*/

#include "boolean.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/* ----- Test List Kosong ----- */
boolean ListEmpty (List L) {
	return (First(L) == Nil); /* Mengirim true jika List Kosong */
}
/* ----- Pembuatan List Kosong ----- */
void CreateList (List *L) {
	/* IS : L sembarang */
	/* FS : Terbentuk List Kosong */
 	First(*L) = Nil;
}
/* ----- Manajemen Memori ----- */
address Alokasi (infotype X) {
 	/* Kamus Lokal */
 	address P;
 	/* Algoritma */
 	P = (address) malloc (sizeof (ElmtList)); /* Mengirimkan address hasil alokasi sebuah elemen */
 	if (P != Nil) { /* Jika alokasi berhasil, maka address != Nil,*/
 		Info(P) = X;
 		Next(P) = Nil; /* dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
 		return P;
 	} else {
 		return Nil; /* Jika alokasi gagal, mengirimkan Nil */
 	}
}
void Dealokasi (address *P) {
	/* IS : P terdefinisi */
	/* FS : P dikembalikan ke sistem */
	/* Melakukan dealokasi / pengembalian address P ke system */
 	free(*P);
}
/* ----- Pencarian Sebuah Elemen List ----- */
address Search (List L, infotype X) {
	/* Mencari apakah ada elemen list dengan Info(P) = X */
	/* Jika ada, mengirimkan address elemen tsb. */
	/* Jika tidak ada, mengirimkan Nil */
	/* Kamus Lokal */
	address P;
 	boolean Found;
 	/* Algoritma */
 	P = First(L);
 	Found = false;
 	while ((P != Nil) && (!Found)) {
 		if (X == Info(P)) {
 			Found = true;
 		} else {
 			P = Next(P);
 		}
 	}
 	return P;
}
boolean FSearch (List L, address P) {
	/* Mencari apakah ada elemen list yang beralamat P */
	/* Mengirimkan true jika ada, false jika tidak ada */
	/* Kamus Lokal */
	address Pcek;
 	boolean ketemu;
 	/* Algoritma */
 	Pcek = First(L);
 	ketemu = false;
 	while ((Pcek != Nil) && (!ketemu)) {
 		if (Pcek == P) {
 			ketemu = true;
 		} else {
 			Pcek = Next(Pcek);
 		}
 	}
	return ketemu;
}
address SearchPrec (List L, infotype X) {
	/* Mengirimkan address elemen sebelum elemen yang nilainya = X */
	/* Mencari apakah ada elemen list dengan Info(P) = X */
	/* Jika ada, mengirimkan address Prec, dengan Next(Prec) = P dan Info(P) = X */
	/* Jika tidak ada, mengirimkan Nil */
	/* Jika P adalah elemen pertama, maka Prec = Nil */
	/* Search dengan spesifikasi seperti ini menghindari */
	/* traversal ulang jika setelah Search akan dilakukan operasi lain */
	/* Kamus Lokal */
 	address P;
 	boolean Found;
 	/* Algoritma */
 	P = First(L);
 	Found = false;
 	if (P == Nil) {
 		return Nil;
 	} else {
 		while ((Next(P) != Nil) && (!Found)) {
 			if (X == Info(Next(P))) {
 				Found = true;
 			} else {
 				P = Next(P);
 			}
 		}
 	}
 	if (Next(P) == Nil) {
 		return Nil;
 	} else {
 		return P;
 	}
}

/* ----- Primitif Berdasarkan Nilai ----- */
/* Penambahan Elemen */
void InsVFirst (List *L, infotype X) {
 	/* Kamus Lokal */
 	address P;
 
 	/* Algoritma */
 	P = Alokasi(X);
 	if (P != Nil) {
 		InsertFirst(L,P);
 	}
}
void InsVLast (List *L, infotype X) {
 	/* Kamus Lokal */
 	address P;
 	/* Algoritma */
 	P = Alokasi(X);
 	if (P != Nil) {
 		InsertLast(L,P);
	}
}
/* Penghapusan ELemen */
void DelVFirst (List *L, infotype *X) {
 	/* Kamus Lokal */
 	address P;
 	/* Algoritma */
 	P = First(*L);
 	(*X) = Info(P);
 	First(*L) = Next(First(*L));
 	Next(P) = Nil;
 	Dealokasi(&P);
}
void DelVLast (List *L, infotype *X) {
 	/* Kamus Lokal */
 	address P;
 	/* Algoritma */
 	DelLast(L,&P);
 	(*X) = Info(P);
 	Dealokasi(&P);
}
/* ----- Primitif Berdasarkan Alamat ------ */
/* Penambahan Elemen Berdasarkan Alamat */
void InsertFirst (List *L, address P) {
 	/* Kamus Lokal */
 	/* Algoritma */
 	Next(P) = First(*L);
 	First(*L) = P;
}	
void InsertAfter (List *L, address P, address Prec) {
 	/* Kamus Lokal */
 	/* Algoritma */
 	Next(P) = Next(Prec);
 	Next(Prec) = P;
}
void InsVAfter (List *L, infotype X, infotype Y) {
    address new = Alokasi(X);
    address P = Search(*L, Y);
    if (new != Nil && Info(P) == Y){
        Next(new) = Next(P);
        Next(P) = new;
    }
}
void InsertLast (List *L, address P) {
 	/* Kamus Lokal */
 	address Last;
 
 	/* Algoritma */
 	Last = First(*L);
 	if (First(*L) == Nil) {
 		InsertFirst(L,P);
 	} else {
 		while (Next(Last) != Nil) {
 			Last = Next(Last);
 		}
 		InsertAfter(L,P,Last);
 	}
}
/* Penghapusan Sebuah Elemen */
void DelFirst (List *L, address *P) {
 	/* Kamus Lokal */
 	/* Algoritma */
 	*P = First(*L);
 	First(*L) = Next(First(*L));
}
void DelP (List *L, infotype X) {
 	/* Kamus Lokal */
 	address P, Prec;
 	infotype Y;
 	/* Algoritma*/
 	P = First(*L);
 	if (Info(P) == X) {
 		DelVFirst(L,&Y);
 	} else {
 		Prec = Nil;
 		while (P != Nil) {
 			if (Info(P) == X) {
 				DelAfter(L,&P,Prec);
 				Dealokasi(&P);
 			} else {
 				Prec = P;
 				P = Next(P);
 			}
 		}
 	}
}
void DelLast (List *L, address *P) {
 	/* Kamus Lokal */
 	address Last, PrecLast;
 	
 	/* Algoritma */
 	Last = First(*L);
 	PrecLast = Nil;
 	while (Next(Last) != Nil) {
 		PrecLast = Last;
 		Last = Next(Last);;
 	}
 	*P = Last;
 	if (PrecLast == Nil) {
 		First(*L) = Nil;
 	} else {
 		Next(PrecLast) = Nil;
 	}
}
void DelAfter (List *L, address *Pdel, address Prec) {
 	/* Kamus Lokal */
 	/* Algoritma */
 	*Pdel = Next(Prec);
 	Next(Prec) = Next(Next(Prec));
 	Next(*Pdel) = Nil;
}	
/* Proses Semua Elemen List */
void PrintInfo (List L) {
 	/* Kamus Lokal */
 	address P;
 	/* Algoritma */
 	P = First(L);
 	if (P == Nil) {
 		printf("List kosong\n");
 	} else {
 		printf("Elemen List: {");
 		while (Next(P) != Nil) {
 			printf("%d,",Info(P));
 			P = Next(P);
 		}
 		printf("%d}\n", Info(P));
 	}
}
int NbElmt (List L) {
 	/* Kamus Lokal */
 	address P;
 	int i;
 	/* Algoritma */
 	i = 0;
	P = First(L);
 	while (P != Nil) {
 		i++;
 		P = Next(P);
 	}
 	return i;
}
/* ----- Proses Terhadap List */
void DelAll (List *L) {
 	/* Kamus Lokal */
 	address P;
 	/* Algoritma */
 	P = First(*L);
 	while (P != Nil) {
		First(*L) = Next(First(*L));
 		Next(P) = Nil;
 		Dealokasi(&P);
 		P = First(*L);
 	}
}
void InversList (List *L) {
 	/* Kamus Lokal */
 	address P, Pt;
 
 	/* Algoritma */
 	P = First(*L);
 	if (P != Nil) {
 		while (Next(P) != Nil) {
 			Pt = Next(P);
 			DelAfter(L,&P,Pt);
 			InsertFirst(L,Pt);
 		}
 	}
}
List FInversList (List L) {
 	/* Kamus Lokal */
 	List Li;
 	address P, Pt;
 	boolean gagal;
 	/* Algoritma */
 	gagal = false;
 	CreateList(&Li);
	P = First(L);
 	while ((P != Nil) && (!gagal)) {
 		Pt = Alokasi(Info(P));
 		if (Pt != Nil) {
 			InsertFirst(&Li, Pt);
 			P = Next(P);
 		} else {
 			DelAll(&Li);
 			gagal = true;
 		}
 	}
 	return Li;
}
