/* --------------------------------------------------------- */
/* File Program : PTR3.CPP */
/* Contoh pengubahan isi suatu variabel melalui pointer*/
/* Tujuan : menggunakan type data pointer dan manipulasinya*/
/* --------------------------------------------------------- */
#include <stdio.h>
int main() {
float d, *pd;
d = 54.5;
printf("Isi d semula = %g\n", d);
pd = &d;
*pd = *pd + 10;
printf("Isi d kini = %g\n", d);
return 0;
}

