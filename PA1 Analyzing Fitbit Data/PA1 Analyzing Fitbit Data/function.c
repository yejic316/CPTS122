/******************************************************************************
* Programmer: Yeji Chung													  *
* Class: CptS 121; Lab Section 06                                             *
* Programming Assignment: PA1 Analyzing Fitbit Data                           *
* Date:  1/23/2016                                                            *
*                                                                             *
* Description: This file is "function.c". This file contain all of function   *
*              which needed in this probram.                                  *
******************************************************************************/

#include"function.h"

void read_fitbitdata(FitbitData fitbit[], int size, int index, char ptemp[],int size_t, FILE*infile)
{
	int empty_check = NULL;
	fgets(ptemp, 100, infile);

	if (strstr(ptemp, ",,") != NULL)// find ",,"
	{
		strcpy(fitbit[index].minute, strtok(ptemp, ","));
		fitbit[index].calories = atof(strtok(NULL, ","));
		fitbit[index].distance = atof(strtok(NULL, ","));
		fitbit[index].floors = atoi(strtok(NULL, ",,"));
		fitbit[index].heartRate = NULL;
		fitbit[index].steps = atoi(strtok(NULL, ","));
		fitbit[index].sleepLevel = (Sleep)atoi(strtok(NULL, ""));

	}
	else // no ",,"
	{
		strcpy(fitbit[index].minute, strtok(ptemp, ","));
		fitbit[index].calories = atof(strtok(NULL, ","));
		fitbit[index].distance = atof(strtok(NULL, ","));
		fitbit[index].floors = atoi(strtok(NULL, ","));
		fitbit[index].heartRate = atoi(strtok(NULL, ","));
		fitbit[index].steps = atoi(strtok(NULL, ","));
		fitbit[index].sleepLevel = (Sleep)atoi(strtok(NULL, ""));

	}
/*
	printf("%d)  ", index);
	printf("%s ", fitbit[index].minute);
	printf("%.9lf ", fitbit[index].calories);
	printf("%.9lf ", fitbit[index].distance);
	printf("floor : %u, ", fitbit[index].floors);
	printf(" rate : %u, ", fitbit[index].heartRate);
	printf(" steps: %u, ", fitbit[index].steps);
	printf(" level : %d \n\n", fitbit[index].sleepLevel);
*/	
}
double compute_total_calories(FitbitData fitbit[], int size)
{
	double sum = 0;
	for (int i = 0; i < size; ++i)
	{
		sum += fitbit[i].calories;
	}
	return sum;
}
double compute_total_distance(FitbitData fitbit[], int size)
{
	double sum = 0;
	for (int i = 0; i < size; ++i)
	{
		sum += fitbit[i].distance;
	}
	return sum;
}
unsigned int compute_total_floors_walked(FitbitData fitbit[], int size)
{
	double sum = 0;
	for (int i = 0; i < size; ++i)
	{
		sum += fitbit[i].floors;
	}
	return sum;
}

unsigned int compute_total_steps_taken(FitbitData fitbit[], int size)
{
	double sum = 0;
	for (int i = 0; i < size; ++i)
	{
		sum += fitbit[i].steps;
	}
	return sum;
}
double compute_average_heartrate(FitbitData fitbit[], int size)
{
	int sum = 0, count=0;
	double average = 0.0;

	for (int i = 0; i < size; ++i)
	{
		if (fitbit[i].heartRate != NULL)
		{
			sum += fitbit[i].heartRate;
			++count;
		}
	}
	average = (double)sum / count;
	return average;
}
unsigned int compute_max_step(FitbitData fitbit[], int size)
{
	int i = 0, max_index=0;

	for (i = 0; i < size; ++i)
	{
		if (fitbit[i].steps >= fitbit[max_index].steps)
		{
			max_index = i;
		}
	}
	return max_index;
}
void compute_longest_poor_sleep(FitbitData fitbit[], int size, char *start_poorsleep, char *finish_poorsleep)
{
	int i = 0, sum = 0, longest_sum = 0, finish_index=0, start_index = 0, count=0;
	for (i = 0; i < size; ++i)
	{
		if (fitbit[i].sleepLevel > 1)
		{
			sum += fitbit[i].sleepLevel;
			if (count == 0) // check starting point of poor sleep
			{
				start_index = i;
			}
			if (sum>=longest_sum)// if sum is longer than before
			{
				longest_sum = sum;// longest sum updated
				finish_index = i;// check finishing point of poor sleep
			}
			++count;
		}
		else
		{
			sum = 0;
			count = 0;
		}		
	}
	strcpy(start_poorsleep, fitbit[start_index].minute);
	strcpy(finish_poorsleep, fitbit[finish_index].minute);
}