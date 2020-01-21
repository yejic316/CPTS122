#include "BSTNode.h"

BSTNode::BSTNode(int newScore)
{
	mScore = newScore;
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
int BSTNode::getScore() const
{
	return mScore;
}

BSTNode *& BSTNode::getLeft()
{
	return mpLeft;
}
BSTNode *& BSTNode::getRight()
{
	return mpRight;
}

void BSTNode::setScore(const int newScore)
{
	mScore = newScore;
}
void BSTNode::setLeft(BSTNode * const newLeft)
{
	mpLeft = newLeft;
}
void BSTNode::setRight(BSTNode * const newRight)
{
	mpRight = newRight;
}
