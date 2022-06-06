/** Nama File : main.c
 *  Deskripsi : Main Driver Kalkulator
 *  Oleh      : -Zacky Faishal Abror
 *				-Annisa Dinda Gantini
 *				-Dhafin Rizqi Fadhilah
 *  Tanggal   : 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "kalkulator.h"
#include "billings.h"
#include "konversi.h"
//#include "Trigonometri.h"

void mainKalkulator();
void mainBilling();
void mainKonversi();
void SetColor(unsigned short);
void features();
void about();
int choice;

int main(){
	system("cls");
	SetColor(13);
	printf(" _________________________________________________________________________________________________________________ \n");
	printf("\xb3");
	printf("                                                                                                                 \xb3\n");
	printf("\xb3");
	SetColor(12);
	printf("   $$$$$$$$$     $$$$$    $$        $$$$$$$$  $$      $$  $$           $$$$$    $$$$$$$$$$    $$$$$    $$$$$$    ");
	SetColor(13);
	printf("\xb3\n");
	printf("\xb3");
	SetColor(12);
	printf("  $$           $$     $$  $$       $$         $$      $$  $$         $$     $$      $$      $$     $$  $$    $$  ");
	SetColor(13);
	printf("\xb3\n");
	printf("\xb3");
	SetColor(12);
	printf("  $$           $$     $$  $$       $$         $$      $$  $$         $$     $$      $$      $$     $$  $$    $$  ");
	SetColor(13);
	printf("\xb3\n");
	printf("\xb3  $$           $$     $$  $$       $$         $$      $$  $$         $$     $$      $$      $$     $$  $$   $$   \xb3\n");
	printf("\xb3  $$           $$$$$$$$$  $$       $$         $$      $$  $$         $$$$$$$$$      $$      $$     $$  $$  $$    \xb3\n");
	printf("\xb3  $$           $$     $$  $$       $$         $$      $$  $$         $$     $$      $$      $$     $$  $$   $$   \xb3\n");
	printf("\xb3    $$$$$$$$   $$     $$  $$$$$$$$$ $$$$$$$$   $$$$$$$$   $$$$$$$$$  $$     $$      $$        $$$$$    $$    $$  \xb3\n");
    printf("\xb3_________________________________________________________________________________________________________________\xb3\n");
    printf("\xb3");
    SetColor(12);
	printf("                      [1]FEATURES                     [2]ABOUT                      [3]EXIT                      ");
	SetColor(13);
	printf("\xb3\n");
    printf("\xb3_________________________________________________________________________________________________________________\xb3\n\n");
    printf("YOUR CHOICE : ");
	scanf("%d",&choice);
	
	switch(choice){
		case 1:
			features();
			break;
		case 2:
			about();
			break;
		case 3:
			return 0;
		default:
			SetColor(64);
			puts("\nINVALID !! PLEASE INSERT THE RIGHT CHOOSE\n");
			SetColor(13);
			system("pause");
			main();
			break;
	}
    return 0;
}

void features(){
	system("cls");
	int choicefeatures;
	SetColor(7);
	puts("\n\n\t\t\t\t\t =========================");
	puts("\t\t\t\t\t| 1] Kalkulator           |");
	SetColor(15);
	puts("\t\t\t\t\t| 2] Konversi Mata Uang   |");
	SetColor(14);
	puts("\t\t\t\t\t| 3] Billing              |");
	SetColor(14);
	puts("\t\t\t\t\t| 4] Trigonometri         |");
	SetColor(6);
	puts("\t\t\t\t\t| 5] Back                 |");
	puts("\t\t\t\t\t =========================");
	printf("\n\t\t\t\t\t\xaf Your Choice: ");
	scanf("%i",&choicefeatures);
	fflush(stdin);
	switch(choicefeatures){
		case 1:
			mainKalkulator();
			break;
		case 2:
			mainKonversi();
			break;	
		case 3:
			mainBilling();
			break;
			/*
		case 4:
			mainTrigonometri();
			break;
			*/
		case 5:
			main();
			break;
		default:
			SetColor(64);
			puts("\n\t\t\t\tINVALID !! PLEASE INSERT THE RIGHT CHOOSE\n");
			SetColor(15);
			system("pause");
			features();
			break;
	}
}

