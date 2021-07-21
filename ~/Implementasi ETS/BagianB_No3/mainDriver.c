/*
	Name: M Azhar Alauddin
	Compiler : GCC 4.9.2
	Date: 08/06/21
	Description: Layanan Fotocopy ETS Bagian B No.3
*/

#include "List.h"

int main(){
	List Antrian;
	int count;
	infotype data;
	int i;
	int start = 1, end = 1;

	CreateList(&Antrian);
	
	// menentukan jumlah Antrian
	scanf("%d", &count); fflush(stdin);

	for(i=0 ; i<count ; i++){
		scanf("%c %d %d", &data.nama, &data.waktu, &data.Jml_Lembar); fflush(stdin);// mengisi data yang diperlukan
		InsVLast(&Antrian, data);
	}

	address customer = Antrian.First;
	while(true){
		// menentukan giliran siapa selanjutnya
		customer = NextNode(Antrian, start); 
		if(customer == Nil)
			break;
		data = customer->info; 
		DelP(&Antrian, customer);
		end = start + data.Jml_Lembar - 1;
		printf("%c %d %d %d %d\n", data.nama, data.waktu, data.Jml_Lembar, start, end);
		start = end;
	}
	return 0;
}
