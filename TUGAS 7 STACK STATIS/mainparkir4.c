/* File main.c untuk Main Driver ADT Stack */ 

#include "parkir4.h"
#include <stdio.h>
#include <string.h>

void ShowMenu(){ 
	system("cls");
	printf("==== PROGRAM PARKIR MOBIL ====");
	printf("\n1. Masukkan Mobil Ke Lahan Parkir");
	printf("\n2. Keluarkan Mobil");
	printf("\n3. Tampilkan Isi Parkiran");
	printf("\n4. Quit");
}
/*Prosedur untuk menampilkan menu operasi stack*/

int main() {
	/* Menampilkan Menu pada saat program dijalankan */
     ShowMenu(); 
     
	

	/* Membuat Stack */
	Stack s,s2;
	CreateEmpty(&s);
	CreateEmpty(&s2);

	int pilihan;
	char masuk[15];
	char keluar[15];
	char tmp[15];
	do{
		/*Mengambil input piliham menu dari user */
		printf("\nMasukkan Pilihan anda : ");
		scanf("%d", &pilihan);
		getchar();
		
		/* Jika user memilih menu Push */
		if(pilihan == 1){
			/* Ambil input angka dari user */
			printf("Masukkan nilai yang akan dimasukkan ke stack : ");		
			gets(masuk);
			
			/* Push angka ke stack */
			Push(&s, masuk);
			
			/* Tampilkan menu lagi */
			ShowMenu();
		}
		
		if(pilihan == 2){
			if(IsEmpty(s)){
				printf("PARKIRAN KOSONG!!!\n");
			}else{
				pop:
				system("cls");
				printf("\nDaftar Mobil Yang Terparkir:\n");
				PrintStack(s);
				printf("\nMasukkan Plat Nomor Mobil Yang Akan Dikeluarkan:\n\xaf ");
				gets(keluar);
			
				if(CariMobil(s,keluar)==0){
					printf("\nTidak Ada Mobil Dengan Plat %s\n",keluar);
					system("pause");
					goto pop;
				}
			
				if(strcmp(keluar, InfoTop(s))==0){
					Pop(&s, &(InfoTop(s)));
					printf("Mobil Dengan Plat Nomor %s Berhasil Dikeluarkan\n",keluar);
				}else{
					printf("\nMobil Dengan Plat Nomor %s Tidak Bisa Langsung Keluar.\nBeberapa Mobil Didepannya Harus Dipindahkan Terlebih Dahulu.\n\n", keluar);
					system("pause");
					
					while(strcmp(keluar, InfoTop(s))!=0){
						printf("\n===== MEMASUKKAN MOBIL %s KE AREA SEMENTARA =====\n", InfoTop(s));
						Push(&s2, InfoTop(s));
						Pop(&s, &(InfoTop(s)));
						printf("\xaf Area di Luar Parkiran (Tempat Sementara):\n");
						PrintStack(s2);
						system("pause");
					}
				
					system("cls");
					printf("\n\xaf Area di Luar Parkiran (Tempat Sementara):\n");
					PrintStack(s2);
					printf("\n\xaf Area di Dalam Parkiran:\n");
					PrintStack(s);
					system("pause");
					
					system("cls");
					printf("\n===== MENGELUARKAN MOBIL DENGAN PLAT %s =====",keluar);
					Pop(&s, &(InfoTop(s)));
					printf("\n\xaf Area di Dalam Parkiran:\n");
					PrintStack(s);
					printf("\n\xaf Area di Luar Parkiran:\n");
					if(IsEmpty(s2)){
						printf("\nEMPTY\n");
					}else{
						PrintStack(s2);
					}
					
					printf("\n===== MEMASUKKAN MOBIL DARI AREA SEMENTARA =====");
					while(!IsEmpty(s2)){
						Push(&s, InfoTop(s2));
						printf("\n\xaf Area di Dalam Parkiran:\n");
						PrintStack(s);
						Pop(&s2, &(InfoTop(s2)));
						printf("\n\xaf Area di Luar Parkiran (Tempat Sementara):\n");
						if(IsEmpty(s2)){
							printf("\nEMPTY\n");
						}else{
							PrintStack(s2);
						}
					}
				}
			}
			/* Tampilkan menu lagi */
			system("pause");	
			ShowMenu();
		}
		
		if(pilihan == 3){
			/* Tampilkan isi dari stack */
			printf("\nIsi Parkiran Mobil :\n");
			PrintStack(s);
			
			/* Tampilkan jumlah dari stack */
			printf("\n========== %d (Tumpukan)==========\n\n", Top(s));
			
			/* Tampilkan menu lagi */	
			system("pause");
			ShowMenu();
		}
		
	}while(pilihan < 4);
	
	return 0;
}

