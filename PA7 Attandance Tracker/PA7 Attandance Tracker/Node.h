#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "stack.h"

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ostream;
using std::string;
using std::to_string;

typedef enum level{

	Freshman, Sophomore, Junior, Senior, Graduate
}Level;
typedef struct record
{
	int record_number;
	int ID_number;
	string name;
	string email;
	string unit;
	string major;
	string level;

}Record;

class Node
{
private:
	Record mStudent;
	int mNumAbsences;// number of absences
	Stack mpDateAbsences;// stack, for storing the dates of absences
	Node *mpNext;

public:
	Node();
	Node(Record newStudent);
	//Node(Node &copy);
	~Node();

	Record getStudent() const;
	int getNumAbsences() const;
	Stack &getpDateAbsences() ;
	Node *& getpNext();

	void setStudent(Record newStudent);
	void setNumAbsences(int newNumAbsences);
	void setDateAbsences(Stack newpDateAbstance);
	void setpNext(Node *newpNext);
};

