#ifndef MEAL_H
#define MEAL_H
#include "Macros.h"

class Meal :
	public Macros
{
public:
	Meal();
	void SetMeal();
	int GetMealNum();
	~Meal();
private:
	int mealNum;
};

#endif

