#ifndef MACROLOGGER_H
#define MACROLOGGER_H

#include "Days.h"
#include "Meal.h"
#include <vector>

class MacroLogger
{
public:
	MacroLogger();
	void SetMealsPer(int meals); //set the goal meals per day
	void SetDayProGoal(float protein);
	void SetDayCarbGoal(float carb);
	void SetDayFatGoal(float fat);
	void SetMealProGoal(float meals);
	void SetMealCarbGoal(float meals);
	void SetMealFatGoal(float meals);
	void SaveMealsFile(string file); //save vector meal to file
	void SaveDaysFile(string file); //save vector days to file
	void ReadMealsFile(string file); //read from file to fill vector meal
	void ReadDaysFile(string file); //read from file to fill vector days
	void SaveGoals(string file); //save goals to file
	void ReadGoals(string file); //read from file to set goals 
	void ResetMealsFile(string file); //take out everything once pushed to days then put 0 inside meal
	void ResetMealLog(); // .clear() for vector
	void PushBackMeal(Meal meal); //push meal to meal log
	void PushBackDays(Days day); //push day to day log
	void ShowMeals(); //cout meal vector
	void ShowDays(); //cout days vector
	void ShowGoalsSet(); //show the goals previously set
	//getters
	vector<Meal> GetMeals();
	vector<Days> GetDays();
	int GetMealsPer(); 
	~MacroLogger();
private:
	vector<Meal> mealLog;
	vector<Days> dayLog;
	int goalMealsPer;
	float goalDayProtein;
	float goalDayCarbs;
	float goalDayFats;
	float goalMealProtein;
	float goalMealCarbs;
	float goalMealFats;
};

#endif

