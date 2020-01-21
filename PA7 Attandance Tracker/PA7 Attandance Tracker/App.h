#include "List.h"

class App
{
private:
	List mList;
	ifstream input;
	ofstream output;
	fstream masterFile;


public:
	friend ifstream &operator >> (ifstream &input, List &rhs);
	friend fstream &operator >> (fstream &input, List *rhs);

	App();
	~App();

	void runApp(void);
	void printList(List *pList);
	void printMenu();

	void markAbsences(List *pList);//menu4
	void editAbsences();
	void generateReports();//menu6
	void printReport1(List *pList);//menu6
	void printReport2(List *pList, int absences);//menu6
};
ifstream &operator >> (ifstream &input, List &rhs);// read from .csv

fstream &operator >> (fstream &masterFile, List *rhs);//read from maste file
fstream &operator << (fstream &lhs, List &rhs);//write master file

ofstream &operator << (ofstream &output, Node &rhs);//write report file

ostream &operator<< (ostream &lhs, Record &newStudent);//write for display

ostream &operator<< (ostream &lhs, Node *newStudent);//write for display
