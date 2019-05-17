#include "Meal.h"
#include <iostream>

using namespace std;

Meal::Meal()
{
}

void Meal::SetMeal()
{
	string userInput;
	int mNum;
	bool mealNumValid = false;
	while (mealNumValid == false) //get meal num
	{
		try
		{
			cout << "\nWhich meal number is this for the day?: ";
			cin >> userInput;
			mNum = stoi(userInput);
			mealNumValid = true;
		}
		catch (exception & e)
		{
			cout << "\nException occured: " << e.what() << "\n\n";
		}
	}
	mealNum = mNum;
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
