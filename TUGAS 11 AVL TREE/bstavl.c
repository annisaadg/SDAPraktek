#include "bstavl.h"

int lr,del;
char nam[20];

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
			lr=1; // 1=left
			strcpy(nam,Nama(Root(*T)));
			Left(Root(*T)) = insertNode(&Left(Root(*T)), id, nama);
		}
		else{
			lr=2; // 2=right
			strcpy(nam,Nama(Root(*T)));
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
		if(lr==1){
			printf("%s adalah left child dari %s\n",nama,nam);
		}else if(lr==2){
			printf("%s adalah right child dari %s\n",nama,nam);
		}
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
		printf("Print node\n");
		printf("Nama : %s\nID : %d\n\n", Nama(root),Id(root));
		printf("Telusur left child atau cari parent\n");
		preOrder(Left(root));
		preOrder(Right(root));
		printf("Telusur right child atau cari parent\n");
	}
}


/*
Author	: Annisa Dinda Gantini
I.S 	: data belum ditampilkan di layar
F.S	: data ditampilkan secara inorder
*/
void inOrder(address root){
	if (root != Nil){
		printf("Telusur left child atau right child\n");
		inOrder(Left(root));
		printf("Print node\n");
		printf("Nama : %s\nID : %d\n\n", Nama(root),Id(root));
		inOrder(Right(root));
		printf("Telusur right child atau cari parent\n");
	}
}


/*
Author	: Annisa Dinda Gantini
I.S 	: data belum ditampilkan di layar
F.S	: data ditampilkan secara postorder
void postOrder(address root){
	if (root != Nil){
		inOrder(Left(root));
		inOrder(Right(root));
		printf("Nama : %s\nID : %d\n\n", Nama(root),Id(root));
	}
}
*/


/*
Author	: Raihan Shidqi Pangestu
I.S 	: data pegawai belum ditampilkan di layar
F.S	: data pegawai ditampilkan secara inorder
*/
void printPegawaiInorder(address root){
	if(root == Nil){
		printf("Data pegawai Kosong!\n\n");
	}
	else{
		inOrder(root);
	}
}
void printPegawaiPreorder(address root){
	if(root == Nil){
		printf("Data pegawai Kosong!\n\n");
	}
	else{
		preOrder(root);
	}
}



/////////////////////////////////////////////////////



// A utility function to get height of the tree
int heightAVL(Tree *T)
{
	if (Root(*T) = Nil)
		return 0;
	return Height(Root(*T));
}

// A utility function to get maximum of two integers
int maxAVL(int a, int b)
{
	return (a > b)? a : b;
}

/* Helper function that allocates a new node with the given id and
	Nil left and right pointers. */
