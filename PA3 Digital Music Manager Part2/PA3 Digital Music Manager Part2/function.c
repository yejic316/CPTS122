#include "function.h"
Node *makeNode(Node *pMem)
{
	pMem = (Node*)malloc(sizeof(Node));
	pMem->pNext = NULL;
	pMem->pPrev = NULL;

	return pMem;
}
int load(FILE*infile, Node **pList)
{
	char pReadLine[100]="", temp_song_length[5]="";
	Node *pMem = NULL, *pCur = NULL;
	Record newRecord = {"",};

	/* Read each line from the file */
	while (!feof(infile) && fgets(pReadLine, 100, infile))
	{
		pMem = makeNode(pMem);			

		/* process information of a record */
		if (pReadLine!=NULL);
		{
			if (pReadLine[0] == '"')//if the type of artist's name is "-, -"
			{
				strcpy(newRecord.artist, strtok(pReadLine, ","));
				strcat(newRecord.artist, ",");
				strcat(newRecord.artist, strtok(NULL, ","));

			}
			else// if the type of artist's name is a word
			{
				strcpy(newRecord.artist, strtok(pReadLine, ","));
			}
			strcpy(newRecord.album_title, strtok(NULL, ","));
			strcpy(newRecord.song_title, strtok(NULL, ","));
			strcpy(newRecord.genre, strtok(NULL, ","));

			strcpy(temp_song_length, strtok(NULL, ","));

			newRecord.number_times_played = atoi(strtok(NULL, ","));
			newRecord.rating = atoi(strtok(NULL, ","));

			newRecord.song_length.minute = atoi(strtok(temp_song_length, ":"));
			newRecord.song_length.second = atoi(strtok(NULL, ":"));

			pMem->data = newRecord;

			if (*pList == NULL)//
			{
				*pList = pMem;
				pMem->pNext = NULL;
			}
			else
			{
				(*pList)->pPrev = pMem;
				pMem->pNext = *pList;
				*pList = pMem;
			}
		}
	}
	return 1;
}

void store(FILE*outfile, Node **pList)
{
	Node* pCur = NULL;
	pCur = *pList;
	while (pCur != NULL)
	{
		fprintf(outfile,"%s,", pCur->data.artist);
		fprintf(outfile, "%s,", pCur->data.album_title);
		fprintf(outfile, "%s,", pCur->data.song_title);
		fprintf(outfile, "%s,", pCur->data.genre);
		fprintf(outfile, "%d:%d,", pCur->data.song_length.minute, pCur->data.song_length.second);
		fprintf(outfile, "%d,", pCur->data.number_times_played);
		fprintf(outfile, "%d\n", pCur->data.rating);

		pCur = pCur->pNext;
	}
}

