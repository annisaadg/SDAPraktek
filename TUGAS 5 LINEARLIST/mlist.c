/*
Program : mlist.c
Author : 211524003, Annisa Dinda Gantini
Kelas : 1A
Deskripsi: Header file dari prototype linear linked list
Tanggal : 8/3/2022
*/

#include "list.h"
#include "boolean.h"
#include <stdio.h>
/* ----- Header Prosedur / Fungsi */
void Menu();
/* I.S. Layar kosong
F.S. Layar tertulis menu-menu yang disediakan */
/* ----- Program Utama ----- */

List L1,Lt;
	address P,Prec;
	int opt; /* untuk pilihan menu */
	infotype X; /* untuk pencarian alamat elemen dan penambahan elemen */
	infotype Y,Z; /* untuk penguraman elemen */

int main () {
	/* Kamus Lokal */
	
	boolean exit; 
	float average;
	/* Algoritma */
	exit = false;
	do {
		Menu();
 		scanf("%d",&opt);
 		switch (opt) {
 		case 1 : 
		 	CreateList(&L1);
			PrintInfo(L1);
			printf(" \n\xaf\xaf LIST BERHASIL DIBUAT!");
 			break;
 		case 2 : 
		 	printf("Elemen masukan: "); scanf("%d",&X);
 			printf("\nSetelah elemen: "); scanf("%d",&Y);
 			printf("\Sebelum elemen: "); scanf("%d",&Z);
 			InsVAfter(&L1,X,Y);
 			PrintInfo(L1);
 			break;
 		case 3 : 
		 	printf("Elemen : ");
 			scanf("%d",&X);
 			InsVFirst(&L1,X);
 			PrintInfo(L1);
 			break;
 		case 4 : 
		 	printf("Elemen : ");
 			scanf("%d",&X);
 			InsVLast(&L1,X);
 			PrintInfo(L1);
	 		break;
 		case 5 : 
 			DelVFirst(&L1,&Y);
 			break;
 			printf("Elemen yang dihapus : %d\n",Y);
 			PrintInfo(L1);
			break;
 		case 6 : 
			DelVLast(&L1,&Y);
 			break;
			printf("Elemen yang dihapus : %d\n",Y);
		 	PrintInfo(L1);
			break;
 		case 7 : 
			printf("Elemen : ");
 			scanf("%d",&Y);
 			DelP(&L1,Y);
 			PrintInfo(L1);
			break;
 		case 8 : 
			PrintInfo(L1);
 			break;
 		case 9 : 
 			DelAll(&L1);
 			PrintInfo(L1);
 			break;
 		case 10 : 
		 	exit = true; 
			break;
 		}
 		system("pause");
	} while (!exit);
	DelAll(&L1);
return 0;
}
/* ----- Implementasi Prosedur / Fungsi ----- */
void Menu() {
/* Kamus Lokal */
/* Algoritma */
system("cls");
printf("------ Menu ------\n\n");
printf(" 1.	Membuat List\n");
printf(" 2.	Memasukkan Suatu Elemen pada Suatu Posisi List\n");
printf(" 3.	Memasukkan Suatu Elemen pada Depan List\n");
printf(" 4.	Memasukkan Suatu Elemen pada Belakang List\n");
printf(" 5.	Menghapus Elemen yang Berada di Depan List\n");
printf(" 6.	Menghapus Elemen yang Berada di Belakang List\n");
printf(" 7.	Menghapus Alamat Sesuai dengan Elemen yang Ditentukan\n");
printf(" 8.	Tulis Isi List\n");
printf(" 9.	Menghapus Seluruh Elemen\n");
printf(" 10.	Exit\n");
printf("\n\xaf\xaf Pilihan : ");
}

