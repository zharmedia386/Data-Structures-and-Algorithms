/* File        : list1.cpp */
/* Dibuat oleh : Muhammad Azhar Alauddin*/

#include "list.h"


void createList(list *L){

  (*L).first = NULL;

}



int countElement(list L){



  int hasil = 0;

  if(L.first !=NULL){
    /*list tidak kosong*/
    
    elemen *elmt;

    /*inisialisasi*/
    elmt = L.first;

    while(elmt != NULL){
      /*proses*/
      hasil = hasil + 1;

      /*iterasi*/
      elmt = elmt->next;
    }

  }

  return hasil;

}


void addFirst(char ktp[], char nama[], char telpon[], char tanggal[],char jam[], char kategori[], char instansi[],char usia[], char sekolah[], char kampus[], list *L){

  elemen *elmt;
  elmt = (elemen *) malloc (sizeof (elemen));
  strcpy(elmt->info.ktp, ktp);       
  strcpy(elmt->info.nama, nama);       
  strcpy(elmt->info.telpon, telpon);
  strcpy(elmt->info.tanggal, tanggal);
  strcpy(elmt->info.jam, jam);
strcpy(elmt->info.kategori,kategori);
  strcpy(elmt->info.instansi, instansi);
  strcpy(elmt->info.usia, usia);
  strcpy(elmt->info.sekolah,sekolah);
  strcpy(elmt->info.kampus,kampus);
  elmt->next = (*L).first;
  (*L).first = elmt;
  elmt = NULL; 

}


void addAfter(elemen *prec, char ktp[], char nama[], char telpon[], char tanggal[],char jam[], char kategori[], char instansi[], char usia[], char kampus[], char sekolah[], list *L){

  elemen *elmt;
  elmt = (elemen *) malloc (sizeof (elemen));
  strcpy(elmt->info.ktp, ktp);       
  strcpy(elmt->info.nama, nama);       
  strcpy(elmt->info.telpon, telpon);
  strcpy(elmt->info.tanggal, tanggal);
  strcpy(elmt->info.jam, jam);
  strcpy(elmt->info.kategori,kategori);
  strcpy(elmt->info.instansi, instansi);
  strcpy(elmt->info.usia, usia);
  strcpy(elmt->info.sekolah,sekolah);
  strcpy(elmt->info.kampus,kampus);
  elmt->next = prec->next;
  prec->next = elmt;
  elmt = NULL; 

}


void addLast(char ktp[], char nama[], char telpon[], char tanggal[],char jam[], char kategori[], char instansi[],char usia[], char sekolah[], char kampus[], list *L){

  if((*L).first == NULL){
    /*jika list adalah list kosong*/
    addFirst(ktp, nama, telpon, tanggal, jam, kategori, instansi,usia,sekolah,kampus, L);
  }
  else{
    /*jika list tidak kosong*/
    elemen *elmt;
    elmt = (elemen *) malloc (sizeof (elemen));
    strcpy(elmt->info.ktp, ktp);       
	strcpy(elmt->info.nama, nama);       
	strcpy(elmt->info.telpon, telpon);
	strcpy(elmt->info.tanggal, tanggal);
	strcpy(elmt->info.jam, jam);
	strcpy(elmt->info.kategori,kategori);
	strcpy(elmt->info.instansi, instansi);
    strcpy(elmt->info.kampus, kampus);
    strcpy(elmt->info.sekolah, sekolah);
    strcpy(elmt->info.usia, usia);
    elmt->next = NULL;

    /*mencari elemen terakhir list*/
    elemen *last = (*L).first;

    while(last->next != NULL){
 
      /*iterasi*/
      last = last->next;

    }
    
    last->next = elmt;
    elmt = NULL;
  }

}



void delFirst(list *L){

  if((*L).first != NULL){
    /*jika list bukan list kosong*/

    elemen *elmt = (*L).first;
    (*L).first = (*L).first->next;
    elmt->next = NULL;
    free(elmt);
  }

}




void delAfter(elemen *prec, list *L){


  elemen *elmt = prec->next;
  prec->next = elmt->next;
  elmt->next = NULL;
  free(elmt);

}


void delLast(list *L){

  if((*L).first != NULL){
    /*jika list tidak kosong*/
    if(countElement(*L) == 1){
      /*list terdiri dari satu elemen*/
      delFirst(L);

    }
    else{

      /*mencari elemen terakhir list*/
      elemen *last = (*L).first;
      elemen *before_last;

      while(last->next != NULL){

        /*iterasi*/
        before_last = last;
        last = last->next;

      }

      before_last->next = NULL;
      free(last);

    }
  }

}

int KategoriValue(dataPendaftar X){
	if(stricmp(X.kategori,"Lansia") == 0)
		return 1;
	else if (stricmp(X.kategori,"Guru") == 0)
		return 2;
	else if (stricmp(X.kategori,"Dosen") == 0)
		return 3;
	else if (stricmp(X.kategori,"BUMN") == 0)
		return 4;
	
	return 0;
}

void printElement(list L){  
  
  elemen *elmt = L.first;
  int i = 1;
  
  if(L.first != NULL){
    /*jika list tidak kosong*/
    /*inisialisasi*/

    while(elmt != NULL){
      /*proses*/
      
      printf("\n Elemen ke : %d\n", i); 
      printf("\n NO KTP			 : %s\n",elmt->info.ktp);
      printf(" Nama		   	 : %s\n",elmt->info.nama);
      printf(" Nomor Telepon	         : %s\n", elmt->info.telpon);
      printf(" Tanggal Kedatangan      : %s\n", elmt->info.tanggal);
	  printf(" Jam Kedatangan	         : %s\n", elmt->info.jam); 
      printf(" Kategori	         : %s\n", elmt->info.kategori);
      
      if(KategoriValue(elmt->info) == 4){
      	printf(" Instansi	         : %s\n",elmt->info.instansi);
      	printf("\n =============================");
      }
      if(KategoriValue(elmt->info) == 3){
      	printf(" Kampus                  : %s\n", elmt->info.kampus); 
        printf("\n =============================");
      }
      if(KategoriValue(elmt->info) == 2){
      	printf(" Sekolah                 : %s\n", elmt->info.sekolah); 
      	printf("\n =============================");
      }
      if(KategoriValue(elmt->info) == 1){
      	printf(" Usia                    : %s\n", elmt->info.usia);  
      	printf("\n =============================");
      }
	  
      /*iterasi*/
    elmt = elmt->next;
      i = i + 1;
    }

  }
  else{
   /*proses jika list kosong*/
    printf("\n\n list kosong\n");
  }

}

void printElement1(list L){  
  
  elemen *elmt = L.first;
  int i = 1;
  
  if(L.first != NULL){
    /*jika list tidak kosong*/
    /*inisialisasi*/

    while(elmt != NULL){
      /*proses*/
      
      printf("\n %s (%s - %s)", elmt->info.nama,elmt->info.jam,elmt->info.kategori); 
	  
      /*iterasi*/
    elmt = elmt->next;
      i = i + 1;
    }

  }
  else{
   /*proses jika list kosong*/
    printf("\n\n list kosong\n");
  }

}

void delAll(list *L){ 

 if(countElement(*L) != 0){

  int i;

  for(i=countElement(*L);i>=1;i--){
  /*proses menghapus elemen list*/
    delLast(L);   
  }

 }

}
