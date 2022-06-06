#include <stdio.h>
#include <conio.h>
#include <windows.h>

void SetColor(unsigned short);

int main(int argc, char *argv[]) {
	
	SetColor(6);
	puts("Hello World!");
	SetColor(15);
	puts("Hello World!");
	SetColor(14);
	puts("Hello World!");
	
	SetColor(13);
	puts("Hello World!");
	SetColor(12);
	puts("Hello World!");
	
	
	SetColor(55);
	puts("Hello World!");
	SetColor(64);
	puts("Hello World!");
	SetColor(83);
	puts("Hello World!");
	SetColor(92);
	puts("Hello World!");
	SetColor(31);
	puts("Hello World!");
	SetColor(20);
	puts("Hello World!");
	SetColor(11);
	puts("Hello World!");
	SetColor(10);
	puts("Hello World!");
	SetColor(9);
	puts("Hello World!");
	SetColor(8);
	puts("Hello World!");
	SetColor(7);
	puts("Hello World!");
	SetColor(5);
	puts("Hello World!");
	SetColor(4);
	puts("Hello World!");
	SetColor(3);
	puts("Hello World!");
	puts("Hello World!");
	SetColor(1);
	puts("Hello World!");
	SetColor(0);
	puts("Hello World!");
	getch();
	fflush(stdin);
	return(0);
}

void SetColor(unsigned short color) {
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleOutput,color);
}
