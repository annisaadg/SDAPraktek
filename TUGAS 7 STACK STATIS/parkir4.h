/*
Program : parkir.h
Author : 211524003, Annisa Dinda Gantini
Kelas : 1A
Deskripsi: Header file dari program parkir
Tanggal : 18 Maret 2022
*/

#ifndef parkir4_H
#define parkir4_H
#include "boolean.h"
#define Nil 0
#define MaxEl 10
/* Nil adalah stack dengan elemen kosong . */
/* Karena indeks dalam bhs C dimulai O maka tabel dg indeks O tidak */
/* dipakai */
typedef char infoplat[15];
typedef int address; /* indeks tabel */
/* Contoh deklarasi variabel bertype stack denqan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { infoplat T[MaxEl+1];/*tabel penyimpan elemen*/
                 address TOP; /* alamat TOP: elemen puncak */
               } Stack;
/* Definisi stack S kosong : S.TOP : Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[l]..T[MaxEl] */
/* Jika S adalah Stack maka akses elemen : */
/* S.T[(S.TOP)] untuk mengakses elemen TOP */
/* S.TOP adalah alamat elemen TOP */
/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]
/*** Perubahan nilai komponen struktur ***/
/*** Untuk bahasa C tidak perlu direalisasi *****/
/******************* Prototype ****************/
/*** Konstruktor/Kreator ***/
void CreateEmpty(Stack *S);
/* T.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosonq berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+l karena O tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
/*********** Predikat Untuk test keadaan KOLEKSI **/
boolean IsEmpty (Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull(Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
/*********** Menambahkan sebuah elemen ke Stack **********/
void Push (Stack *S, infoplat X);
/* Menambahkan X sebagai elemen Stack S. */
/* T.S. S mungkin kosong, tabel penampung elemen stack TTDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
/*********** Menqhapus sebuah elemen Stack **********/
void Pop (Stack *S, infoplat *X);
/* Menghapus X dari Stack S. */
/* T.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang l */

void PrintStack(Stack S);
/*Menampilkan nilai-nilai pada Stack S */

int CariMobil(Stack S, infoplat X);
#endif
