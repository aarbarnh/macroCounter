#include "MacroLogger.h"
#include <fstream>


MacroLogger::MacroLogger()
{
}

void MacroLogger::SetDayProGoal(float protein)
{
	goalDayProtein = protein;
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
	ofstream outFile(file, ios::app); //append to file, not write over
	if (outFile.is_open())
	{
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
	ofstream outFile(file, ios::app); //append to file not write over
	if (outFile.is_open())
	{
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

	ifstream inFile(file);
	if (inFile.is_open())
	{
		getline(inFile, inString); //get meal goal proteins
		inFloat = stof(inString); //convert
		goalMealProtein = inFloat; //set meal proteins

		getline(inFile, inString); //get meal goal fats
		inFloat = stof(inString); //convert
		goalMealFats = inFloat; //set

		getline(inFile, inString); //get meal goal carbs
		inFloat = stof(inString); //convert
		goalMealCarbs = inFloat; //set

		getline(inFile, inString); //get day goal proteins
		inFloat = stof(inString); //convert
		goalDayProtein = inFloat; //set meal proteins

		getline(inFile, inString); //get day goal fats
		inFloat = stof(inString); //convert
		goalDayFats = inFloat; //set

		getline(inFile, inString); //get day goal carbs
		inFloat = stof(inString); //convert
		goalDayCarbs = inFloat; //set


	}
	inFile.close();
}

void MacroLogger::ReadMealsFile(string file)
{
	string inString;
	float inFloat;
	int inInt; //for meal num only

	ifstream inFile(file);
	if (inFile.is_open())
	{
		while (!inFile.eof())
		{
			Meal tempMeal; //temp obj
			getline(inFile, inString); //get meal num
			inInt = stof(inString); //change string to int
			tempMeal.SetMealNumFile(inInt); //set meal num to inInt

			getline(inFile, inString); //get protein grams
			inFloat = stof(inString); //change proteins
			tempMeal.SetProteins(inFloat); //set proteins

			getline(inFile, inString); //get fats grams
			inFloat = stof(inString); //change fats
			tempMeal.SetFats(inFloat); //set fats

			getline(inFile, inString); //get carbs grams
			inFloat = stof(inString); //change carbs
			tempMeal.SetCarbs(inFloat); //set carbs

			getline(inFile, inString); //get meal cals
			inFloat = stof(inString); //change cals
			tempMeal.SetMealCalsFile(inFloat); //set cals

			mealLog.push_back(tempMeal); //push meal to log
		}
	}
	inFile.close(); //close file after done
	
}

void MacroLogger::ReadDaysFile(string file)
{
	string inString;
	float inFloat;

	ifstream inFile(file);
	if (inFile.is_open())
	{
		while (!inFile.eof())
		{
			Days tempDay; //temp obj
			getline(inFile, inString); //get day date, keep string
			tempDay.SetDateFile(inString); //set day date 

			getline(inFile, inString); //get protein grams
			inFloat = stof(inString); //change proteins
			tempDay.SetProteinTotal(inFloat); //set protein total for day

			getline(inFile, inString); //get fats grams
			inFloat = stof(inString); //change fats
			tempDay.SetFatTotal(inFloat); //set fats

			getline(inFile, inString); //get carbs grams
			inFloat = stof(inString); //change carbs
			tempDay.SetCarbTotal(inFloat); //set carbs

			getline(inFile, inString); //get meal cals
			inFloat = stof(inString); //change cals
			tempDay.SetCalsTotal(inFloat); //set cals

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
