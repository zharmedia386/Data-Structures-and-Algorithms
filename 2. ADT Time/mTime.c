#include <stdio.h>
#include <stdlib.h>
#include "Time.h"
#include <time.h>

int main()
{
	// Welcoming
	printf("Hi!, Selamat Datang di Pomodoro Timer ^_^");
	sleep(3);
	system("cls");
	
	// Orientation
	printf("Pomodoro adalah metode manajemen waktu yang \n");
	printf("dikembangkan oleh Francesco Cirillo pada akhir 1980-an.\n"); 
	printf("Teknik ini menggunakan pengatur waktu untuk membagi pekerjaan \n");
	printf("menjadi beberapa interval, biasanya berdurasi 25 menit, \n");
	printf("dipisahkan dengan jeda singkat.");
	sleep(5);
	system("cls");
	
	// Declaration
    TIME a, b, c;
    int N,N1;
    
    // Content
	printf("Waktu anda memulai belajar : \n");
    ReadTIME(&a); // Jam Awal
    printf("\n");
    system("cls");
    
	printf("Waktu anda memulai belajar : \n");
    PrintTIME(a);
    printf("\n");
    sleep(1);
    
    N = TimeToDetik(a);
	N1 = N + 1500;
	
	printf("Waktu anda berakhir belajar :\n");
    DetikToTIME(N1);
    sleep(4);
    system("cls");
    
    // Content for Timer
    int j, k;
    
    // Timer selama 25 menit
	for(j = 25; j >= 0;){ //menit
		for(k = 60; k >= 0;){ //detik
		    	printf("Timer = %d : %d\n", j, k);
		    	system("cls");
		    	k--;
		    		if(k == 0){
		    			j--;
		    		}
		}
	}
	
	// Penutup
	system("cls");
	printf("Mulai lagi program ini, untuk memulai belajar kembali selama 25 menit ");
	printf("Semoga anda bisa fokus mengerjakan tugas dan pekerjaan anda tanpa terganggu dengan distraksi di sekitar anda");
	printf("Terima kasih! ^_^");
	
    return 0;
}
