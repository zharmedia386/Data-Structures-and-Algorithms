/**
  * Nama File		: time.c
  * Deskripsi		: Body ADT Time (header file)
  * Author			: Asri Maspupah
  * Edited By		: M Azhar Alauddin
 **/
 
#include "time.h"
#include "boolean.h"
#include <stdio.h>

#ifndef time_c
#define time_c


/* Constructor Time */
time CreateTime()
{
	time newTime;
	Hour(newTime) = 8;
	Minute(newTime) = 0;
	Second(newTime) = 0;
	
	return newTime;
}

/* Accessor Time */
int GetHour(time T)
{
	return Hour(T);
}

int GetMinute(time T)
{
	return Minute(T);
}

int GetSecond(time T)
{
	return Second(T);
}

/* MutatorTime */
void SetHour(time *T, int H)
{
	T->hour = H;
}

void SetMinute(time *T, int M)
{
	T->minute = M;
}

void SetSecond(time *T, int S)
{
	T->second = S;
}

/* Reader */
void ReadTime(time *T)
{
	printf("Masukan Jam : "); scanf("%d", &T->hour);
	printf("Masukan Menit : "); scanf("%d", &T->minute);
	printf("Masukan detik : "); scanf("%d", &T->second);
	
	if(!IsValid(*T))
	{
		printf("Inputan tidak valid, waktu akan direset\n");
		*T = CreateTime();
	}
}

void ReadTimeOneLn(time *T)
{
	scanf("%d:%d", &T->hour, &T->minute);
	if(!IsValid(*T))
	{
		printf("Inputan salah, waktu akan di reset\n");
		*T = CreateTime();
	}
}

/* Printer */
void PrintTime(time T)
{
	printf("%d : %d : %d\n", Hour(T), Minute(T), Second(T));
}

void PrintTimeFormat(time T)
{
	if(T.hour <= 9)
		printf("0");
	printf("%d:", T.hour);
	
	if(T.minute <= 9)
		printf("0");
	printf("%d", T.minute);
}

/* Validator */
boolean IsValid(time T)
{
	if((Hour(T) < 0 || Hour(T) > 24) && (Minute(T) < 0 || Minute(T) > 59) && (Second(T) < 0 || Second(T) > 59))
		return false;
	else
		return true;
}

int CompareTime(time T1, time T2)
{
	if(T1.hour == T2.hour)
	{
		if(T1.minute == T2.minute)
			return 0;
		else if(T1.minute > T2.minute)
			return 1;
		else
			return -1;
	}else if(T1.hour > T2.hour)
	{
		return 1;
	}else
	{
		return -1;
	}

}

#endif
