/* ---------------------------------------------------------
*/ /* File Program : PTR8a.CPP */
/* Contoh Pointer dan String bagian ke-2*/
/* Tujuan : memahami operasi menukarkan isi dua buah string TANPA pemakaian
pointer */
/* --------------------------------------------------------- */
#include <stdio.h>
#include <string.h>
#define PANJANG 20	// mendeklarasikan bahwa nilai dari PANJANG adalah 20
int main() {
/* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
char nama1[PANJANG] = "DEWI SARTIKA";
char nama2[PANJANG] = "SULTAN HASANUDDIN";
char namaX[PANJANG];
puts("Nama semula : ");
printf("Nama 1 --> %s\n", nama1);
printf("Nama 2 --> %s\n", nama2);
/* Pertukaran string */
strcpy(namaX, nama1);	// menukar nilai variabel namaX dengan variabel nama1
strcpy(nama1, nama2);	// menukar nilai variabel nama1 dengan variabel nama2
strcpy(nama2, namaX);	// menukar nilai variabel nama2 dengan variabel namaX
puts("Nama sekarang : ");
printf("Nama 1 --> %s\n", nama1);
printf("Nama 2 --> %s\n", nama2);
return 0;
}

