#include "bintree.h"

address createNode(Infotype X){
  address NewNode = (address)malloc(sizeof(Node));

  NewNode->data = X;
  NewNode->Left = NULL;
  NewNode->Right = NULL;

  return NewNode;
}

void insertNode(address *node,address P){
  if((*node) == NULL)
    (*node) = P;
  else{
    if(P->data > (*node)->data)
      insertNode(&(*node)->Right,P);
    else if(P->data < (*node)->data)
      insertNode(&(*node)->Left,P);
  }
}

address findNode(address node, Infotype X){
  if(node == NULL || node->data == X)
    return node;
  else{
    if(X > node->data)
      return findNode(node->Right,X);
    else if(X < node->data)
      return findNode(node->Left, X);
  }
}

void preOrder(address node){
  if(node != NULL){
    printf("%d ",node->data);
    preOrder(node->Right);
    preOrder(node->Left);
  }
}

void inOrder(address node){
  if(node != NULL){
    inOrder(node->Right);
    printf("%d ",node->data);
    inOrder(node->Left);
  }
}

void postOrder(address node){
  if(node != NULL){
    postOrder(node->Right);
    postOrder(node->Left);
    printf("%d ", node->data);
  }
}