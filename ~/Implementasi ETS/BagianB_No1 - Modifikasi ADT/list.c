#include "list.h"

void CreateList(List *L)
{
  (*L).first = NULL;
}

int CountElement(List L)
{
  int hasil = 0;
  address P;
  P = (L).first;
  while (P != NULL)
  {
    hasil += 1;
    P = P->next;
  }
  return hasil;
}

void addFirst(Infotype input, List *L)
{
  address P;
  P = (address)malloc(sizeof(elemen));
  strcpy(P->data.Nama, input.Nama);
  strcpy(P->data.Nilai, input.Nilai);
  P->next = (*L).first;
  (*L).first = P;
}

void addLast(Infotype input, List *L)
{
  if ((*L).first == NULL)
  {
    addFirst(input, L);
  }
  else
  {
    address P;
    P = (address)malloc(sizeof(elemen));
    strcpy(P->data.Nama, input.Nama);
    strcpy(P->data.Nilai, input.Nilai);

    address Last;
    Last = (*L).first;
    while (Last->next != NULL)
    {
      Last = Last->next;
    }
    Last->next = P;
  }
}

void addAfter(address Prec, Infotype input, List *L)
{
  address P;
  P = (address)malloc(sizeof(elemen));
  strcpy(P->data.Nama, input.Nama);
  strcpy(P->data.Nilai, input.Nilai);
  P->next = Prec->next;
  Prec->next = P;
}

void delFirst(List *L)
{
  address P;
  P = (*L).first;
  (*L).first = P->next;
  P->next = NULL;
  free(P);
}

void delLast(List *L)
{
  if (CountElement(*L) == 1)
  {
    delFirst(L);
  }
  else
  {
    address last;
    address beforeLast;

    last = (*L).first;
    while (last->next != NULL)
    {
      beforeLast = last;
      last = last->next;
    }
    beforeLast->next = NULL;
    free(last);
  }
}

void delAll(List *L)
{
  if (CountElement(*L) != 0)
  {
    int i;
    for (i = CountElement(*L); i > 0; i--)
    {
      delLast(L);
    }
  }
}

void PrintElement(List L)
{
  if ((L).first != NULL)
  {
    address P;
    P = L.first;
    while (P != NULL)
    {
      printf("%s %s\n", P->data.Nama, P->data.Nilai);
      P = P->next;
    }
    printf("\n");
  }
  else
  {
    printf("\n\nList Kosong!");
  }
}

void ReadElement(Infotype *input)
{
  fflush(stdin);
  printf ("Nama  : ");
  scanf ("%[^\n]*c", input->Nama);
  fflush(stdin);
  printf ("Nilai : ");
  scanf ("%[^\n]*c", input->Nilai);
  fflush(stdin);
}
