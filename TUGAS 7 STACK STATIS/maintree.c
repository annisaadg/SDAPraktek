/*
 Main Driver Sederhana untuk implementasi Non Binary Tree
 Author  : Lukmannul Hakim Firdaus
 Created At  : 07-04-2022 
*/

#include "nbtree.h"
#include <stdio.h>
#include <string.h>

int main(){

 nbTree tree;
 
 
 //buat tree kosong
 InitTree(&tree);

 
 //tambahkan node baru --> jadi root => Ujang Kartiwa
 nbAddr root = InsertNode(&tree, "Ujang Kartiwa", "Kepala Pusat", nil);
 
 //CHILD DARI UJANG KARTIWA
 nbAddr fs = InsertNode(&tree, "Engkos Koswara", "Kepala Bagian Perencanaan", root);
 nbAddr nb1 = InsertNode(&tree, "Hoerul Anam", "Kepala Bagian SDM", root);
 nbAddr nb2 = InsertNode(&tree, "Dana Sukirman", "Kepala Bagian Keuangan", root);
 
 //CHILD DARI ENGKOS KOSWARA
 nbAddr fs_fs = InsertNode(&tree, "Tati Sulastri", "Kepala Sub Bagian Anggaran", fs);
 nbAddr fs_nb1 = InsertNode(&tree, "Irvan Susilo", "Kepala Sub Bagian Pendataan", fs);
 nbAddr fs_nb2 = InsertNode(&tree, "Evi Sukaesih", "Kepala Sub Bagian Evaluasi", fs);
 
 //CHILD DARI HOERUL ANAM
 nbAddr nb1_fs = InsertNode(&tree, "Smabas Nugroho", "Kepala Sub Bagian Kepagawaian", nb1);
 nbAddr nb1_nb1 = InsertNode(&tree, "Mujani Gani", "Kelapa Sub Bagian Tata Laksana", nb1);
 
 //CHILD DARI DANA SUKIRMAN
 nbAddr nb2_fs = InsertNode(&tree, "Noviyanti", "Kepala Sub Bagian Pelaksana Keuangan", nb2);
 
 //CHILD DARI TATI SULASTRI
 nbAddr fs_fs_fs = InsertNode(&tree, "Muktadi", "Staf", fs_fs);
 nbAddr fs_fs_nb1 = InsertNode(&tree, "Hartanto Utomo", "Staf", fs_fs);
 
 //CHILD IRVAN SUSILO
 nbAddr fs_nb1_fs = InsertNode(&tree, "Candra Dimuka","Staf", fs_nb1);
 
 //CHILD EVI SUKAESIH
 nbAddr fs_nb2_fs = InsertNode(&tree, "Kartono", "Staf", fs_nb2);
 
 //CHILD SAMBAS NUGROHO
 nbAddr nb1_fs_fs = InsertNode(&tree, "Markonah", "Staf", nb1_fs);
 nbAddr nb1_fs_nb1 = InsertNode(&tree, "Jaelani Supri Utama", "Staf", nb1_fs);
 nbAddr nb1_fs_nb2 = InsertNode(&tree, "Ukar Mustopa", "Staf", nb1_fs);
 
 //CHILD MUJANI GANI
 nbAddr nb1_nb1_fs = InsertNode(&tree, "Marcellino", "Staf", nb1_nb1);
 nbAddr nb1_nb1_nb1 = InsertNode(&tree, "Opik Taufik", "Staf", nb1_nb1);

 //tampilkan tree 
 //printNode(tree);
 printf("\n\nAtasan Kartono : %s", fs_nb2_fs->parent->nama);
 printf("\nBawahan Sambas Nugroho : %s, %s, dan %s", nb1_fs->fs->nama, nb1_fs->fs->nb->nama, nb1_fs->fs->nb->nb->nama);
 printf("\nKepala Bagian dari Opik Taufik : %s", nb1_nb1_nb1->parent->parent->nama);
}
