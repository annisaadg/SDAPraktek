/*
    File         	: tree.c
    Description    	: Body ADT Binary Tree
    Author    		: Kelompok A6
    Date/Version   	: 8 April 2022/1.0
    Compiler        	: TDM-GCC 4.9.2
*/

#include <malloc.h>
#include <string.h>
#include "tree.h"


/*
Author	: Berliana Elfada
I.S 	: Tree belum terbentuk
F.S	: Tree sudah terbentuk dengan root = nil
*/
void initTree(Tree *T){
	Root(*T) = Nil;
}


/*
Author	: Berliana Elfada
I.S 	: Terdapat data dalam tree
F.S	: Seluruh data pada tree terhapus
*/
void deleteTree(Tree *T){
	if((Root(*T)) != Nil){
		deleteTree(&Left(Root(*T)));
		deleteTree(&Right(Root(*T)));
		Root(*T) = Nil;
		free(Root(*T));
	}
}


/*
Author	: Berliana Elfada
I.S 	: Terdapat data dalam tree
F.S	: Seluruh data pada tree terhapus
*/
address createNode(int id, char* nama){
	address P;
	P =(address) malloc(sizeof(ElmTree));
	if (P != Nil){
		Left(P) = Nil;
		Right(P) = Nil;
		Id(P) = id;
		strcpy(Nama(P),nama);
	}
	return P;
}


/*
Author	: Mohammad Fathul'Ibad
I.S 	: node belum terdapat pada tree
F.S	: node sudah dimasukan ke dalam tree
*/
address insertNode(Tree *T, int id,char* nama){
	
	if(Root(*T) == Nil){
		Root(*T) = createNode(id, nama);
	}
	else{
		if(id < Id(Root(*T))){
			Left(Root(*T)) = insertNode(&Left(Root(*T)), id, nama);
		}
		else{
			Right(Root(*T)) = insertNode(&Right(Root(*T)), id, nama);
		}
	}
	return Root(*T);

}


/*
Author	: GeeksforGeeks
I.S 	: nilai key/id terkecil dari tree belum ditemukan
F.S	: nilai key/id terkecil ditemukan
Modified by : Mohammad Fathul'Ibad
*/
address minValueNode(address node){
	address current = node;
	
	while(current && Left(current) != Nil){
		current = Left(current);
	}
	return current;
}


/*
Author	: GeeksforGeeks
I.S 	: node terdapat pada tree
F.S	: node terhapus dari tree
Modified by : Mohammad Fathul'Ibad
*/
address deleteNode(Tree *T, int id){
	
	if(Root(*T) == Nil){
		return Root(*T);
	}
	
	if(id < Id(Root(*T))){
		Left(Root(*T)) = deleteNode(&Left(Root(*T)), id);
	}
	else if(id > Id(Root(*T))){
		Right(Root(*T)) = deleteNode(&Right(Root(*T)), id);
	}
	else{
		if(Left(Root(*T)) == Nil){
			address temp = Right(Root(*T));
			Root(*T) = Nil;
			free(Root(*T));
			return temp;
		}
		else if(Right(Root(*T)) == Nil){
			address temp = Left(Root(*T));
			Root(*T) = Nil;
			free(Root(*T));
			return temp;
		}
		else{
			address temp = minValueNode(Right(Root(*T)));
			Id(Root(*T)) = Id(temp);
			strcpy(Nama(Root(*T)),Nama(temp));
			Right(Root(*T)) = deleteNode(&Right(Root(*T)),Id(temp));
		}
		
	}
	
	return Root(*T);
}


/*
Author	: Mohammad Fathul'Ibad
I.S 	: node yang dicari belum ditemukan
F.S	: node yang dicari ditemukan
*/
address searchNode(Tree *T, int id){
	if(Root(*T) == Nil || Id(Root(*T)) == id){
		return Root(*T);
	}
	
	if(id < Id(Root(*T))){
		return searchNode(&Left(Root(*T)), id);
	}
	else{
		return searchNode(&Right(Root(*T)), id);
	}
}


/*
Author	: Raihan Shidqi Pangestu
I.S 	: data pegawai belum terdapat pada tree
F.S	: data pegawai sudah dimasukan ke dalam tree
*/
void insertPegawai(Tree *T, int id, char* nama){
	address temp;
	temp = Nil;
	temp = searchNode(&*T,id);
	
	if(temp != Nil){
		printf("\nPegawai %s dengan ID %d tidak berhasil dimasukan karena terdapat kesamaan ID!\n",nama,id);
	}
	else{
		insertNode(&*T, id, nama);
		printf("\nPegawai %s dengan ID %d berhasil dimasukan\n", nama, id);
	}
}


/*
Author	: Raihan Shidqi Pangestu
I.S 	: data pegawai masih terdapat pada tree
F.S	: data pegawai terhapus dari tree
*/
void deletePegawai(Tree *T, int id){
	address temp;
	temp = searchNode(&*T,id);
	
	if(temp == Nil){
		printf("\nPenghapusan gagal, pegawai dengan ID %d tidak ditemukan!\n",id);
	}
	else{
		printf("\nPegawai %s dengan ID %d berhasil dihapus\n", Nama(temp), id);
		deleteNode(&*T,id);
	}
}


/*
Author	: Raihan Shidqi Pangestu
I.S 	: data pegawai belum ditampilkan di layar
F.S	: data pegawai ditampilkan secara inorder
*/
void searchPegawai(Tree T, int id){
	address temp;
	temp = searchNode(&T,id);
	
	if(temp == Nil){
		printf("\nPegawai dengan ID %d tidak ditemukan!\n",id);
	}
	else{
		printf("\nPegawai dengan ID %d adalah %s\n", id, Nama(temp));
	}
	
}


/*
Author	: Annisa Dinda Gantini
I.S 	: data belum ditampilkan di layar
F.S	: data ditampilkan secara preorder
*/
void preOrder(address root){
	if (root != Nil){
		printf("Nama : %s\nID : %d\n\n", Nama(root),Id(root));
		preOrder(Left(root));
		preOrder(Right(root));
	}
}


/*
Author	: Annisa Dinda Gantini
I.S 	: data belum ditampilkan di layar
F.S	: data ditampilkan secara inorder
*/
void inOrder(address root){
	if (root != Nil){
		inOrder(Left(root));
		printf("Nama : %s\nID : %d\n\n", Nama(root),Id(root));
		inOrder(Right(root));
	}
}


/*
Author	: Annisa Dinda Gantini
I.S 	: data belum ditampilkan di layar
F.S	: data ditampilkan secara postorder
*/
void postOrder(address root){
	if (root != Nil){
		inOrder(Left(root));
		inOrder(Right(root));
		printf("Nama : %s\nID : %d\n\n", Nama(root),Id(root));
	}
}


/*
Author	: Raihan Shidqi Pangestu
I.S 	: data pegawai belum ditampilkan di layar
F.S	: data pegawai ditampilkan secara inorder
*/
void printPegawai(address root){
	if(root == Nil){
		printf("Data pegawai Kosong!\n\n");
	}
	else{
		inOrder(root);
	}
}

