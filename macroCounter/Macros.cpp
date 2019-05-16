#include "Macros.h"

Macros::Macros()
{
}

void Macros::SetProteins(float grams)
{
	proteins = grams;
}

void Macros::SetCarbs(float grams)
{
	carbs = grams;
}

void Macros::SetFats(float grams)
{
	fats = grams;
}

void Macros::SetMealCals()
{
	float proCals = proteins * 4;
	float carbCals = carbs * 4;
	float fatCals = fats * 9;

	mealCals = proCals + carbCals + fatCals;
}

void Macros::SetMealCalsFile(float cals)
{
	mealCals = cals;
}

float Macros::GetMealCals()
{
	return mealCals;
}

float Macros::GetProteins()
{
	return proteins;
}

float Macros::GetCarbs()
{
	return carbs;
}

float Macros::GetFats()
{
	return fats;
}

Macros::~Macros()
{
}
