#include <iostream>
#include <string>
#include <fstream>
using std::string;
using std::cout;
using std::cin;
using std::endl;

class BSTNode {

private:
	char mChar;
	string mCode;
	BSTNode *mpLeft;
	BSTNode *mpRight;
public:
	BSTNode(char newChar='\0', string newCode="");
	~BSTNode();

	char getChar() const;
	string getString() const;
	BSTNode *& getLeft();
	BSTNode *& getRight();

	void setChar(const char newChar);
	void setString(const string newString);
	void setLeft(BSTNode * const newLeft);
	void setRight(BSTNode * const newRight);
};