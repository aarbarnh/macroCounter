#ifndef MACROLOGGER_H
#define MACROLOGGER_H

#include "Days.h"
#include "Meal.h"
#include <vector>

class MacroLogger
{
public:
	MacroLogger();
	void SetDayProGoal(int protein);
	void SetDayCarbGoal(int carb);
	void SetDayFatGoal(int fat);
	void SetMealProGoal(int meals);
	void SetMealCarbGoal(int meals);
	void SetMealFatGoal(int meals);
	void SaveMealsFile(string file); //save vector meal to file
	void SaveDaysFile(string file); //save vector days to file
	void ReadMealsFile(string file); //read from file to fill vector meal
	void ReadDaysFile(string file); //read from file to fill vector days
	void SaveMealGoals(string file); //save meal goals for p,f,c
	void SaveDayGoals(string file); //save day goals for p,f,c
	void ReadMealGoals(string file); //read from file to set goals (meals)
	void ReadDayGoals(string file); //read from file to set goals (days)
	vector<Meal> GetMeals();
	vector<Days> GetDays();
	~MacroLogger();
private:
	vector<Meal> mealLog;
	vector<Days> dayLog;
	int goalDayProtein;
	int goalDayCarbs;
	int goalDayFats;
	int goalMealProtein;
	int goalMealCarbs;
	int goalMealFats;
};

#endif

