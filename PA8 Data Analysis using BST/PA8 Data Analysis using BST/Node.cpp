#include "Node.h"

Node::Node(string newData)
{
	mData = newData;
	mpLeft = nullptr;
	mpRight = nullptr;
}
Node:: ~Node()
{
	cout << "Inside Node's destructor!" << endl;
}

string Node::getData() const
{
	return mData;
}

Node *& Node::getLeft()
{
	return mpLeft;
}
Node *& Node::getRight()
{
	return mpRight;
}

void Node::setString(const string newData)
{
	mData = newData;
}
void Node::setLeft(Node * const newLeft)
{
	mpLeft = newLeft;
}
void Node::setRight(Node * const newRight)
{
	mpRight = newRight;
}

void Node::printData()
{
	cout << "Data : " << getData() << endl;
}