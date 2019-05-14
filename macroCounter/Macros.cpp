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
