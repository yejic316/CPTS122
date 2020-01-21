#include "BST.h"
/*
ifstream &operator>> (ifstream &lhs, BSTNode &rhs)
{
	string line = "";
	string code = "";
	char c = '\0';
	
	lhs >> c >> code;

	rhs.setChar(c);
	rhs.setString(code);
	return lhs;
}*/
BSTNode * BST::getRoot() const
{
	return mpRoot;
}
void BST::setRoot(BSTNode * const newRoot)
{
	mpRoot = newRoot;
}

BST::BST()
{
	BSTNode pMem = NULL;
	string result = "";
	mpRoot = nullptr;


}
BST::~BST()
{
	if (getRoot() != nullptr)
	{
		delete this->mpRoot;
	}
	cout << "Inside BST's destructor!" << endl;
}

void BST::insert(int newScore)
{
	insert(this->mpRoot, newScore);
}
void BST::insert(BSTNode *& pTree, int newScore)
{
	if (pTree == nullptr)
	{
		pTree = new BSTNode(newScore);
	}
	else if (newScore < pTree->getScore())
	{
		insert(pTree->getLeft(),newScore);
	}
	else if (newScore > pTree->getScore())
	{
		insert(pTree->getRight(), newScore);
	}
	else
	{
		cout << "duplicate" << endl;
	}	
}

void BST::printInOrder() 
{
	printInOrder(this->mpRoot) ;
	cout << endl << endl;
}
void BST::printInOrder(BSTNode *&pTree) const
{
	if (pTree != nullptr)
	{
		printInOrder(pTree->getLeft());
		cout << pTree->getScore() <<" ";
		printInOrder(pTree->getRight());
	}
}

int BST::highestScore()
{	
	BSTNode *pCur = mpRoot;
	while (pCur != nullptr)
	{
		pCur = pCur->getRight();
	}
	return pCur->getScore();
}
