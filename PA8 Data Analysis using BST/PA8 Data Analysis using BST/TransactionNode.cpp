#include "TransactionNode.h"

TransactionNode::TransactionNode(string newData, int newUnits) : Node(newData)
{
	mData = newData;
	mUnits = newUnits;
}
TransactionNode::~TransactionNode()
{
	cout << "Inside TransactionNode's destructor!" << endl;
}

int TransactionNode::getUnits() const
{
	return mUnits;
}

void TransactionNode::setUnits(int newUnits)
{
	mUnits = newUnits;
}
void TransactionNode::printData()
{
	cout << "Units : " << getUnits() << endl;
}