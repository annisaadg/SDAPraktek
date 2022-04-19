#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void showMenu();
int pilih;

int main(int argc, char *argv[]) {
	Tree T;
 	address temp;

 	initTree(&T);
 
 	showMenu();
 	char nama[20];
 	int id;
 	do{
 		switch(pilih){
  		case 1:
   			printf("Masukkan Nama Pegawai : ");
   			getchar();
   			gets(nama);
   			printf("Masukkan ID Pegawai : ");
   			scanf("%d",&id);
   			insertNode(&T,id,nama);
   			printf("\nDAFTAR PEGAWAI:\n");
   			inOrder(Root(T));
   			system("pause");
   			showMenu();
   			break;
  		case 2:
  			printf("\nDAFTAR PEGAWAI:\n");
   			inOrder(Root(T));
   			printf("\n");
  		 	printf("Masukkan ID Pegawai yang Akan Dihapus: ");
   			scanf("%d",&id);
   			deletePegawai(&T, id);
   			printf("\nDAFTAR PEGAWAI SEKARANG:\n");
   			inOrder(Root(T));
   			system("pause");
   			showMenu();
   			break;
   		case 3:
   			printf("Masukkan ID Pegawai yang Akan Dicari: ");
   			scanf("%d",&id);
   			searchPegawai(T, id);
   			system("pause");
   			showMenu();
   			break;
   		case 4:
   			insertNode(&T,45,"Dhika Putra");
 			insertNode(&T,87,"Chandra Diva");
 			insertNode(&T,65,"Abdullah Ahugrah");
 			insertNode(&T,39,"Bayu Virani");
 			insertNode(&T,92,"Chaerul Ardina");
 			insertNode(&T,88,"Fikri Syabantika");
 			insertNode(&T,73,"Christian Dayanti");
 			insertNode(&T,58,"Haris Anjani");
 			insertNode(&T,47,"Aprian Amalina");
 			insertNode(&T,62,"Doni Assodiqin");
 			insertNode(&T,59,"Marvel Tilasnuari");
	 		insertNode(&T,64,"Hilman Ardiansyah");
 			insertNode(&T,11,"Izhar Subekti");
 			insertNode(&T,41,"Mustofa Sabri");
 			printf("\nDAFTAR PEGAWAI SEKARANG:\n");
			inOrder(Root(T));
			system("pause");
   			showMenu();
   			break;
 		}
	 }while(pilih<5);
 	return 0;
}

void showMenu() {
	system("cls");
 	printf("============= PROGRAM DATA PEGAWAI =============\n");
 	printf("1] Menambah Data Pegawai Baru dan Menampilkan\n");
 	printf("   Seluruh Data Pegawai\n");
 	printf("2] Menghapus Data Pegawai berdasarkan ID dan\n");
 	printf("   Menampikan Seluruh Data Pegawai\n");
 	printf("3] Mencari Data Pegawai berdasarkan ID dan \n");
 	printf("   Menampikan Seluruh Data Pegawai\n");
 	printf("4] Menambah 14 Data Pegawai Dari Deskripsi Kasus\n");
 	printf("5] Quit\n");
 	printf("================================================\n");
 	printf("Masukkan Pilihanmu : ");
 	scanf("%d",&pilih);
}
