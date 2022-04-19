/* File main.c untuk Main Driver ADT Stack */ 
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void ShowMenu(){ 
	printf("==== PRAKTIKUM STACK ====");
	printf("\n1. Push");
	printf("\n2. Pop");
	printf("\n3. Print Stack");
	printf("\n4. Quit");
}
/*Prosedur untuk menampilkan menu operasi stack*/

int main() {
	/* Menampilkan Menu pada saat program dijalankan */
     ShowMenu(); 
     
	

	/* Membuat Stack */
	stack s;
	createstack(&s);

	int pilihan, nilai_stack;
	do{
		/*Mengambil input piliham menu dari user */
		printf("\nMasukkan Pilihan anda : ");
		scanf("%d", &pilihan);
		
		/* Jika user memilih menu Push */
		if(pilihan == 1){
			/* Ambil input angka dari user */
			printf("Masukkan nilai yang akan dimasukkan ke stack : ");		
			scanf("%d", &nilai_stack);
			
			/* Push angka ke stack */
			push(&s, nilai_stack);
			
			/* Tampilkan menu lagi */
			ShowMenu();
		}
		
		if(pilihan == 2){
			tabstack *p;
			/* Pop data teratas */
			p = top(s);
			pop(&s, &(info(p)));
			/* Tampilkan informasi bahwa data terlah berhasil di pop*/
			printf("Berhasil di Pop");
			/* Tampilkan menu lagi */
			ShowMenu();
}
		
		if(pilihan == 3){
			/* Tampilkan isi dari stack */
			printf("\nIsi dari Stack :\n");
			cetakstack(s);
			
			/* Tampilkan jumlah dari stack */
			printf("\n========== %d (Tumpukan)==========\n\n", top(s));
			
			/* Tampilkan menu lagi */	
			ShowMenu();
		}
	}while(pilihan < 4);
	
	return 0;
}

