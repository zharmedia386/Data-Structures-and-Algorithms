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

address Alokasi(Infotype X){
  address P;
  P = (address)malloc(sizeof(Node));
  strcpy(P->data.Nama,X.Nama);
  strcpy(P->data.NIM,X.NIM);
  P->next = NULL;
  return P;
}

void addFirst(List *L, Infotype input){  
  L->First = Alokasi(input);
}

void addLast(List *L, Infotype input){
  address last;
  last = L->First;

  // Menuju ke node last
  while(last->next != NULL){
    last = last->next;
  }

  last->next = Alokasi(input);
}

void ReadElement(Infotype *input){
  printf("Nama : ");
  scanf("%[^\n]c",input->Nama);
  fflush(stdin);
  printf("NIM  : ");
  scanf("%[^\n]c",input->NIM);
  fflush(stdin);
}

void PrintElement(List L){
  address P = L.First;
  while(P != NULL){
    printf("Nama : %s\n",P->data.Nama);
    printf("NIM  : %s\n\n",P->data.NIM);
    P = P->next;
  }
}

int main(){
  Infotype data;
  List L;

  // Membuat List Pertama
  CreateList(&L);
  // Tambah Node Awal
  ReadElement(&data);
  addFirst(&L,data);

  // Print Seluruh node
  PrintElement(L);
  
  return 0;
}