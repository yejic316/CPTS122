#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ostream;
using std::string;

class Stack
{
public:
	Stack(int newSize = 0);
	~Stack();

	string *&getDateAbs();
	int getMaxSize();
	int getIndex();

	//void setDateAbs(string *newDateAbs);
	void setMaxSize(int newMaxSize);
	void setIndex(int newIndex);

	void push(string &newDateAbs);
	void pop(string &popedDateAbs);
	bool peek(string &dateAbs);
	bool isEmpty();

private:
	string *mDateAbs;
	int mMaxSize;
	int mIndex;

};