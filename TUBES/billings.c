/** Nama File : billings.c
 *  Deskripsi : File Body Billings
 *  Oleh      : Annisa Dinda Gantini
 *  Tanggal   : 
 */

#include "billings.h"


/* Menghitung harga item setelah diberi/ tidak diberi diskon
 * I.S. : Harga belum termasuk diskon
 * F.S. : Harga sudah termasuk diskon
 */
float hitungHarga(float harga, float disc){
	float hrg;
	hrg = harga - (harga*(disc/100));
	return hrg;
}

/* Menghitung harga diskon item
 * I.S. : Harga diskon belum diketahui
 * F.S. : Harga diskon sudah diketahui
 */
float hitungDiskon(int jmlh, float temp, float disc){
	float dis;
	dis = jmlh*(temp*(disc/100));
	return dis;
}

/* Menghitung tax attau pajak dari seluruh belanjaan
 * I.S. : Jumlah tax belum diketahui
 * F.S. : Jumlah tax sudah diketahui
 */
float hitungTax(float tsh){
	float tax;
	tax=tsh*(0.1);
	return tax;
}

/* Menghitung total harga belanja 
 * I.S. : Total harga belanja belum dikeatahui
 * F.S. : Total harga belanja sudah dikeatahui
 */
float hitungTsh(float tsh){
	float total;
	total = tsh+(tsh*0.1);
	return total;
}

/* Menghitung jumlah kembalian setelah user melakukan pembayaran 
 * I.S. : Total harga kembalian belum dikeatahui
 * F.S. : Total harga kembalian belum dikeatahui
 */
float hitungKembalian(float pmbyr, float tsh){
	float pay;
	pay = pmbyr-tsh; 
	return pay;
}
   
/* Menghitung jumlah kembalian jika pembayaran yang dilakukan kurang
 * I.S. : Total harga minus kembalian belum dikeatahui
 * F.S. : Total harga minus kembalian belum dikeatahui
 */
float hitungMinus(float kmbl){
	float hutang;
	hutang =-1*kmbl;
	return hutang;
}

