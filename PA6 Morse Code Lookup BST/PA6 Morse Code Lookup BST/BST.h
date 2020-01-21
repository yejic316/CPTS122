#include <iostream>
#include <string>
#include <fstream>
#include "BSTNode.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ostream;

class BST {

private:
	BSTNode *mpRoot;
	ifstream input;
	ifstream input_convert;

	void insert(BSTNode*& pTree, char c, string code);
	void printInOrder(BSTNode *&pTree) const;
	void search(BSTNode *& pTree, char c, string &code) const;

public:

	friend ifstream &operator >> (ifstream &lhs, BSTNode &rhs);
	
	BST();
	~BST();	

	BSTNode *getRoot() const;
	void setRoot(BSTNode *const newRoot);

	void insert(char c, string code);
	void printInOrder();
	string search(char c);
};




//non member function
//ostream &operator<<(ostream &lhs, BSTNode &rhs);
//fstream &operator<<(fstream &lhs, BSTNode &rhs);
ifstream &operator >> (ifstream &lhs, BSTNode &rhs);
