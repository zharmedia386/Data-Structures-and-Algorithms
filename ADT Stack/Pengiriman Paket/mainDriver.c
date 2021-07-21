/**
  * Nama File		: mainDriver.c
  * Deskripsi		: Program Vaksinasi - Studi Kasus Vaksinasi
  * Author			: Muhammad Azhar Alauddin / 201524013
 **/
 
#include "stack.h"

void TambahPaket(Stack *daftar);
void TampilPaket(Stack S);
void ProsesPaket(Stack *S);

int main()
{
	Stack S;
	CreateStack(&S);
	address1 p;
	
	int choice = -1;
	
	while(true)
	{
		system("cls");
		printf("PENDAFTARAN PAKET\n");
		printf("1. Tambah Paket\n");
		printf("2. Tampilkan Paket\n");
		printf("3. Proses Paket\n");
		printf("4. Keluar Program\n");
		printf("\nPilih : ");
		scanf("%d", &choice);
		switch(choice) 
		{
			case 1 :
				TambahPaket(&S);
				break;
			case 2 :
				TampilPaket(S);
				break;
			case 3 :
				ProsesPaket(&S);
				break;
			case 4 :
				exit(0);
				break;
			case 0 :
				return 0;
		}
	}
	
	return 0;
}

void TambahPaket(Stack *S)
{
	dokumen data;
	printf("Input Data Paket\n");
	printf("================================================\n");
	ReadPaket(&data);
	Push(S,data);
	printf("\n================================================\n");
	getch();
}

void TampilPaket(Stack S)
{
	PrintStack(S);
	printf("\n================================================\n");
	getch();
}

void ProsesPaket(Stack *S){
	char Proses;
	dokumen data;
	do{
		if(!isStackEmpty(*S)){
			printf("Daftar Paket Masuk\n");
			PrintStack(*S);
			printf("\nLakukan Pengiriman untuk Paket %s? [Y/N] ", Peek(*S).NamaPengirim);
			fflush(stdin);
			scanf("%c",&Proses);
			if(Proses == 'Y'){
				Pop(S,&data);
			}
		}
		printf("\n================================================\n");
		if(isStackEmpty(*S)){
			printf("Paket yang sudah diproses\n");
			PrintStack(*S);
		}
	}while(!isStackEmpty(*S));
	getch();
}
