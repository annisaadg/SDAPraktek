#include "bst.h"

void showMenu();
int pilih;

int main(int argc, char *argv[]) {
	struct Node *root = Nil;
	struct Node* temp;
 
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
   			temp = searchNode(root,id);
   			if(temp==Nil){
   				root = insertBST(root, id,nama);
   				printf("\n\xaf Pegawai %s dengan ID %d berhasil dimasukan\n", nama, id);
   				insertPegawai(root,id,nama);
			}else{
				printf("\n\xaf Pegawai %s dengan ID %d tidak berhasil dimasukan karena terdapat kesamaan ID!\n",nama,id);
			}
   			printf("\n");
   			system("pause");
   			showMenu();
   			break;
  		case 2:
  			if(root != Nil){
	  		 	printf("Masukkan ID Pegawai yang Akan Dihapus: ");
	   			scanf("%d",&id);
	   			temp = searchNode(root,id);
	   			if(temp==Nil){
	   				printf("\n\xaf Penghapusan gagal, pegawai dengan ID %d tidak ditemukan!\n",id);
				}else{
					printf("\n\xaf Pegawai %s dengan ID %d berhasil dihapus\n", temp->nama, id);
					root = deleteNodeBST(root, id);
				}
			}
			else{
				printf("\n\xaf Data kosong, tidak ada data yang bisa dihapus!\n");
			}
   			printf("\n");
   			system("pause");
   			showMenu();
   			break;
   		case 3: 
   			printf("Masukkan ID Pegawai yang Akan Dicari: ");
   			scanf("%d",&id);
   			searchPegawai(root, id);
   			printf("\n");
   			system("pause");
   			showMenu();
   			break;
   		case 4:
   			printf("\nDAFTAR PEGAWAI:\n\n");
   			printPegawaiPreorder(root);
   			printf("\n");
   			system("pause");
   			showMenu();
   			break;
   		case 5:
   			root = insertBST(root,45,"Dhika Putra");
   			printf("\n\xaf Pegawai %s dengan ID %d berhasil dimasukan\n", "Dhika Putra", 45);
   			insertPegawai(root,45,"Dhika Putra");
 			root = insertBST(root,87,"Chandra Diva");
 			printf("\n\xaf Pegawai %s dengan ID %d berhasil dimasukan\n", "Chandra Diva", 87);
 			insertPegawai(root,87,"Chandra Diva");
 			root = insertBST(root,65,"Abdullah Ahugrah");
 			printf("\n\xaf Pegawai %s dengan ID %d berhasil dimasukan\n", "Abdullah Ahugrah", 65);
			insertPegawai(root,65,"Abdullah Ahugrah");
 			root = insertBST(root,39,"Bayu Virani");
 			printf("\n\xaf Pegawai %s dengan ID %d berhasil dimasukan\n", "Bayu Virani", 39);
 			insertPegawai(root,39,"Bayu Virani");
 			root = insertBST(root,92,"Chaerul Ardina");
 			printf("\n\xaf Pegawai %s dengan ID %d berhasil dimasukan\n", "Chaerul Ardina", 92);
 			insertPegawai(root,92,"Chaerul Ardina");
 			root = insertBST(root,88,"Fikri Syabantika");
 			printf("\n\xaf Pegawai %s dengan ID %d berhasil dimasukan\n", "Fikri Syabantika", 88);
 			insertPegawai(root,88,"Fikri Syabantika");
 			root = insertBST(root,73,"Christian Dayanti");
 			printf("\n\xaf Pegawai %s dengan ID %d berhasil dimasukan\n", "Christian Dayanti", 73);
 			insertPegawai(root,73,"Christian Dayanti");
 			root = insertBST(root,58,"Haris Anjani");
 			printf("\n\xaf Pegawai %s dengan ID %d berhasil dimasukan\n", "Haris Anjani", 58);
 			insertPegawai(root,58,"Haris Anjani");
 			root = insertBST(root,47,"Aprian Amalina");
 			printf("\n\xaf Pegawai %s dengan ID %d berhasil dimasukan\n", "Aprian Amalina", 47);
 			insertPegawai(root,47,"Aprian Amalina");
 			root = insertBST(root,62,"Doni Assodiqin");
 			printf("\n\xaf Pegawai %s dengan ID %d berhasil dimasukan\n", "Doni Assodiqin", 62);
 			insertPegawai(root,62,"Doni Assodiqin");
 			root = insertBST(root,59,"Marvel Tilasnuari");
 			printf("\n\xaf Pegawai %s dengan ID %d berhasil dimasukan\n", "Marvel Tilasnuari", 59);
 			insertPegawai(root,59,"Marvel Tilasnuari");
	 		root = insertBST(root,64,"Hilman Ardiansyah");
	 		printf("\n\xaf Pegawai %s dengan ID %d berhasil dimasukan\n", "Hilman Ardiansyah", 64);
			insertPegawai(root,64,"Hilman Ardiansyah");
 			root = insertBST(root,11,"Izhar Subekti");
			printf("\n\xaf Pegawai %s dengan ID %d berhasil dimasukan\n", "Izhar Subekti", 11);
 			insertPegawai(root,11,"Izhar Subekti");
 			root = insertBST(root,41,"Mustofa Sabri");
 			printf("\n\xaf Pegawai %s dengan ID %d berhasil dimasukan\n", "Mustofa Sabri", 41);
			insertPegawai(root,41,"Mustofa Sabri");
			printf("\n");
   			system("pause");
   			showMenu();
   			break;
   		case 6:
   			root = deleteTree(root);
   			printf("\n\xaf Seluruh data pegawai berhasil dihapus\n\n");
   			system("pause");
   			showMenu();
   			break;
   		case 7:
   			printf("bye!");
   			break;
		default:
			printf("\n\xaf Mohon maaf opsi menu salah. Silakan ulangi lagi\n\n");
			system("pause");
			showMenu();
			break;
 		}
		
	 }while(pilih!=7);
 	return 0;
}

void showMenu() {
	system("cls");
 		printf("============= PROGRAM DATA PEGAWAI =============\n");
 		printf("1] Menambah Data Pegawai Baru \n\n");
 		printf("2] Menghapus Data Pegawai berdasarkan ID\n\n");
 		printf("3] Mencari Data Pegawai berdasarkan ID\n\n");
 		printf("4] Menampikan Seluruh Data Pegawai (preOrder)\n\n");
 		printf("5] Menambah 14 Data Pegawai Dari Deskripsi Kasus\n\n");
 		printf("6] Hapus Seluruh Data Pegawai\n\n");
 		printf("7] Quit\n");
 		printf("================================================\n");
 		printf("Masukkan Pilihanmu : ");
 		scanf("%d",&pilih);
}
