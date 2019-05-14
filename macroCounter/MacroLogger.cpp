#include "MacroLogger.h"
#include <fstream>


MacroLogger::MacroLogger()
{
}

void MacroLogger::SetDayProGoal(int protein)
{
	goalDayProtein = protein;
}

void MacroLogger::SetDayCarbGoal(int carb)
{
	goalDayCarbs = carb;
}

void MacroLogger::SetDayFatGoal(int fat)
{
	goalDayFats = fat;
}

void MacroLogger::SetMealProGoal(int meals)
{
	goalMealProtein = goalDayProtein / meals;
}

void MacroLogger::SetMealCarbGoal(int meals)
{
	goalMealCarbs = goalDayCarbs / meals;
}

void MacroLogger::SetMealFatGoal(int meals)
{
	goalMealFats = goalDayFats / meals;
}

void MacroLogger::SaveMealsFile(string file)
{
	//todo::file i/o, look at gwent final to remind. open meal file, add meals from vector, close
}

void MacroLogger::SaveDaysFile(string file)
{
	ofstream outFile(file);
	if (outFile.is_open())
	{
		for (int i = 0; i < dayLog.size(); i++)
		{
			
		}
	}
}

void MacroLogger::ReadMealsFile(string file)
{
	string inString;
	int inInt;

	ifstream inFile(file);
	if (inFile.is_open())
	{
		while (!inFile.eof())
		{
			Meal tempMeal; //temp obj
			getline(inFile, inString); //get meal num
			inInt = stoi(inString); //change string to int
			tempMeal.SetMealNumFile(inInt); //set meal num to inInt

			getline(inFile, inString); //get protein grams
			inInt = stoi(inString); //change proteins
			tempMeal.SetProteins(inInt); //set proteins

			getline(inFile, inString); //get carb grams
			inInt = stoi(inString); //change carbs
			tempMeal.SetCarbs(inInt); //set carbs

			getline(inFile, inString); //get fat grams
			inInt = stoi(inString); //change fats
			tempMeal.SetFats(inInt); //set fats

			getline(inFile, inString); //get meal cals
			inInt = stoi(inString); //change cals
			tempMeal.SetMealCalsFile(inInt); //set cals

			mealLog.push_back(tempMeal); //push meal to log
		}
	}
	inFile.close(); //close file after done
	
}

void MacroLogger::ReadDaysFile(string file)
{
	string inString;
	int inInt;

	ifstream inFile(file);
	if (inFile.is_open())
	{
		while (!inFile.eof())
		{
			Days tempDay; //temp obj
			getline(inFile, inString); //get day date, keep string
			tempDay.SetDateFile(inString); //set day date 

			getline(inFile, inString); //get protein grams
			inInt = stoi(inString); //change proteins
			tempDay.SetProteinTotal(inInt); //set protein total for day

			getline(inFile, inString); //get carb grams
			inInt = stoi(inString); //change carbs
			tempDay.SetCarbTotal(inInt); //set carbs

			getline(inFile, inString); //get fat grams
			inInt = stoi(inString); //change fats
			tempDay.SetFatTotal(inInt); //set fats

			getline(inFile, inString); //get meal cals
			inInt = stoi(inString); //change cals
			tempDay.SetCalsTotal(inInt); //set cals

			dayLog.push_back(tempDay); //push meal to log
		}
	}
	inFile.close(); //close file after done
}

vector<Meal> MacroLogger::GetMeals()
{
	return mealLog;
}

vector<Days> MacroLogger::GetDays()
{
	return dayLog;
}

MacroLogger::~MacroLogger()
{
}
