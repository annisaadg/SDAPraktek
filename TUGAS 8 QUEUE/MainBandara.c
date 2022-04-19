/*
Program : MainBandara.c
Author : 211524003 Annisa Dinda Gantini
Kelas : 1A
Deskripsi: Main Kasus Antrian Bandara 4
Tanggal : 31 Maret 2022
*/

#include "Bandara.h"

void ShowMenu();

int main(int argc, char *argv[]) {
	Queue Q;
	CreateQueue(&Q);
	int pilihan;
	int index;
	int finish;
	char name[15];
	Bandara M;
	ShowMenu();
	do{
		printf("\n\xaf\xaf Masukkan pilihan: ");
		scanf("%d", &pilihan);
		if(pilihan == 1){
			printf("\nNama: ");
			getchar();
			gets(name);
			strcpy(M.nama,name);		
			printf("Waktu datang: ");
			scanf("%d", &M.arrival);
			printf("Jumlah koper: ");
			scanf("%d", &M.koper);
			printf("\n\n");
			updateTime(&M, Q);	
			finish = M.finish;		
			AddQue(&Q, M);
			index++;
			ShowMenu();	
				
		}
		
		if(pilihan == 2){
			DelQue(&Q, &(info(HEAD(Q))));
			index--;
			printf("\xaf\xaf Satu antrian telah dihapus\n");	
			system("pause");
			ShowMenu();
		}
		
		if(pilihan == 3){
			printf("\nAntrian Bandara:\n");
			CetakQueue(Q);
			printf("======== %d (Queue) ========\n\n", index);
			system("pause");	
			ShowMenu();
		}
		
		if(pilihan == 4){
			return 0;
		}
	}while(pilihan < 4);
}

void ShowMenu(){ 
	system("cls");
	printf("===== PROGRAM ANTRIAN BANDARA =====");
	printf("\n1] Tambah antrian penumpang");
	printf("\n2] Hapus Antrian");
	printf("\n3] Show Queue");
	printf("\n4] Quit");
}

