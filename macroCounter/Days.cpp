#include "Days.h"
#include <iostream>


Days::Days()
{
}

//set date function
void Days::SetDate()
{
	string userInput; //continue messing with regex later, for now follow format
	cout << "What day did you eat these meals on? (Enter in mm/dd/yyyy format): ";
	cin >> userInput;
	dDate = userInput; //set date to user input
}
//set total proteins in grams for the day
void Days::SetPFCTotals(vector<Meal> mLog)
{
	for (int i = 0; i < mLog.size(); i++) //grab the PFC from each meal entry
	{
		proteinTotal = mLog[i].GetProteins();
		carbTotal = mLog[i].GetCarbs();
		fatTotal = mLog[i].GetFats();
	}
}
//set cals for each nutrient and total
void Days::SetCals()
{
	proteinCals = proteinTotal * 4; //cals per protein is 4
	carbCals = carbTotal * 4; //cals per carb is 4
	fatCals = fatTotal * 9; //cals per fat is 9
	totalCals = proteinCals + carbCals + fatCals; //add all cals up to get total macro cals
}

string Days::GetDate()
{
	return dDate;
}

int Days::GetProteinTotal()
{
	return proteinTotal;
}

int Days::GetCarbTotal()
{
	return carbTotal;
}

int Days::GetFatTotal()
{
	return fatTotal;
}

int Days::GetProteinCals()
{
	return proteinCals;
}

int Days::GetCarbCals()
{
	return carbCals;
}

int Days::GetFatCals()
{
	return fatCals;
}

int Days::GetTotalCals()
{
	return totalCals;
}

Days::~Days()
{
}
