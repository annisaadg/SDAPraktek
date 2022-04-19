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
	printf("\n1. Masukkan Kata");
	printf("\n2. Hapus Kata");
	printf("\n3. Tampilkan Kata");
	printf("\n4. Quit");
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
		if(pilihan == 1){
			/* Ambil input angka dari user */
			printf("\nMasukkan jumlah huruf pada kata (maksimal 10 huruf): ");
			scanf("%d",&jml);
			printf("\nMasukkan huruf dari kata secara berurutan : ");	
			for(i=0; i<=jml; i++){
				printf("\nMasukkan huruf ke-%d : ",i);
				gets(huruf);
				/* Push angka ke stack */
				Push(&s, huruf);
			}	
			printf("\nKata :\n");
			PrintStack(s);
			
			CekPalindrom(s,jml);
			
			/* Tampilkan menu lagi */
			ShowMenu();
		}
		
		if(pilihan == 2){
			if(IsEmpty(s)){
				printf("Tidak ada huruf\n");
			}else{
				while(!IsEmpty(s)){
					int i;
					for(i=Top(s); i >=1; i--){
						Pop(&s, &(InfoTop(s)));
					}
				}
			}
		}
			/* Tampilkan menu lagi */
			system("pause");	
			ShowMenu();
		
		if(pilihan == 3){
			/* Tampilkan isi dari stack */
			printf("\nKata :\n");
			PrintStack(s);
			
			
			/* Tampilkan menu lagi */	
			system("pause");
			ShowMenu();
		}
		
	}while(pilihan < 4);
	
	return 0;
}

