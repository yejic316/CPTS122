#include <iostream>
#include <string>
//#include <fstream>
using std::string;
using std::cout;
using std::cin;
using std::endl;

class BSTNode {

private:
	int mScore;
	BSTNode *mpLeft;
	BSTNode *mpRight;
public:
	BSTNode(int newScore=0);
	~BSTNode();

	int getScore() const;
	BSTNode *& getLeft();
	BSTNode *& getRight();

	void setScore(const int newScore);
	void setLeft(BSTNode * const newLeft);
	void setRight(BSTNode * const newRight);
};