void mainKalkulator(){
	system("cls");
	SetColor(4);
	stack s;
    RootTree root;
    info hasil;
    char operasi[100];

    createstack(&s);
    createTree(&root);
    
    printf("\n  _  __     _ _          _       _              ");
    printf("\n | |/ /    | | |        | |     | |             ");
    printf("\n | ' / __ _| | | ___   _| | __ _| |_ ___  _ __  ");
    printf("\n |  < / _` | | |/ / | | | |/ _` | __/ _ \\| '__| ");
    printf("\n | . \\\ (_| | |   <| |_| | | (_| | || (_) | |    ");
    printf("\n |_|\_\\\\__,_|_|_|\\_\\\\__,_|_|\\__,_|\\__\\___/|_|    ");
                                               
	SetColor(64);
    printf("\n\n\n \xaf Masukkan perhitungan: ");
    scanf("%[^\n]s",&operasi);
    toPostfix(operasi,s,&hasil);

    buildTree(s,&root,hasil);
    
    SetColor(4);
    printf("\n \xaf hasil : %d\n\n",calculate(root));
	
	system("pause");
    main();
}

void mainBilling(){
	
	float disc, tax, dis[100], pmbyr, kmbl, k2, hrg[100], tsh=0, ttlhrg[100],tshd, temp, harga; 
	char nama[100][30];
	int brng,i,jmlh[100]; 
	
	system("cls");      
	system("COLOR F0");
	
	printf("\t\t\t\t-----------------------------------------------\n");
    printf("\t\t\t\t==================== BILLING ==================\n");
    printf("\t\t\t\t-----------------------------------------------\n");
    printf("\t\t\t\t|               PROGRAM STRUK TOKO            |\n");
    printf("\t\t\t\t-----------------------------------------------\n");
    awal:
    printf("\t\t\t\t Masukkan banyak barang: ");
    scanf("%i",&brng);   
    for(i=1; i<=brng; i++) {
		printf("\t\t\t\t Masukkan nama barang ke-%i\t: ",i);
		getchar();
        gets(nama[i]);
        printf("\t\t\t\t Masukkan harga per barang\t: Rp. ");
        scanf("%f",&harga); 
        printf("\t\t\t\t Masukkan diskon (dalam satuan %): ");
        scanf("%f",&disc); 
        temp = harga;
        hrg[i] = hitungHarga(harga,disc);
        printf("\t\t\t\t Masukkan jumlah barang\t\t: ");
        scanf("%i", &jmlh[i]); 
        dis[i] = hitungDiskon(jmlh[i],temp,disc); 
        printf("\n");
    }
    for(i=1; i<=brng; i++) {
        ttlhrg[i]=jmlh[i]*hrg[i]; 
        tsh=tsh+ttlhrg[i];       
    }
    disc=0;
    for(i=1; i<=brng; i++) {
        disc=disc+dis[i]; 
    }
    printf("\t\t\t\t Sub Total              \t  Rp. %.2f\n", tsh);
    
    tax = hitungTax(tsh);
    tsh = hitungTsh(tsh); 

    printf("\t\t\t\t Tax                     \t @Rp. %.2f\n", tax);
	printf("\t\t\t\t Total harga keseluruhan\t  Rp. %.2f\n", tsh);
	printf("\n\t\t\t\t Masukkan jumlah pembayaran\t: Rp. ");
    scanf("%f", &pmbyr);   
    
    kmbl = hitungKembalian(pmbyr,tsh); 
    
    printf("\n\t\t\t\t ==============================================\n");
    printf("\t\t\t\t                    RECEIPT                    \n");
    printf("\t\t\t\t ==============================================\n");
    
    for(i=1; i<=brng; i++) {
       printf("\t\t\t\t %i. %i buah %s (@Rp.%.2f)\t  Rp. %.2f\n", i, jmlh[i], nama[i], hrg[i], ttlhrg[i]);
    }                  
    if(pmbyr>=tsh) {
        printf("\t\t\t\t\tTotal harga\t\t  Rp. %.2f\n", tsh);
        printf("\t\t\t\t\tPembayaran\t\t  Rp. %.2f\n", pmbyr);
        printf("\t\t\t\t\tKembalian\t\t  Rp. %.2f\n\n", kmbl);
        printf("\n\t\t\t\t\tTax       \t\t  + Rp. %.2f\n", tax);
        printf("\t\t\t\t\tDiskon    \t\t  - Rp. %.2f\n", disc);
        printf("\t\t\t\t ===============================================\n");
        printf ("\t\t\t\t|                  Terimakasih                  |\n");
        printf ("\t\t\t\t|                Telah berbelanja               |\n");
        printf ("\t\t\t\t|                    Di Toko                    |\n");
        printf ("\t\t\t\t|                   SERBA ADA                   |\n");
    }
    else {
        k2=-1*kmbl;
        printf("\t\t\t\tTotal harga\t: Rp. %.2f\n", tsh);
        printf("\t\t\t\tPembayaran\t: Rp. %.2f\n", pmbyr);
        printf("\t\t\t\tKekurangan\t: Rp. %.2f\n", k2);
    }
    printf("\t\t\t\t ===============================================\n");
    system("pause");
    SetColor(13);
    main();
}

