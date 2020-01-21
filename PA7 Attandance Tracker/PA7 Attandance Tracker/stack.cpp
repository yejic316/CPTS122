#include "stack.h"
Stack::Stack(int newSize)
{
	mDateAbs = new string[100];
	mMaxSize = 100;
	mIndex = newSize;
}

Stack::~Stack()
{
	delete[] mDateAbs;
	//cout << "Inside Stack's destructor!" << endl;

}

string *& Stack::getDateAbs()
{
	return mDateAbs;
}

int Stack::getMaxSize()
{
	return mMaxSize;
}

int Stack::getIndex()
{
	return mIndex;
}

void Stack::setMaxSize(int newMaxSize)
{
	mMaxSize = newMaxSize;
}

void Stack::setIndex(int newIndex)
{
	mIndex = newIndex;
	//cout << "into setIndex(), "<<mIndex << endl;

}

void Stack::push(string &newDateAbs)
{
	setIndex(getIndex() + 1);

	this->mDateAbs[this->mIndex] = newDateAbs;

}

void Stack::pop(string &popedDateAbs)
{
	popedDateAbs = this->mDateAbs[this->mIndex];
//	popedDateAbs = this->getDateAbs()[];
	this->mDateAbs--;
}

bool Stack::peek(string &dateAbs)
{
	return (getIndex() == getMaxSize());
}

bool Stack::isEmpty()
{
	if (getIndex() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}