#include <stdio.h>
#include <stdlib.h>
#include "bintreeAVL.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void ShowMenu(){ 
	printf("======== Data Pegawai ========");
	printf("\n1. Tambah Data Pegawai");
	printf("\n2. Print Data Pegawai");
	printf("\n3. Hapus Data Pegawai");
	printf("\n4. Cari Data Pegawai");
	printf("\n\n0. Quit\n");
}

int main(int argc, char *argv[]) {
	BinTree tree;
	BinTree forSearch;
	CreateEmpty(&tree);
	tree = AddDaun(tree, 45, "Dhika Putra");
	tree = AddDaun(tree, 87, "Chandra Diva");
	tree = AddDaun(tree, 65, "Abdullah Ahugrah");
	tree = AddDaun(tree, 39, "Bayu Virani");
	tree = AddDaun(tree, 92, "Chaerul Ardina");
	tree = AddDaun(tree, 88, "Fikri Syabantika");
	tree = AddDaun(tree, 73, "Christian Dayanti");
	tree = AddDaun(tree, 58, "Haris Anjani");
	tree = AddDaun(tree, 47, "Aprian Amalina");
	tree = AddDaun(tree, 62, "Doni Assodiqin");
	tree = AddDaun(tree, 59, "Marvel Tilasnuari");
	tree = AddDaun(tree, 64, "Hilman Ardiansyah");
	tree = AddDaun(tree, 11, "Izhar Subekti");
	tree = AddDaun(tree, 41, "Mustofa Sabri");
	system("cls");
	ShowMenu();
	int pilihan, id;
	char nama[50];
	do{
		/*Mengambil input piliham menu dari user */
		printf("\nMasukkan Pilihan anda : ");
		scanf("%d", &pilihan);
		
		/* Jika user memilih menu Push */
		if(pilihan == 1){
			system("cls");
			printf("Masukan ID Pegawai: ");		
			scanf("%d", &id);
			getchar();
			printf("Masukan Nama Pegawai: ");	
			gets(nama);
			system("cls");
			
			AddDaun(tree, id, nama);
			if (SearchNode(tree, id) != Nil){
				printf("Penambahan berhasil dilakukan!\n\n");
			}
			ShowMenu();
		}
		
		if(pilihan == 2){
			system("cls");
			printf("============= Data Pegawai =============");	
			if (IsEmptyTree(tree)){
				printf("\nData Pegawai Kosong");
			} else {
				PrintInorder(tree);
			}
			
			printf("\n\n");	
			ShowMenu();
		}
		
		if(pilihan == 3){
			system("cls");
			printf("Masukan ID Pegawai: ");		
			scanf("%d", &id);
			system("cls");
			tree = DeleteNode(tree, id);	
			ShowMenu();
		}
		
		if(pilihan == 4){
			system("cls");
			printf("Masukan ID Pegawai: ");		
			scanf("%d", &id);
			system("cls");
			findPrint(tree, id);
			printf("\n\n");	
			ShowMenu();
		}
		
		if (pilihan<0 || pilihan>4){
			system("cls");
			printf("Mohon maaf opsi menu salah. Silahkan ulangi lagi\n\n");
			ShowMenu();
		}
		
	}while(pilihan != 0);
}
