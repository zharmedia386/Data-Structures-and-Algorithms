#include <stdio.h>
#include <stdlib.h>
#include "line.h"

int main(){
	LINE L1;
	
	ReadLine(&L1);
	PrintLine(L1);
	
	printf("\nPanjang Line : %d", PanjangLine(L1));
	
	return 0;
}
