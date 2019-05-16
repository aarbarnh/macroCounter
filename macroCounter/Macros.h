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
	void SetProteins(float grams);
	void SetCarbs(float grams);
	void SetFats(float grams);
	void SetMealCals();
	void SetMealCalsFile(float cals);
	float GetMealCals();
	float GetProteins();
	float GetCarbs();
	float GetFats();
protected:
	float proteins;
	float carbs;
	float fats;
	float mealCals;

};

#endif
