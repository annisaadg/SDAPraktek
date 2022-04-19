/*
Program : mainque2.c
Author : 211524003 Annisa Dinda Gantini
Kelas : 1A
Deskripsi: Main Kasus Cuci Mobil 4
Tanggal : 16 Maret 2022
*/

#include "Queue2.h"

void ShowMenu();
void kodeMobil();

int main(int argc, char *argv[]) {
	Queue Q;
	CreateQueue(&Q);
	int pilihan;
	int jenis;
	int index;
	int finish;
	CuciMobil M;
	finish = 0;
	ShowMenu();
	do{
		printf("\n\xaf\xaf Enter your preference: ");
		scanf("%d", &pilihan);
		if(pilihan == 1){
			kodeMobil();
			printf("\nType of Car: ");
			scanf("%d", &jenis);
			M = jenisMobil(jenis);		
			printf("Arrival Time: ");
			scanf("%d", &M.arrival);
			printf("\n\n");
			updateTime(&M, Q, finish);	
			finish = M.finish;		
			AddQue(&Q, M);
			index++;
			ShowMenu();	
				
		}
		
		if(pilihan == 2){
			DelQue(&Q, &(info(HEAD(Q))));
			index--;
			printf("\xaf\xaf A Queue of Car Wash Has Been Done\n");	
			system("pause");
			ShowMenu();
		}
		
		if(pilihan == 3){
			printf("\nCar Wash Queue:\n");
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
	printf("===== CAR WASH QUEUE PROGRAM =====");
	printf("\n1] Add car wash queue");
	printf("\n2] Mark as done a car wah queue");
	printf("\n3] Show Queue");
	printf("\n4] Quit");
}

void kodeMobil(){
	printf("\n==========================Tipe Mobil==========================\n");
	printf("(1) Small Car	20 minutes	(Ex: Ceria/Karimun/Agya)\n");
	printf("(2) SUV		30 minutes	(Ex: Avanza)\n");
	printf("(3) SUV-2	45 minutes	(Ex: Innova/CRV/Pajero)\n");
	printf("(4) Mini	60 minutes	(Ex: Alphard, Grand Max)\n");
	printf("(5) Truck-1	80 minutes	(Ex: Angkel)\n");
	printf("(6) Truck-2	100 minutes	(Ex: Truck Normal)\n");
	printf("(7) Truck-3	120 minutes	(Ex: Besar)\n");
	printf("(8) Bus		125 minutes	(Ex: Bus)\n");
}
