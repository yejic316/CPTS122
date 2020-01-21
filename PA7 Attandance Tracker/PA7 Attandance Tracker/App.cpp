#include "App.h"
App::App()
{

	runApp();
}
App::~App()
{
	cout << "Inside ListApp's destructor! Closing open files!" << endl;
	if (input.is_open())
	{
		input.close();
	}
}


void App::runApp(void)
{
	Node node;

	int menu = 0;
	do
	{
		printMenu();
		cout << "Select Menu : ";
		cin >> menu;
		system("cls");
		switch (menu)
		{
		case 1:
			input.open("classList.csv");
			if (input.is_open())
			{
				cout << "\"class List\" file open successfully!" << endl;
				input >> mList;
				//printList(&mList);
			}
			else
			{
				cout << "\"class List\" file was not opened.." << endl;
			}
			input.close();
			break;
		case 2:  // Load master list
			masterFile.open("master.txt", 'r');
			if (masterFile.is_open())
			{
				cout << "\"master.txt\" file open successfully!" << endl;
				
				masterFile >> &mList;
				
			}
			else
			{
				cout << "\"master.txt\" file was not opened..." << endl;
			}
			masterFile.close();
			break;
		case 3:
			masterFile.open("master.txt", 'w');
			if (masterFile.is_open())
			{
				cout << "\"master.txt\" file open successfully!" << endl;
				masterFile << mList;
			}
			else
			{
				cout << "\"master.txt\" file was not opened..." << endl;
			}
			masterFile.close();
			break;
		case 4:
			markAbsences(&mList);
			break;
		case 5:
			editAbsences();

			break;
		case 6:
			generateReports();

			break;
		case 7:
			break;
		default:
			break;
		}
	}while (menu != 7);

}


void App::printList(List *pList)
{
	Node *pCur = nullptr;
	pCur = pList->getpHead();

	while (pCur != nullptr)
	{
		cout << pCur->getStudent().record_number << ") " << pCur->getStudent().name << " -> ";
		pCur = pCur->getpNext();
	}
	cout << endl;

}
void App::printMenu()
{
	int menu = 0;
	cout <<endl<< "********< MENU >********" << endl;
	cout << "1. Import course list" << endl;
	cout << "2. Load master list" << endl;
	cout << "3. Store master list" << endl;
	cout << "4. Mark absences" << endl;
	cout << "5. Edit absences" << endl;
	cout << "6. Generate report" << endl;
	cout << "7. Exit" << endl<<endl;
}

void App::markAbsences(List *pList)
{
	int i = 0;
	char YorN = '\0';
	string year = "", month = "", date = "", today="";
	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);

	Node *pCur = nullptr;
	pCur = pList->getpHead();

	
	year = to_string(now->tm_year + 1900);
	month = to_string(now->tm_mon + 1);
	date = to_string(now->tm_mday);
	today = year + '-'+month + '-'+ date;


	cout << "- Mark Absences for today (" ;
	cout << (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-' << now->tm_mday << ")" << endl << endl;
	cout << "[student List]" << endl;

	while (pCur != nullptr)
	{
		do
		{
			cout << "Name: " << pCur->getStudent().name << endl;
			cout << " - Absent?(Y/N)  :";
			cin >> YorN;
			cout << endl;

		} while ((YorN != 'Y') && (YorN != 'y') && (YorN != 'N') && (YorN != 'n'));

		if ((YorN == 'Y') || (YorN == 'y'))
		{
			pCur->setNumAbsences(pCur->getNumAbsences() + 1);
			pCur->getpDateAbsences().push(today);
		}
		else if ((YorN == 'N') || (YorN == 'n'))
		{
		}

		pCur = pCur->getpNext();
	}
}
void App::editAbsences()
{

}

