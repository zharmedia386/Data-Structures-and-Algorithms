/*
	Name: M Azhar Alauddin
	Compiler : GCC 4.9.2
	Date: 08/06/21
	Description: Siapa Berikutnya ETS Bagian B No.2
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

int main(){
	char* barisan[10][10] = {};
	int i;
	
	char input[255] = {};
	scanf("%s", input);
	fflush(stdin);
	barisan[10][10] = (char*)malloc(strlen(input)+1);
	strcpy(barisan[0][0],input);
	
	while(true){
		char input[255] = {};
		char nama[255] = {};
		int x = 0, y = 0;
		scanf("%[^\n]%*c", input);
		fflush(stdin);
		if(stricmp(input, "TUTUP BARISAN") == 0){
			break;
		}
		sscanf(input, "%s %d %d", nama, &x, &y);
		if(x > 10 || y > 10 || x < 1 || y < 1 ){
			continue; //maks 10x10 
		}
		barisan[y-1][x-1] = (char*)malloc(strlen(nama)+1);
		strcpy(barisan[y-1][x-1], nama);
	}
	
	int x = 1, y = 1;
	while(true){
		char input[255] = {};
		int pos = 0;
		
		scanf("%[^\n]%*c", input);
		fflush(stdin);
		
		if(stricmp(input, "STOP") == 0){
			break;
		}
		sscanf(input, "%d %s", &pos, input);
		if(stricmp(input, "Kiri") == 0){
			int pos_here = x-pos;
			if(pos_here < 1 || pos_here > 10 || barisan[y-1][pos_here-1] == 0){
				printf("Lapor tidak ada dalam barisan\n");
				printf("%d\n\n", pos_here);
				continue;
			}
			x = pos_here;
		} else if(stricmp(input, "Kanan") == 0){
			int pos_here = x+pos;
			if(pos_here < 1 || pos_abs > 10 || barisan[y-1][pos_here-1] == 0){
				printf("Lapor tidak ada dalam barisan\n");
				printf("%d\n\n", pos_here);
				continue;
			}
			x = pos_abs;
		} else if(stricmp(input, "Depan") == 0){
			int pos_here = y-pos;
			if(pos_here < 1 || pos_here > 10 || barisan[pos_here-1][x-1] == 0){
				printf("Lapor tidak ada dalam barisan\n");
				printf("%d\n\n", pos_here);
				continue;
			}
			y = pos_here;
		} else if(stricmp(input, "Belakang") == 0){
			int pos_here = y+pos;
			if(pos_here < 1 || pos_here > 10 || barisan[pos_here-1][x-1] == 0){
				printf("Lapor tidak ada dalam barisan\n");
				printf("%d\n\n", pos_here);
				continue;
			}
			y = pos_here;
		}
		printf("kolom %d baris %d, %s\n", x, y, barisan[y-1][x-1]);
	}
	printf("SELESAI\n");
	return 0;
}

