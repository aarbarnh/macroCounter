//macro counter v1, make into mobile app after
#include <string>
#include <iostream>
#include "Meal.h"
#include "Days.h"
#include "MacroLogger.h"

using namespace std; 

//prototype functions
void StartScreen();
bool SetGoals(); //set day/meal goals into logger, then ask to save
bool LogMeal(); //push meal to log (save)
bool LogDaily(); //log daily counts, calculate totals then push to dayLog, then save to file
bool ShowMealLog(); //show meals in log
bool ShowGoals(); //shows the goals that the user set
bool ShowDayLog(); //show days in log
bool QuitVerif(); //quitting or back to main menu

//global variables/objs
MacroLogger logger; //logger obj to hold goals and vectors
bool programOn = true; //keeps user inside of program, exit if false

int main()
{
	system("color 17");
	while (programOn == true)
	{
		//load all data in before the start of the program
		logger.ReadDaysFile("days.txt");
		logger.ReadMealsFile("meals.txt");
		logger.ReadGoals("macroGoals.txt");
		StartScreen();
	}

	system("pause");
	return 0;
}

void StartScreen() //description and title, also menu options
{
	bool mainMenu = true;
	while (mainMenu)
	{
		try
		{
			cout << R"(
  __  __                        _______             _             
 |  \/  |                      |__   __|           | |            
 | \  / | __ _  ___ _ __ ___      | |_ __ __ _  ___| | _____ _ __ 
 | |\/| |/ _` |/ __| '__/ _ \     | | '__/ _` |/ __| |/ / _ \ '__|
 | |  | | (_| | (__| | | (_) |    | | | | (_| | (__|   <  __/ |   
 |_|  |_|\__,_|\___|_|  \___/     |_|_|  \__,_|\___|_|\_\___|_|   
                                                                  
                                                                  
)"; //put title
			string menuString;
			int menuInt;
			cout << "1. Set Macro Goals\n2. Show Macro Goals\n3. Log Meal Macros\n4. Log Daily Macros\n5. Show logged meals macros\n6. Show logged daily macros\n7. Quit\n\nWhat would you like to do? (Enter the number shown in the menu): ";
			cin >> menuString;
			menuInt = stoi(menuString); //test if string is an int, catch exception
			if (menuInt < 1 || menuInt > 6) //catch out of range menu number
			{
				throw "You entered a number out of range of the menu. Only enter 1-6.\n";
			}
			switch (menuInt) //switch statement for menu choice
			{
			case 1: //set macro goals (P,F,C for each day)
				mainMenu = SetGoals(); //make programOn false in function, mainMenu assigned with return
				system("cls");
				break;
			case 2: //show the set goals
				mainMenu = ShowGoals();
				system("cls");
				break;
			case 3: //log meal
				mainMenu = LogMeal(); //return bool for main, log meal to vector then save to file
				system("cls");
				break;
			case 4: //log daily
				mainMenu = LogDaily(); //return bool to main
				system("cls");
				break;
			case 5: //see meals
				mainMenu = ShowMealLog(); //show meals in vector
				system("cls");
				break;
			case 6: //see daily
				mainMenu = ShowDayLog(); //show days in vector
				system("cls");
				break; 
			case 7: //quit option
				mainMenu = false;
				programOn = false;
				system("cls");
				break;
			}
		}
		catch (const char * msg) //oor string msg exception
		{
			cout << "\n\n" << msg << endl;
		}
		catch (exception& e) //stoi exception
		{
			cout << "\n\nException occured: " << e.what() << "\n\n";
		}
	}
}

bool QuitVerif()
{
	bool quitProgramVerif = false;
	while (quitProgramVerif == false) //loop to quit program or just go back to menu
	{
		char userValidate;

		cout << "\nWould you like to exit the program? If you do enter 'y'. If you do not, and just want to return to the main menu, enter 'n'.\nChoice: ";
		cin >> userValidate; //get y/n for quitting
		if (userValidate == 'y' || userValidate == 'Y')
		{
			cout << "\nThank you for using the Macro Tracker!\n\nExiting the program...\n"; //goodbye message
			quitProgramVerif = true; //exit loop
			programOn = false; //exit program
			return false; //exit main menu
		}
		else if (userValidate == 'n' || userValidate == 'Y')
		{
			cout << "\nTaking you back to the main menu...\n"; //return message
			quitProgramVerif = true; //exit loop
			return true; //keep in main menu
		}
		else
		{
			cout << "\nYou can only enter 'y' to exit the entire program or 'n' to go back to the main menu. Please try again.\n\n";
		}
	}
}

bool SetGoals() //set goals definition
{
	//loop control variables
	bool setBeforeVerif = false;
	bool makeNewVerif = false;
	bool returnBool = false; //send back to main menu
	bool proVerif = false; //keep in try/catch loop
	bool carbVerif = false;
	bool fatVerif = false;
	bool mealVerif = false;
	
	char userValidate; //char to hold y/n for all four questions
	string userInput; //string to hold p,f,c grams; test with stoi
	float floatGrams; //conv
	int mealNum; //used to get 

	while (setBeforeVerif == false) //first question
	{
		cout << "\nHave you set daily macro goals before?\n(Enter 'y' if you made them before or 'n' if you have not): ";
		cin >> userValidate;
		if (userValidate == 'y' || userValidate == 'Y')
		{
			while (makeNewVerif == false)
			{
				cout << "\nWould you like to make new macro goals?\n(Enter 'y' to make new goals, or 'n' to keep old goals): ";
				cin >> userValidate;
				if (userValidate == 'y' || userValidate == 'Y') 
				{
					while (proVerif == false)
					{
						try
						{
							cout << "\nHow many grams of protein do you want to have per day?: "; //protein
							cin >> userInput;
							floatGrams = stof(userInput); //stoi test
							logger.SetDayProGoal(floatGrams); //set goal proteins 
							proVerif = true;
						}
						catch (exception & e)
						{
							cout << "\nException occured: " << e.what() << "\n";
						}
					}
					while (fatVerif == false)
					{
						try
						{
							cout << "\nHow many grams of fats do you want to have per day?: "; //fats
							cin >> userInput;
							floatGrams = stof(userInput); //stoi test
							logger.SetDayFatGoal(floatGrams); //set goal fats
							fatVerif = true;
						}
						catch (exception & e)
						{
							cout << "\nException occured: " << e.what() << "\n";
						}
					}
					while (carbVerif == false)
					{
						try
						{
							cout << "\nHow many grams of carbohydrates do you want to have per day?: "; //carbs
							cin >> userInput;
							floatGrams = stof(userInput); //stoi test
							carbVerif = true;
						}
						catch (exception & e)
						{
							cout << "\nException occured: " << e.what() << "\n";
						}
					}
					while (mealVerif == false)
					{
						try
						{
							//figure out meal nums to get meal goals
							cout << "\nHow many meals do you plan to have in the day?\nThis will determine your meal macro goals from the daily macro goals given: ";
							cin >> userInput;
							mealNum = stoi(userInput); //stoi test
							logger.SetMealsPer(mealNum); //set meals per day goal
							mealVerif = true;
						}
						catch (exception & e)
						{
							cout << "\nException occured: " << e.what() << "\n";
						}
					}
					//set meal goals
					logger.SetMealProGoal(mealNum); //can probably make these three into one, change later
					logger.SetMealFatGoal(mealNum);
					logger.SetMealCarbGoal(mealNum);
					//save goals to file
					logger.SaveGoals("macroGoals.txt"); //saves to file, will make on own if I do not
					cout << "\nYour daily and meal goals have been set and saved!\n";
					makeNewVerif = true; //get out of loop
					setBeforeVerif = true; //get out of outer loop
				}
				else if (userValidate == 'n' || userValidate == 'N')
				{
					cout << "\nLet's load in your macro goals from before! One moment please...\n\n";
					logger.ReadGoals("macroGoals.txt"); //read goals from file and set them
					cout << "Your goals have been loaded in!\n";
					makeNewVerif = true; //get out of loop 
					setBeforeVerif = true; //get out of outer loop
				}
				else
				{
					cout << "\nYou can only enter 'y' or 'n'. Remember 'y' means that you want to make new goals, 'n' means you want to load in old goals.\n"; 
				}
			}
		}
		else if (userValidate == 'n' || userValidate == 'N')
		{
			cout << "\nLet's make some brand new macro goals then!\n";
			while (proVerif == false)
			{
				try
				{
					cout << "\nHow many grams of protein do you want to have per day?: "; //protein
					cin >> userInput;
					floatGrams = stof(userInput); //stoi test
					logger.SetDayProGoal(floatGrams); //set goal proteins 
					proVerif = true;
				}
				catch (exception& e)
				{
					cout << "\nException occured: " << e.what() << "\n";
				}
			}
			while (fatVerif == false)
			{
				try
				{
					cout << "\nHow many grams of fats do you want to have per day?: "; //fats
					cin >> userInput;
					floatGrams = stof(userInput); //stoi test
					logger.SetDayFatGoal(floatGrams); //set goal fats
					fatVerif = true;
				}
				catch (exception& e)
				{
					cout << "\nException occured: " << e.what() << "\n";
				}
			}
			while (carbVerif == false)
			{
				try
				{
					cout << "\nHow many grams of carbohydrates do you want to have per day?: "; //carbs
					cin >> userInput;
					floatGrams = stof(userInput); //stoi test
					logger.SetDayCarbGoal(floatGrams);
					carbVerif = true;
				}
				catch (exception& e)
				{
					cout << "\nException occured: " << e.what() << "\n";
				}
			}
			while (mealVerif == false)
			{
				try
				{
					//figure out meal nums to get meal goals
					cout << "\nHow many meals do you plan to have in the day?\nThis will determine your meal macro goals from the daily macro goals given: ";
					cin >> userInput;
					mealNum = stoi(userInput); //stoi test
					logger.SetMealsPer(mealNum); //set meals per day goal
					mealVerif = true;
				}
				catch (exception& e)
				{
					cout << "\nException occured: " << e.what() << "\n";
				}
			}
			//set meal goals
			logger.SetMealProGoal(mealNum); //can probably make these three into one, change later
			logger.SetMealFatGoal(mealNum);
			logger.SetMealCarbGoal(mealNum);
			//save goals to file
			logger.SaveGoals("macroGoals.txt"); //saves to file, will make on own if I do not
			cout << "\nYour daily and meal goals have been set and saved!\n";
			setBeforeVerif = true; //get out of outer loop
		}
		else
		{
			cout << "\nYou can only enter 'y' or 'n'. Remember 'y' means that you have made macro goals before, 'n' means that you have not.\n";
		}
	}
	returnBool = QuitVerif();
	return returnBool;
}

bool LogMeal()
{
	//variables for logging, string is for stoi/stof
	string userInput;
	char logMoreMeals;
	float macroEntry;
	Meal tempMeal;

	//bools for control
	bool proteinValid = false;
	bool carbValid = false;
	bool fatValid = false;
	bool returnBool = false;
	bool logAnother = true;

	//set meal num
	tempMeal.SetMeal();

	//get meal proteins
	while (proteinValid == false)
	{
		try
		{
			cout << "\nHow many grams of protein was in your meal?: ";
			cin >> userInput;
			macroEntry = stof(userInput);
			tempMeal.SetProteins(macroEntry);
			proteinValid = true;
		}
		catch (exception & e)
		{
			cout << "\nException occured: " << e.what() << "\n";
		}
	}
	//get meal fats
	while (fatValid == false)
	{
		try
		{
			cout << "\nHow many grams of fat was in your meal?: ";
			cin >> userInput;
			macroEntry = stof(userInput);
			tempMeal.SetFats(macroEntry);
			fatValid = true;
		}
		catch (exception & e)
		{
			cout << "\nException occured: " << e.what() << "\n";
		}
	}
	//get meal carbs
	while (carbValid == false)
	{
		try
		{
			cout << "\nHow many grams of carbohydrates was in your meal?: ";
			cin >> userInput;
			macroEntry = stof(userInput);
			tempMeal.SetCarbs(macroEntry);
			carbValid = true;
		}
		catch (exception & e)
		{
			cout << "\nException occured: " << e.what() << "\n";
		}
	}
	tempMeal.SetMealCals(); //set cals
	logger.PushBackMeal(tempMeal);
	logger.SaveMealsFile("meals.txt");

	returnBool = QuitVerif();
	return returnBool;
}

bool LogDaily()
{
	Days tempDay;
	char logDayVerif;
	bool logValid = false;
	bool returnBool = false;

	while (logValid == false)
	{
		cout << "\nDo you want to log your daily macros? This will add up the macros of all the meals you've logged so far and combine them into a day total.\nEnter 'y' for yes or 'n' for no: ";
		cin >> logDayVerif;
		if (logDayVerif == 'Y' || logDayVerif == 'y')
		{
			cout << "\nLogging your daily macros...\n\n";
			tempDay.SetDate(); //set the date of the day being logged
			tempDay.SetPFCTotals(logger.GetMeals()); //get p f and c for day, passing in logger vector
			tempDay.SetCals(); //set cals for the day
			logger.PushBackDays(tempDay); //push to days vector in logger
			logger.SaveDaysFile("days.txt"); //save the days to file
			cout << "\nDaily macros logged successfully!\n";
			logger.ResetMealLog(); //make sure meal log is empty now
			logger.ResetMealsFile("meals.txt"); //reset file to have just 0 for # of meals
			returnBool = QuitVerif();
			logValid = true;
			return returnBool; //stay in main menu or not
		}
		else if (logDayVerif == 'N' || logDayVerif == 'n')
		{
			cout << "\nYour daily macros will not be logged yet\n";
			returnBool = QuitVerif();
			logValid = true;
			return returnBool;
		}
		else
		{
			cout << "\nYou can only enter 'y' or 'n'. Please try again.\n";
		}
	}

} //taking meals, totaling, set to day vector then save to file

bool ShowMealLog()
{
	bool returnBool; //for main menu
	logger.ShowMeals(); 
	returnBool = QuitVerif();

	return returnBool;
}

bool ShowDayLog()
{
	bool returnBool; //for main menu
	logger.ShowDays();
	returnBool = QuitVerif();

	return returnBool;
}

bool ShowGoals()
{
	bool returnBool; //for main menu
	logger.ShowGoalsSet();
	returnBool = QuitVerif();

	return returnBool;
}