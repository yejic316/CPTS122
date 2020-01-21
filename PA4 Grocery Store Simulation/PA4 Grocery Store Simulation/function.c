#include "function.h"
QueueNode *makeNode(EorN eorn, int ordinal)
{
	QueueNode *pMem = {NULL};
	pMem = (QueueNode*)malloc(sizeof(QueueNode));

	if (pMem != NULL)
	{
		pMem->pNext = NULL;
		pMem->customerNumber = ordinal;

		pMem->serviceTime = generate_serviceTime(eorn);
	}
	return pMem;
}

int isEmpty(Queue *qLane)
{
	if (qLane->pHead == NULL)// if Lane is empty
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void enqueue(Queue*qLane,EorN eorn, int ordinal)
{
	QueueNode *pMem = NULL;
	pMem = makeNode(eorn, ordinal);
	pMem->totalTime = 0;
	//pCur = qLane->pHead;

	if (pMem != NULL)
	{
		if (isEmpty(qLane))//first node
		{
		//	pMem->totalTime = pMem->serviceTime;
			qLane->pHead = qLane->pTail = pMem;
		}
		else
		{
			pMem->totalTime = qLane->pTail->totalTime + qLane->pTail->serviceTime;// change total Time
			qLane->pTail->pNext = pMem;
			qLane->pTail = pMem;
		}
	}
}

void dequeue(Queue *qLane)
{
	QueueNode *pTemp = NULL, *pCur = NULL;

	pTemp = pCur = qLane->pHead;
	if (qLane->pHead == qLane->pTail)// if there is one node
	{
		qLane->pHead = qLane->pTail = NULL;
	}
	else
	{
		while (pCur != NULL)// change total Time
		{
			pCur->totalTime -= pTemp->serviceTime;
			pCur = pCur->pNext;
		}
		qLane->pHead = qLane->pHead->pNext;		
	}
	free(pTemp);
}

void print_queue(Queue *qLane)
{
	QueueNode *pCur = NULL;
	
	pCur = qLane->pHead;
	printf(" <- ");
	
	while (pCur != NULL)
	{
		printf("customer %d (ST: %d , TT:%d) <-", pCur->customerNumber,pCur->serviceTime, pCur->totalTime);
		pCur = pCur->pNext;
	}
	printf("\n\n");

}
int generate_serviceTime(EorN eorn)
{
	if (eorn == EXPRESS)
	{
		return rand() % 5 + 1;
	}
	else if (eorn == NORMAL)
	{
		return rand() % 5 + 3;
	}
}
void print_arrived(Queue *qLane, EorN eorn)
{
	if (eorn == EXPRESS)
	{
		printf("\t(EXPRESS)\n");
		printf("\tCustomer %d > Arrived <\n ", qLane->pTail->customerNumber);
		printf("\t-service time : %d\n", qLane->pTail->serviceTime);
		printf("\t-total time : %d\n\n ", qLane->pTail->totalTime);
	}
	else if (eorn == NORMAL)
	{
		printf("\t\t\t\t\t\t(NORMAL)\n");
		printf("\t\t\t\t\t\tCustomer %d > Arrived <\n ", qLane->pTail->customerNumber);
		printf("\t\t\t\t\t\t-service time : %d\n", qLane->pTail->serviceTime);
		printf("\t\t\t\t\t\t-total time : %d\n\n ", qLane->pTail->totalTime);
	}

}
void print_checkOut(Queue *qLane, EorN eorn)
{
	if (eorn == EXPRESS)
	{
		printf("\t(EXPRESS)\n");
		printf("\tCustomer %d > Checking out <\n\n ", qLane->pHead->customerNumber);
	}
	else if (eorn == NORMAL)
	{
		printf("\t\t\t\t\t\t(NORMAL)\n");
		printf("\t\t\t\t\t\tCustomer %d > Checking out <\n\n ", qLane->pHead->customerNumber);
	}

}
