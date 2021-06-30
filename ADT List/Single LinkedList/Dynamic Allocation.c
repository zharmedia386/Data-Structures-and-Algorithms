#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

// Kamus Data
typedef struct{
  char Nama[50];
  char NIM[50];
}Mahasiswa;

typedef Mahasiswa Infotype;
typedef struct elmt *address;

typedef struct elmt{
  Infotype data;
  address next;
}Node;

typedef struct{
  address First;
}List;

// Algoritma
void CreateList(List *L){
  L->First = NULL;
}

// Alokasi Node Baru
address Alokasi(Infotype X){
  address P;
  P = (address)malloc(sizeof(Node));
  strcpy(P->data.Nama,X.Nama);
  strcpy(P->data.NIM,X.NIM);
  P->next = NULL;
  return P;
}

// Menambah Node di awal
void addFirst(List *L, Infotype input){  
  L->First = Alokasi(input);
}

// Menambah Node di akhir
void addLast(List *L, Infotype input){
  address last;
  last = L->First;

  // Menuju ke node last
  while(last->next != NULL){
    last = last->next;
  }

  last->next = Alokasi(input);
}

// Menambah node diantara Node
void addAfter(List *L, Infotype input){
  
}

// Input Element
void ReadElement(Infotype *input){
  printf("Nama : ");
  scanf("%[^\n]c",input->Nama);
  fflush(stdin);
  printf("NIM  : ");
  scanf("%[^\n]c",input->NIM);
  fflush(stdin);
  printf("\n");
}

// Menampilkan isi seluruh node
void PrintElement(List L){
  address P = L.First;
  int i = 1;
  while(P != NULL){
    printf("Node ke-%d\n",i);
    printf("Nama : %s\n",P->data.Nama);
    printf("NIM  : %s\n\n",P->data.NIM);
    P = P->next;
    i++;
  }
}

int main(){
  Infotype data;
  List L;

  // Membuat List Pertama
  CreateList(&L);
  
  printf("READ ELEMENT\n");
  // Tambah Node Awal
  ReadElement(&data);
  addFirst(&L,data);

  // Tambah node Akhir
  ReadElement(&data);
  addLast(&L,data);

  // Print Seluruh node
  printf("PRINT ELEMENT\n");
  PrintElement(L);
  
  return 0;
}