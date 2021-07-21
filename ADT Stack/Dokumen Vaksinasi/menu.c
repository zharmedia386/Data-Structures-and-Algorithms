#include "menu.h"

menu CreateMenu(){
	menu newMenu;
	return newMenu;
}

void ReadMenu(menu *M)
{
	fflush(stdin); // clear last char in stdin
	
	printf("No KTP                       : "); 
	scanf("%s", &M->noKTP);
	fflush(stdin); // clear last char in stdin
	
	printf("Nama                         : "); 
	scanf("%[^\n]c", &M->nama);
	
	printf("Nomor Telepon                : "); 
	scanf("%s", &M->noTLP);
	
	printf("Tanggal Kedatangan Vaksinasi : "); 
	BacaDateOneLn(&M->tanggal);
	
	printf("Jam Kedatangan Vaksinasi     : "); 
	ReadTimeOneLn(&M->jam);
	
	printf("Kategori                     : "); 
	scanf("%s", &M->kategori);
	
	if(strcmp(M->kategori, "Lansia") == 0)
	{
		printf("Usia                         : "); 
		scanf("%d", &M->usia);
	}
	else
	{
		fflush(stdin);
		printf("Instansi                     : "); 
		scanf("%[^\n]c", &M->instansi);
	} 
	
	/* Calculate Session */
	
	if(M->jam.hour >= 8 && M->jam.hour < 11)
	{
		if(M->jam.hour < 10)
			M->sesi = 1;
		else if(M->jam.hour == 10 && M->jam.minute == 0)
			M->sesi = 1;
	}else if(M->jam.hour >= 11 && M->jam.hour < 14)
	{
		if(M->jam.hour < 13)
			M->sesi = 2;
		else if(M->jam.hour == 13 && M->jam.minute == 0)
			M->sesi = 2;
	}else if(M->jam.hour >= 14 && M->jam.hour < 17)
	{
		if(M->jam.hour < 16)
			M->sesi = 3;
		if(M->jam.hour == 16 && M->jam.minute == 0)
			M->sesi = 3;
	}else
		M->sesi = 0;
}

void PrintMenu(menu M)
{
	printf("No KTP                        : %s\n", M.noKTP);
	printf("Nama                          : %s\n", M.nama);
	printf("Nomor Telepon                 : %s\n", M.noTLP);
	printf("Tanggal Kedatangan Vaksinasi  : "); PrintObj(M.tanggal);
	printf("Jam Kedatangan Vaksinasi      : %d:%d\n", GetHour(M.jam), GetMinute(M.jam));
	printf("Kategori                      : %s\n", M.kategori);
	
	if(strcmp(M.kategori, "Lansia") == 0)
		printf("Usia                          : %d\n", M.usia);
	else
		printf("Instansi                      : %s\n", M.instansi);

}
