/*
    File         	: tree.c
    Description    	: Body ADT Binary Tree
    Author    		: Kelompok A6
    Date/Version   	: 8 April 2022/1.0
    Compiler        : TDM-GCC 4.9.2
*/

#include <malloc.h>
#include "tree.h"

void initTree(Tree *T){
	Root(*T) = Nil;
}

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


address minValueNode(address node){
	address current = node;
	
	while(current && Left(current) != Nil){
		current = Left(current);
	}
	return current;
}


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
			free(Root(*T));
			return temp;
		}
		else if(Right(Root(*T)) == Nil){
			address temp = Left(Root(*T));
			free(Root(*T));
			return temp;
		}
		else{
			address temp = minValueNode(Right(Root(*T)));
			Id(Root(*T)) = Id(temp);
			Right(Root(*T)) = deleteNode(&Right(Root(*T)),Id(temp));
		}
		
	}
	
	return Root(*T);
}


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


void insertPegawai(Tree *T, int id, char* nama){
	address temp;
	temp = Nil;
	temp = searchNode(&*T,id);
	
	if(temp != Nil){
		printf("Pegawai %s dengan ID %d tidak berhasil dimasukan karena terdapat kesamaan ID!\n",nama,id);
	}
	else{
		insertNode(&*T, id, nama);
		printf("Pegawai %s dengan ID %d berhasil dimasukan\n", nama, id);
	}
}


void deletePegawai(Tree *T, int id){
	address temp;
	temp = searchNode(&*T,id);
	
	if(temp == Nil){
		printf("Penghapusan gagal, pegawai dengan ID %d tidak ditemukan!\n",id);
	}
	else{
		printf("Pegawai %s dengan ID %d berhasil dihapus\n", Nama(temp), id);
		deleteNode(&*T,id);
	}
}


void searchPegawai(Tree T, int id){
	address temp;
	temp = searchNode(&T,id);
	
	if(temp == Nil){
		printf("\xaf Pegawai dengan ID %d tidak ditemukan!\n",id);
	}
	else{
		printf("\xaf Pegawai dengan ID %d adalah %s\n", id, Nama(temp));
	}
	
}


void preOrder(address root){
	if (root != Nil && Nama(root) != Nil){
		printf("Nama : %s\nID : %d\n\n", Nama(root),Id(root));
		preOrder(Left(root));
		preOrder(Right(root));
	}else{
		printf("Data Pegawai Kosong\n");
	}
}


void inOrder(address root){
	if (root != Nil){
		inOrder(Left(root));
		printf("Nama : %s\nID : %d\n\n", Nama(root),Id(root));
		inOrder(Right(root));
	}
}

void cekEmpty(Tree *T){
	if(Root(*T) == Nil){
		printf("Data Pegawai Kosong\n");
	}
}

void postOrder(address root){
	if (root != Nil && Nama(root) != Nil){
		inOrder(Left(root));
		inOrder(Right(root));
		printf("Nama : %s\nID : %d\n\n", Nama(root),Id(root));
	}else{
		printf("Data Pegawai Kosong\n");
	}
}
