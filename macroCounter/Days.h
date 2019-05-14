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
	void SetPFCTotals(vector<Meal> mLog);
	void SetCals();
	string GetDate();
	int GetProteinTotal();
	int GetCarbTotal();
	int GetFatTotal();
	int GetProteinCals();
	int GetCarbCals();
	int GetFatCals();
	int GetTotalCals();
	~Days();
private:
	string dDate;
	int proteinTotal;
	int carbTotal;
	int fatTotal;
	int proteinCals;
	int fatCals;
	int carbCals;
	int totalCals;
};

#endif
