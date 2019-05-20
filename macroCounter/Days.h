#ifndef DAYS_H
#define DAYS_H
#include "Meal.h"
#include <string>
#include <vector>

using namespace std;

class Days
{
public:
	Days();
	//getter/setters 
	void SetDate();
	void SetDateFile(string date);
	void SetPFCTotals(vector<Meal> mLog);
	void SetProteinTotal(float protein);
	void SetCarbTotal(float carb);
	void SetFatTotal(float fat);
	void SetCals();
	void SetCalsTotal(float cals);
	string GetDate();
	float GetProteinTotal();
	float GetCarbTotal();
	float GetFatTotal();
	float GetProteinCals();
	float GetCarbCals();
	float GetFatCals();
	float GetTotalCals();
	~Days();
private:
	string dDate;
	float proteinTotal = 0;
	float carbTotal = 0;
	float fatTotal = 0;
	float proteinCals;
	float fatCals;
	float carbCals;
	float totalCals;
};

#endif
