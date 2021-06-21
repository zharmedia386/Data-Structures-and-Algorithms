#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct{
  char huruf;
}isiNode;

typedef isiNode Infotype;

typedef struct elmt *address;

typedef struct elmt{
  Infotype data;
  address Right;
  address Left;
}Node;

typedef struct{
  address Root;
}Tree;

void CreateTree(Tree *T, Infotype input){
  address P;
  P = (address)malloc(sizeof(Node));
  P->Right = NULL;
  P->Left = NULL;
  (*T).Root = P;
}