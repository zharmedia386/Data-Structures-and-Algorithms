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
  P->data.huruf = input.huruf;
  P->Right = NULL;
  P->Left = NULL;
  (*T).Root = P;
}

void addLeft(address *Root, Infotype input){
  if((*Root)->Left == NULL){
    address P;
    P = (address)malloc(sizeof(Node));
    P->data.huruf = input.huruf;
    P->Right = NULL;
    P->Left = NULL;
    (*Root)->Left = P;
  }
  else{
    printf("Sub Tree kiri telah terisi \n");
  }
}

void delLeft(address *Root){
  if((*Root)->Left != NULL){
    address P = (*Root)->Left;
    (*Root)->Left = NULL;
    free(P);
  }
  else{
    printf("Sub Tree kiri kosong \n");
  }
}

void addRight(address *Root, Infotype input){
  if((*Root)->Right == NULL){
    address P;
    P = (address)malloc(sizeof(Node));
    P->data.huruf = input.huruf;
    P->Left = NULL;
    P->Right = NULL;
    (*Root)->Right = P;
  }
  else{
    printf("Sub Tree kanan telah terisi \n");
  }
}

void delRight(address *Root){
  if((*Root)->Right != NULL){
    address P = (*Root)->Right;
    (*Root)->Right = NULL;
    free(P);
  }
  else{
    printf("Sub Tree kanan kosong \n");
  }
}

void PrintPreOrder(address Root){
  if(Root != NULL){
    printf(" %c ", Root->data.huruf);
    PrintPreOrder(Root->Left);
    PrintPreOrder(Root->Right);
  }
}

void PrintInOrder(address Root){
  if(Root != NULL){
    PrintInOrder(Root->Left);
    printf(" %c ", Root->data.huruf);
    PrintPreOrder(Root->Right);
  }
}

void PrintPostOrder(address Root){
  if(Root != NULL){
    PrintPostOrder(Root->Left);
    PrintPostOrder(Root->Right);
    printf(" %c ", Root->data.huruf);
  }
}

void PrintLevelOrder(address Root){
  if(Root != NULL){
    // Level 0 'A'
    printf(" %c ",Root->data.huruf);
    // Level 1 Left 'B'
    if(Root->Left != NULL){
      printf(" %c ",Root->Left->data.huruf);
    }
    // Level 1 Right 'C'
    if(Root->Right != NULL){
      printf(" %c ",Root->Right->data.huruf);
    }
    // Level 2 Left 'D' & Right 'E'
    if(Root->Left != NULL){
      printf(" %c ",Root->Left->Left->data.huruf);
      printf(" %c ",Root->Left->Right->data.huruf);
      // PrintLevelOrder(Root->Left);
    }
    // Level 2 Right 'F'
    if(Root->Right != NULL){
      printf(" %c ",Root->Right->Left->data.huruf);
      // PrintLevelOrder(Root->Right);
    }
    // Level 3 left'G' & Right 'H'
    if(Root->Left != NULL){
      printf(" %c ",Root->Left->Right->Left->data.huruf);
      printf(" %c ",Root->Left->Right->Right->data.huruf);
      // PrintLevelOrder(Root->Left->Right);
    }
    // Level 3 Left 'I' & Right 'J' 
    if(Root->Right != NULL){
      printf(" %c ",Root->Left->Right->Left->Left->data.huruf);
      printf(" %c ",Root->Left->Right->Left->Right->data.huruf);
      // PrintLevelOrder(Root->Left->Right->Left);
    }
  }
}

void ReadElement(Infotype *input){
  fflush(stdin);
  scanf("%c",&input->huruf);
}

int main(){
  /* DEKLARASI*/
  Tree T;
  Infotype data;
  
  /* Read Node*/
  printf(" INPUT : \n");

  // A
  printf(" Node ke-1 : ");
  ReadElement(&data);
  CreateTree(&T,data);

  // B
  printf(" Node ke-2 : ");
  ReadElement(&data);
  addLeft(&T.Root,data);

  // C
  printf(" Node ke-3 : ");
  ReadElement(&data);
  addRight(&T.Root,data);

  // D
  printf(" Node ke-4 : ");
  ReadElement(&data);
  addLeft(&T.Root->Left,data);

  // E
  printf(" Node ke-5 : ");
  ReadElement(&data);
  addRight(&T.Root->Left,data);

  // F
  printf(" Node ke-6 : ");
  ReadElement(&data);
  addLeft(&T.Root->Right,data);

  // G
  printf(" Node ke-7 : ");
  ReadElement(&data);
  addLeft(&T.Root->Left->Right,data);

  // H
  printf(" Node ke-8 : ");
  ReadElement(&data);
  addRight(&T.Root->Left->Right,data);

  // I
  printf(" Node ke-9 : ");
  ReadElement(&data);
  addLeft(&T.Root->Left->Right->Left,data);

  // J
  printf(" Node ke-10 : ");
  ReadElement(&data);
  addRight(&T.Root->Left->Right->Left,data);

  printf("\n =================\n");

  /* Print Node*/
  printf("\n HASIL OUTPUT : \n");
  
  // PreOrder
  printf(" preOrder\n");
  PrintPreOrder(T.Root);

  // InOrder
  printf("\n inOrder\n");
  PrintInOrder(T.Root);

  // postOrder
  printf("\n postOrder\n");
  PrintPostOrder(T.Root);

  // levelOrder
  printf("\n levelOrder\n");
  PrintLevelOrder(T.Root);

  return 0;
}