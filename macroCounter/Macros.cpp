#include "Macros.h"

Macros::Macros()
{
}

void Macros::SetProteins(int grams)
{
	proteins = grams;
}

void Macros::SetCarbs(int grams)
{
	carbs = grams;
}

void Macros::SetFats(int grams)
{
	fats = grams;
}

void Macros::SetMealCals()
{
	int proCals = proteins * 4;
	int carbCals = carbs * 4;
	int fatCals = fats * 9;

	mealCals = proCals + carbCals + fatCals;
}

void Macros::SetMealCalsFile(int cals)
{
	mealCals = cals;
}

int Macros::GetMealCals()
{
	return mealCals;
}

int Macros::GetProteins()
{
	return proteins;
}

int Macros::GetCarbs()
{
	return carbs;
}

int Macros::GetFats()
{
	return fats;
}

Macros::~Macros()
{
}
