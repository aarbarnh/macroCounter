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
//set date for file i/o
void Days::SetDateFile(string date)
{
	dDate = date;
}

//set total proteins in grams for the day
void Days::SetPFCTotals(vector<Meal> mLog)
{
	for (int i = 0; i < mLog.size(); i++) //grab the PFC from each meal entry
	{
		proteinTotal += mLog[i].GetProteins();
		carbTotal += mLog[i].GetCarbs();
		fatTotal += mLog[i].GetFats();
	}
}
//set protein total, file i/o
void Days::SetProteinTotal(float protein)
{
	proteinTotal = protein;
}
//set carb total, file i/o
void Days::SetCarbTotal(float carb)
{
	carbTotal = carb;
}
//set fat total, file i/o
void Days::SetFatTotal(float fat)
{
	fatTotal = fat;
}
//set cals for each nutrient and total
void Days::SetCals()
{
	proteinCals = proteinTotal * 4; //cals per protein is 4
	carbCals = carbTotal * 4; //cals per carb is 4
	fatCals = fatTotal * 9; //cals per fat is 9
	totalCals = proteinCals + carbCals + fatCals; //add all cals up to get total macro cals
}
//set cals total only, file i/o
void Days::SetCalsTotal(float cals)
{
	totalCals = cals;
}
//get day date
string Days::GetDate()
{
	return dDate;
}

float Days::GetProteinTotal()
{
	return proteinTotal;
}

float Days::GetCarbTotal()
{
	return carbTotal;
}

float Days::GetFatTotal()
{
	return fatTotal;
}

float Days::GetProteinCals()
{
	return proteinCals;
}

float Days::GetCarbCals()
{
	return carbCals;
}

float Days::GetFatCals()
{
	return fatCals;
}

float Days::GetTotalCals()
{
	return totalCals;
}

Days::~Days()
{
}
