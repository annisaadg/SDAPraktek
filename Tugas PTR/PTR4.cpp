/* ---------------------------------------------------------
*/ /* File Program : PTR4.CPP */
/* Contoh operasi pemakaian pointer*/
/* Tujuan : melakukan operasi pada nilai yang ditunjuk pada pointer*/
/* --------------------------------------------------------- */
#include <stdio.h>
int main() {
int z, s, *pz, *ps;
z = 20;
printf("z = %d, ",z);
s = 30;
pz = &z;
ps = &s;
*pz = *pz + *ps; 	/* assignment nilai dari alamat yang ditunjuk
					   pz ditambah nilai dari alamat yang ditunjuk ps
					   */
printf("s = %d, z+s = %d\n", s , z);
return 0;
}

