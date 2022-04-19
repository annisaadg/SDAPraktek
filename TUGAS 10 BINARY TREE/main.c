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
   			printf("\nDAFTAR PEGAWAI :\n");
   			cekEmpty(&T);
   			inOrder(Root(T));
   			system("pause");
   			showMenu();
   			break;
  		case 2:
  			insertPegawai(&T,45,"Dhika Putra");
 			insertPegawai(&T,87,"Chandra Diva");
 			insertPegawai(&T,65,"Abdullah Ahugrah");
 			insertPegawai(&T,39,"Bayu Virani");
 			insertPegawai(&T,92,"Chaerul Ardina");
 			insertPegawai(&T,88,"Fikri Syabantika");
 			insertPegawai(&T,73,"Christian Dayanti");
 			insertPegawai(&T,58,"Haris Anjani");
 			insertPegawai(&T,47,"Aprian Amalina");
 			insertPegawai(&T,62,"Doni Assodiqin");
 			insertPegawai(&T,59,"Marvel Tilasnuari");
	 		insertPegawai(&T,64,"Hilman Ardiansyah");
 			insertPegawai(&T,11,"Izhar Subekti");
 			insertPegawai(&T,41,"Mustofa Sabri");
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
   			printf("\n");
  		 	printf("Masukkan ID Pegawai yang Akan Dihapus: ");
   			scanf("%d",&id);
   			deletePegawai(&T, id);
   			system("pause");
   			showMenu();
   			break;
   		case 5:
   			printf("Masukkan Nama Pegawai : ");
   			getchar();
   			gets(nama);
   			printf("Masukkan ID Pegawai : ");
   			scanf("%d",&id);
   			insertPegawai(&T,id,nama);
   			system("pause");
   			showMenu();
   			break;
 		}
	 }while(pilih<6);
 	return 0;
}

void showMenu() {
	home:
	system("cls");
 	printf("============= PROGRAM DATA PEGAWAI =============\n");
 	printf("1] Menampilkan Seluruh Data Pegawai\n");
 	printf("2] Menambah 14 Data Pegawai Dari Deskripsi Kasus\n");
 	printf("3] Mencari Data Pegawai berdasarkan ID dan \n");
 	printf("   Menampikan Data Pegawainya\n");
 	printf("4] Menghapus Data Pegawai berdasarkan ID\n");
 	printf("5] Menambah Data Pegawai Baru \n");
 	printf("6] Quit\n");
 	printf("================================================\n");
 	printf("Masukkan Pilihanmu : ");
 	scanf("%d",&pilih);
 	if(pilih<1 || pilih>6){
 		printf("Mohon maaf opsi menu salah\n");
 		system("pause");
 		goto home;
	 }
}
