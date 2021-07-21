#include "date.h"
#include "time.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef menu_H
#define menu_H

typedef struct{
	char noKTP[20];
	char nama[100];
	char noTLP[15];
	date tanggal;
	time jam;
	char kategori[10];
	char instansi[100];
	int usia;
	int sesi;
}menu;

menu CreateMenu();

void ReadMenu(menu *M);

void PrintMenu(menu M);

#endif