void App::generateReports()
{
	int menu1 = 0, absences=0;
	do
	{
		cout << "***********************************" << endl;
		cout << "1. Generate report for all students" << endl;
		cout << "2. Generate report for students whose absences exceed" << endl;
		cout << "- Select Menu : ";
		cin >> menu1;
		system("cls");

	} while ((menu1 != 1) && (menu1 != 2));

	if (menu1 == 1)
	{
		printReport1(&mList);
	}
	else if (menu1 == 2)
	{
		cout << "* Find student with absences match or exceed *" << endl;

		cout << "Enter the number of absence :";
		cin >> absences;
		printReport2(&mList, absences);
	}

}
void App::printReport1(List *pList)
{
	int i = 0;
	Node *pCur = pList->getpHead();
	
	output.open("Report1.txt", std::ios::trunc);
	if (output.is_open())
	{
		cout << "output file \"Report1.txt\" open successfully!" << endl;
		output << "[ Report for All students ]" << endl << endl;

		while (pCur != nullptr)
		{

			cout << ++i << ')' << endl << pCur->getStudent();
			cout << "The number of Absence : " << pCur->getNumAbsences() << endl;
			if (pCur->getNumAbsences() == 0)
			{
				cout << "there is no abscence record" << endl << endl;
			}
			else
			{
				cout << "The most recent date of Abcence: " << pCur->getpDateAbsences().getDateAbs()[pCur->getpDateAbsences().getIndex()] << endl << endl;
			}
			output << pCur << endl;// write output file
			pCur = pCur->getpNext();
		}
	}
	else
	{
		cout << "output file \"Report1.txt\" was not opened...." << endl;
	}
	
	output.close();

}
void App::printReport2(List *pList, int absences)
{
	int i = 1;
	Node *pCur = pList->getpHead();
	output.open("Report2.txt", std::ios::trunc);
	if (output.is_open())
	{
		cout << "output file \"Report2.txt\" open successfully!" << endl;
		output << "[ Report for the students who absent over " << absences << " times ]" << endl << endl;
		while (pCur != nullptr)
		{
			if (pCur->getNumAbsences() >= absences)
			{
				cout << pCur << endl;
				output << pCur;// write output file

				output << "record of absent dates" << endl;
				for (i = 1; i <= pCur->getNumAbsences();++i)
				{
					output << "/" << pCur->getpDateAbsences().getDateAbs()[i];   // print all record of absent date in stack
				}
				output << endl << endl;

			}
			else;//pass
			pCur = pCur->getpNext();
		}
	}
	else
	{
		cout << "output file \"Report2.txt\" was not opened...." << endl;
	}
	output.close();
}


/* operator   ******************************************************************************************/
ifstream &operator >> (ifstream &input, List &rhs)// read from .csv
{
	char line[100] = "";
	input.getline(line, 100);
	Record newStudent;

	while (!input.eof())
	{
		input.getline(line, 100, ',');
		newStudent.record_number = atoi(line);

		input.getline(line, 100, ',');
		newStudent.ID_number = atoi(line);

		input.getline(line, 100, '"');
		input.getline(line, 100, '"');
		newStudent.name = line;

		input.getline(line, 100, ',');	
		input.getline(line, 100, ',');
		newStudent.email = line;

		input.getline(line, 100, ',');
		newStudent.unit = line;
		//cout << newStudent.unit << endl;

		input.getline(line, 100, ',');
		newStudent.major = line;


		input.getline(line, 100, '\n');
		newStudent.level = line;

		cout << newStudent << endl;
		
		rhs.insertAtFront(newStudent);

	}
	return input;

}

fstream &operator >> (fstream &masterFile, List *rhs)//read from maste file
{
	char line[100] = "";
	string line_S = "";
	Record newStudent;
	Node* pCur = rhs->getpHead();

	while (!masterFile.eof())
	{
		masterFile >> newStudent.record_number;
		masterFile >> newStudent.ID_number;
		masterFile >> newStudent.name;
		masterFile >> newStudent.email;
		masterFile >> newStudent.unit;
		masterFile >> newStudent.major;
		masterFile >> newStudent.level;

		//cout << newStudent << endl;
		pCur->setStudent(newStudent);
		//rhs.insertAtFront(newStudent);


		masterFile >> line;
		pCur->setNumAbsences(atoi(line));
		//cout << line << endl;

		masterFile >> line;
		//cout << line << endl;
		line_S = line;
		pCur->getpDateAbsences().push(line_S);

		pCur = pCur->getpNext();
	}

	return masterFile;
}


fstream &operator << (fstream &lhs, List &rhs)//write master file
{

	Node *pCur = rhs.getpHead();
	while (pCur != nullptr)
	{
		lhs << pCur->getStudent().record_number << endl;
		lhs << pCur->getStudent().ID_number << endl;
		lhs << pCur->getStudent().name << endl;
		lhs << pCur->getStudent().email << endl;
		lhs << pCur->getStudent().unit << endl;
		lhs << pCur->getStudent().major << endl;
		lhs << pCur->getStudent().level << endl;
		lhs << pCur->getNumAbsences() << endl;
		lhs <<'/' <<pCur->getpDateAbsences().getDateAbs()[pCur->getpDateAbsences().getIndex()] << endl << endl;

		pCur = pCur->getpNext();
	}	

	return lhs;
}


ofstream &operator << (ofstream &output, Node &rhs)//write report file
{
	output << rhs;
	return output;

}

ostream &operator<< (ostream &lhs, Record &newStudent)//write for display
{
	lhs << " -record number: "<<newStudent.record_number << endl;
	lhs << " -ID : " << newStudent.ID_number << endl;
	lhs << " -Name : " << newStudent.name << endl;
	lhs << " -Email : " << newStudent.email << endl;
	lhs << " -Unit : " << newStudent.unit << endl;
	lhs << " -Major : " << newStudent.major << endl;
	lhs << " -Level : " << newStudent.level << endl;

	return lhs;
}
ostream &operator<< (ostream &lhs, Node *newStudent)//write for display
{

	lhs << newStudent->getStudent();
	lhs << "The number of Absence : " << newStudent->getNumAbsences() << endl;
	lhs << "The recent date of Absence : " << newStudent->getpDateAbsences().getDateAbs()[newStudent->getpDateAbsences().getIndex()] << endl;
	return lhs;

}
