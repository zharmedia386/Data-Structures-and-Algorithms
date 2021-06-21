#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct{
  char nama[255];
  char title[255];
}Jabatan;

typedef Jabatan Infotype;

typedef struct elmt *address;

typedef struct elmt{
  Infotype data;
  address Parent;
  address Child;
  address NextSibling;
}Node;

typedef struct{
  address Root;
}Tree;

void CreateTree(Tree *T, Infotype input){
  address P;
  P = (address)malloc(sizeof(Node));
  strcpy(P->data.nama,input.nama);
  strcpy(P->data.title,input.title);
  P->Child = NULL;
  P->NextSibling = NULL;
  (*T).Root = P;
}

void addChild(address *Root, Infotype input){
  if((*Root)->Child == NULL){
    address P;
    P = (address)malloc(sizeof(Node));
    strcpy(P->data.nama,input.nama);
    strcpy(P->data.title,input.title);
    P->Parent = (*Root);
    P->Child = NULL;
    P->NextSibling = NULL;
    (*Root)->Child = P;
  }
  else{
    printf("Root sudah memiliki anak");
  }
}

void delChild(address *Root){
  address P = (*Root)->Child;
  (*Root)->Child = NULL;
  free(P);
}

void addSibling(address *Root, Infotype input){
  if((*Root)->NextSibling == NULL){
    address P;
    P = (address)malloc(sizeof(Node));
    strcpy(P->data.nama,input.nama);
    strcpy(P->data.title,input.title);
    P->Parent = (*Root)->Parent;
    P->Child = NULL;
    P->NextSibling = NULL;
    (*Root)->NextSibling = P;
  }
  else{
    printf("Root sudah memiliki sibling");
  }
}

void delSibling(address *Root){
  address P = (*Root)->NextSibling;
  (*Root)->NextSibling = NULL;
  free(P);
}

void findChild(address Root){
  printf(" - Child dari %s adalah %s\n",Root,Root->Child);
}

void findParent(address Root){
  printf(" - Parent dari %s adalah%s\n",Root,Root->Parent);
}

void findGrandParent(address Root){
  printf(" - GrandParent dari %s adalah %s\n",Root,Root->Parent->Parent);
}

void findSibling(address Root){
  printf(" - Sibling dari %s adalah %s\n",Root,Root->NextSibling);
}

void PrintPreOrder(address Root){
  if(Root != NULL){
    printf(" %s - ",Root->data.nama);
    printf(" %s\n",Root->data.title);
    PrintPreOrder(Root->Child);
    PrintPreOrder(Root->NextSibling);
  }
}

void PrintPostOrder(address Root){
  if(Root != NULL){
    PrintPostOrder(Root->Child);
    PrintPostOrder(Root->NextSibling);
    printf(" %s - ",Root->data.nama);
    printf(" %s\n",Root->data.title);
  }
}

void PrintInOrder(address Root){
  if(Root != NULL){
    PrintInOrder(Root->Child);
    printf(" %s - ",Root->data.nama);
    printf(" %s\n",Root->data.title);
    PrintInOrder(Root->NextSibling);
  }
}

void ReadElement(Infotype *input){
  fflush(stdin);
  scanf("%[^\n]c",&input->nama);
  printf(" Jabatan : ");
  fflush(stdin);
  scanf("%[^\n]c",&input->title);
}

