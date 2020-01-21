#include "Node.h"

class TransactionNode : public Node
{

private:
	int mUnits;

public:
	TransactionNode(string newData="", int newUnits=0);
	~TransactionNode();

	int getUnits() const;

	void setUnits(int newUnits);

	void printData();


};