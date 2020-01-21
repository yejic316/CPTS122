#include "BST.h"

BST::BST()
{
	mpRoot = nullptr;
}
BST::~BST()
{
	destroyTree(mpRoot);
	cout << "Inside BST's destructor!" << endl;
}

Node *BST::getRoot() const
{
	return mpRoot;
}

void BST::setRoot(Node *const newRoot)
{
	mpRoot = newRoot;
}

void BST::insert(int newUnits, string newData)
{
	insert(this->mpRoot, newUnits, newData);
}

void BST::inOrderTraversal()
{
	inOrderTraversal(mpRoot);
}

TransactionNode & BST::findSmallest()
{
	TransactionNode *pCur = (TransactionNode *)mpRoot;

	while (pCur->getLeft() != nullptr)
	{
		pCur = (TransactionNode *)pCur->getLeft();
	}
	return *pCur;
}
TransactionNode & BST::findLargest()
{
	TransactionNode *pCur = (TransactionNode *)mpRoot;

	while (pCur->getRight() != nullptr)
	{
		pCur = (TransactionNode *)pCur->getRight();
	}
	return *pCur;
}

//private member function
void BST::destroyTree(Node *&pTree)
{
	//it should visit each node in postOrder to delete them

	if (pTree != nullptr)
	{
		destroyTree(pTree->getLeft());
		destroyTree(pTree->getRight());
		delete pTree;
	}
}


void BST::insert(Node *&pTree, int newUnits, string newData)
{
	if (pTree == nullptr)
	{
		pTree = new TransactionNode(newData, newUnits);
	}
	else if (newUnits < dynamic_cast<TransactionNode*>(pTree)->getUnits())
	{
		insert(pTree->getLeft(), newUnits, newData);
	}
	else if (newUnits >dynamic_cast<TransactionNode*>(pTree)->getUnits())
	{
		insert(pTree->getRight(), newUnits, newData);
	}
	else
	{
		cout << "duplicate" << endl;
	}
}
void BST::inOrderTraversal(Node *&pTree)
{
	if (pTree != nullptr)
	{
		inOrderTraversal(pTree->getLeft());
		pTree->Node::printData();
		pTree->printData();
		cout << endl;
		inOrderTraversal(pTree->getRight());
	}
}
