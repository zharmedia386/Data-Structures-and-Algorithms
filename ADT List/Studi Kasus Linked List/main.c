/* File  : drivlist.c			*/
/* Desk  : Driver list1.c		*/
/*         ANI RAHMANI / 23501007	*/
/* Tgl	 : 25/10/01			*/
/* Tgl modifikasi List1.c : 15/11/01    */

#include "list.h"
#include "list.c"
#include <stdlib.h>
#include <stdio.h>

int main()
{	/* Kamus */
	List myList;
	address P;
	
	CreateList(&myList);
	
	/* Insert Huruf Pertama, value 'u' */
	InsVFirst(&myList, 'u');
	
	/* Insert value 'c' setelah huruf pertama*/
	InsVLast(&myList,'c');
	
	/* Insert value 'h' setelah huruf kedua*/
	InsVLast(&myList,'h');
	
	/* Insert value 'i' setelah huruf ketiga*/
	InsVLast(&myList,'i');
	
	/* Insert value 'n' setelah huruf pertama*/
	InsertVAfter(&myList,'u','n');
	
	/* Delete value 'i' pada elemen list*/
	DelP(&myList, 'h');
	
	/* Insert value 'p' di awal list*/
	InsVFirst(&myList,'p');
	
	/* Insert 'a' setelah huruf 'h'*/
	InsertVAfter(&myList,'h','a');
	
	/* Show semua elemen karakter*/
	PrintInfo(myList);
	
	/* Mencari huruf 'h'*/
	int position = SearchAt(myList, 'h');
	if(position)
		printf("\nHuruf 'h' berada pada posisi elemen ke-%d\n", position);
	else
		printf("\nTidak ada elemen dengan isi huruf 'h'\n");
	
	/* Delete semua elemen list karakter*/
	DelAll(&myList);
	
	return 0;
}

