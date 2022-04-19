/*
 Body File untuk Non Binary Tree
 Author  : Lukmannul Hakim Firdaus
 Created At  : 07-04-2022 
*/

#include "nbtree.h"
#include <string.h>
#include <malloc.h>

void InitTree(nbTree *t){
 (*t).root = nil;
}

nbAddr AlokasiNode(char* name, char* jabatan, nbAddr parent, nbAddr fchild, nbAddr nbrother){
 nbTreeNode *node;
 
 //alokasi tree di memori
 node = (nbTreeNode*)malloc(sizeof(nbTreeNode));
 
 strcpy(Nama(node), name);
 strcpy(Jabatan(node), jabatan);
 node->parent = parent;
 node->fs = fchild;
 node->nb = nbrother;
 
 return node;
}

nbAddr InsertNode(nbTree t, char name, char* jabatan, nbAddr parent){
 
 //jika node adalah root tapi rootnya sudah ada
 if(parent == nil && t->root != nil){
  printf("\nNULL");
  return nil;
 }

 //jika node adalah root
 if(parent == nil && t->root == nil){
  printf("Creating Root...");
  nbAddr rootNode = AlokasiNode(name, jabatan, nil, nil, nil);
  //set root dengan node baru
  t->root = rootNode;
  printf("\n> ROOT Created : %s - %s", t->root->jabatan, t->root->nama);
  return rootNode;
 }else {
  //apakah first-child
  if(parent->fs == nil){
   printf("\nCreating First Child...");
   nbAddr firstChild = AlokasiNode(name, jabatan, parent, nil, nil);
   
   //set firstchild dengan node baru
   parent->fs = firstChild;
   printf("\n> FirstChild Created : %s - %s", parent->fs->jabatan, parent->fs->nama);
   return firstChild;
  }else{
   printf("\nCreating Next Brother..." );
   
   //ambil first chiled dari parent
   nbAddr lastChild = parent->fs;
   
   //cari child terakhir
   while(lastChild->nb != nil){
    lastChild = lastChild->nb;
   }
   
   nbAddr broChild = AlokasiNode(name,jabatan, parent, nil, nil);
   //set nextbrother di last child dengan node baru
   lastChild->nb = broChild;
   
   printf("\n> BroChild Created : %s - %s", broChild->jabatan, broChild->nama);
   return broChild;
  } 
 }
 

}
