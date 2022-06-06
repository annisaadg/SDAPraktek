/* --------------------------------------------------------- */
/* File Program : PTR2.CPP */
/* Contoh pemakaian pointer yang salah */
/* Tujuan : mengetahui panjang dan posisi variabel di memory */
/* --------------------------------------------------------- */
#include <stdio.h>
int main() {
float *pu;
float nu;
int u = 1234;
pu = &u;
nu = *pu;
printf("u = %d\n", u);
printf("nu = %f\n", nu);
return 0;
}

