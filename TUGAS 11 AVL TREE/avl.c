#include "avl.h"
int lr,del;
char nam[20];
// A utility function to get height of the tree
int height(struct Node *N) {
	if (N == Nil)
		return 0;
	return N->height;
}

// A utility function to get maximum of two integers
int max(int a, int b)
{
	return (a > b)? a : b;
}

/* Helper function that allocates a new node with the given id and
	Nil left and right pointers. */
struct Node* newNode(int id, char* name)
{
	struct Node* node = (struct Node*)
						malloc(sizeof(struct Node));
	node->id = id;
	strcpy(node->nama,name);
	node->left = Nil;
	node->right = Nil;
	node->height = 1; // new node is initially added at leaf
	return(node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct Node *rightRotate(struct Node *y)
{
	printf("  Melakukan right rotate kepada node %d\n\n", y->id);
	struct Node *x = y->left;
	struct Node *T2 = x->right;

	// Perform rotation
	printf("  Right child dari %d mengambil tempat  %d\n", x->id, y->id);
	x->right = y;
	printf("  Left child dari %d diisi oleh right child dari left child %d\n\n", y->id, y->id);
	y->left = T2;

	// Update heights
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;

	// Return new root
	return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct Node *leftRotate(struct Node *x)
{
	printf("  Melakukan left rotate kepada node %d\n\n", x->id);
	struct Node *y = x->right;
	struct Node *T2 = y->left;

	// Perform rotation
	printf("  Left child dari right child %d mengambil alih posisi %d\n",x->id, x->id);
	y->left = x;
	printf("  Right child dari %d diisi oleh node yang sebelumnya left child dari right child %d\n\n",x->id, x->id);
	x->right = T2;

	// Update heights
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(struct Node *N)
{
	if (N == Nil)
		return 0;
	return height(N->left) - height(N->right);
}

struct Node* insert(struct Node* node, int id, char* name)
{
	/* 1. Perform the normal BST rotation */
	if (node == Nil){
		return(newNode(id,name));
	}

	if (id < node->id){
		lr=1;
		strcpy(nam,node->nama);
		node->left = insert(node->left, id, name);	
	}
	else if (id > node->id){
		lr=2;
		strcpy(nam,node->nama);
		node->right = insert(node->right, id, name);
	}
	else{
		// Equal ids not allowed
		return node;
	} 

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left),
						height(node->right));

	/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced, then there are 4 cases

	// Left Left Case
	if (balance > 1 && id < node->left->id)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && id > node->right->id)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && id > node->left->id)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && id < node->right->id)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}

/* Given a non-empty binary search tree, return the
node with minimum id value found in that tree.
Note that the entire tree does not need to be
searched. */
struct Node * minValueNode(struct Node* node)
{
	struct Node* current = node;

	/* loop down to find the leftmost leaf */
	while (current->left != Nil)
		current = current->left;

	return current;
}

// Recursive function to delete a node with given id
// from subtree with given root. It returns root of
// the modified subtree.
struct Node* deleteNode(struct Node* root, int id)
{
	// STEP 1: PERFORM STANDARD BST DELETE

	if (root == Nil)
		return root;

	// If the id to be deleted is smaller than the
	// root's id, then it lies in left subtree
	if ( id < root->id )
		root->left = deleteNode(root->left, id);

	// If the id to be deleted is greater than the
	// root's id, then it lies in right subtree
	else if( id > root->id )
		root->right = deleteNode(root->right, id);

	// if id is same as root's id, then This is
	// the node to be deleted
	else
	{
		// node with only one child or no child
		if( (root->left == Nil) || (root->right == Nil) )
		{
			struct Node *temp = root->left ? root->left :
											root->right;

			// No child case
			if (temp == Nil)
			{
				temp = root;
				root = Nil;
			}
			else // One child case
			*root = *temp; // Copy the contents of
							// the non-empty child
			free(temp);
		}
		else
		{
			// node with two children: Get the inorder
			// successor (smallest in the right subtree)
			struct Node* temp = minValueNode(root->right);

			// Copy the inorder successor's data to this node
			root->id = temp->id;
			strcpy(root->nama,temp->nama);

			// Delete the inorder successor
			root->right = deleteNode(root->right, temp->id);
		}
	}

