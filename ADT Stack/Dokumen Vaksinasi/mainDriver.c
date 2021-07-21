/**
  * Nama File		: mainDriver.c
  * Deskripsi		: Program Vaksinasi - Studi Kasus Vaksinasi
  * Author			: Muhammad Azhar Alauddin / 201524013
 **/
 
#include "stack.h"
#include "date.h"
#include "menu.h"
#include "time.h"
#include "list.h"

void Daftar(List *daftar);
void TampilPendaftar(List data);
void TampilDaftarTunggu(List data);
void RegistrasiPendaftar(Stack *S);
void VerifikasiPendaftar(Stack *S);

int main()
{
	Stack S;
	CreateStack(&S);
	address1 p;

	/* Deklarasi */
	List l;
	List sorted;
	
	int choice = -1;
	
	/* Algoritma */
	CreateList(&l);
	while(true)
	{
		system("cls");
		printf("PENDAFTARAN VAKSINASI\n");
		printf("1. Tambah Pendaftar\n");
		printf("2. Tampilkan Pendaftar\n");
		printf("3. Tampilkan Daftar Tunggu\n");
		printf("4. Registrasi Pendaftar\n");
		printf("5. Verifikasi Pendaftar\n");
		printf("\nPilih : ");
		scanf("%d", &choice);
		switch(choice) 
		{
			case 1 :
				Daftar(&l);
				break;
			case 2 :
				TampilPendaftar(l);
				break;
			case 3 :
				TampilDaftarTunggu(l);
				break;
			case 4 :
				RegistrasiPendaftar(&S);
				break;
			case 5 :
				VerifikasiPendaftar(&S);
				break;
			case 0 :
				return 0;
		}
	}
	
	return 0;
}

void Daftar(List *daftar)
{
	menu data;
	printf("Input Data Pendaftar\n");
	printf("================================================\n");
	ReadMenu(&data);
	if(ListEmpty(*daftar))
		InsVFirst(daftar, data);
	else
		InsVLast(daftar, data);
	printf("\n================================================\n");
	getch();
}

void TampilPendaftar(List data)
{
	PrintFormat(data);
	printf("\n================================================\n");
	getch();
}

void TampilDaftarTunggu(List data)
{
	int choice;
	List sorted;
	CreateList(&sorted);
	CpAlokList(data, &sorted);
	
	if(ListEmpty(data))
	{
		printf("\nPendaftar Masih Kosong!\n");
		printf("\n================================================\n");
		getch();
		return;
	}
					
	printf("\n1. Tampilkan berdasarkan Jam Kedatangan\n");
	printf("2. Tampilkan berdasarkan Kategori\n");
	printf("\nPilih : ");
	scanf("%d", &choice);
	
	switch(choice)
	{
		case 1 :	
			SortListByTime(&sorted);
			TampilPendaftar(sorted);
			break;
		case 2 :
			printf("\n1. Lansia\n");
			printf("2. Guru\n");
			printf("3. Dosen\n");
			printf("4. BUMN\n");
			printf("\nPilih : ");
			scanf("%d", &choice);
			switch(choice)
			{
				case 1 : 
					PrintListByCategory(data, "Lansia");
					break;
				case 2 : 
					PrintListByCategory(data, "Guru");
					break;
				case 3 : 
					PrintListByCategory(data, "Dosen");
					break;
				case 4 : 
					PrintListByCategory(data, "BUMN");
					break;
			}
			printf("\n================================================\n");
			getch();
			break;
	}			
	DelAll(&sorted);
}

void RegistrasiPendaftar(Stack *S){
	dokumen data;
	printf("Registrasi Pendaftar\n");
	printf("================================================\n");
	ReadRegistrasi(&data);
	if(stricmp(data.kategori,"Lansia") == 0){
		if((data.FotoCopyKTP == 'Y') && (data.KartuKeluarga == 'Y')){
			printf("\n\nRegistrasi Berhasil");
			Push(S,data);
		}
		else{
			printf("\n\nRegistrasi Gagal");
		}
	}
	else{
		if((data.FotoCopyKTP == 'Y') && (data.SuratPengantar == 'Y')){
			printf("\n\nRegistrasi Berhasil");
			Push(S,data);
		}
		else{
			printf("\n\nRegistrasi Gagal");
		}
 	}
	printf("\n================================================\n");
	getch();
}

void VerifikasiPendaftar(Stack *S){
	char Verifikasi;
	dokumen data;
	do{
		if(!isStackEmpty(*S)){
			printf("Peserta yang sudah Registrasi\n");
			PrintStack(*S);
			printf("\nLakukan Verifikasi untuk %s? [Y/N] ", Peek(*S).nama);
			fflush(stdin);
			scanf("%c",&Verifikasi);
			if(Verifikasi == 'Y'){
				Pop(S,&data);
			}
		}
		printf("\n================================================\n");
		if(isStackEmpty(*S)){
			printf("Peserta yang sudah Registrasi\n");
			PrintStack(*S);
		}
	}while(!isStackEmpty(*S));
	getch();
}
