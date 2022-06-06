/** Nama File : billings.h
 *  Deskripsi : Header Body Billings
 *  Oleh      : Annisa Dinda Gantini
 *  Tanggal   : 
 */

#ifndef BILLINGS_H
#define BILLINGS_H
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

/* Menghitung harga item setelah diberi/ tidak diberi diskon
 * I.S. : Harga belum termasuk diskon
 * F.S. : Harga sudah termasuk diskon
 */
float hitungHarga(float harga, float disc);

/* Menghitung harga diskon item
 * I.S. : Harga diskon belum diketahui
 * F.S. : Harga diskon sudah diketahui
 */
float hitungDiskon(int jmlh, float temp, float disc);

/* Menghitung tax attau pajak dari seluruh belanjaan
 * I.S. : Jumlah tax belum diketahui
 * F.S. : Jumlah tax sudah diketahui
 */
float hitungTax(float tsh);

/* Menghitung total harga belanja 
 * I.S. : Total harga belanja belum dikeatahui
 * F.S. : Total harga belanja sudah dikeatahui
 */
float hitungTsh(float tsh);

/* Menghitung jumlah kembalian setelah user melakukan pembayaran 
 * I.S. : Total harga kembalian belum dikeatahui
 * F.S. : Total harga kembalian belum dikeatahui
 */
float hitungKembalian(float pmbyr, float tsh);

/* Menghitung jumlah kembalian jika pembayaran yang dilakukan kurang
 * I.S. : Total harga minus kembalian belum dikeatahui
 * F.S. : Total harga minus kembalian belum dikeatahui
 */
float hitungMinus(float kmbl);

#endif