void display_list(Node *pList)
{
	Node *pCur = NULL;

	pCur = pList;
	printf("\n-> ");
	while (pCur!= NULL)
	{
		printf("%s -> ", pCur->data.song_title);
		pCur = pCur->pNext;
	}
	putchar('\n');
}
int searching_artist(Node **pList, char*pArtist, Node artist_multiAlbum[])
{
	Node *pCur = NULL;
	int flag_search = 0, index = 1;

	pCur = *pList;
	while (pCur != NULL)
	{
		if (strstr(pCur->data.artist, pArtist) != NULL)// found matched artist
		{
			artist_multiAlbum[index] = *pCur;
			printf("\n\t[%d]artist : %s _ song : %s", index, artist_multiAlbum[index].data.artist, artist_multiAlbum[index].data.song_title);
			++index;
			flag_search = 1;
		}
		pCur = pCur->pNext;
	}
	if (flag_search == 1)//if found the artist
	{
		return index;
	}
	else
	{
		return 0;
	}
}
void display_record(Node *pCur)
{
	printf("\t(1)artist : %s\n", pCur->data.artist);
	printf("\t(2)album title : %s \n", pCur->data.album_title);
	printf("\t(3)song title : %s \n", pCur->data.song_title);
	printf("\t(4)genre : %s \n", pCur->data.genre);
	printf("\t(5)song length : %d:%d \n", pCur->data.song_length.minute, pCur->data.song_length.second);
	printf("\t(6)Number times played : %d \n", pCur->data.number_times_played);
	printf("\t(7)Rating : %d \n\n", pCur->data.rating);
}
int edit(Node **pList, char*pArtist)
{
	int  index = 0, select1 = 0, select2 = 0;
	Node *pCur = NULL, artist_multiAlbum[10] = {NULL};
	char temp_char[50] = "";

	pCur = *pList;
	index = searching_artist(pList, pArtist, artist_multiAlbum);
	if (index != 0)// if find artist
	{
		do// Choose a Song
		{
			printf("\n\n -Select artist to edit information (enter a number): ");
			scanf("%d", &select1);
			while (getchar() != '\n'); // buffer'\n'
		} while (select1 > index);

		//for matching pCur and the song which we found 
		pCur = *pList;
		while (pCur != NULL)
		{
			if (strcmp(pCur->data.song_title, artist_multiAlbum[select1].data.song_title) == 0)// found matched song
			{
				*pCur = artist_multiAlbum[select1];
				break;
			}
			pCur = pCur->pNext;
		}

		//show all attribute about chosen song
		display_record(pCur);

		do
		{
			printf(" -Select a attribute which you want to modify(enter a number): ");
			scanf("%d", &select2);
			while (getchar() != '\n'); // buffer'\n'

		} while ((select2 > 7) || (select2 < 1));

		switch (select2)
		{
		case 1:
			printf("Edit Artist->");
			gets(temp_char);
			strcpy(pCur->data.artist, temp_char);
			break;
		case 2:
			printf("Edit Album title->");
			gets(temp_char);
			strcpy(pCur->data.album_title, temp_char);
			break;
		case 3:
			printf("Edit Song Title->");
			gets(temp_char);
			strcpy(pCur->data.song_title, temp_char);
			break;
		case 4:
			printf("Edit Genre->");
			gets(temp_char);
			strcpy(pCur->data.genre, temp_char);
			break;
		case 5:
			printf("Edit Song Length(Enter mm:ss)->");
			scanf("%d:%d", &pCur->data.song_length.minute, &pCur->data.song_length.second);
			while (getchar() != '\n');
			break;
		case 6:
			printf("Edit the Number of times Played->");
			scanf("%d", &pCur->data.number_times_played);
			while (getchar() != '\n');
			break;
		case 7: 
			printf("Edit Rating->");
			scanf("%d", &pCur->data.rating);
			while (getchar() != '\n');
			break;
		}

		display_record(pCur);
		system("pause");
		return 1;
	}
	else// if we can't find any artist
	{
		puts("\t\"Can not find any artist\"");
		return 0;
	}
}
Node *searching_song(Node **pList, char *temp_song)
{
	Node *pCur = NULL;
	int flag_search = 0;

	pCur = *pList;
	while (pCur != NULL)
	{
		if (strcmp(pCur->data.song_title, temp_song) == 0)// found matched song
		{
			flag_search = 1;
			return pCur;
			break;
		}
		pCur = pCur->pNext;
	}
	if (flag_search == 0)
	{
		puts("\n\t\"Can not find any song\"");
		return NULL;
	}
}
void rate(Node**pList)
{
	Node *pCur = NULL;
	char YorN = '\0', temp_song[50] = "";
	int flag_search = 0;
	//int count = 1;

	pCur = *pList;
	while (pCur != NULL)// display all song with rate
	{
		printf("\t%15s _ rate : %d\n", pCur->data.song_title, pCur->data.rating);
		pCur = pCur->pNext;
	}

	//ask if user want to edit rate
	do {
		printf("- Do you want to change rate? Enter Y or N : ");
		scanf("%c", &YorN);
		while (getchar() != '\n'); // buffer'\n'

	} while ((YorN != 'Y') && (YorN != 'y') && (YorN != 'N') && (YorN != 'n'));
	
	if ((YorN == 'Y') || (YorN == 'y'))
	{
		
		do //search matched song
		{
			pCur = *pList;
			printf("\n- Enter the title of song which you want to edit rating : ");
			gets(temp_song);
			pCur = searching_song(pList, temp_song);
			
		} while (pCur==NULL);
		
		// found song,  change rating
		printf("\tsong : %s _ rate : %d\n", pCur->data.song_title, pCur->data.rating);
		do
		{
			printf("\n -change rate ->");
			scanf("%d", &pCur->data.rating);
			while (getchar() != '\n'); // buffer'\n'
			if ((pCur->data.rating < 1) || (pCur->data.rating > 5))
			{
				puts("\" Pleas Enter a integer between 1 ~ 5\"");
			}
		} while ((pCur->data.rating < 1) || (pCur->data.rating > 5));

	}

}

