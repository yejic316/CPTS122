#include "BST.h"

class DataAnalysis
{
private:
	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCsvStream;

	void openCsvFile();//A function that opens data.csv // yes, it’s private, and must use mCsvStream to open the file

	void readOneLine(int &units, string &type, string &transaction);//A function that reads one line from the file and splits the line into units, type, and transaction fields
	void readAllLine();//A function that loops until all lines are read from the file; calls the function below, and then displays the current contents of both BSTs; use inOrderTraversal () to display the trees
	void insertToTree(int &units, string &type, string &transaction);//A function that compares the transaction field and inserts the units and type into the appropriate tree (mTreeSold or mTreePurchased) // note with the way the data.csv file is organized the trees will be fairly balanced
	void writeTree();//A function that writes to the screen the trends we see in our tree; the function must display the type and number of units that are least purchased and sold, and the most purchased and sold

public:

	void runAnalysis(); //aside from possibly a constructor and / or destructor; this function calls the other private functions
};