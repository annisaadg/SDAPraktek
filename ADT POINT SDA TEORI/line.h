#include "boolean.h"
#include "point.h"
#ifndef LINE_H
#define LINE_H
/* definisi type data */
typedef struct
{ POINT start;
POINT end;
} LINE; // type LINE

/*Fungsi untuk membuat LINE dari 2 nilai Point dari modul pemanggil
pStart : Titik awal bertipe POINT
pEnd : Titik akhir bertipe POINT
*/
LINE CreateLine(POINT pStart, POINT pEnd);
/*Fungsi untuk membuat LINE secara horizontal
pStart : Titik awal bertipe POINT
lengthX : panjang nilai X bertipe int
*/
LINE CreateHorizontalLine(POINT start, int lenghtX);
/*Fungsi untuk membuat LINE secara vertikal
start : Titik awal bertipe POINT
lengthY : panjang nilai Y bertipe int
*/
LINE CreateVerticalLine(POINT start, int lenghtY);
/*Prosedur untuk menampilkan Line ke layar
tampilkan nilai X dan Y dari Titik awal serta nilai X dan Y dari
Titik Akhir
*/
void PrintLine(LINE line);
/*Prosedur untuk memberikan nilai Titik awal bertipe POINT pada

sebuah Line*/
void SetPointStart(POINT pStart, LINE line);

/*Fungsi untuk mendapatkan nilai Titik awal bertipe POINT dari
sebuah Line*/
POINT GetPointStart(LINE line);
/*Prosedur untuk memberikan nilai Titik akhir bertipe POINT pada
sebuah Line*/
void SetPointEnd(POINT pEnd, LINE line);
/*Fungsi untuk mendapatkan nilai Titik awal bertipe POINT dari
sebuah Line */
POINT GetPointEnd(LINE line);
/*Fungsi untuk mengecek apakah nilai parameter line adalah sebuah
LINE atau bukan
Fungsi ini mengembalikan nilai true jika nilai titik awal (x,y)
!= nilai titik akhir (x,y)
dengan asumsi : jika nilai titik awal (x,y) = nilai titik akhir
(x,y) maka bukanlah sebuah line, akan tetapi titik yang bertumpuk
*/
boolean IsLine(LINE line);
/*Fungsi untuk mengecek apakah sebuah Line horizontal atau tidak
Fungsi ini mengembalikan nilai true jika nilai x pada titik awal
= nilai x pada titik akhir
*/
boolean IsHorizontalLine(LINE line);
/*Fungsi untuk mengecek apakah sebuah Line horizontal atau tidak
Fungsi ini mengembalikan nilai true jika nilai y pada titik awal
= nilai y pada titik akhir
*/
boolean IsVerticalLine(LINE line);
/*Fungsi untuk menghitung panjang dari sebuah line dan
mengembalikan nilai integer
panjang dihitung dari nilai titik awal dan titik akhirnya
*/
int LineLength(LINE line);
/*Prosedur untuk mereset Line menjadi nilai null*/
void ResetLine(LINE line);

/*EKSPERIMEN*/
boolean IsDiagonal(LINE line);
/*Mengecek Line diagonal, jika line diagonal kembalikan nilai boolean true.
*/
void CompareLines(LINE line1, LINE line2);
/*Membandingkan 2 Line, tampilkan ke layar mana yang paling panjang.
*/
void TransposeVerticalLine(LINE line);
/*Melakukan transpose Line dari vertikal ke horizontal. Gunakan method IsVerticalLine
untuk mengetahui apakah line berbentuk vertikal atau tidak, jika bukan maka proses transpose
tidak boleh dilakukan.
*/
void TransposeHorizontalLine(LINE line);
/*Melakukan transpose Line dari horizontal ke vertical. Gunakan method isHorizontalLine
untuk mengetahui apakah line berbentuk horizontal atau tidak, jika bukan maka proses
transpose tidak boleh dilakukan
*/
int ResizeHorizontalLine(LINE line, int size);
/*Menambah panjang Line yang berbentuk horizontal ke arah kanan (Titik Akhir) senilai angka
yang diinputkan oleh user. Gunakan method isHorizontalLine untuk mengecek apakah
line berbentuk horizontal atau tidak. Jika bukan, maka proses penambahan panjang tidak boleh
dilakukan.
*/

#endif
