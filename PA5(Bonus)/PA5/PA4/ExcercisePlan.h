#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::fstream;
using std::ofstream;

class ExcercisePlan
{
public:
	ExcercisePlan(const string &newPlanName = "", const string &newDate = "", const int &newGoalStep = 0);
	ExcercisePlan(const ExcercisePlan &copy);
	~ExcercisePlan();

	ExcercisePlan &operator = (const ExcercisePlan &rhs);

	string getPlanName() const;
	string getDate() const;
	int getGoalSteps() const;

	void setPlanName(const string &newPlanName);
	void setDate(const string &newDate);
	void setGoalSteps(const int &newGoalSteps);

	void editGoal();


private:
	string mPlanName;
	string mDate;
	int mGoalSteps;
};


// nonmember functions
ostream & operator<< (ostream &lhs, const ExcercisePlan &rhs); 
fstream & operator<< (fstream &lhs, const ExcercisePlan &rhs);
fstream & operator >> (fstream &lhs, ExcercisePlan &rhs);