/* ---------------------------------------------------------
*/ /* File Program : PTR6.CPP */
/* Contoh pointer menunjuk ke array*/
/* Tujuan : memahami operasi pointer yang menunjuk kepada array*/
/* --------------------------------------------------------- */
#include <stdio.h>
int main() {
/* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
static int tgl_lahir[] = {18, 6, 1989}; 	/* variabel static untuk menyimpan nilai permanen dalam memori.
												variabel tersebut akan menyimpan nilai terakhir yang diberikan*/
int *ptgl;
ptgl = tgl_lahir;
printf("Nilai yang ditunjuk oleh ptgl = %d\n", *ptgl);
printf("Nilai dari tgl_lahir[0] = %d\n", tgl_lahir[0]);
printf("Nilai dari tgl_lahir[0] = %d\n", tgl_lahir[1]);
printf("Nilai dari tgl_lahir[0] = %d\n", tgl_lahir[2]);
return 0;
}

