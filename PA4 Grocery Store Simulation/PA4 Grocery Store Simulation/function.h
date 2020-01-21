#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MAX_MINUTE 100
#define ONE_MINUTE 5  // you can change this value / faster : smaller than 5/ slower-> larger than 5
typedef struct queueNode
{
	int customerNumber; 
	int serviceTime;   
	int totalTime;   

	struct queueNode *pNext;

} QueueNode;

typedef struct queue
{
	QueueNode *pHead;
	QueueNode *pTail;

} Queue;
typedef enum Express_or_Normal
{
	EXPRESS, NORMAL
}EorN;


typedef struct check_time
{// structure of various variables related count minute 

	int count_customer;
	int newArrivalTime;
	int count_service_minute;// for checking service time
	int count_arrival_minute;// for checking arrival time
}CheckTime;

QueueNode *makeNode(EorN eorn, int ordinal);
int isEmpty(Queue *qLane);
void enqueue(Queue*qLane, EorN eorn, int ordinal);
void dequeue(Queue *qLane);
void print_queue(Queue *qLane);
int generate_serviceTime(EorN eorn);
void print_arrived(Queue *qLane, EorN eorn);
void print_checkOut(Queue *qLane, EorN eorn);
