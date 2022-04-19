#include "boolean.h"
#include "point.h"
#include "line.h"

LINE CreateLine(POINT pStart, POINT pEnd)
/*Prosedur untuk menampilkan Line ke layar
tampilkan nilai X dan Y dari Titik awal serta nilai X dan Y dari
Titik Akhir
*/
{
	LINE P;
	
	/*P.start.x = pStart.x;
	P.end.x = pEnd.x;
	P.start.y = pStart.y;
	P.end.y = pEnd.y;
	*/
	P.start = pStart;
	P.end = pEnd;
	
	return P;
}

LINE CreateHorizontalLine(POINT start, int lenghtX)
/*Fungsi untuk membuat LINE secara horizontal
pStart : Titik awal bertipe POINT
lengthX : panjang nilai X bertipe int
*/
{
	LINE P;
	P.start.x = start.x;
	P.start.y = start.y;
	P.end.x = start.x + lenghtX;
	P.end.y = start.y;
	return P;
}

LINE CreateVerticalLine(POINT start, int lenghtY)
/*Fungsi untuk membuat LINE secara vertikal
start : Titik awal bertipe POINT
lengthY : panjang nilai Y bertipe int
*/
{
	LINE P;
	P.start.y = start.y;
	P.end.y = P.start.y + lenghtY;
	return P;
}

void PrintLine(LINE line)
/*Prosedur untuk memberikan nilai Titik awal bertipe POINT pada
sebuah Line*/
{
	printf("\n   (%d,%d) ", line.start.x, line.start.y);
	printf("\n   (%d,%d) ", line.end.x, line.end.y);
}

void SetPointStart(POINT pStart, LINE line)
/*Fungsi untuk mendapatkan nilai Titik awal bertipe POINT dari
sebuah Line*/
{
	pStart.x = line.start.x;
	pStart.y = line.start.y;
	
}

POINT GetPointStart(LINE line)
/*Prosedur untuk memberikan nilai Titik akhir bertipe POINT pada
sebuah Line*/
{
	printf("\n   Point Start		: (%d,%d)", line.start.x, line.start.y);
}

void SetPointEnd(POINT pEnd, LINE line)
/*Fungsi untuk mendapatkan nilai Titik awal bertipe POINT dari
sebuah Line */
{
	pEnd.x = line.end.x;
	pEnd.y = line.end.y;
}

POINT GetPointEnd(LINE line)
/*Fungsi untuk mengecek apakah nilai parameter line adalah sebuah
LINE atau bukan
Fungsi ini mengembalikan nilai true jika nilai titik awal (x,y)
!= nilai titik akhir (x,y)
dengan asumsi : jika nilai titik awal (x,y) = nilai titik akhir
(x,y) maka bukanlah sebuah line, akan tetapi titik yang bertumpuk
*/
{
	printf("\n   Point End		: (%d,%d)", line.end.x, line.end.y);
}

boolean IsLine(LINE line)
/*Fungsi untuk mengecek apakah nilai parameter line adalah sebuah
LINE atau bukan
Fungsi ini mengembalikan nilai true jika nilai titik awal (x,y)
!= nilai titik akhir (x,y)
dengan asumsi : jika nilai titik awal (x,y) = nilai titik akhir
(x,y) maka bukanlah sebuah line, akan tetapi titik yang bertumpuk
*/
{
	return ((line.start.x != line.end.x) && (line.start.y != line.end.y));
}

boolean IsHorizontalLine(LINE line)
/*Fungsi untuk mengecek apakah sebuah Line horizontal atau tidak
Fungsi ini mengembalikan nilai true jika nilai x pada titik awal
= nilai x pada titik akhir
*/
{
	return ((line.start.y == line.end.y) && (line.start.x != line.end.x));
}

boolean IsVerticalLine(LINE line)
/*Fungsi untuk mengecek apakah sebuah Line vertikal atau tidak
Fungsi ini mengembalikan nilai true jika nilai y pada titik awal
= nilai y pada titik akhir
*/
{
	return ((line.start.x == line.end.x) && (line.start.y != line.end.y));
}

int LineLength(LINE line)
/*Fungsi untuk menghitung panjang dari sebuah line dan
mengembalikan nilai integer
panjang dihitung dari nilai titik awal dan titik akhirnya
*/
{
	return Jarak(line.start, line.end);
}

void ResetLine(LINE line)
/*Prosedur untuk mereset Line menjadi nilai null*/
{
	line.start.x = 0;
	line.end.x = 0;
	line.start.y = 0;
	line.end.y = 0;
	PrintLine(line);
}

/*EKSPERIMEN*/
boolean IsDiagonal(LINE line)
/*Mengecek Line diagonal, jika line diagonal kembalikan nilai boolean true.
*/
{
	return(abs(line.end.x-line.start.x)==abs(line.end.y-line.start.y));
}

void CompareLines(LINE line1, LINE line2)
/*Membandingkan 2 Line, tampilkan ke layar mana yang paling panjang.
*/
{
	if(LineLength(line1)>LineLength(line2)){
		printf("\n   LINE 1 lebih panjang");
	}else if (LineLength(line1)<LineLength(line2)){
		printf("\n   LINE 2 lebih panjang");
	}else if(LineLength(line1)==LineLength(line2)){
		printf("\n   LINE 1 dan LINE 2 sama panjang");
	}
}

void TransposeVerticalLine(LINE line)
/*Melakukan transpose Line dari vertikal ke horizontal. Gunakan method IsVerticalLine
untuk mengetahui apakah line berbentuk vertikal atau tidak, jika bukan maka proses transpose
tidak boleh dilakukan.
*/
{
	int tmp;
	
	tmp = line.start.x;
	line.start.x = line.start.y;
	line.start.y = tmp;
	
	tmp = line.end.x;
	line.end.x = line.end.y;
	line.end.y = tmp;
	PrintLine(line);
	
}

void TransposeHorizontalLine(LINE line)
/*Melakukan transpose Line dari horizontal ke vertical. Gunakan method isHorizontalLine
untuk mengetahui apakah line berbentuk horizontal atau tidak, jika bukan maka proses
transpose tidak boleh dilakukan
*/
{
	int tmp;
	
	tmp = line.start.x;
	line.start.x = line.start.y;
	line.start.y = tmp;
	
	tmp = line.end.x;
	line.end.x = line.end.y;
	line.end.y = tmp;
	PrintLine(line);
}

int ResizeHorizontalLine(LINE line, int size)
/*Menambah panjang Line yang berbentuk horizontal ke arah kanan (Titik Akhir) senilai angka
yang diinputkan oleh user. Gunakan method isHorizontalLine untuk mengecek apakah
line berbentuk horizontal atau tidak. Jika bukan, maka proses penambahan panjang tidak boleh
dilakukan.
*/
{
	line.start.x = line.start.x;
	line.end.x = line.end.x+size;
	line.start.y = line.start.y;
	line.end.y = line.end.y;
	PrintLine(line);
}