void select_play(Node **pList)
{
	Node *pCur = NULL, *pCur_forPlay = NULL, *pHead = NULL;
	char temp_song[50] = "";
	int flag = 0;

	pHead = *pList;

	do //search matched song
	{
		pCur = *pList;
		printf("\n- Enter the title of song which you want to play first : ");
		gets(temp_song);
		pCur = searching_song(pList, temp_song);

	} while (pCur == NULL);

	if (pCur_forPlay == NULL)
	{
		pCur_forPlay = pCur;
	}
	while (pCur_forPlay->pNext != NULL)
	{
		system("cls");
		puts(">>Playing Music ..\n");

		display_record(pCur_forPlay);
		pCur_forPlay = pCur_forPlay->pNext;
		Sleep(1000);
	}

	system("cls");
	puts(">>Playing Music ..\n");
	display_record(pCur_forPlay);
	Sleep(1000);

	while(strcmp(pCur->data.song_title, pHead->data.song_title) != 0)
	{
		system("cls");
		puts(">>Playing Music ..\n");

		display_record(pHead);
		pHead = pHead->pNext;
		Sleep(1000);
	}
	puts(">>All music has been played ..\n");
	system("pause");
	system("cls");

}

void order_play(Node **pList)
{
	Node *pCur = NULL;

	pCur = *pList;
	while (pCur->pNext != NULL)
	{
		system("cls");
		puts(">>Playing Music ..\n");

		display_record(pCur);
		Sleep(1000);

		pCur = pCur->pNext;
	}

	system("cls");
	puts(">>Playing Music ..\n");// Last one

	display_record(pCur);
	Sleep(1000);
	puts(">>All music has been played ..\n");

	system("pause");
	system("cls");
}


/* For PA3 (part2) insert/ delete/ sort/ shuffle ***************************************************/

