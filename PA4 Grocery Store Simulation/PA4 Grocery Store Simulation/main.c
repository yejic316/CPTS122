/******************************************************************************
* Programmer: Yeji Chung													  *
* Class: CptS 122; Lab Section 06                                             *
* Programming Assignment: PA4 Grocery Store Simulation                        *
* Date:  2/22/2017                                                            *
*                                                                             *
* Description: This program is to simulate two lines in a grocery store       *
*              using two queue structure                                      *
******************************************************************************/
#include "function.h"
int main(void)
{
	Queue ELane = { NULL }, NLane = { NULL };

	CheckTime E = { 0 }, N = { 0 };
	time_t  total_minute=0, presentTime0 = 0;

	srand((unsigned int)time(NULL));

	presentTime0 = time(NULL);

	//generate service time only for first customer's arrival time
	E.newArrivalTime = generate_serviceTime(EXPRESS);
	N.newArrivalTime = generate_serviceTime(NORMAL);

	printf("\n[%d:00]", total_minute);

	while (total_minute<MAX_MINUTE)
	{
		// generate new arrival time
												
		if ((time(NULL) - presentTime0) == ONE_MINUTE)// count "one minute"
		{
			++total_minute;
			++(E.count_arrival_minute);// count 1 minute for enqueue, ELane
			++(N.count_arrival_minute);// count 1 minute for enqueue, NLane
			
			presentTime0 = time(NULL);
			printf("\n[%d:00]", total_minute);

	//check out first
		// for Check out ELane, when the ELane is not empty
			if (ELane.pHead != NULL)
			{
				(E.count_service_minute)++; // count 1 minute for dequeue

				if (ELane.pHead->serviceTime == E.count_service_minute)
				{
					print_checkOut(&ELane, EXPRESS);

					dequeue(&ELane);
					E.count_service_minute = 0;
				}
			}
		// for Check out NLane, when the NLane is not empty
			if (NLane.pHead != NULL)
			{
				(N.count_service_minute)++; // count 1 minute for dequeue
				if (NLane.pHead->serviceTime == N.count_service_minute)
				{
					print_checkOut(&NLane, NORMAL);

					dequeue(&NLane);
					N.count_service_minute = 0;
				}
			}

	//arrived Last
		// arrive new customer at ELane
			if (E.count_arrival_minute == E.newArrivalTime)
			{
				enqueue(&ELane, EXPRESS, ++(E.count_customer));
				E.count_arrival_minute = 0;
				print_arrived(&ELane, EXPRESS);

				//generate arrival time for next customer
				E.newArrivalTime = generate_serviceTime(EXPRESS);
			}

		// arrive new customer at NLane
			if (N.count_arrival_minute == N.newArrivalTime)
			{
				enqueue(&NLane, NORMAL, ++(N.count_customer));
				N.count_arrival_minute = 0;
				print_arrived(&NLane, NORMAL);

				//generate arrival time for next customer
				N.newArrivalTime = generate_serviceTime(NORMAL);
			}


			// print out the entire queue for every 10 minute
			if (total_minute % 10 == 0)
			{
				puts("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ \n");
				puts("(EXPRESS LANE)");
				print_queue(&ELane); 
				puts("(NORMAL LANE)");
				print_queue(&NLane);
				puts("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ \n");
			}
		}
	}

	return 0;
}