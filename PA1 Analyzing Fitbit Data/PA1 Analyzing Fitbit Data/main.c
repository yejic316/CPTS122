/******************************************************************************
* Programmer: Yeji Chung													  *
* Class: CptS 121; Lab Section 06                                             *
* Programming Assignment: PA1 Analyzing Fitbit Data                           *
* Date:  1/23/2016                                                            *
*                                                                             *
* Description: This program analyze 24 hours of fitbit Data.                  *
*              Each record in the “FitbitData.csv” represents one minute of   *
*              data and consists of seven fields : 1. Minute, 2.Calories,     *
*				3. Distance (in miles), 4. Floors, 5. Heartrate, 6. Steps,	  *
*				7. Sleep level line						                      *
******************************************************************************/

#include"function.h"
int main(void)
{
	FitbitData fitbitdata[MAX] = {'\0',};
	FILE*infile = NULL, *outfile = NULL;
	char temp_readline[100] = "", max_step_minute[9] = "", start_poorsleep[9] = "", finish_poorsleep[9] = "";
	int index = 0;
	unsigned int total_floor = 0, total_steps = 0, max_step_index = 0, max_step = 0;
	double burned_calories = 0.0, total_distance=0.0, average_heartRate;

	infile = fopen("FitbitData.csv", "r");
	outfile = fopen("Results.csv", "w");

	fgets(temp_readline, 100, infile);

	for (index = 0; index < MAX; ++index)
	{
		read_fitbitdata(fitbitdata, MAX, index, temp_readline, 100, infile);
	}
	burned_calories = compute_total_calories(fitbitdata, MAX);
	total_distance = compute_total_distance(fitbitdata, MAX);
	total_floor = compute_total_floors_walked(fitbitdata, MAX);
	total_steps = compute_total_steps_taken(fitbitdata, MAX);
	average_heartRate = compute_average_heartrate(fitbitdata, MAX);
	
	max_step_index = compute_max_step(fitbitdata, MAX);
	max_step = fitbitdata[max_step_index].steps;
	strcpy(max_step_minute, fitbitdata[max_step_index].minute);

	compute_longest_poor_sleep(fitbitdata, MAX, start_poorsleep, finish_poorsleep);

	printf("total burned calories : %.9lf\n", burned_calories);
	printf("total walk distance : %.9lf\n", total_distance);
	printf("total floors walked  : %u\n", total_floor);
	printf("total steps taken  : %u\n", total_steps);
	printf("average heart rate : %lf\n", average_heartRate);
	printf("max_step : %d (%s)\n", max_step, max_step_minute);
	printf("longest poor sleep time : %s ~ %s\n", start_poorsleep, finish_poorsleep);
	
	fprintf(outfile, "Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n");
	fprintf(outfile, "%lf, %lf, %u, %u, %lf, %u,  %s : %s ", burned_calories, total_distance, total_floor, total_steps, average_heartRate, max_step, start_poorsleep, finish_poorsleep);

	fclose(infile);
	fclose(outfile);
	return 0;
}