void insertFront(Node**pList)
{
	Node *pMem = NULL;
	int flag_rating = 0;
	pMem = makeNode(pMem);

	printf("- Enter the name of Artist : ");
	scanf("%s", pMem->data.artist);
	printf("- Enter the title of Album : ");
	scanf("%s", pMem->data.album_title);
	printf("- Enter the title of song : ");
	scanf("%s", pMem->data.song_title);
	printf("- Enter the type of Genre : ");
	scanf("%s", pMem->data.genre);
	printf("- Enter the length of the song (mm:ss): ");
	scanf("%d:%d", &pMem->data.song_length.minute, &pMem->data.song_length.second);
	printf("- Enter the number of times played : ");
	scanf("%d", &pMem->data.number_times_played);
	do
	{
		printf("- Enter rating (Enter a integer between 1~5): ");
		scanf("%d", &pMem->data.rating);
	} while ((pMem->data.rating > 5) || (pMem->data.rating < 1));

	if (*pList == NULL)
	{
		*pList = pMem;
		pMem->pNext = NULL;
	}
	else
	{
		(*pList)->pPrev = pMem;
		pMem->pNext = *pList;
		*pList = pMem;
	}
}
int delete(Node**pList, char*pSong)
{
	Node*pCur = NULL, *pPrev = NULL, *pNext = NULL;
	int success = 0;
	pCur = *pList;

	while ((pCur != NULL) && (strcmp(pCur->data.song_title, pSong) != 0))
	{// search the song which correspond
		pPrev = pCur;
		pCur = pCur->pNext;
	}
	if (pCur != NULL)// found
	{
		if (pPrev != NULL)
		{
			pPrev->pNext = pCur->pNext;
			free(pCur);
		}
		else
		{
			*pList = (*pList)->pNext;
			free(pCur);
		}
		success = 1;
	}
	return success;

}
int get_size_List(Node *pList, Node *pCur, int length)
{
	if (length == 0)
	{
		display_list(pList);
		pCur = pList;
	}
	if (pCur != NULL)
	{
		return get_size_List(pList, pCur->pNext, ++length);
	}
	else
	{
		return length;
	}
}
void sort_artist(Node **pList)
{
	Node *pCur = NULL, *pNext = NULL;
	char temp_cur_artist[50] = "", temp_next_artist[50] = "";
	int size_List = 0;

	size_List = get_size_List(*pList, pCur, size_List);

	pCur = *pList;
	pNext = pCur->pNext;

	for(int i=0;i<size_List;++i)
	{
		while (pNext != NULL)
		{
			if (pCur->data.artist[0] == '"')
			{
				strtok(pCur->data.artist, ", ");
				strcpy(temp_cur_artist, strtok(NULL, ", "));// for Last name
				strcat(pCur->data.artist, ", ");
				strcat(pCur->data.artist, temp_cur_artist);
			}
			else
			{
				strcpy(temp_cur_artist, pCur->data.artist);
			}

			if (pNext->data.artist[0] == '"')// pNext->data.artist : for last name
			{
				strtok(pNext->data.artist, ", ");
				strcpy(temp_next_artist, strtok(NULL, ", "));// for Last name
				strcat(pNext->data.artist, ", ");
				strcat(pNext->data.artist, temp_next_artist);
			}
			else
			{
				strcpy(temp_next_artist, pNext->data.artist);
			}

			if (strcmp(temp_cur_artist, temp_next_artist) > 0)
			{				
				if (pCur->pPrev == NULL)// fist node
				{
					pCur->pNext = pNext->pNext;
					pNext->pNext = pCur;

					pCur->pNext->pPrev = pCur;
					pCur->pPrev = pNext;
					pNext->pPrev = pCur->pPrev;
					pNext->pPrev = NULL;

					*pList = pNext;
				}
				else if (pNext->pNext == NULL)//Last Node
				{
					pNext->pNext = pCur;
					pCur->pPrev->pNext = pNext;
					pCur->pNext = NULL;

					pNext->pPrev = pCur->pPrev;
					pCur->pPrev = pNext;

				}
				else
				{
					pCur->pNext = pNext->pNext;
					pNext->pNext = pCur;
					pCur->pPrev->pNext = pNext;

					pCur->pNext->pPrev = pCur;
					pNext->pPrev = pCur->pPrev;
					pCur->pPrev = pNext;
				}
			}
			else
			{
				pCur = pCur->pNext;
			}
			pNext = pCur->pNext;
		}
		pCur = *pList;
		pNext = pCur->pNext; 
	}
	display_list(*pList);
}

void sort_albumTitle(Node **pList)
{
	Node *pCur = NULL, *pNext = NULL;
	int size_List = 0;

	size_List = get_size_List(*pList, pCur, size_List);

	pCur = *pList;
	pNext = pCur->pNext;

	for (int i = 0; i<size_List; ++i)
	{
		while (pNext != NULL)
		{
			if (strcmp(pCur->data.album_title, pNext->data.album_title) > 0)
			{
				if (pCur->pPrev == NULL)// fist node
				{
					pCur->pNext = pNext->pNext;
					pNext->pNext = pCur;

					pCur->pNext->pPrev = pCur;
					pCur->pPrev = pNext;
					pNext->pPrev = pCur->pPrev;
					pNext->pPrev = NULL;

					*pList = pNext;
				}
				else if (pNext->pNext == NULL)//Last Node
				{
					//		puts("3");
					pNext->pNext = pCur;
					pCur->pPrev->pNext = pNext;
					pCur->pNext = NULL;

					pNext->pPrev = pCur->pPrev;
					pCur->pPrev = pNext;

				}
				else
				{
					//		puts("2");
					pCur->pNext = pNext->pNext;
					pNext->pNext = pCur;
					pCur->pPrev->pNext = pNext;

					pCur->pNext->pPrev = pCur;
					pNext->pPrev = pCur->pPrev;
					pCur->pPrev = pNext;
				}
			}
			else
			{
				//	puts("no change order");
				pCur = pCur->pNext;
			}
			pNext = pCur->pNext;
		}
		pCur = *pList;
		pNext = pCur->pNext;
	}
	display_list(*pList);


}

