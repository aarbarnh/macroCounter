#include "Meal.h"
#include <iostream>

using namespace std;

Meal::Meal()
{
}

void Meal::SetMeal()
{
	int userInput; //continue messing with regex later, for now follow format
	cout << "What meal of the day is this for you? (Enter a number): ";
	cin >> userInput;
	mealNum = userInput; //set date to user input
}

void Meal::SetMealNumFile(int num)
{
	mealNum = num;
}

int Meal::GetMealNum()
{
	return mealNum;
}

Meal::~Meal()
{
}