int main(){
   /* DEKLARASI*/
  Tree T;
  Infotype data;
  
  /* Read Node*/
  printf(" INPUT : \n");

  // Kepala Pusat (Root) - Ujang Kartiwa
  printf(" Node Kepala Pusat : ");
  ReadElement(&data);
  CreateTree(&T,data);

  // Kepala Bagian Perencanaan - Engkos Koswara
  printf(" Node Kepala Bagian 1 : ");
  ReadElement(&data);
  addChild(&T.Root,data);

  // Kepala Sub Bagian Anggaran - Tati Sulastri
  printf(" Node Kepala Sub Bagian 1 : ");
  ReadElement(&data);
  addChild(&T.Root->Child,data);

  // Staff - Muktadi
  printf(" Node Staff 1 : ");
  ReadElement(&data);
  addChild(&T.Root->Child->Child,data);

  // Staff - Hartanto Utomo
  printf(" Node Staff 2 : ");
  ReadElement(&data);
  addSibling(&T.Root->Child->Child->Child,data);

  // Kepala Sub Bagian Pendataan - Irvan Susilo
  printf(" Node Kepala Sub Bagian 2 : ");
  ReadElement(&data);
  addSibling(&T.Root->Child->Child,data);
  
  // Staff - Candra Dimuka
  printf(" Node Staff 3 : ");
  ReadElement(&data);
  addChild(&T.Root->Child->Child->NextSibling,data);

  // Kepala Sub Bagian Evaluasi - Evi Sukaesih
  printf(" Node Kepala Sub Bagian 3 : ");
  ReadElement(&data);
  addSibling(&T.Root->Child->Child->NextSibling,data);

  // Staff - Kartono
  printf(" Node Staff 4 : ");
  ReadElement(&data);
  addChild(&T.Root->Child->Child->NextSibling->NextSibling,data);

  //------------------------

  // Kepala Bagian SDM - Hoerul Anam
  printf(" Node Kepala Bagian 2 : ");
  ReadElement(&data);
  addSibling(&T.Root->Child,data);

  // Kepala Sub Bagian Kepegawaian - Sambas Nugroho
  printf(" Node Kepala Sub Bagian 4 : ");
  ReadElement(&data);
  addChild(&T.Root->Child->NextSibling,data);

  // Staff - Markonah
  printf(" Node Staff 5 : ");
  ReadElement(&data);
  addChild(&T.Root->Child->NextSibling->Child,data);

  // Staff - Jaelani Supri Utama
  printf(" Node Staff 6 : ");
  ReadElement(&data);
  addSibling(&T.Root->Child->NextSibling->Child->Child,data);

  // Staff - Ukar Mustopa
  printf(" Node Staff 7 : ");
  ReadElement(&data);
  addSibling(&T.Root->Child->NextSibling->Child->Child->NextSibling,data);

  // Kepala Sub Bagian Tata Laksana - Mujani Gani
  printf(" Node Kepala Sub Bagian 5 : ");
  ReadElement(&data);
  addSibling(&T.Root->Child->NextSibling->Child,data);

  // Staff - Marcellino
  printf(" Node Staff 8 : ");
  ReadElement(&data);
  addChild(&T.Root->Child->NextSibling->Child->NextSibling,data);

  // Staff - Opik Taufik
  printf(" Node Staff 9 : ");
  ReadElement(&data);
  addSibling(&T.Root->Child->NextSibling->Child->NextSibling->Child,data);

  //----------------------

  // Kepala Bagian Keuangan - Dana Sukirman
  printf(" Node Kepala Bagian 3 : ");
  ReadElement(&data);
  addSibling(&T.Root->Child->NextSibling,data);

  // Kepala Sub Bagian Pelaksana Keuangan - Noviyanti
  printf(" Node Kepala Sub Bagian 6 : ");
  ReadElement(&data);
  addChild(&T.Root->Child->NextSibling->NextSibling,data);

  printf("\n =================\n");

  /* Print Node*/
  printf("\n HASIL OUTPUT : \n");
  
  // PreOrder
  printf(" preOrder Sequence :\n");
  PrintPreOrder(T.Root);
  
  // Study Case
  printf("\n Study Case :\n");
  
  // Mencari Child - Irvan
  findChild(T.Root->Child->Child->NextSibling);

  // Mencari Sibling - Muktadi
  findSibling(T.Root->Child->Child->Child);

  // Mencari Parent - Tati
  findParent(T.Root->Child->Child);

  // Mencari Grand Parent - Markonah
  findGrandParent(T.Root->Child->NextSibling->Child->Child);

  return 0;
}
