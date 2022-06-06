/* --------------------------------------------------------- */
/* File Program : PTR1.CPP */
/* Contoh pemakaian pointer */
/* Tujuan : mengetahui panjang dan posisi variabel di memory */
/* --------------------------------------------------------- */

#include <stdio.h>
int main() {
int x, y;
int *px;	// lambang pointer p untuk mengambil alamat dari suatu variabel
x = 87;
//px = &x;	// variabel px mengambil address dari variabel nilai x
y = *px;
y = *px;	// variabel y mengambil nilai dari alamat yang ditunjuk px
printf("Alamat x = %p\n", &x);
printf("Isi px = %d\n", x);
printf("Nilai yang ditunjuk oleh px = %d\n", *px);
printf("Nilai y = %d\n", y);
printf("Alamat y = %p\n", &y);
return 0;
}

