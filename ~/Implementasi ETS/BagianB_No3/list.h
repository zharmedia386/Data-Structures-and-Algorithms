/*
	Name: M Azhar Alauddin
	Compiler : GCC 4.9.2
	Date: 08/06/21
	Description: Layanan Fotocopy ETS Bagian B No.3
*/

#ifndef List_H
#define List_H
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>

#define Nil  NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)

typedef struct{
	char nama; 
	int waktu; // waktu kedatangan pengunjung
	int Jml_Lembar; // jumlah kertas yang akan difotokopi
}infotype; 

typedef struct tElmtlist *address;

typedef struct tElmtlist{
	infotype info;
	address next;
}ElmtList; 

typedef struct{
	address First;
}List; 

void CreateList(List *L); 
/* I.S  :  Sembarang    		*/
/* F.S  :  Terbentuk  List kosong  	*/

/* Manajeman  memory  			*/

address Alokasi(infotype X);
/* Mengirimkan  address  hasil alokasi    sebuah elemen */
/* Jika alokasi  berhasil, maka  address tidak nil, dan misalnya  */
/* menghasilkan   P,  maka info(P)=X,  Nest(P)=Nil;               */
/* Jika alokasi  gagal,  mengirimkan  Nil 			   */

void InsVLast(List *L, infotype X); 
/* I.S  : L mungkin kosong          */
/* F.S  : Melakukan alokasi sebuah elemen dan                */
/*        menambahkan elemen list di akhir; elemen terakhir  */
/*        yang baru bernilai X jika alokasi berhasil,        */	
/*	    Jika alokasi gagal: I.S = F.S		       */

void DelP (List * L, address P); 
/* I.S   : Sembarang  */
/* F.S   : Jika ada elemen  list beraddress P    */
/*         Maka P dihapus dari List dan di-dealokasi		     */
/*	       Jika tidak ada elemen List dengan address P, maka list tetap  */
/*         List mungkin menjadi kosomg karena penghapusan   */

address NextNode(List L, int time); 
/* I.S   : L mungkin kosong  */
/* F.S   : menentukan node mana yang akan di proses berdasarkan waktu dan jumlah lembar */

#endif
