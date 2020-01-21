#include "function.h"
Node *makeNode(Contact newData)
{
	Node *pMem = NULL;
	pMem = (Node*)malloc(sizeof(Node));
	if (pMem != NULL)
	{
		strcpy(pMem->data.name, newData.name);// 4 times
		strcpy(pMem->data.phone, newData.phone);// 4 times
		strcpy(pMem->data.email, newData.email);// 4 times
		strcpy(pMem->data.title, newData.title);// 4 times
		pMem->pNext = NULL;
	}
	return pMem;

}// pMEM;
Boolean loadContacts(FILE *infile, Node **pList)
{
	Node *pCur = NULL, *pPrev = NULL, *pMem = NULL;
	Boolean success = FALSE;
	Contact temp_c = { "" };
	char line[133] = "";

	while (!feof(infile))
	{
		fgets(line, 133, infile);
		strcy(temp_c.name, strtok(line, ","));
		strcy(temp_c.phone, strtok(NULL, ","));
		strcy(temp_c.email, strtok(NULL, ","));
		strcy(temp_c.title, strtok(NULL, ","));
	}


}
