///////////////////////////////////////////////////////////////////////////////
/// \file         
/// \author       AO
/// \date         
/// \brief   You are to write a basic fitness application, in C++, 
///          that allows the user of the application to manually edit 
///          “diet” and “exercise” plans.For this application you will 
///          need to create three classes : DietPlan, ExercisePlan, and FitnessAppWrapper.     
///           
///       
/// REVISION HISTORY:
/// \date  
///            
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cstdlib> // to use system("cls");

#include "DietPlan.h"
#include "ExcercisePlan.h"

class FitnessAppWrapper
{
public:
	FitnessAppWrapper(); // default constructor
	~FitnessAppWrapper(); // destructor

	void runApp(); // will drive the application
	void perform_user_selection(const int &option);

	void loadWeeklyDietPlan(); // this will call the private loadWeeklyPlan() function
	void loadWeeklyExcercisePlan();

	void displayWeeklyDietPlan(); // this will call the private displayWeeklyPlan() function
	void displayWeeklyExcercisePlan();

	void storeWeeklyDietPlan(); // this will call the private storeWeeklyPlan() function
	void storeWeeklyExcercisePlan();

	bool editDietPlan(); // will prompt the user for the name of the plan to edit
	bool editExcercisePlan(); 

private:
	DietPlan mDPList[7]; // will store the weekly list of DietPlan objects - 1 week = 7 days
	ExcercisePlan mEPList[7];

	fstream mFstrDP;    // stream object for input/output to dietPlans.txt
	fstream mFstrEP;

	// private helper/utility functions
	void loadDailyPlan(fstream &fileStream, DietPlan &plan);
	void loadDailyPlan(fstream &fileStream, ExcercisePlan &plan);

	void loadWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[]);
	void loadWeeklyPlan(fstream &fileStream, ExcercisePlan weeklyPlan[]);

	void displayDailyPlan(const DietPlan &plan);
	void displayDailyPlan(const ExcercisePlan &plan);

	void displayWeeklyPlan(const DietPlan weeklyPlan[]);
	void displayWeeklyPlan(const ExcercisePlan weeklyPlan[]);

	void storeDailyPlan(fstream &fileStream, const DietPlan &plan);
	void storeDailyPlan(fstream &fileStream, const ExcercisePlan &plan);

	void storeWeeklyPlan(fstream &fileStream, const DietPlan weeklyPlan[]);
	void storeWeeklyPlan(fstream &fileStream, const ExcercisePlan weeklyPlan[]);

	void displayMenu();
};