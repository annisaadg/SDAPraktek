/*
 Program : mahasiswa.h
 Author : 211524003, Annisa Dinda Gantini
 Kelas : 1A
 Deskripsi: Header file dari list mahasiswa
 Tanggal : 9/3/2022
*/

#ifndef _MAHASISWA_H
#define _MAHASISWA_H
#include "boolean.h"
#include <stdio.h>
#include <conio.h>
#define Nil NULL
#define Info(P) (P)->info
#define Nama(P) (P)->nama
#define TinggiBadan(P) (P)->tb
#define Next(P) (P)->next
#define First(L) (L).First

/** Definisi ABSTRACT DATA TYPE List **/
/*Definisi List :*/
/* List kosong ===> First (L) =Nil
Setiap elemen dengan address P dapat diacu Nama (P), TinggiBadan (P), dan Next (P);
Elemen terakhir list ===> Jika addressnya Last maka Next (Last) = Nil
*/
typedef struct tElmtList *address; // pointer menunjuk ke alamat tElmtList
typedef char *namaMhs;
typedef int tinggiBadan;

typedef struct tElmtList{
	namaMhs nama;
	tinggiBadan tb;
 	address next;
} Mahasiswa;
typedef struct{
 	address First;
} List;

/* Prototype Linear List */
/* Konstruktor membentuk List */
void CreateList(List *L);
/* I.S : L terdefinisi, tidak diketahui nilainya
F.S : L diinisialisasi first(L) = nil
*/
Mahasiswa CreateMahasiswa(char *nama, int tinggi);

/* Destruktor/Dealokator: */
address Alokasi(Mahasiswa X);
/*Mengirimkan address hasil alokasi sebuah elemen
Jika alokasi berhasil, maka address !=Nil,
dan misalnya menghasilkan P, maka Info(P)= x, Next(P)=Nil
Jika alokasi gagal, mengirimkan Nil
*/
void DeAlokasi(address *P);
/*I.S : P terdefinisi
F.S : P dikembalikan ke sistem
Melakukan dealokasi/ pengembalian address P ke system
*/

/** { KELOMPOK OPERASI Cek Elemen (VALIDATOR) } **/
boolean isListEmpty(List L);
// mengecek apakah jumlah elemen pada List kosong
// mengirimkan true jika List kosong, mengirimkan false jika tidak
boolean isValid(Mahasiswa M);
boolean isEqual(Mahasiswa X, Mahasiswa Y);

/** { GETTER/SETTER } **/
char* GetName(Mahasiswa M);
void SetName(Mahasiswa *M, char *nama);
int GetTb(Mahasiswa M);
void SetTb(Mahasiswa *M, int tb);

/** {KELOMPOK Interaksi operasi linear list} **/

/**Penambahann Elemen Berdasarkan Nilai**/
void InsVFirst (List *L, Mahasiswa X);
/*I.S : L terdefinisi, mungkin kosong
F.S : melakukan alokasi sebuah elemen dan
menambahkan elemen pertama pada List dengan nilai X jika alokasi
berhasil. Jika alokasi gagal IS = FS
*/
void InsVLast (List *L, Mahasiswa X);
/*I.S : L terdefinisi, mungkin kosong
F.S : melakukan alokasi sebuah elemen dan
menambahkan elemen terakhir pada List dengan nilai X jika alokasi
berhasil. Jika alokasi gagal IS = FS
*/
void InsVAfter (List *L, Mahasiswa X, Mahasiswa Y);
/*I.S : L terdefinisi, mungkin kosong
F.S : melakukan alokasi sebuah elemen dengan nilai x dan
menambahkan elemen list setelah y ditemukan pertama kali pada list
*/
void InsertSort(List *L, Mahasiswa X);

/**Penambahann Elemen Berdasarkan Address**/
void InsAFirst(List *L, address P);
/* IS : L sembarang, P sudah dialokasi */
/* FS : menambahkan elemen ber-address P sebagai elemen pertama */
void InsALast(List *L, address P);
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */
void InsAAfter (List * L, address P, address Prec);
/* IS : Prec pastilah elemen List dan bukan elemen terakhir */
/* P sudah dialokasi */
/* FS : Insert P sebagai elemen sesudah elemen beralamat Prec */


/**Pengurangan Elemen Berdasarkan Nilai**/
void DelVFirst (List *L, Mahasiswa *M);
/*I.S : L tidak kosong
F.S : Elemen pertama List dihapus, nilai info disimpan ke X
dan alamat elemen pertama di dealokasi. Sehingga elemen pertama pada List
adalah elemen berikutnya sebelum penghapusan.
*/
void DelP (List *L, Mahasiswa M);
/* IS : L sembarang */
/* FS : Jika ada elemen list beraddress P, dengan Info(P) = X */
/* Maka P dihapus dari list dan di dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap 
*/
/* List mungkin menjadi kosong karena penghapusan */
void DelVLast (List *L, Mahasiswa *M);
/*I.S : L tidak kosong
F.S : Elemen terakhir list dihapus: nilai info disimpan pada X
dan alamat elemen terakhir di dealokasi. Sehingga elemen terakhir pada
List adalah elemen sebelumnya sebelum penghapusan.
*/
void DelVAfter (List *L, namaMhs *N, namaMhs M, tinggiBadan *X);
/*I.S : L terdefinisi, mungkin kosong
F.S : melakukan dealokasi sebuah elemen dengan nilai x setelah nilai y
pertama ditemukan pada list.
Nilai x yang dihapus dalam list akan disimpan sebagai keluaran dari
prosedur
*/
void DelAll (List *L);
void DelEqual(address head);

/**Pengurangan Elemen Berdasarkan Address**/
void DelAFirst (List *L, address * P);
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen pertama list sebelum penghapusan */
/* elemen list berkurang satu (mungkin menjadi kosong) */
/* First elemen yang baru adalah suksessor elemen pertama yang lama 
*/
void DelALast (List *L, address * P);
/* FS : P adalah alamat elemen terakhir list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last elemen baru adalah predesessor elemen terakhir yang lama, 
jika ada */
void DelAAfter (List * L, address * Pdel, address Prec);
/* IS : L TIDAK Kosong, Prec adalah anggota List */
/* FS : menghapus Next(Prec): Pdel adalah alamat elemen list yang 
dihapus */
void DelAll (List *L);
/* Delete semua elemen list dan alamat elemen di dealokasi */
void DelEqual(address head);

/*Menampilkan Elemen*/
void PrintMahasiswa(Mahasiswa M);
void PrintInfo(List L);
void PrintInfo (List L);
/* I.S : L terdefinisi, mungkin kosong
F.S : Jika List tidak kosong, menampilkan semua info yang disimpan pada
elemen list ke layar. jika List kosong, hanya menampilkan pesan “list
kosong”
*/

/** KELOMPOK OPERASI LAIN TERHADAP TYPE **/
/* Operasi pencarian */
address Search (List L, Mahasiswa X);
/* Mencari apakah ada elemen list dengan Info (P)= X
Jika ada, mengirimkan address elemen tersebut yang pertama kali ditemukan.
jika tidak ada, mengirimkan Nil
*/
address SearchNama (List L, namaMhs N);
address SearchPrec (List L, Mahasiswa X);

int NbElmt (List L);
// Mengirimkan banyaknya elemen List atau mengirimkan 0 jika List kosong
List NewList (List L, int Tb);
// Mengirimkan list baru, hasil invers dari L

#endif
