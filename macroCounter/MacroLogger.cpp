#include "MacroLogger.h"
#include <fstream>
#include <iostream>


MacroLogger::MacroLogger()
{
}

void MacroLogger::SetDayProGoal(float protein)
{
	goalDayProtein = protein;
}

void MacroLogger::SetMealsPer(int meals)
{
	goalMealsPer = meals;
}

void MacroLogger::SetDayCarbGoal(float carb)
{
	goalDayCarbs = carb;
}

void MacroLogger::SetDayFatGoal(float fat)
{
	goalDayFats = fat;
}

void MacroLogger::SetMealProGoal(float meals)
{
	goalMealProtein = goalDayProtein / meals;
}

void MacroLogger::SetMealCarbGoal(float meals)
{
	goalMealCarbs = goalDayCarbs / meals;
}

void MacroLogger::SetMealFatGoal(float meals)
{
	goalMealFats = goalDayFats / meals;
}

void MacroLogger::PushBackMeal(Meal meal)
{
	mealLog.push_back(meal);
}

void MacroLogger::PushBackDays(Days day)
{
	dayLog.push_back(day);
}

void MacroLogger::SaveMealsFile(string file)
{
	int nMeals = mealLog.size(); //get a number of meals in mealLog
	ofstream outFile(file); //append to file, not write over
	if (outFile.is_open())
	{
		outFile << nMeals << "\n"; //put number of meals at top, used for reading later
		for (int i = 0; i < mealLog.size(); i++)
		{
			outFile << mealLog[i].GetMealNum() << "\n"; //write in meal number
			outFile << mealLog[i].GetProteins() << "\n"; //write in proteins for meal
			outFile << mealLog[i].GetFats() << "\n"; //write in fats for meal
			outFile << mealLog[i].GetCarbs() << "\n"; //write in carbs for meal
			outFile << mealLog[i].GetMealCals() << "\n"; //write in total cals for meal
		}
	}
	outFile.close();
}

void MacroLogger::SaveGoals(string file)
{
	ofstream outFile(file);
	if (outFile.is_open())
	{ //write in the goals for the meals
		outFile << goalMealsPer << "\n";
		outFile << goalMealProtein << "\n";
		outFile << goalMealFats << "\n";
		outFile << goalMealCarbs << "\n";
		outFile << goalDayProtein << "\n";
		outFile << goalDayFats << "\n";
		outFile << goalDayCarbs << "\n";
	}
	outFile.close();
}

void MacroLogger::SaveDaysFile(string file)
{
	int nDays = dayLog.size(); //get a number for days in dayLog for reading 
	ofstream outFile(file); //append to file not write over
	if (outFile.is_open())
	{
		outFile << nDays << "\n"; //put number of days at top, will be tested in reading
		for (int i = 0; i < dayLog.size(); i++)
		{
			outFile << dayLog[i].GetDate() << "\n"; //write date in
			outFile << dayLog[i].GetProteinTotal() << "\n"; //write in protein total in grams
			outFile << dayLog[i].GetFatTotal() << "\n"; //write in fat total in grams
			outFile << dayLog[i].GetCarbTotal() << "\n"; //write in carb total in grams
			outFile << dayLog[i].GetTotalCals() << "\n"; //write in total cals
		}
	}
	outFile.close();
}

void MacroLogger::ReadGoals(string file)
{
	string inString;
	float inFloat; //testing purpose
	int inInt;
	int mealGoals; //test if goals are in file

	ifstream inFile(file);
	if (inFile.is_open())
	{
		inFile >> inString; //get test value
		mealGoals = stoi(inString); //convert

		if (mealGoals > 0)
		{
			goalMealsPer = mealGoals; //set meal goals with the value grabbed to test

			inFile >> inString; //get meal goal proteins
			inFloat = stof(inString); //convert
			goalMealProtein = inFloat; //set meal proteins

			inFile >> inString; //get meal goal fats
			inFloat = stof(inString); //convert
			goalMealFats = inFloat; //set

			inFile >> inString; //get meal goal carbs
			inFloat = stof(inString); //convert
			goalMealCarbs = inFloat; //set

			inFile >> inString; //get day goal proteins
			inFloat = stof(inString); //convert
			goalDayProtein = inFloat; //set meal proteins

			inFile >> inString; //get day goal fats
			inFloat = stof(inString); //convert
			goalDayFats = inFloat; //set

			inFile >> inString; //get day goal carbs
			inFloat = stof(inString); //convert
			goalDayCarbs = inFloat; //set
		}


	}
	inFile.close();
}