	// If the tree had only one node then return
	if (root == Nil)
	return root;

	// STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
	root->height = 1 + max(height(root->left),
						height(root->right));

	// STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
	// check whether this node became unbalanced)
	int balance = getBalance(root);

	// If this node becomes unbalanced, then there are 4 cases

	// Left Left Case
	if (balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);

	// Left Right Case
	if (balance > 1 && getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right Right Case
	if (balance < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);

	// Right Left Case
	if (balance < -1 && getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}



/////////////////////////////////////////////////////


struct Node* insertBST(struct Node* node, int id, char* name)
{
    /* If the tree is empty, return a new node */
    if (node == Nil){
    	return newNode(id, name);
	}
 
    /* Otherwise, recur down the tree */
    if (id < node->id){
    	lr=1;
    	strcpy(nam,node->nama);
        node->left = insertBST(node->left, id, name);
	}
    else{
    	lr=2;
    	strcpy(nam,node->nama);
        node->right = insertBST(node->right, id, name);
	}
 
    /* return the (unchanged) node pointer */
    return node;
}

struct Node* deleteNodeBST(struct Node* root, int id)
{
    // base case
    if (root == Nil)
        return root;
 
    // If the id to be deleted
    // is smaller than the root's
    // id, then it lies in left subtree
    if (id < root->id)
        root->left = deleteNodeBST(root->left, id);
 
    // If the id to be deleted
    // is greater than the root's
    // id, then it lies in right subtree
    else if (id > root->id)
        root->right = deleteNodeBST(root->right, id);
 
    // if id is same as root's id,
    // then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->left == Nil) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == Nil) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        struct Node* temp = minValueNode(root->right);
 
        // Copy the inorder
        // successor's content to this node
        root->id = temp->id;
 
        // Delete the inorder successor
        strcpy(root->nama,temp->nama);
        root->right = deleteNodeBST(root->right, temp->id);
    }
    return root;
}

struct Node* searchNode(struct Node* node, int id){
	if(node == Nil || node->id == id){
		return node;
	}
	
	if(id < node->id){
		return searchNode(node->left, id);
	}
	else{
		return searchNode(node->right, id);
	}
}

void searchPegawai(struct Node* node, int id){
	struct Node* temp;
	temp = searchNode(node,id);
	
	if(temp == Nil){
		printf("\n\xaf Pegawai dengan ID %d tidak ditemukan!\n",id);
	}
	else{
		printf("\n\xaf Pegawai dengan ID %d adalah %s\n", id, temp->nama);
	}
}

void insertPegawai(struct Node* node, int id, char* nama){
	if(lr==1){
		printf("  %s adalah left child dari %s\n",nama,nam);
	}else if(lr==2){
		printf("  %s adalah right child dari %s\n",nama,nam);
	}
}

struct Node* deleteTree(struct Node* node){
	if(node != Nil){
		deleteTree(node->left);
		deleteTree(node->right);
		node = Nil;
		free(node);
	}
	lr=5;
	return node;
}


// A utility function to print preorder traversal of
// the tree.
// The function also prints height of every node
void preOrder(struct Node *root)
{
	if(root != Nil)
	{
		printf("Print node\n");
		printf("Nama : %s\nID : %d\n\n", root->nama, root->id);
		printf("Telusur left child atau cari parent\n");
		preOrder(root->left);
		preOrder(root->right);
		printf("Telusur right child atau cari parent\n");
	}
}

void printPegawaiPreorder(struct Node *root){
	if(root == Nil){
		printf("Data pegawai Kosong!\n\n");
	}
	else{
		preOrder(root);
	}
}

