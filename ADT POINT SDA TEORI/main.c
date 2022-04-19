#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "line.h"

void programPOINT();
void programLINE();

int main(int argc, char *argv[]) {
	
	programPOINT();
	programLINE();
	
}

void programPOINT(){
	POINT p;
 	int x=0, y=0, m=0, n=0;
 	printf("===== PROGRAM POINT =====\n");
 	/*Buat Point ke-1 menggunakan method CreatePoint, dimana nilai x dan y diambil dari
   inputan User*/
 	printf("\n\xaf\xaf Masukkan Koordinat POINT p: ");
 	scanf("%d %d", &x, &y); // input atribut point dari user
	p = CreatePoint(x,y); // buat point dari inputan user
  
 	/*Tampilkan Point ke-1 dengan method PrintPoint*/
 	printf("   POINT p berada pada koordinat : \n");
 	PrintPoint(p);
 
 	/*Tampilkan koordinat X dari Point ke-1 menggunakan method GetX
   Tampilkan Koordinat Y dari Point ke-1 menggunakan method GetY*/
 	printf("\n   Koordinat: (%d,%d)\n", GetX(p), GetY(p));
 
 	/*Buat Point ke-2 menggunakan method MakePoint, dimana nilai x dan y diambil dari
   inputan User*/
 	POINT q;
 	printf("\xaf\xaf Masukkan Koordinat POINT q: ");
 	scanf("%d %d", &m, &n); 
 	MakePoint(&q,m,n);
  
 	/*Tampilkan Point ke-2 dengan method PrintPoint*/
 	printf("   POINT q berada pada koordinat : ");
 	PrintPoint(q);
 
 	/*Tampilkan koordinat X dari Point ke-2 menggunakan method GetX
   Tampilkan Koordinat Y dari Point ke-2 menggunakan method GetY*/
 	printf("\n   Koordinat: (%d,%d)\n", GetX(q), GetY(q));
 
 	/*Hitung dan tampilkan jarak antara Poin ke-1 dan Point ke-2 menggunakan method Jarak*/
 	printf("   Jarak POINT p dan POINT q: %d", Jarak(p,q));
 
 	/*Reset Point ke-1 menggunakan method ReSet*/
 	ReSet(&p);
 
 	/*Set nilai X dan Y untuk Point ke-2 menggunakan method SetX, dimana nilainya diambil dari
   inputan user*/
 	printf("\n\xaf\xaf Masukkan Set Ulang X dan Y untuk POINT q: ");
 	scanf("%d",&m);
 	scanf("%d",&n);
 	SetX(&q,m);
 	SetY(&q,n);
 
 	/*Tampilkan point ke-1 dan point ke-2*/
 	printf("\nPOINT p: ");
 	PrintPoint(p);
 	printf("\nPOINT q: ");
}