void sort_rating(Node **pList)
{
	Node *pCur = NULL, *pNext = NULL;
	int size_List = 0;

	size_List = get_size_List(*pList, pCur, size_List);

	pCur = *pList;
	pNext = pCur->pNext;

	for (int i = 0; i<size_List; ++i)
	{
		while (pNext != NULL)
		{
			if (pCur->data.rating > pNext->data.rating)
			{
				if (pCur->pPrev == NULL)// fist node
				{
					pCur->pNext = pNext->pNext;
					pNext->pNext = pCur;

					pCur->pNext->pPrev = pCur;
					pCur->pPrev = pNext;
					pNext->pPrev = pCur->pPrev;
					pNext->pPrev = NULL;

					*pList = pNext;
				}
				else if (pNext->pNext == NULL)//Last Node
				{
					pNext->pNext = pCur;
					pCur->pPrev->pNext = pNext;
					pCur->pNext = NULL;

					pNext->pPrev = pCur->pPrev;
					pCur->pPrev = pNext;

				}
				else
				{
					pCur->pNext = pNext->pNext;
					pNext->pNext = pCur;
					pCur->pPrev->pNext = pNext;

					pCur->pNext->pPrev = pCur;
					pNext->pPrev = pCur->pPrev;
					pCur->pPrev = pNext;
				}
			}
			else
			{
				pCur = pCur->pNext;
			}
			pNext = pCur->pNext;
		}
		pCur = *pList;
		pNext = pCur->pNext;
	}
	display_list(*pList);
}

void sort_timesPlayed(Node **pList)
{
	Node *pCur = NULL, *pNext = NULL;
	int size_List = 0;

	size_List = get_size_List(*pList, pCur, size_List);

	pCur = *pList;
	pNext = pCur->pNext;


	for (int i = 0; i<size_List; ++i)
	{
		while (pNext != NULL)
		{
			if (pCur->data.number_times_played< pNext->data.number_times_played)
			{
				if (pCur->pPrev == NULL)// fist node
				{
					pCur->pNext = pNext->pNext;
					pNext->pNext = pCur;

					pCur->pNext->pPrev = pCur;
					pCur->pPrev = pNext;
					pNext->pPrev = pCur->pPrev;
					pNext->pPrev = NULL;

					*pList = pNext;
				}
				else if (pNext->pNext == NULL)//Last Node
				{
					pNext->pNext = pCur;
					pCur->pPrev->pNext = pNext;
					pCur->pNext = NULL;

					pNext->pPrev = pCur->pPrev;
					pCur->pPrev = pNext;

				}
				else
				{
					pCur->pNext = pNext->pNext;
					pNext->pNext = pCur;
					pCur->pPrev->pNext = pNext;

					pCur->pNext->pPrev = pCur;
					pNext->pPrev = pCur->pPrev;
					pCur->pPrev = pNext;
				}
			}
			else
			{
				pCur = pCur->pNext;
			}
			pNext = pCur->pNext;
		}
		pCur = *pList;
		pNext = pCur->pNext;
	}
	display_list(*pList);
}
void shuffle(Node **pList)
{
	Node *pCur = NULL;
	int size_List = 0, random_order[100] = { 0 }, flag = 0, count = 0;

	size_List = get_size_List(*pList, pCur, size_List);
	//printf("size : %d\n", size_List);
	srand((unsigned int)time(NULL));

	for (int i = 0; i < size_List; ++i)
	{
		do
		{
			flag = 0;
			random_order[i] = rand() % size_List + 1;

			for (int j = 0; j < i; ++j) // check if there are correspond order
			{
				if (random_order[j] == random_order[i])//find correspond number
				{
					flag = 1;
					break;
				}
			}
			
		} while (flag == 1);
	}

	for (int i = 0; i < size_List; ++i)
	{
		pCur = *pList;

		while (count < random_order[i]-1)// search order
		{
			pCur = pCur->pNext;
			++count;
		}

		//play music
		system("cls");
		puts(">>Playing Music ..\n");
		printf("%d) order from list : %d\n", i+1, random_order[i]);

		display_record(pCur);
		Sleep(2500);

		count = 0;
	}
	
}