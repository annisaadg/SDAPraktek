#include "bintreeAVL.h"
#include<string.h>
#include<stdio.h>

BinTree Alokasi(infoid id, infonama nama){
	/* Menghasilkan  address hasil alokasi sebuah  Node 	*/
	/* Jika alokasi berhasil, maka  address tidak NIl   	*/
	/* infoid(P)=id, infonama=nama, left(P)=Nil, Right(P)=Nil*/
	/* Jika alokasi gagal mengembalikan Nil  		*/
	BinTree P;
	
	P = (ElmtNode*)malloc(sizeof(ElmtNode));
	if (P != Nil){
		Id(P) = id;
		strcpy(Nama(P),nama);
		Right(P) = Nil;
		Left(P) = Nil;
	}
	
	return P;
}

boolean IsEmptyTree(BinTree T){
	/* Mengembalikan true jika pohon kosong */
	return (T == Nil); 
}

void CreateEmpty(BinTree *T){
	/* Membuat  Tree   kosong  */
	*T = Nil;
}

BinTree CreateTree(infoid id, infonama nama, BinTree L, BinTree R){
	/* Menghasilkan sebuah pohon Biner dari A, L, dan R jika Alokasi berhasil */
	/* Menghasilkan pohon kosong Nil, jika alokasi gagal*/
	address node = Alokasi(id, nama);
	if(node == NULL){
		return node;
	}
	Left(node) = L;
	Right(node) = R;
	Height(node) = 1;
	
	return node;
}

BinTree AddDaun (BinTree node, infoid id, infonama nama) {
  	// Find the correct position to insertNode the node and insertNode it
  	if (IsEmptyTree(node))
    	return CreateTree(id, nama, Nil, Nil);

  	if (id < Id(node))
    	Left(node) = AddDaun(Left(node), id, nama);
  	else if (id > Id(node))
    	Right(node) = AddDaun(Right(node), id, nama);
  	else
    	return node;

	// Update the balance factor of each node and
	// Balance the tree
  	Height(node) = 1 + max(getHeight(Left(node)), getHeight(Right(node)));

  	int balance = getBalance(node);
  	if (balance > 1 && id < Id(Left(node)))
    	return rightRotate(node);

  	if (balance < -1 && id > Id(Right(node)))
    	return leftRotate(node);

  	if (balance > 1 && id > Id(Left(node))) {
    	Left(node) = leftRotate(Left(node));
    	return rightRotate(node);	
  	}

  	if (balance < -1 && id < Id(Right(node))) {
    	Right(node) = rightRotate(Right(node));
    	return leftRotate(node);
  	}
  	
	return node;
}

infoid GetAkar(BinTree P){
	/* Mengirimkan nilai Akar pohon biner P */
	return Id(P); 
}

BinTree GetLeft(BinTree P){
 	/* Mengirimkan anak kiri pohon biner P  */
	return Left(P); //Mengembalikan alamat anak kanan pada pohon biner
}


BinTree GetRight(BinTree P){
	return Right(P);
}
/* Mengirimkan anak kanan pohon biner P  */

/*** Traversal ***/
void PrintPreorder (BinTree P){
	//I.S. P terdefinisi
	//F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon
	//kanan. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
 	if (P!=Nil)  {
  		printf("\n> %d : %s ", Id(P), Nama(P)); //menampilkan terlebih dahulu akarnya
  		PrintPreorder(Left(P)); //untuk menampilkan anak kiri tree
  		PrintPreorder(Right(P)); //untuk menampilkan anak kanan tree
	}
}

void PrintInorder (BinTree P)
//I.S. P terdefinisi
//F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon
//kanan. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
{
	//Kamus Lokal
	
	//Algoritma
	if (!IsEmptyTree(P))  {
		PrintInorder(Left(P));
		printf("\n> %d : %s", Id(P), Nama(P));
		PrintInorder(Right(P));
	}
}

void PrintPostorder (BinTree P)
//I.S. P terdefinisi
//F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan
//akar. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
{
	if (!IsEmptyTree(P))  {
		PrintPostorder(Left(P));
		PrintPostorder(Right(P));
		printf("\n> %d : %s ", Id(P), Nama(P));
	}
}

BinTree SearchNode(BinTree T, infoid id){
 	//modul untuk mencari address dari suatu node dengan id tertentu.
	//akan return Nil jika tidak ditemukan.
 	if (!IsEmptyTree(T)){
  		if(Id(T) == id)
   			return T;
  		if(id > Id(T) && Right(T) != Nil)  //jika id yang akan dicari lebih besar dari node yang ditunjuk  
   			return SearchNode(Right(T),id); // dan right child atau node kanan tidak kosong.
  		if(id < Id(T) && Left(T) != Nil)
   			return SearchNode(Left(T),id);  //jika id yang akan dicari lebih kecil dari node yang ditunjuk
 	}          //dan left child atau node kiri tidak kosong.
 	return Nil;
}

