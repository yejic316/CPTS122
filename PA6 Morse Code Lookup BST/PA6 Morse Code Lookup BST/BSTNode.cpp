#include "BSTNode.h"

BSTNode::BSTNode(char newChar, string newCode)
{
	mChar = newChar;
	mCode = newCode;
	mpLeft = nullptr;
	mpRight = nullptr;
}
BSTNode:: ~BSTNode()
{
	if (getLeft() != nullptr)
	{
		delete this->mpLeft;
	}
	if (getRight() != nullptr)
	{
		delete this->mpRight;
	}
	cout << "Inside BSTNode's destructor!" << endl;

}
char BSTNode::getChar() const
{
	return mChar;
}
string BSTNode::getString() const
{
	return mCode;
}

BSTNode *& BSTNode::getLeft()
{
	return mpLeft;
}
BSTNode *& BSTNode::getRight()
{
	return mpRight;
}
void BSTNode::setChar(const char newChar)
{
	mChar = newChar;
}
void BSTNode::setString(const string newString)
{
	mCode = newString;
}
void BSTNode::setLeft(BSTNode * const newLeft)
{
	mpLeft = newLeft;
}
void BSTNode::setRight(BSTNode * const newRight)
{
	mpRight = newRight;
}
