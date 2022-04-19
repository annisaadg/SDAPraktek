/*
 Program : mainmahasiswa.c
 Author : 211524003, Annisa Dinda Gantini
 Deskripsi: main driver dari list mahasiswa
 Tanggal : 9/3/2022
*/

#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include<string.h>
#include "mahasiswa.h"
#include "boolean.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void menu();
int main(int argc, char *argv[]) {
	Mahasiswa M;
   	List L;
   	char *nama;
   	int tb;
   	int banyak,i=0;
  
   	List L1, L2; 
   	printf("===== PEMBUATAN LIST KOSONG =====\n");
   	CreateList(&L1);
   	CreateList(&L2);
 
   	printf("List kosong");
   	printf("\nList 1 = ");
   	PrintInfo(L1);
   	printf("\nList 2 = ");
   	PrintInfo(L2);
   
   	//Mahasiswa 1
   	nama = "Aldy";
   	tb = 180; 
   	M = CreateMahasiswa(nama, tb);
   	InsertSort(&L1, M);
 
   	//Mahasiswa 2
   	nama = "Annisa";
   	tb = 168; 
   	M = CreateMahasiswa(nama, tb);
   	InsertSort(&L1, M);
 	
   	//Mahasiswa 3
  	nama = "Aruna";
   	tb = 167; 
   	M = CreateMahasiswa(nama, tb);
   	InsertSort(&L1, M);
   
   	//Mahasiswa 4
  	nama = "Dzulfikar";
   	tb = 170; 
   	M = CreateMahasiswa(nama, tb);
   	InsertSort(&L1, M);
   
   	//Mahasiswa 5
  	nama = "Faishal";
   	tb = 165; 
   	M = CreateMahasiswa(nama, tb);
   	InsertSort(&L1, M);
   
   	//Mahasiswa 6
  	nama = "Hasna";
   	tb = 160; 
   	M = CreateMahasiswa(nama, tb);
   	InsertSort(&L1, M);
   
   	//Mahasiswa 7
  	nama = "Irnanda";
   	tb = 165; 
   	M = CreateMahasiswa(nama, tb);
   	InsertSort(&L1, M);
   
   	//Mahasiswa 8
  	nama = "MAldizar";
   	tb = 181; 
   	M = CreateMahasiswa(nama, tb);
   	InsertSort(&L1, M);
   
   	//Mahasiswa 9
  	nama = "Mahdi";
   	tb = 185; 
   	M = CreateMahasiswa(nama, tb);
   	InsertSort(&L1, M);
   
   	//Mahasiswa 10
  	nama = "Nasya";
   	tb = 165; 
   	M = CreateMahasiswa(nama, tb);
   	InsertSort(&L1, M);
   
   	//Mahasiswa 11
  	nama = "Ridha";
   	tb = 163; 
   	M = CreateMahasiswa(nama, tb);
   	InsertSort(&L1, M);
   
   	//Mahasiswa 12
  	nama = "Satriyo";
   	tb = 182; 
   	M = CreateMahasiswa(nama, tb);
   	InsertSort(&L1, M);
   
   	//Mahasiswa 13
  	nama = "Tiara";
   	tb = 176; 
   	M = CreateMahasiswa(nama, tb);
   	InsertSort(&L1, M);
   
   	//Mahasiswa 14
  	nama = "Yane";
   	tb = 155; 
   	M = CreateMahasiswa(nama, tb);
   	InsertSort(&L1, M);
   
   	//Mahasiswa 15
  	nama = "Yasmin";
   	tb = 169; 
   	M = CreateMahasiswa(nama, tb);
   	InsertSort(&L1, M);
   	
   	//Mahasiswa 16
  	nama = "Yasmin";
   	tb = 152; 
   	M = CreateMahasiswa(nama, tb);
   	InsertSort(&L1, M);
   	
   	//Mahasiswa 17
  	nama = "Yasmin";
   	tb = 167; 
   	M = CreateMahasiswa(nama, tb);
   	InsertSort(&L1, M);
   	
   	//Mahasiswa 18
  	nama = "Yasmin";
   	tb = 169; 
   	M = CreateMahasiswa(nama, tb);
   	InsertSort(&L1, M);
   
  	
   	printf("\n\n===== ISI LIST 1 =====");
   	printf("\xaf\xaf List 1 = \n");
	PrintInfo(L1);
 
   	printf("\n\xaf\xaf Jumlah Elemen List L1: %d\n", NbElmt(L1));
  
   	L2 = NewList(L1,170); //Menyalin List L1 yang dengan data tinggi > 170 ke List L2
 
   	printf("\n===== ISI LIST 2=====");
   	printf("\n\xaf\xaf List 2 = ");
   	PrintInfo(L2);
 
   	DelEqual(First(L1)); //Menghapus data duplikat pada List L1
 
   	printf("\n\n=====ISI LIST 1 YANG BARU=====");
   	printf("\nList 1 = ");
   	PrintInfo(L1);
 
   	printf("\n\n=====MENGHAPUS LIST 1 DAN LIST 2=====");
   	DelAll(&L1);
   	DelAll(&L2);
   	printf("\nList 1 = ");
   	PrintInfo(L1);
   	printf("\nList 2 = ");
   	PrintInfo(L2);
 
   	return 0;
}
