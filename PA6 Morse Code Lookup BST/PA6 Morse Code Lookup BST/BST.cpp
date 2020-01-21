#include "BST.h"
ifstream &operator>> (ifstream &lhs, BSTNode &rhs)
{
	string line = "";
	string code = "";
	char c = '\0';
	
	lhs >> c >> code;

	rhs.setChar(c);
	rhs.setString(code);
	return lhs;
}
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

	input.open("MorseTable.txt");
	if (input.is_open())
	{
		cout << "Morse Table was opened successfully!" << endl << endl;
		while (!input.eof())
		{
			input >> pMem;
			insert(pMem.getChar(), pMem.getString());
		}
	}
	//print the current tree
	printInOrder();
	
	char tempC = '\0';

	//opening "Convert.txt"
	input_convert.open("Convert.txt");

	//performing conversion of English to MorseCode
	if (input_convert.is_open())
	{
		cout << "\"Convert.txt\" was opened successfully!" << endl << endl;
		while (!input_convert.eof())
		{
			input_convert >> tempC;

			//convert lowercase to uppercase
			if ((tempC >= 'a') && (tempC <= 'z'))
			{
				tempC = tempC - 'a' + 'A';
			}
			//Echoing MorseCode to screen, after searching
			cout << search(tempC) << " ";
			
		}
	}
	cout << endl << endl;
	system("pause");

	//closing "MorseTable.txt"
	input.close();
	
	//closing "Convert.txt"
	input_convert.close();

}
BST::~BST()
{
	if (getRoot() != nullptr)
	{
		delete this->mpRoot;
	}
	cout << "Inside BST's destructor!" << endl;
}

void BST::insert(char c, string code)
{
	insert(this->mpRoot, c, code);
}
void BST::insert(BSTNode *& pTree, char c, string code)
{
	if (pTree == nullptr)
	{
		pTree = new BSTNode(c,code);
	}
	else if (c < pTree->getChar())
	{
		insert(pTree->getLeft(), c, code);
	}
	else if (c > pTree->getChar())
	{
		insert(pTree->getRight(), c, code);
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
		cout << pTree->getChar() <<" ";
		printInOrder(pTree->getRight());
	}
}

string BST::search(char c)  
{
	string code = "";

	search(this -> mpRoot, c, code);
	return code;
}
 void BST::search(BSTNode *&pTree, char c, string &code) const
{
	if (pTree != nullptr)
	{
		if (pTree->getChar() > c)
		{
			search(pTree->getLeft(),c, code);
		}
		else if (pTree->getChar() < c)
		{
			search(pTree->getRight(),c, code);
		}
		else// found 
		{
			code = pTree->getString();
		}
	}
}