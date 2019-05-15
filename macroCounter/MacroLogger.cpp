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

void MacroLogger::SaveMealGoals(string file)
{
	ofstream outFile(file);
	if (outFile.is_open())
	{ //write in the goals for the meals
		outFile << goalMealProtein << "\n";
		outFile << goalMealFats << "\n";
		outFile << goalMealCarbs << "\n";
	}
	outFile.close();
}

void MacroLogger::SaveDayGoals(string file)
{
	ofstream outFile(file);
	if (outFile.is_open())
	{//write in the goals for days
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

void MacroLogger::ReadMealGoals(string file)
{
	string inString;
	int inInt;

	ifstream inFile(file);
	if (inFile.is_open())
	{
		getline(inFile, inString); //get meal goal proteins
		inInt = stoi(inString); //convert
		goalMealProtein = inInt; //set meal proteins

		getline(inFile, inString); //get meal goal fats
		inInt = stoi(inString); //convert
		goalMealFats = inInt; //set

		getline(inFile, inString); //get meal goal carbs
		inInt = stoi(inString); //convert
		goalMealCarbs = inInt; //set

	}
	inFile.close();
}

void MacroLogger::ReadDayGoals(string file)
{
	string inString;
	int inInt;

	ifstream inFile(file);
	if (inFile.is_open())
	{
		getline(inFile, inString); //get meal goal proteins
		inInt = stoi(inString); //convert
		goalDayProtein = inInt; //set meal proteins

		getline(inFile, inString); //get meal goal fats
		inInt = stoi(inString); //convert
		goalDayFats = inInt; //set

		getline(inFile, inString); //get meal goal carbs
		inInt = stoi(inString); //convert
		goalDayCarbs = inInt; //set

	}
	inFile.close();
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

			getline(inFile, inString); //get fats grams
			inInt = stoi(inString); //change fats
			tempMeal.SetFats(inInt); //set fats

			getline(inFile, inString); //get carbs grams
			inInt = stoi(inString); //change carbs
			tempMeal.SetCarbs(inInt); //set carbs

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

			getline(inFile, inString); //get fats grams
			inInt = stoi(inString); //change fats
			tempDay.SetFatTotal(inInt); //set fats

			getline(inFile, inString); //get carbs grams
			inInt = stoi(inString); //change carbs
			tempDay.SetCarbTotal(inInt); //set carbs

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
