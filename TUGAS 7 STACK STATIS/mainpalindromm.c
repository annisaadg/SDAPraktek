/*
Program : palindrom.c
Author : 211524003, Annisa Dinda Gantini
Kelas : 1A
Deskripsi: main program palindrom
Tanggal : 21 Maret 2022
*/

#include "parkir4.h"
#include <stdio.h>
#include <string.h>

void ShowMenu(){ 
	system("cls");
	printf("==== PROGRAM CEK PALINDROM ====");
	printf("\n1. Cek Kata 'MALAM'");
	printf("\n2. Cek Kata 'DIA'");
	printf("\n3. Cek Kata 'RADAR'");
}
/*Prosedur untuk menampilkan menu operasi stack*/

int main() {
	/* Menampilkan Menu pada saat program dijalankan */
     ShowMenu(); 
     
	

	/* Membuat Stack */
	Stack s;
	CreateEmpty(&s);

	int pilihan;
	int jml,i;
	char huruf[10];
	do{
		/*Mengambil input piliham menu dari user */
		printf("\nMasukkan Pilihan anda : ");
		scanf("%d", &pilihan);
		getchar();
		
		/* Jika user memilih menu Push */
		if(pilihan == 2){
			Push(&s," ");
			Push(&s,"D");
			Push(&s,"I");
			Push(&s,"A");
			printf("\nKata :\n");
			if(CekPalindrom(s,3)==0){
				printf("\nOops, kata DIA bukan palindrom\n");
			}else if(CekPalindrom(s,3)==1){
				printf("\nYa, kata DIA adalah palindrom\n");
			}
			
			system("pause");
			
			/* Tampilkan menu lagi */
			ShowMenu();
		}
		
		if(pilihan == 1){
			Push(&s," ");
			Push(&s,"M");
			Push(&s,"A");
			Push(&s,"L");
			Push(&s,"A");
			Push(&s,"M");
			printf("\nKata :\n");
			if(CekPalindrom(s,5)==0){
				printf("\nOops, kata MALAM bukan palindrom\n");
			}else if(CekPalindrom(s,5)==1){
				printf("\nYa, kata MALAM adalah palindrom\n");
			}
			
			system("pause");
			
			/* Tampilkan menu lagi */
			ShowMenu();
		}
		
		if(pilihan == 3){
			Push(&s," ");
			Push(&s,"R");
			Push(&s,"A");
			Push(&s,"D");
			Push(&s,"A");
			Push(&s,"R");
			printf("\nKata :\n");
			if(CekPalindrom(s,5)==0){
				printf("\nOops, kata RADAR bukan palindrom\n");
			}else if(CekPalindrom(s,5)==1){
				printf("\nYa, kata RADAR adalah palindrom\n");
			}
			
			system("pause");
			
			/* Tampilkan menu lagi */
			ShowMenu();
		}
		
	}while(pilihan < 5);
	
	return 0;
}

