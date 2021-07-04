#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>

#define SIZE 5

typedef struct{
  int First;
  int Next;
  int data[SIZE];
}List;

void CreateList(List *L){
  int First = -1;
}

bool isEmpty(List L){
  if(L.First == -1)
    return true;
  else
    return false;
}

bool isFull(List L){
  if(L.First == 4)
    return true;
  else
    return false;
}

// Menambah node di Node Pertama 
void addFirst(List *L, int value){
  if(isFull(*L))
    printf("List is Full!!\n");
  else{
    int temp = L->First; // Indeks di depan L->First
    temp++;
    L->data[temp] = value;
    printf("Penambahan Node Berhasil! %d sudah ditambahkan\n",L->data[temp]);
  }
}

// Menambah Node Terakhir
void addLast(List *L, int value){
  if(isFull(*L))
    printf("List is Full!!\n");
  else{
    int temp = L->First;
    while(temp != NULL){ // Selangkah di depan Node Terakhir
      temp++; 
    }
    L->data[temp-1] = value;
    printf("Penambahan Node Berhasil! %d sudah ditambahkan\n",L->data[temp-1]);
  }
}

void PrintElement(List L){
  if(isEmpty(L))
    printf("List is Empty!!\n");
  else{
    int temp = L.First;
    int i = 0;
    printf("List Elements :\n");
    while(temp != NULL){
      printf("%d ",L.data[i]);
      temp++; i++;
    }
  }
}

int main(){
  List L;

  // Membuat List Baru
  CreateList(&L);

  // Menambah Node Baru pada List 
  addFirst(&L,1);
  
  // Menambah Node Baru pada List 
  addLast(&L,2);

  // Menambah Node Baru pada List 
  addLast(&L,3);

  // Menambah Node Baru pada List 
  addLast(&L,4);

  // Menambah Node Baru pada List 
  addLast(&L,5);

  // Menghapus Node Baru pada List 

  // Menampilkan isi Seluruh node
  PrintElement(L);
  
  return 0;
}