#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>

typedef char Infotype;
typedef struct elmt *address;

typedef struct elmt{
  Infotype data;
  address next;
}Node;

typedef struct{
  address Top;
}Stack;

void CreateStack(Stack *S){
  S->Top = NULL;
}

address Alokasi(Infotype X){
  address P = (address)malloc(sizeof(Node));
  P->data = X;
  return P;
}

bool isEmpty(Stack S){
  if(!S.Top){
    return false;
  }
  else{
    return true;
  }
}

int CountElement(Stack S){
  int result = 0;
  address P = S.Top;
  if(!S.Top){
    while(!S.Top->next){
      P = P->next;
      result++;
    }
  }
  return result;
}

void Push(Stack *S, Infotype input){
  address P = Alokasi(input);
  P->next = S->Top;
  S->Top = P;
}

void Pop(Stack *S){
  address P = S->Top;
  printf("\nNode '%c' sudah dihapus\n",P->data);
  S->Top = S->Top->next;
  P->next = NULL;
  free(P);
}

void ReadElement(Infotype *input){
  printf("Isi Node : ");
  scanf("%c",input);
  fflush(stdin);
}

void PrintElement(Stack S){
  printf("PRINT ELEMENT\n");
  int i = 1;
  while(S.Top != NULL){
    printf("Huruf ke-%d : %c\n",i,S.Top->data);
    S.Top = S.Top->next;
    i++;
  }
}

int main(){
  Stack S;
  Infotype data;

  // Membuat Stack Baru
  CreateStack(&S);

  printf("READ ELEMENT\n");

  // Menambah Node pada Stack - Operasi Push
  ReadElement(&data);
  Push(&S,data);

  // Menambah Node pada Stack - Operasi Push
  ReadElement(&data);
  Push(&S,data);

  // Menambah Node pada Stack - Operasi Push
  ReadElement(&data);
  Push(&S,data);

  // Menghapus Node pada Stack - Operasi Pop
  Pop(&S);

  printf("\n");

  // Menampilkan Seluruh Isi Node ke Layar
  PrintElement(S);
  
  return 0;
}