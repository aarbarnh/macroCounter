#ifndef MACROS_H
#define MACROS_H
#include <string>

using namespace std;

class Macros
{
public:
	Macros();
	~Macros();
	//getters/setters
	void SetProteins(int grams);
	void SetCarbs(int grams);
	void SetFats(int grams);
	void SetMealCals();
	void SetMealCalsFile(int cals);
	int GetMealCals();
	int GetProteins();
	int GetCarbs();
	int GetFats();
protected:
	int proteins;
	int carbs;
	int fats;
	int mealCals;

};

#endif
