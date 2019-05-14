#ifndef MEAL_H
#define MEAL_H
#include "Macros.h"

class Meal :
	public Macros
{
public:
	Meal();
	void SetMeal();
	void SetMealNumFile(int num);
	int GetMealNum();
	~Meal();
private:
	int mealNum;
};

#endif

