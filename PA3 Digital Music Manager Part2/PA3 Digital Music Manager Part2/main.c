/******************************************************************************
* Programmer: Yeji Chung													  *
* Class: CptS 121; Lab Section 06                                             *
* Programming Assignment: PA3 Digital Music Manager_part2                     *
* Date:  2/9/2017                                                             *
*                                                                             *
* Description: modify insert, delete, sort, shuffle		                      *
******************************************************************************/

#include "function.h"
int main(void)
{
	FILE *infile = NULL, *outfile=NULL;
	int select = 0, select3 = 0, found = 0, flag_edit = 0, index = 0, flag_load = 0, play_option = 0, flag_sort = 0;
	Node *pList = NULL, artist_multiAlbum[10] = {NULL};
	Record *pNewRecord = NULL;
	char temp_song[50] = "", temp_artist[50]="";


	do
	{
		printf("******* < MENU > ******\n");
		printf("(1)  load\n(2)  store\n(3)  display\n(4)  insert\n(5)  delete\n(6)  edit\n(7)  sort\n(8)  rate\n(9)  play\n(10) shuffle\n(11) exit\n");
		printf("***********************\n");
		do
		{
			printf("Select Menu : ");
			scanf(" %d", &select);
			while (getchar() != '\n');

		} while ((select > 11) || (select < 1));

		system("cls");
		switch(select)
		{
		case 1://(1)  load
			puts("< Load >");
			if (pList == NULL)
			{
				infile = fopen("musicPlayList.csv", "r");
				flag_load = load(infile, &pList);
				if (flag_load == 1)
				{
					puts("\"load successfully!\"");
					fclose(infile);
				}
				else
				{
					puts("\"Fail loading... \"");
				}
			}
			else
			{
				puts("\"It has already been loaded\"");
			}
			system("pause");
			system("cls");
			break;

		case 2:	//(2)  store
			puts("< Store >");
			
			outfile = fopen("musicPlayList.csv", "w");
			store(outfile, &pList);
			fclose(outfile);
			puts("\"store successfully!\"");

			system("pause");
			system("cls");
			break;

		case 3:	//(3)  display
			puts("< Display >");

			do {
				printf("\n\t1) Print all record\n\t2) Print all records that match an artist\n\n");
				printf("select menu : ");
				scanf("%d", &select3);
				while (getchar() != '\n'); // buffer'\n'

				if (select3 == 1)
				{
					display_list(pList);
					system("pause");
				}
				else if (select3 == 2)
				{
					do
					{
						system("cls");

						puts("<Disply Searched Record> ");

						printf("\tEnter artist : ");
						gets(temp_artist);
						index = searching_artist(&pList, temp_artist, artist_multiAlbum);
						if (index == 0)// can not find any artist
						{
							puts("\t\"Can not find any artist\"");
						}
						
						for (int i = 1; i < index; ++i)
						{
							printf("\n\n[%d] ", i);
							display_record(&artist_multiAlbum[i]);
						}
						system("pause");

					} while (index == 0);

				}
			} while ((select3 != 1) && (select3 != 2));
			system("cls");
			break;
		case 4:	//(4)  insert
			puts("< Insert >");
			insertFront(&pList);
			system("cls");
			break;
		case 5:	//(5)  delete
			puts("< Delete >");
			//while ((found == 0)&&(pList!=NULL))
			//{
			if(pList!=NULL)
			{
				printf("- Enter the name of song which you want delete : ");
				gets(temp_song);
				found = delete(&pList, temp_song);
				if (found == 0)
				{
					puts("\t\"Can not find any song\"");
				}
			}
			found = 0;
			if (pList == NULL)
			{
				puts("\"There is no List\"");
			}
			system("pause");
			system("cls");
			break;
		case 6:	//(6)  edit
			puts("< Edit >");
			do
			{
				printf("- Enter artist whose record you want to edit : ");
				gets(temp_artist);
				flag_edit = edit(&pList, temp_artist);

			} while (flag_edit == 0);
			system("cls");
			break;
		case 7:	//(7)  sort
			puts("< Sort >");
			do {
				printf("\n\t1) Sort based on artist(A-Z)\n\t2) sort based o album title(A-Z)\n\t3) Sort based on rating(1-5)\n\t4) Sort based on times played(largest-smallest)\n\n");
				printf("select sorting option : ");
				scanf("%d", &flag_sort);
				if (flag_sort == 1)//  Sort based on artist (A-Z)
				{
					sort_artist(&pList);
				}
				else if (flag_sort == 2)//Sort based on album title (A-Z)
				{
					sort_albumTitle(&pList);
				}
				else if (flag_sort == 3)//  Sort based on rating (1-5)
				{
					sort_rating(&pList);
				}
				else if (flag_sort == 4)// Sort based on times played (largest-smallest)
				{
					sort_timesPlayed(&pList);
				}
			} while ((flag_sort > 4) || (flag_sort < 1));

			system("pause");
			system("cls");
			break;
		case 8:	//(8)  rate
			puts("< Rate >");
			rate(&pList);
			system("cls");

			break;
		case 9:	//(9)  play
			puts("< Play >");
			do {
				printf("\n\t1) Play in Order\n\t2) Play from Song you select\n\n");
				printf("select menu : ");
				scanf("%d", &play_option);
				while (getchar() != '\n'); // buffer'\n'
				if (play_option == 1)
				{
					order_play(&pList);
				}
				if (play_option == 2)
				{
					select_play(&pList);
				}
			} while ((play_option != 1) && (play_option != 2));

			break;
		case 10:	//(10) shuffle
			puts("< Shuffle >");
			puts(">>Playing Music ..\n");
			system("pause");

			shuffle(&pList);
			system("pause");
			system("cls");
			break;
		case 11:	//(11) exit
			puts("< Exit >");
			outfile = fopen("musicPlayList.csv", "w");
			store(outfile, &pList);
			fclose(outfile);
			break;
		} 

	} while (select != 11);
	return 0;
}