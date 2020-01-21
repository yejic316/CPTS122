#include "Node.h"

Node::Node()
{
	mStudent.record_number = 0;
	mStudent.ID_number = 0;
	mStudent.name = "";
	mStudent.email = "";
	mStudent.unit = "";
	mStudent.major = "";
	mStudent.level = "freshman";
	mNumAbsences = 0;
	//mpDateAbsences = nullptr;
	mpNext = nullptr;
}
Node::Node(Record newStudent)
{
	mStudent = newStudent;
	mNumAbsences = 0;
	//mpDateAbsences = nullptr;
	mpNext = nullptr;
}

Node::~Node()
{
	cout << "deconstructor ~Node()" << endl;
}
Record Node::getStudent() const
{
	return mStudent;
}
int Node::getNumAbsences() const
{
	return mNumAbsences;
}

Stack & Node::getpDateAbsences()
{
	return mpDateAbsences;
}
Node *& Node::getpNext()
{
	return mpNext;
}



void Node::setStudent(Record newStudent)
{
	mStudent = newStudent;
}
void Node::setNumAbsences(int newNumAbsences)
{
	mNumAbsences = newNumAbsences;
}

void Node::setDateAbsences(Stack newpDateAbstance)
{
	mpDateAbsences = newpDateAbstance;
}
void Node::setpNext(Node *newpNext)
{
	mpNext = newpNext;
}

