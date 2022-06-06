#include "bst.h"
int lr,del;
char nam[20];
// A utility function to get height of the tree

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
	return(node);
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

