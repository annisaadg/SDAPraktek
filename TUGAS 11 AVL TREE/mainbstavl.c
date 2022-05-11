#include "bstavl.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void showFirst();
void showMenu();
int pilih,choice;

int main(int argc, char *argv[]) {
	Tree T;
 	address temp;

 	initTree(&T);
 
 	showFirst();
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
   			if(choice==1){
   				insertPegawai(&T,id,nama);
			   }
			   else if(choice==2){
			   	insertAVL(&T,id,nama);
			   }
   			printf("\n");
   			system("pause");
   			showMenu();
   			break;
  		case 2:
  			if((Root(T)) != Nil){
	  		 	printf("Masukkan ID Pegawai yang Akan Dihapus: ");
	   			scanf("%d",&id);
	   			if(choice==1){
   					deletePegawai(&T,id);
			   		}
			   		else if(choice=2){
			   			deleteNodeAVL(&T,id);
			   		}
			}
			else{
				printf("\nData kosong, tidak ada data yang bisa dihapus!\n");
			}
   			printf("\n");
   			system("pause");
   			showMenu();
   			break;
   		case 3:
   			printf("Masukkan ID Pegawai yang Akan Dicari: ");
   			scanf("%d",&id);
   			searchPegawai(T, id);
   			printf("\n");
   			system("pause");
   			showMenu();
   			break;
   		case 4:
   			printf("\nDAFTAR PEGAWAI:\n\n");
   			printPegawaiInorder(Root(T));
   			printf("\n");
   			system("pause");
   			showMenu();
   			break;
   		case 5:
   			printf("\nDAFTAR PEGAWAI:\n\n");
   			printPegawaiPreorder(Root(T));
   			printf("\n");
   			system("pause");
   			showMenu();
   			break;
   		case 6:
   			/*
   			printf("\nDAFTAR PEGAWAI:\n\n");
   			if(&T == Nil){
			printf("Data pegawai Kosong!\n\n");
			}
			else{
				postOrder(Root(T));
			}
   			printf("\n");
   			system("pause");
   			*/
   			showMenu();
   			break;
   		case 7:
   			if(choice==1){
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
			   }else if(choice==2){
			   		insertAVL(&T,45,"Dhika Putra");
 					insertAVL(&T,87,"Chandra Diva");
 					insertAVL(&T,65,"Abdullah Ahugrah");
 					insertAVL(&T,39,"Bayu Virani");
 					insertAVL(&T,92,"Chaerul Ardina");
 					insertAVL(&T,88,"Fikri Syabantika");
 					insertAVL(&T,73,"Christian Dayanti");
 					insertAVL(&T,58,"Haris Anjani");
 					insertAVL(&T,47,"Aprian Amalina");
 					insertAVL(&T,62,"Doni Assodiqin");
 					insertAVL(&T,59,"Marvel Tilasnuari");
	 				insertAVL(&T,64,"Hilman Ardiansyah");
 					insertAVL(&T,11,"Izhar Subekti");
 					insertAVL(&T,41,"Mustofa Sabri");
			   }
			printf("\n");
   			system("pause");
   			showMenu();
   			break;
   		case 8:
   			deleteTree(&T);
   			printf("\nSeluruh data pegawai berhasil dihapus\n\n");
   			system("pause");
   			showMenu();
   			break;
   		case 9:
   			printf("bye!");
   			break;
		default:
			printf("\nMohon maaf opsi menu salah. Silakan ulangi lagi\n\n");
			system("pause");
			showMenu();
			break;
 		}
		
	 }while(pilih!=9);
 	return 0;
}

void showFirst(){
	first:
	system("cls");
	printf("============= PROGRAM DATA PEGAWAI =============\n\n");
 	printf("1] Menggunakan Metode Binary Search Tree\n\n");
 	printf("2] Menggunakan Metode AVL Tree\n\n");
 	printf("================================================\n");
 	printf("Masukkan Pilihanmu : ");
 	scanf("%d",&choice);
 	if(choice<1 || choice >2){
 		printf("\nMohon maaf opsi menu salah. Silakan ulangi lagi\n\n");
		system("pause");
		goto first;
	 }else{
	 	showMenu();
	 }
}

void showMenu() {
	system("cls");
 		printf("============= PROGRAM DATA PEGAWAI =============\n");
 		printf("1] Menambah Data Pegawai Baru \n\n");
 		printf("2] Menghapus Data Pegawai berdasarkan ID\n\n");
 		printf("3] Mencari Data Pegawai berdasarkan ID\n\n");
 		printf("4] Menampikan Seluruh Data Pegawai (inOrder)\n\n");
 		printf("5] Menampikan Seluruh Data Pegawai (preOrder)\n\n");
 		//printf("6] Menampikan Seluruh Data Pegawai (postOrder)\n\n");
 		printf("7] Menambah 14 Data Pegawai Dari Deskripsi Kasus\n\n");
 		printf("8] Hapus Seluruh Data Pegawai\n\n");
 		printf("9] Quit\n");
 		printf("================================================\n");
 		printf("Masukkan Pilihanmu : ");
 		scanf("%d",&pilih);
}