address newNode(int id, char* name)
{
	address P;
	P = (address)malloc(sizeof(ElmTree));
	if (P != Nil){
		Left(P) = Nil;
		Right(P) = Nil;
		Id(P) = id;
		Height(P) =1;
		strcpy(Nama(P),name);
	}
	return P;
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
address rightRotateAVL(Tree *T)
{
	address x,T2;
	Root(*x) = Left(Root(*T));
	Root(*T2) = Right(Root(*x));

	// Perform rotation
	Right(Root(*x)) = Root(*T);
	Left(Root(*T)) = Root(*T2);

	// Update heights
	Height(Root(*T)) = maxAVL(heightAVL(&Left(Root(*T))), heightAVL(&Right(Root(*T))))+1;
	Height(Root(*x)) = maxAVL(heightAVL(&Left(Root(*x))), heightAVL(&Right(Root(*x))))+1;

	// Return new root
	return x;
}



// A utility function to left rotate subtree rooted with x
// See the diagram given above.
address leftRotateAVL(Tree *T)
{
	address y,T2;
	y = Right(Root(*T));
	T2 = Left(Root(*y));

	// Perform rotation
	Left(Root(*y)) = T;
	Right(Root(*T)) = T2;

	// Update heights
	Height(Root(*T)) = maxAVL(heightAVL(&Left(Root(*T))), heightAVL(&Right(Root(*T))))+1;
	Height(Root(*y)) = maxAVL(heightAVL(&Left(Root(*y))), heightAVL(&Right(Root(*y))))+1;

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalanceAVL(Tree *T)
{
	if (Root(*T) = Nil)
		return 0;
	return heightAVL(&Left(Root(*T))) - heightAVL(&Right(Root(*T)));
}


address insertAVL(Tree *T, int id, char* name)
{
	/* 1. Perform  normal BST rotation */
	if(Root(*T) == Nil){
		return (createNode(id, name));
	}
	if(id < Id(Root(*T))){
		lr=1; // 1=left
		strcpy(nam,Nama(Root(*T)));
		Left(Root(*T)) = insertAVL(&Left(Root(*T)), id, name);
	}
	else if(id > Id(Root(*T))) {
		lr=2; // 2=right
		strcpy(nam,Nama(Root(*T)));
		Right(Root(*T)) = insertAVL(&Right(Root(*T)), id, name);
	}
	else{
		return Root(*T);
	}

	/* 2. Update height of this ancestor node */
	Height(Root(*T)) = 1 + maxAVL(heightAVL(&Left(Root(*T))),
						heightAVL(&Right(Root(*T))));

	/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
	int balance = getBalanceAVL(&Root(*T));

	// If this node becomes unbalanced, then there are 4 cases

	// Left Left Case
	if (balance > 1 && id < Left(Root(*T))->id) {
		return rightRotateAVL(&Root(*T));
	}

	// Right Right Case
	if (balance < -1 && id > Id(Right(Root(*T)))) {
		return leftRotateAVL(&Root(*T));
	}

	// Left Right Case
	if (balance > 1 && id > Id(Left(Root(*T))))
	{
		Left(Root(*T)) = leftRotateAVL(&Left(Root(*T)));
		return rightRotateAVL(&Root(*T));
	}

	// Right Left Case
	if (balance < -1 && id < Id(Right(Root(*T))))
	{
		Right(Root(*T)) = rightRotateAVL(&Right(Root(*T)));
		return leftRotateAVL(&Root(*T));
	}

	/* return the (unchanged) node pointer */
	return Root(*T);
}

/* Given a non-empty binary search tree, return the
node with minimum id value found in that tree.
Note that the entire tree does not need to be
searched. */
address minValueNodeAVL(address node){
	address current = node;
	
	while(current && Left(current) != Nil){
		current = Left(current);
	}
	return current;
}

// Recursive function to delete a node with given id
// from subtree with given root. It returns root of
// the modified subtree.
address deleteNodeAVL(Tree *T, int id)
{
	address temp;
	// STEP 1: PERFORM STANDARD BST DELETE

	if (Root(*T) == Nil)
		return Root(*T);

	// If the id to be deleted is smaller than the
	// root's id, then it lies in left subtree
	if ( id < Id(Root(*T)) )
		Left(Root(*T)) = deleteNodeAVL(&Left(Root(*T)), id);

	// If the id to be deleted is greater than the
	// root's id, then it lies in right subtree
	else if( id > Id(Root(*T)) )
		Right(Root(*T)) = deleteNodeAVL(&Right(Root(*T)), id);

	// if id is same as root's id, then This is
	// the node to be deleted
	else
	{
		// node with only one child or no child
		if( (Left(Root(*T)) == Nil) || (Right(Root(*T)) == Nil) )
		{
			temp = Left(Root(*T)) ? Left(Root(*T)) :Right(Root(*T));

			// No child case
			if (temp == Nil)
			{
				temp = Root(*T);
				Root(*T) = Nil;
			}
			else // One child case
			*Root(*T) = *temp; // Copy the contents of
							// the non-empty child
			free(temp);
		}
		else
		{
			// node with two children: Get the inorder
			// successor (smallest in the right subtree)
			temp = minValueNodeAVL(Right(Root(*T)));

			// Copy the inorder successor's data to this node
			Id(Root(*T)) = Id(temp);
			
			strcpy(Nama(Root(*T)),Nama(temp));
			
			// Delete the inorder successor
			Right(Root(*T)) = deleteNodeAVL(&Right(Root(*T)),Id(temp));
		}
	}

	// If the tree had only one node then return
	if (Root(*T) == Nil)
	return Root(*T);

	// STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
	Height(Root(*T)) = 1 + maxAVL(heightAVL(&Left(Root(*T))),
						heightAVL(&Right(Root(*T))));

	// STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
	// check whether this node became unbalanced)
	int balance = getBalanceAVL(Root(*T));

	// If this node becomes unbalanced, then there are 4 cases

	// Left Left Case
	if (balance > 1 && getBalanceAVL(&Left(Root(*T))) >= 0)
		return rightRotateAVL(Root(*T));

	// Left Right Case
	if (balance > 1 && getBalanceAVL(&Left(Root(*T))) < 0)
	{
		Left(Root(*T)) = leftRotateAVL(&Left(Root(*T)));
		return rightRotateAVL(Root(*T));
	}

	// Right Right Case
	if (balance < -1 && getBalanceAVL(&Right(Root(*T))) <= 0)
		return leftRotateAVL(Root(*T));

	// Right Left Case
	if (balance < -1 && getBalanceAVL(&Right(Root(*T))) > 0)
	{
		Right(Root(*T)) = rightRotateAVL(&Right(Root(*T)));
		return leftRotateAVL(Root(*T));
	}

	return Root(*T);
}
