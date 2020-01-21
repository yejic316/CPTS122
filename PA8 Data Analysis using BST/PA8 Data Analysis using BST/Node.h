#include <iostream>
#include <string>
#include <fstream>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
class Node {

protected:
	string mData; 
	Node *mpLeft;
	Node *mpRight;
public:
	Node(string newData = "");
	virtual ~Node();

	string getData() const;
	Node *& getLeft();
	Node *& getRight();

	void setString(const string newData);
	void setLeft(Node * const newLeft);
	void setRight(Node * const newRight);

	virtual void printData();//+ pure virtual printData () function, which must be overridden in class TransactionNode

};