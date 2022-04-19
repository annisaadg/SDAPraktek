/*
Program : list.h
Author : 211524003, Annisa Dinda Gantini
Kelas : 1A
Deskripsi: Header file dari prototype linear linked list
Tanggal : 8/3/2022
*/

#ifndef list_H
#define list_H
#include "boolean.h"
#include <stdio.h>
#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First

/** Definisi ABSTRACT DATA TYPE List **/
/*Definisi List :*/
/* List kosong ===> First (L) =Nil
Setiap elemen dengan address P dapat diacu info (P) dan Next (P);
Elemen terakhir list ===> Jika addressnya Last maka Next (Last) = Nil
*/
typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
 		infotype info;
 		address next;
} ElmtList; 
typedef struct {
 	address First; 
} List;

/* Prototype Linear List */
/* Konstruktor membentuk List */
void CreateList (List *L);
/* I.S : L terdefinisi, tidak diketahui nilainya
F.S : L diinisialisasi first(L) = nil
*/

/* Destruktor/Dealokator: */
address Alokasi (infotype X);
/*Mengirimkan address hasil alokasi sebuah elemen
Jika alokasi berhasil, maka address !=Nil,
dan misalnya menghasilkan P, maka Info(P)= x, Next(P)=Nil
Jika alokasi gagal, mengirimkan Nil
*/
void DeAlokasi (address P);
/*I.S : P terdefinisi
F.S : P dikembalikan ke sistem
Melakukan dealokasi/ pengembalian address P ke system
*/

/** { KELOMPOK OPERASI Cek Elemen kosong atau penuh} **/

boolean ListEmpty(List L);
// mengecek apakah jumlah elemen pada List kosong
// mengirimkan true jika List kosong, mengirimkan false jika tidak

/** { KELOMPOK Interaksi operasi linear list, baca tulis } **/
/**Penambahan Elemen***/
void InsVFirst (List *L, infotype X);
/*I.S : L terdefinisi, mungkin kosong
F.S : melakukan alokasi sebuah elemen dan
menambahkan elemen pertama pada List dengan nilai X jika alokasi
berhasil. Jika alokasi gagal IS = FS
*/
void InsVLast (List * L, infotype X);
/*I.S : L terdefinisi, mungkin kosong
F.S : melakukan alokasi sebuah elemen dan
menambahkan elemen terakhir pada List dengan nilai X jika alokasi
berhasil. Jika alokasi gagal IS = FS
*/
void InsVAfter (List * L, infotype X, infotype Y);
/*I.S : L terdefinisi, mungkin kosong
F.S : melakukan alokasi sebuah elemen dengan nilai x dan
menambahkan elemen list setelah y ditemukan pertama kali pada list
*/
/*Penghapusan Elemen*/
void DelVFirst (List * L, infotype *X);
/*I.S : L tidak kosong
F.S : Elemen pertama List dihapus, nilai info disimpan ke X
dan alamat elemen pertama di dealokasi. Sehingga elemen pertama pada List
adalah elemen berikutnya sebelum penghapusan.
*/
void DelVLast (List *L, infotype *X);
/*I.S : L tidak kosong
F.S : Elemen terakhir list dihapus: nilai info disimpan pada X
dan alamat elemen terakhir di dealokasi. Sehingga elemen terakhir pada
List adalah elemen sebelumnya sebelum penghapusan.
*/
void DelVAfter (List * L, infotype *X, infotype Y);
/*I.S : L terdefinisi, mungkin kosong
F.S : melakukan dealokasi sebuah elemen dengan nilai x setelah nilai y
pertama ditemukan pada list.
Nilai x yang dihapus dalam list akan disimpan sebagai keluaran dari
prosedur
*/
void DelAll (List * L);
/* Delete semua elemen list dan alamat elemen di dealokasi */

/*Menampilkan Elemen*/
void PrintInfo (List L);
/* I.S : L terdefinisi, mungkin kosong
F.S : Jika List tidak kosong, menampilkan semua info yang disimpan pada
elemen list ke layar. jika List kosong, hanya menampilkan pesan “list
kosong”
*/

/** KELOMPOK OPERASI LAIN TERHADAP TYPE **/
int NbElmt (List L);
// Mengirimkan banyaknya elemen List atau mengirimkan 0 jika List kosong
address Search (List L, infotype X);
/* Mencari apakah ada elemen list dengan Info (P)= X
Jika ada, mengirimkan address elemen tersebut yang pertama kali ditemukan.
jika tidak ada, mengirimkan Nil
*/
void InversList (List *L);
/* I.S : L sembarang
F.S : Mengubah Elemen list menjadi terbalik, yaitu elemen terakhir
menjadi elemen pertama, elemen kedua menjadi elemen sebelum terakhir dst
Membalik elemen list, tanpa melakukan alokasi / dealokasi
*/
List getNewInversList (List L);
// Mengirimkan list baru, hasil invers dari L


/* TAMBAHAN*/
boolean FSearch (List L, address P);
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
address SearchPrec (List L, infotype X);
/* Mengirimkan address elemen sebelum elemen yang nilainya = X */
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec) = P dan Info(P) 
= X */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec = Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */

void InsertFirst (List * L, address P);
/* IS : L sembarang, P sudah dialokasi */
/* FS : menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (List * L, address P, address Prec);
/* IS : Prec pastilah elemen List dan bukan elemen terakhir */
/* P sudah dialokasi */
/* FS : Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List * L, address P);
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */
/**** Penghapusan sebuah elemen ****/
void DelFirst (List * L, address * P);
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen pertama list sebelum penghapusan */
/* elemen list berkurang satu (mungkin menjadi kosong) */
/* First elemen yang baru adalah suksessor elemen pertama yang lama */
void DelP (List * L, infotype X);
/* IS : L sembarang */
/* FS : Jika ada elemen list beraddress P, dengan Info(P) = X */
/* Maka P dihapus dari list dan di dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast (List * L, address * P);
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen terakhir list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last elemen baru adalah predesessor elemen terakhir yang lama, jika 
ada */
void DelAfter (List * L, address * Pdel, address Prec);
/* IS : L TIDAK Kosong, Prec adalah anggota List */
/* FS : menghapus Next(Prec): Pdel adalah alamat elemen list yang dihapus 
*/
/**** PROSES SEMUA ELEMEN LIST ****/


#endif
