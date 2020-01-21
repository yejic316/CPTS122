/******************************************************************************
* Programmer: Yeji Chung													  *
* Class: CptS 121; Lab Section 06                                             *
* Programming Assignment: PA1 Analyzing Fitbit Data                           *
* Date:  1/23/2016                                                            *
*                                                                             *
* Description: This file is "function.h". This file include needed header file*
*              , function declaration, struct declaration, type definition,   *
*              and macro constant.                                            *
******************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define MAX 1440
typedef enum sleep
{
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

typedef struct fitbit
{
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
} FitbitData;
void read_fitbitdata(FitbitData fitbit[], int size, int index, char ptemp[], int size_t, FILE*infile);
double compute_total_calories(FitbitData fitbit[], int size);
double compute_total_distance(FitbitData fitbit[], int size);
unsigned int compute_total_floors_walked(FitbitData fitbit[], int size);
unsigned int compute_total_steps_taken(FitbitData fitbit[], int size);
double compute_average_heartrate(FitbitData fitbit[], int size);
unsigned int compute_max_step(FitbitData fitbit[], int size);
void compute_longest_poor_sleep(FitbitData fitbit[], int size, char *start_poorsleep, char *finish_poorsleep);