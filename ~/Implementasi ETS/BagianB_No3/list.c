/*
	Name: M Azhar Alauddin
	Compiler : GCC 4.9.2
	Date: 08/06/21 
	Description: Layanan Fotocopy ETS Bagian B No.3
*/

#include "list.h"
#include <limits.h>

void CreateList(List *L){
/* I.S  :  Sembarang    		*/
/* F.S  :  Terbentuk  List kosong  	*/

/* Manajeman  memory  			*/
	L->First = NULL;
}

address Alokasi(infotype X){
/* Mengirimkan  address  hasil alokasi    sebuah elemen */
/* Jika alokasi  berhasil, maka  address tidak nil, dan misalnya  */
/* menghasilkan   P,  maka info(P)=X,  Nest(P)=Nil;               */
/* Jika alokasi  gagal,  mengirimkan  Nil 			   */
	address P;
   	P=(address)malloc(sizeof(ElmtList));
	if(P!=Nil) { /* Berhasil  */
    Info(P)=X;
	Next(P)=Nil;
   	}
   return P;
}

void InsVLast(List *L, infotype X){ 
/* I.S  : L mungkin kosong          */
/* F.S  : Melakukan alokasi sebuah elemen dan                */
/*        menambahkan elemen list di akhir; elemen terakhir  */
/*        yang baru bernilai X jika alokasi berhasil,        */	
/*	    Jika alokasi gagal: I.S = F.S		       */
	address P = Alokasi(X);
	if(P != Nil){
		if(L->First == Nil){
			L->First = P;
			return;
		}
		address current = L->First;
		while(current->next != Nil){
			current = current->next;
		}
		current->next = P;
	}
}

void DelP (List * L, address P){
/* I.S   : Sembarang  */
/* F.S   : Jika ada elemen 
list beraddress P    */
/*         Maka P dihapus dari List dan di-dealokasi		     */
/*	       Jika tidak ada elemen List dengan address P, maka list tetap  */
/*         List mungkin menjadi kosomg karena penghapusan   */
	address temp = L->First;
	if(temp == Nil){
		return;
	}
	
	if(P == temp){
		L->First = temp->next;
		free(P);
		return;
	}
	while(temp->next != P){ // mencari node yang akan di dealokasi 
		temp = temp->next;
	}
	temp->next = P->next; // mengaikatkan next node yang akan didealokasi sehingga tidak lepas ketika node didealokasi  
	free(P);
}

address NextNode(List L, int waktu){
/* I.S   : L mungkin kosong  */
/* F.S   : menentukan node mana yang akan di proses berdasarkan waktu dan jumlah lembar */
	address here = L.First;
	address result = Nil;
	int min = INT_MAX;

	while(here != Nil){
		if(here->info.waktu <= waktu){
			if(min > here->info.Jml_Lembar){
				min = here->info.Jml_Lembar;
				result = here;
			}
		}
		here = here->next;
	}
	return result;
}
