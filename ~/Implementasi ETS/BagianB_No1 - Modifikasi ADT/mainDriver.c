#include "list.h"

int main()
{
  List L;
  Infotype data;
  CreateList(&L);
  int jumlahMhs;
  int i;

  scanf("%d", &jumlahMhs);
  fflush(stdin);
  
  for(i = 0; i < jumlahMhs; i++)
  {
    ReadElement(&data);
    addFirst(data, &L);
    PrintElement(L);
  }

  return 0;
}
