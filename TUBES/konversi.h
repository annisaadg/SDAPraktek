/** Nama File : konversi.h
 *  Deskripsi : Header File Billings
 *  Oleh      : Dhafin Rizqi Fadhilah
 *  Tanggal   : 
 */

#ifndef BILLINGS_H
#define BILLINGS_H
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

/* Menampilkan waktu berupa tanggal saat kurs diambil
 * I.S. : Waktu belum tampil
 * F.S. : Waktu sudah ditampilkan
 */
void tanggalKurs();

/* Mengubah Rupiah ke Dollar
 * I.S. : Mata uang masih berjenis Rupiah
 * F.S. : 	
 */
void convertRupiahtoDollar();

/* Mengubah Dollar ke Rupiah
 * I.S. : Mata uang masih berjenis Dollar
 * F.S. : Mata uang sudah dikonversi menjadi Rupiah
 */
void convertDollartoRupiah();

/* Mengubah Rupiah ke Yen
 * I.S. : Mata uang masih berjenis Rupiah
 * F.S. : Mata uang sudah dikonversi menjadi Yen
 */
void convertRupiahtoYen();

/* Mengubah Yen ke Rupiah
 * I.S. : Mata uang masih berjenis Yen
 * F.S. : Mata uang sudah dikonversi menjadi Rupiah
 */
void convertYentoRupiah();

/* Mengubah Rupiah ke Euro
 * I.S. : Mata uang masih berjenis Rupiah
 * F.S. : Mata uang sudah dikonversi menjadi Euro
 */
void convertRupiahtoEuro();

/* Mengubah Euro ke Rupiah
 * I.S. : Mata uang masih berjenis Euro
 * F.S. : Mata uang sudah dikonversi menjadi Rupiah
 */
void convertEurotoRupiah();

#endif