void programLINE(){
	printf("\n\n===== PRORAM LINE =====\n\n");
	LINE line1, line2, line3;
	POINT point1a, point1b, point2a, point2b, point3a, point3b;
	int g=0, h=0, i=0, j=0, k=0, l=0, m=0, n=0, o=0, p=0, q=0, r=0;
	int panjang1=0, panjang2=0;
	
	/*Buat Line ke-1 menggunakan method CreateLine dengan input point start (x,y) dan
	  point end (x,y) dari user*/
	  printf("\xaf\xaf Masukkan point start untuk LINE 1	: ");
	  scanf("%d %d", &g, &h);
	  printf("\xaf\xaf Masukkan point end untuk LINE 1	: ");
	  scanf("%d %d", &i, &j);
	  point1a = CreatePoint(g,h);
	  point1b = CreatePoint(i,j);
	  line1 = CreateLine(point1a,point1b);
	  
	/*Tampilkan Line ke-1 dengan PrintLine*/
	  printf("   Koordinat awal dan akhir LINE 1");
	  PrintLine(line1);
	  
	/*Tampilkan Point Start dari Line ke-1 menggunakan method GetPointStart GetPointEnd*/
	  printf("\n\xaf\xaf Point start LINE 1");
	  GetPointStart(line1);
	  GetPointEnd(line1);
	
	/*Hitung panjang Line ke-1 menggunakan method LineLength dan tampilkan ke layar*/
	  printf("\n\xaf\xaf Panjang LINE 1\n   %d",LineLength(line1));
	  
	/*Buat Line ke-2 menggunakan method CreateHorizontalLine, dengan input point
     start dan panjang x dari user.*/
   	 printf("\n\n\xaf\xaf Masukkan point start untuk LINE 2	: ");
     scanf("%d %d", &k, &l);
     point2a = CreatePoint(k,l);
     printf("\xaf\xaf Masukkan panjang LINE 2		: ");
     scanf("%d",&panjang1);
     point2b = CreatePoint(k+panjang1,l);
     
    /*Tampilkan Line ke-2 dengan method PrintPoint*/
      printf("\xaf\xaf Start Point LINE 2\n");
      PrintPoint(point2a);
      printf("\n\xaf\xaf End Point LINE 2	\n");
      PrintPoint(point2b);
      
    /*Hitung panjang Line ke-2 menggunakan method LineLength dan tampilkan ke layar*/
   	 line2 = CreateHorizontalLine(point2a,panjang1);
     //CreateLine(point2a,point2b);
     printf("\n\xaf\xaf Panjang LINE 1\n   %d",LineLength(line2));
     
    /*Set Point End dari Line ke-2 menggunakan method SetPointEnd, dimana nilainya
     diambil dari inputan user*/
     printf("\n\xaf\xaf Masukkan Set End Point LINE 2 	: ");
     scanf("%d %d", &m, &n);
     point2b = CreatePoint(m,n);
     SetPointEnd(point2b,line2);
     
    /*Buat Line ke-3 menggunakan method CreateVerticalLine dengan inputan : Point
     Start (5,10) dan Point End (5,10)*/
     printf("\n\xaf\xaf Point Start LINE 3	: (5,10)\n   Point End LINE 3	: (5,10)\n");
     point3a = CreatePoint(5,10);
     panjang2 = 0;
     point3b = CreatePoint(5,10);
     line3 = CreateVerticalLine(point3a,panjang2);
     
    /*Cek Line ke-3 apakah sebuah Line atau tidak menggunakan method IsLine. Jika false,
     Reset Line ke-3 menggunakan method ResetLine.*/  
     if(!IsLine(line3)){
     	printf("\n\xaf\xaf LINE 3 isn't a line");
    	ResetLine(line3);
   	 }
   	 
   	/*Cek Line ke-1 dan Line ke-2 menggunakan method isVerticalLine dan
     isHorizontalLine lalu tampilkan ke layar.*/
     
     if(IsHorizontalLine(line1)){
     	printf("\n\n\xaf\xaf Line 1 is Horizontal Line");
	 }else if(IsVerticalLine(line1)){
	 	printf("\n\n\xaf\xaf Line 1 is Vertical Line");
	 }else{
	 	printf("\n\n\xaf\xaf Line 1 is not vertical or horizontal");
	 }
	 
	 if(IsHorizontalLine(line2)){
     	printf("\n\n\xaf\xaf Line 2 is Horizontal Line");
	 }else if(IsVerticalLine(line2)){
	 	printf("\n\n\xaf\xaf Line 2 is Vertical Line");
	 }else{
	 	printf("\n\n\xaf\xaf Line 2 is not vertical or horizontal");
	 }
	 
	 
	printf("\n\n\n===== PROGRAM EKSPERIMEN =====\n");
	int compare;
	
	/*Mengecek Line diagonal, jika line diagonal kembalikan nilai boolean true.*/
	if(IsDiagonal(line1) && !IsVerticalLine(line1) && !IsHorizontalLine(line1)){
		printf("\n\xaf\xaf LINE 1 is diagonal");
	}else{
		printf("\n\xaf\xaf LINE 1 is not diagonal");
	}
	if(IsDiagonal(line2) && !IsVerticalLine(line2) && !IsHorizontalLine(line2)){
		printf("\n\xaf\xaf LINE 2 is diagonal");
	}else{
		printf("\n\xaf\xaf LINE 2 is not diagonal");
	}
	if(IsDiagonal(line3) && !IsVerticalLine(line3) && !IsHorizontalLine(line3)){
		printf("\n\xaf\xaf LINE 3 is diagonal");
	}else{
		printf("\n\xaf\xaf LINE 3 is not diagonal");
	}
	
	/*Membandingkan 2 Line, tampilkan ke layar mana yang paling panjang.*/
	printf("\n\n\xaf\xaf Perbandingan panjang antara LINE 1 dan LINE 2");
	CompareLines(line1,line2);
	
	/*Melakukan transpose Line dari vertikal ke horizontal. Gunakan method IsVerticalLine
	  untuk mengetahui apakah line berbentuk vertikal atau tidak, jika bukan maka proses transpose
	  tidak boleh dilakukan.*/
	if(IsVerticalLine(line1)){
		printf("\n\n\xaf\xaf LINE 1 setelah di transpose dari vertikal ke horizontal");
		TransposeVerticalLine(line1);
	}
	if(IsVerticalLine(line2)){
		printf("\n\n\xaf\xaf LINE 2 setelah di transpose dari vertikal ke horizontal");
		TransposeVerticalLine(line2);
	}
	
	/*Melakukan transpose Line dari horizontal ke vertical. Gunakan method isHorizontalLine
	  untuk mengetahui apakah line berbentuk horizontal atau tidak, jika bukan maka proses
	  transpose tidak boleh dilakukan*/
	if(IsHorizontalLine(line1)){
		printf("\n\n\xaf\xaf LINE 1 setelah di transpose dari horizontal ke vertikal");
		TransposeHorizontalLine(line1);
	}
	if(IsHorizontalLine(line2)){
		printf("\n\n\xaf\xaf LINE 2 setelah di transpose dari horizontal ke vertikal");
		TransposeHorizontalLine(line2);
	}
	
	/*Menambah panjang Line yang berbentuk horizontal ke arah kanan (Titik Akhir) senilai angka
	  yang diinputkan oleh user. Gunakan method isHorizontalLine untuk mengecek apakah
	  line berbentuk horizontal atau tidak. Jika bukan, maka proses penambahan panjang tidak boleh
  	  dilakukan.*/
  	int tambah;
  	if(IsHorizontalLine(line1)){
  		printf("\n\n\xaf\xaf Masukkan nilai resize panjang Line 1 ke arah kanan	: ");
  		scanf("%d",&tambah);
  		printf("\xaf\xaf LINE 1 setelah di-resize");
  		ResizeHorizontalLine(line1,tambah);
	  }
	if(IsHorizontalLine(line2)){
  		printf("\n\n\xaf\xaf Masukkan nilai resize panjang Line 2 ke arah kanan	: ");
  		scanf("%d",&tambah);
  		printf("\xaf\xaf LINE 2 setelah di-resize");
  		ResizeHorizontalLine(line2,tambah);
	  }
}