void MacroLogger::ReadMealsFile(string file)
{
	string inString;
	float inFloat;
	int inInt; //for meal num only
	int nMeals;

	ifstream inFile(file);
	if (inFile.is_open())
	{
		inFile >> inString; //get the number of meals first for for loop
		nMeals = stoi(inString); //change to int to test
		if (nMeals > 0)
		{
			for (int i = 0; i < nMeals; i++)
			{
				Meal tempMeal; //temp obj
				inFile >> inString; //get meal num
				inInt = stoi(inString); //change string to int
				tempMeal.SetMealNumFile(inInt); //set meal num to inInt

				inFile >> inString; //get protein grams
				inFloat = stof(inString); //change proteins
				tempMeal.SetProteins(inFloat); //set proteins

				inFile >> inString; //get fats grams
				inFloat = stof(inString); //change fats
				tempMeal.SetFats(inFloat); //set fats

				inFile >> inString; //get carbs grams
				inFloat = stof(inString); //change carbs
				tempMeal.SetCarbs(inFloat); //set carbs

				inFile >> inString; //get meal cals
				inFloat = stof(inString); //change cals
				tempMeal.SetMealCalsFile(inFloat); //set cals

				mealLog.push_back(tempMeal); //push meal to log
			}
		}
	}
	inFile.close(); //close file after done
	
}

void MacroLogger::ReadDaysFile(string file)
{
	string inString;
	float inFloat;
	int nDays;

	ifstream inFile(file);
	if (inFile.is_open())
	{
		inFile >> inString; //get num of days
		nDays = stoi(inString); //change to int to test
		if (nDays > 0)
		{
			while (!inFile.eof())
			{
				Days tempDay; //temp obj
				inFile >> inString; //get day date, keep string
				tempDay.SetDateFile(inString); //set day date 

				inFile >> inString; //get protein grams
				inFloat = stof(inString); //change proteins
				tempDay.SetProteinTotal(inFloat); //set protein total for day

				inFile >> inString; //get fats grams
				inFloat = stof(inString); //change fats
				tempDay.SetFatTotal(inFloat); //set fats

				inFile >> inString; //get carbs grams
				inFloat = stof(inString); //change carbs
				tempDay.SetCarbTotal(inFloat); //set carbs

				inFile >> inString; //get meal cals
				inFloat = stof(inString); //change cals
				tempDay.SetCalsTotal(inFloat); //set cals

				dayLog.push_back(tempDay); //push meal to log
			}
		}
	}
	inFile.close(); //close file after done
}

void MacroLogger::ShowMeals()
{
	if (mealLog.empty())
	{
		cout << "\nYou have not logged a meal yet. Go to the main menu to log one!\n";
	}
	else
	{
		cout << "\nYour meals for the day:\n\n";
		for (int i = 0; i < mealLog.size(); i++)
		{
			cout << mealLog[i].GetMealNum() << "\n" << mealLog[i].GetProteins() << "\n" << mealLog[i].GetFats() << "\n" << mealLog[i].GetCarbs() << "\n" << mealLog[i].GetMealCals() << "\n\n";
		}
	}
}

void MacroLogger::ShowDays()
{
	if (dayLog.empty())
	{
		cout << "\nYou have not logged a day yet. Go to the main menu to log one when you have finished logging your last meal for the day!\n";
	}
	else
	{
		cout << "\nYour logged days:\n\n";
		for (int i = 0; i < dayLog.size(); i++)
		{
			cout << dayLog[i].GetDate() << "\n" << dayLog[i].GetProteinTotal() << "\n" << dayLog[i].GetFatTotal() << "\n" << dayLog[i].GetCarbTotal() << "\n" << dayLog[i].GetTotalCals() << "\n\n";
		}
	}
}

void MacroLogger::ShowGoalsSet()
{
	cout << "\nYour daily macro goals:\n\n";
	cout << "Proteins: " << goalDayProtein << "\n" << "Fats: " << goalDayFats << "\n" << "Carbohydrates: " << goalDayCarbs << "\n\n";
	cout << "Your macros per meal (with " << goalMealsPer << " being your goal meals per day):\n\n";
	cout << "Proteins: " << goalMealProtein << "\n" << "Fats: " << goalMealFats << "\n" << "Carbohydrates: " << goalMealCarbs << "\n\n";
}

void MacroLogger::ResetMealsFile(string file)
{
	int resetVar = 0; //put a zero into meal file once meals logged to days
	ofstream outFile(file); //append to file just one line, delete rest
	outFile << resetVar; //put zero as first and only line
	outFile.close(); 
}

void MacroLogger::ResetMealLog()
{
	mealLog.clear();
}

vector<Meal> MacroLogger::GetMeals()
{
	return mealLog;
}

vector<Days> MacroLogger::GetDays()
{
	return dayLog;
}

int MacroLogger::GetMealsPer()
{
	return goalMealsPer;
}

MacroLogger::~MacroLogger()
{
}
