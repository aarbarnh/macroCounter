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
	void SetMealProGoal();
	void SetMealCarbGoal();
	void SetMealFatGoal();
	void SaveMealsFile(Meal meal);
	void SaveDaysFile(Days day);
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

