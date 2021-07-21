#include "boolean.h"

#ifndef time_h
#define time_h

#define Hour(T) ((T).hour)
#define Minute(T) ((T).minute)
#define Second(T) ((T).second)


typedef struct {
	int hour;
	int minute;
	int second;	
}time;

/* Constructor Time */
time CreateTime();

/* Accessor Time */
int GetHour(time T);
int GetMinute(time T);
int GetSecond(time T);

/* MutatorTime */
void SetHour(time *T, int H);
void SetMinute(time *T, int M);
void SetSecond(time *T, int S);

/* Reader */
void ReadTime(time *T);
void ReadTimeOneLn(time *T);

/* Printer */
void PrintTime(time T);

void PrintTimeFormat(time T);

/* Validator */
boolean IsValid(time T);

/* Other */
int CompareTime(time T1, time T2);

#endif
