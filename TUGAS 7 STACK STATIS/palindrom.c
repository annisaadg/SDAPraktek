/*
Program : palindrom.c
Author : 211524003, Annisa Dinda Gantini
Kelas : 1A
Deskripsi: Body file dari program palindrom
Tanggal : 21 Maret 2022
*/

#include "palindrom.h"

/* Definisi ABSTRACT DATA TYPE POINT *
Stack S;

/******************* Prototype ****************/
/*** Konstruktor/Kreator ***/
void CreateEmpty(Stack *S){
	Top(*S) = Nil;
}
/* T.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosonq berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+l karena O tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
/*********** Predikat Untuk test keadaan KOLEKSI **/
boolean IsEmpty (Stack S){
	return Top(S) == Nil;
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull(Stack S){
	return Top(S) == MaxEl;
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
/*********** Menambahkan sebuah elemen ke Stack **********/
void Push (Stack *S, infopalindrom X){
	if(IsFull(*S)){
		printf("Kata Terlalu Banyak");
		system("pause");
	}else{
		Top(*S) = Top(*S)+1;
		strcpy(InfoTop(*S),X); 
	}
}
/* Menambahkan X sebagai elemen Stack S. */
/* T.S. S mungkin kosong, tabel penampung elemen stack TTDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
/*********** Menqhapus sebuah elemen Stack **********/
void Pop (Stack *S, infopalindrom *X){
	if(IsEmpty(*S)){
		printf("Kata Belum Dimasukkan");
		system("pause");
	}else{
		strcpy(*X,InfoTop(*S));
		Top(*S) = Top(*S)-1;
	}
}
/* Menghapus X dari Stack S. */
/* T.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang l */

void PrintStack(Stack S){
	int i;
	for(i=Top(S); i >=1; i--){
		printf("HURUF: %s\n", S.T[i]);
	}
}
/*Menampilkan nilai-nilai pada Stack S yang diurutkan berdasarkan data yang pertama kali masuk ke stack*/

int CariPalindrom(Stack S, infopalindrom X){
	int i;
	int cek=0;
	for(i=1;i<=MaxEl;i++){
		if(strcmp(S.T[i],X)==0){
			cek=1;
		}
	}
	return cek;
}

int CekPalindrom(Stack S, int jml){
	int i,j;
	int cek=0;
	
	for(i=Top(S); i >=1; i--){
		j=2;
		printf("HURUF: %s\n", S.T[i]);
		printf("HURUF: %s\n", S.T[j]);
		if(strcmp(S.T[i],S.T[j])==0){
			cek=1;
		}else{
			cek=0;
		}
		printf("\n\n");
		printf("A 1: %s\n", S.T[i]);
		printf("A 2: %s\n", S.T[j]);
		system("pause");
		j++;
	}
}