void mainKonversi(){
	int pilih;
	char back;
	menu :
	system("COLOR 60");
	system("cls");
	printf("\n\t\t\t\t ____________________________________________\n");
	printf("\t\t\t\t\xb3 Program Konversi Mata Uang                 \xb3\n");
	printf("\t\t\t\t\xb3____________________________________________\xb3\n");
	printf("\t\t\t\t\xb3 1.Rupiah ke Dollar                         \xb3\n");
	printf("\t\t\t\t\xb3 2.Dollar ke Rupiah                         \xb3\n");
	printf("\t\t\t\t\xb3 3.Rupiah ke Yen                            \xb3\n");
	printf("\t\t\t\t\xb3 4.Yen ke Rupiah                            \xb3\n");
	printf("\t\t\t\t\xb3 5.Rupiah ke Euro                           \xb3\n");
	printf("\t\t\t\t\xb3 6.Euro ke Rupiah                           \xb3\n");
	printf("\t\t\t\t\xb3____________________________________________\xb3\n");
	printf("\t\t\t\t Masukkan Pilihan :");
	scanf("%d",&pilih);
	
	switch(pilih){
		case 1 :
			convertRupiahtoDollar();
			break;
		case 2 :
			convertDollartoRupiah();
			break;
		case 3 :
			convertRupiahtoYen();
			break;
		case 4 :
			convertYentoRupiah();
			break;
		case 5 :
			convertRupiahtoEuro();
			break;
		case 6 :
			convertEurotoRupiah();
			break;
		default :
			SetColor(64);
			puts("\n\t\t\t\tINVALID !! PLEASE INSERT THE RIGHT CHOOSE\n");
			SetColor(6);
			system("pause");
			goto menu;
			break;
	}

	printf("\n\t\t\t\t Apakah ingin mengkonversi mata uang lain?(Masukkan Y/N untuk melanjutkan)");
	scanf("%c",&back);
	
	switch(back){
		case 'y':
		case 'Y':
			system("cls");
			goto menu;
			break;
		case 'n':
		case 'N':
			SetColor(13);
			main();
			break;
	}

	if(back == 'y'|| back == 'Y'){
		system("cls");
		goto menu;
	} else{
		main();
	}
	return 0;
}

void about(){
	system("cls");
	SetColor(12);
	printf("\n\t\t\t About \n");
	printf("\nAplikasi Kalkulator ini dibuat oleh kelompok TOnoCOb");
	printf("\nKelas 1A-D4 Teknik Informatika, yang beranggotakan : ");
	printf("\n  1. Annisa Dinda Gantini  - 211524003");
	printf("\n  2. Dhafin Rizqi Fadhilah - 211524007");
	printf("\n  3. Zacky Faishal Abror   - 211524031");
	printf("\nUntuk memenuhi Tugas Besar mata kuliah Struktur Data dan Algoritma.\n\n");
	system("pause");
	main();
}

void SetColor(unsigned short color) {
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleOutput,color);
}
