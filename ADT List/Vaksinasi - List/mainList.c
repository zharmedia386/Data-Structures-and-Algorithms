/* File        : mainList.cpp */
/* Dibuat oleh : Muhammad Azhar Alauddin*/

#include <stdio.h>
#include <string.h>
#include "list.h"
#include "list.c"
#define KEYBOARD_TAB 9

int main(){

  	int n,i;
	list L;
	
  	createList(&L);
  	address elm =(address*)malloc(sizeof(address));;
  	
  	menu:
  	system("cls");
  	// Tambah Pendaftar
  	printf(" PENDAFTARAN VAKSINASI");
  	printf("\n 1. Tambah Pendaftar");
	printf("\n 2. Tampilkan Hasil Inputan");
	printf("\n 3. Tampilkan Pendaftar");
	printf("\n 4. Tampilkan Daftar Tunggu");
	printf("\n 0. Keluar Program");
	printf("\n\n");
	printf(" Pilih : ");
	scanf("%d",&n);
	
	
		if(n == 1){
			for(i=0;i<5;i++){
				printf("\n Input Data Pendaftar");
			printf("\n =============================");
	 		// Identitas
			printf("\n NO KTP			 : ");
			scanf("%s",elm->info.ktp); 
			printf(" Nama		   	 : "); fflush(stdin);
			scanf("%[^\n]s",elm->info.nama);
			printf(" Nomor Telepon	         : ");
			scanf("%s",elm->info.telpon);
			printf(" Tanggal Kedatangan      : ");
			scanf("%s",elm->info.tanggal);
			printf(" Jam Kedatangan	         : ");
			scanf("%s",elm->info.jam);
			printf(" Kategori	         : ");
			scanf("%s",elm->info.kategori);
			
			// BUMN
			if(KategoriValue(elm->info) == 4){
				printf(" Instansi	         : ");
				scanf("%s",elm->info.instansi);
				addLast(elm->info.ktp, elm->info.nama, elm->info.telpon,elm->info.tanggal,elm->info.jam,elm->info.kategori,elm->info.instansi,elm->info.usia, elm->info.sekolah, elm->info.kampus,&L);
			}
			
			// Dosen
			if(KategoriValue(elm->info) == 3){
				printf(" Perguruan Tinggi	 : "); fflush(stdin);
				scanf("%[^\n]s",elm->info.kampus);
				addLast(elm->info.ktp, elm->info.nama, elm->info.telpon,elm->info.tanggal,elm->info.jam,elm->info.kategori,elm->info.instansi,elm->info.usia, elm->info.sekolah, elm->info.kampus,&L);
			}
			
			// Guru
			if(KategoriValue(elm->info) == 2){
				printf(" Sekolah	     	 : "); fflush(stdin);
				scanf("%[^\n]s",elm->info.sekolah);
				addLast(elm->info.ktp, elm->info.nama, elm->info.telpon,elm->info.tanggal,elm->info.jam,elm->info.kategori,elm->info.instansi,elm->info.usia, elm->info.sekolah, elm->info.kampus,&L);
			}
			
			// Lansia
			if(KategoriValue(elm->info) == 1){
				printf(" Usia	    		 : ");
				scanf("%s",elm->info.usia);
				addLast(elm->info.ktp, elm->info.nama, elm->info.telpon,elm->info.tanggal,elm->info.jam,elm->info.kategori,elm->info.instansi,elm->info.usia, elm->info.sekolah, elm->info.kampus,&L);
			}
			printf("\n =============================");
			}
			printf("\n\n\n Press TAB on your keyboard to main menu");
	 		while(true){
				fflush(stdin);
				char input = getch();
				if((int) input == KEYBOARD_TAB) goto menu;
			}
		}
	 	
	 	else if(n == 2){
	 		printElement(L);

	 		printf("\n\n\n Press TAB on your keyboard to main menu");
	 		while(true){
				fflush(stdin);
				char input = getch();
				if((int) input == KEYBOARD_TAB) goto menu;
			}
		}
		
		else if(n == 3){
	 		printElement1(L);

	 		printf("\n\n\n Press TAB on your keyboard to main menu");
	 		while(true){
				fflush(stdin);
				char input = getch();
				if((int) input == KEYBOARD_TAB) goto menu;
			}
		}
		
		else if(n == 4){
	 		printElement1(L);

	 		printf("\n\n\n Press TAB on your keyboard to main menu");
	 		while(true){
				fflush(stdin);
				char input = getch();
				if((int) input == KEYBOARD_TAB) goto menu;
			}
		}
		
		else if(n == 0){
			exit(0);
		}
	
  
  	return 0;
}
