#include<stdio.h>
#include<string.h>
#include < windows.h >
typedef struct duration {

	int minute;
	int second;

}Duration;

typedef struct record {

	char artist[50];
	char album_title[50];
	char song_title[50];
	char genre[20];
	Duration song_length;
	int number_times_played;
	int rating;
}Record;

typedef struct node {
	Record data;
	struct node *pNext;
	struct node *pPrev;
}Node;

Node *makeNode(Node *pMem);
int load(FILE*infile, Node **pList);
void store(FILE *outfile, Node **pList);
void display_list(Node *pList);
void insertFront(Node**pList);
int delete(Node**pList, char*pSong);
int edit(Node **pList, char*pArtist);
int searching_artist(Node **pList, char*pArtist, Node artist_multiAlbum[]);
Node *searching_song(Node **pList, char *temp_song);
void display_record(Node *pCur);
void rate(Node**pList);
void select_play(Node **pList);
void order_play(Node **pList);