void findPrint(BinTree T, infoid id){
 	//modul untuk print nama dan info dari node tertentu yang dicari.
 	BinTree find = SearchNode(T,id); //memanggil SearchNode untuk menemukan address atau BinTree dari node yang dicari.
 	if (find != Nil){
  		printf("ID %d memiliki nama: %s",Id(find),Nama(find));
	} else {
  		printf("Mohon maaf ID Pegawai tidak ditemukan");
 	}
}

BinTree minValueNode(BinTree T){
	/* Mencari alamat dengan id paling kecil */
	BinTree current = T;
	while(current && Left(current) != Nil){
		current = Left(current);
	}
	
	return current;
}


BinTree DeleteNode(BinTree T, int id){
	/* menghapus satu node*/
 	if (SearchNode(T, id) == Nil){
  		printf("Penghapusan tidak dapat dilakukan karena data pegawai tidak ada\n\n");
  		return T;
	} else {
  		if (T == Nil){
   			return T;
  		}
  		if(id < Id(T)){
   			Left(T) = DeleteNode(Left(T), id);
  		}else if(id > Id(T)){
   			Right(T) = DeleteNode(Right(T), id);
	  	}else{
   			if(Left(T) == Nil){
    			BinTree temp = Right(T);
    			free(T);
    			return temp;
   			}else if(Right(T) == Nil){
    			BinTree temp = Left(T);
    			free(T);
    			return temp;
   			}
   
	   		BinTree temp = minValueNode(Right(T));
		    Id(T) = Id(temp);
	   
	   		Right(T) = DeleteNode(Right(T), Id(temp));
  		}
  		
  		if (T == NULL){
  			return T;
		}
		Height(T) = 1 + max(getHeight(Left(T)), getHeight(Right(T)));
		int balance = getBalance(T);
		
		if (balance > 1 && getBalance(Left(T)) >= 0)
		    return rightRotate(T);
		
		if (balance > 1 && getBalance(Left(T)) < 0) {
		    Left(T) = leftRotate(Left(T));
		    return rightRotate(T);
		}
		
		if (balance < -1 && getBalance(Right(T)) <= 0)
		    return leftRotate(T);
		
		if (balance < -1 && getBalance(Right(T)) > 0) {
		    Right(T) = rightRotate(Right(T));
		    return leftRotate(T);
		}
		
		return T;
 	}
}

void DestructTree(address T){
	/* Menghapus tree*/
	if(T == Nil){
		return;
	}
	
	DestructTree(Left(T));
	DestructTree(Right(T));
	
	printf("\nDeleting node with id : %d", Id(T));
	free(T);
}

// AVL

// Get height
int getHeight(BinTree T) {
  	if (T == NULL)
    	return 0;
  	return Height(T);
}

// Get the balance factor
int getBalance(BinTree T) {
  	if (T == NULL)
    	return 0;
  	return getHeight(Left(T)) - getHeight(Right(T));
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

// Right rotate
BinTree rightRotate(BinTree y) {
	printf("Melakukan rotasi kanan kepada node %d\n\n", y->id);
	delay(2);
	
	//x menjadi anak kiri dari T
  	BinTree x = Left(y);
  	
  	//temp menjadi anak kanan dari x yang merupakan anak kiri dari T
  	BinTree T2 = Right(x);

	//melakukan rotasi
	
	//anak kanan dari x yang merupakan anak kiri dari T menjadi T
	printf("anak kanan dari %d mengambil tempat  %d\n", x->id, y->id);
  	Right(x) = y;
  	delay(1);
  	
  	//anak kiri dari T menjadi temp
	printf("Anak kiri dari %d diisi oleh anak kanan dari anak kiri %d\n\n", y->id, y->id);
	Left(y) = T2;
	delay(1);

	//merubah height dari semua node setelah rotasi
  	Height(y) = max(getHeight(Left(y)), getHeight(Right(y))) + 1;
  	Height(x) = max(getHeight(Left(x)), getHeight(Right(x))) + 1;
	
	//kembalikan root nya
  	return x;
}

// Left rotate
BinTree leftRotate(BinTree x) {
	printf("Melakukan rotasi kiri kepada node %d\n\n", x->id);
	//node x adalah anak kanan dari node T
	delay(2);
	
  	BinTree y = Right(x);
  	//node temp merupakan anak kiri dari node x
  	BinTree T2 = Left(y);

	//anak kiri dari node x menjadi node x;
	printf("Anak kiri dari anak kanan %d mengambil alih posisi %d\n",x->id, x->id);
  	Left(y) = x;
  	delay(1);
  	//anak kanan dari node T menjadi temp(yang sebelumnya merupakan anak kiri x)
	printf("Anak kanan dari %d diisi oleh node yang sebelumnya anak kiri dari anak kanan %d\n\n",x->id, x->id);
	Right(x) = T2;
	delay(1);
	
	//merubah height setelah rotasi
  	Height(x) = max(getHeight(Left(x)), getHeight(Right(x))) + 1;
  	Height(y) = max(getHeight(Left(y)), getHeight(Right(y))) + 1;

	//kembalikan rootnya
  	return y;
}

void delay(double detik){
    // Converting time into milli_seconds
    int milli_seconds = 1000 * detik;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}
