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
void LogMeal(); //push meal to log (save)
void ShowMealLog(); //show meals in log
void ShowDayLog(); //show days in log

//global variables/objs
MacroLogger logger; //logger obj to hold goals and vectors
bool programOn = true; //keeps user inside of program, exit if false

int main()
{
	system("color 17");
	while (programOn == true)
	{
		StartScreen();
	}

	system("pause");
	return 0;
}

void StartScreen() //description and title, also menu options
{
	cout << R"(
  __  __                        _______             _             
 |  \/  |                      |__   __|           | |            
 | \  / | __ _  ___ _ __ ___      | |_ __ __ _  ___| | _____ _ __ 
 | |\/| |/ _` |/ __| '__/ _ \     | | '__/ _` |/ __| |/ / _ \ '__|
 | |  | | (_| | (__| | | (_) |    | | | | (_| | (__|   <  __/ |   
 |_|  |_|\__,_|\___|_|  \___/     |_|_|  \__,_|\___|_|\_\___|_|   
                                                                  
                                                                  
)"; //put title

	bool mainMenu = true;
	while (mainMenu)
	{
		try
		{
			string menuString;
			int menuInt;
			cout << "1. Set Daily Macro Goals\n2. Log Meal Macros\n3. Log Daily Macros\n4. Show logged meals\n5. Show logged daily macros\n6. Quit\n\nWhat would you like to do? (Enter the number shown in the menu): ";
			getline(cin, menuString);
			menuInt = stoi(menuString); //test if string is an int, catch exception
			if (menuInt < 1 || menuInt > 6) //catch out of range menu number
			{
				throw "You entered a number out of range of the menu. Only enter 1-6.\n";
			}
			switch (menuInt) //switch statement for menu choice
			{
			case 1: //set macro goals (P,F,C for each day)
				mainMenu = SetGoals(); //make programOn false in function, mainMenu assigned with return
				break;
			case 2: //log meal
				break;
			case 3: //log daily
				//mainMenu = false; make function bool, still need to affect mainMenu bool
				break;
			case 4: //see meals
				break;
			case 5: //see daily
				break; 
			case 6: //quit option
				mainMenu = false;
				programOn = false;
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
	system("pause");
	system("cls");
}

bool SetGoals() //set goals definition
{
	//loop control variables
	bool setBeforeVerif = false;
	bool makeNewVerif = false;
	bool quitProgramVerif = false;
	
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
					cout << "\nHow many grams of protein do you want to have per day?: "; //protein
					cin >> userInput;
					floatGrams = stof(userInput); //stoi test, add exception later REMEMBER!
					logger.SetDayProGoal(floatGrams); //set goal proteins 

					cout << "\nHow many grams of fats do you want to have per day?: "; //fats
					cin >> userInput;
					floatGrams = stof(userInput); //stoi test, EXCEPTION ADD MUST
					logger.SetDayFatGoal(floatGrams); //set goal fats

					cout << "\nHow many grams of carbohydrates do you want to have per day?: "; //carbs
					cin >> userInput;
					floatGrams = stof(userInput); //stoi test, EXCEPTION ADD MUST
					logger.SetDayCarbGoal(floatGrams);
					//figure out meal nums to get meal goals
					cout << "\nHow many meals do you plan to have in the day?\nThis will determine your meal macro goals from the daily macro goals given: ";
					cin >> userInput;
					mealNum = stoi(userInput); //stoi test, EXCEPTION ADD MUST
					//set meal goals
					logger.SetMealProGoal(mealNum); //can probably make these three into one, change later
					logger.SetMealFatGoal(mealNum);
					logger.SetMealCarbGoal(mealNum);
					//save goals to file
					logger.SaveGoals("macroGoals.txt"); //saves to file, will make on own if I do not
					cout << "\nYour daily and meal goals have been set and saved!\n\n";
					makeNewVerif = true; //get out of loop
					setBeforeVerif = true; //get out of outer loop
				}
				else if (userValidate == 'n' || userValidate == 'N')
				{
					cout << "\nLet's load in your macro goals from before! One moment please...\n\n";
					logger.ReadGoals("macroGoals.txt"); //read goals from file and set them
					cout << "Your goals have been loaded in!\n\n";
					makeNewVerif = true; //get out of loop 
					setBeforeVerif = true; //get out of outer loop
				}
				else
				{
					cout << "\nYou can only enter 'y' or 'n'. Remember 'y' means that you want to make new goals, 'n' means you want to load in old goals.\n\n"; 
				}
			}
		}
		else if (userValidate == 'n' || userValidate == 'N')
		{
			cout << "\nLet's make some brand new macro goals then!\n\nHow many grams of protein do you want to have per day?: "; //protein
			cin >> userInput;
			floatGrams = stof(userInput); //stoi test, add exception later REMEMBER!
			logger.SetDayProGoal(floatGrams); //set goal proteins 

			cout << "\nHow many grams of fats do you want to have per day?: "; //fats
			cin >> userInput;
			floatGrams = stof(userInput); //stoi test, EXCEPTION ADD MUST
			logger.SetDayFatGoal(floatGrams); //set goal fats

			cout << "\nHow many grams of carbohydrates do you want to have per day?: "; //carbs
			cin >> userInput;
			floatGrams = stof(userInput); //stoi test, EXCEPTION ADD MUST
			logger.SetDayCarbGoal(floatGrams);
			//figure out meal nums to get meal goals
			cout << "\nHow many meals do you plan to have in the day?\nThis will determine your meal macro goals from the daily macro goals given: ";
			cin >> userInput;
			mealNum = stoi(userInput); //stoi test, EXCEPTION ADD MUST
			//set meal goals
			logger.SetMealProGoal(mealNum); //can probably make these three into one, change later
			logger.SetMealFatGoal(mealNum);
			logger.SetMealCarbGoal(mealNum);
			//save goals to file
			logger.SaveGoals("macroGoals.txt"); //saves to file, will make on own if I do not
			cout << "\nYour daily and meal goals have been set and saved!\n\n";
			setBeforeVerif = true; //get out of outer loop
		}
		else
		{
			cout << "\nYou can only enter 'y' or 'n'. Remember 'y' means that you have made macro goals before, 'n' means that you have not.\n\n";
		}
	}
	while (quitProgramVerif == false) //loop to quit program or just go back to menu
	{
		cout << "Would you like to exit the program? If you do enter 'y'. If you do not, and just want to return to the main menu, enter 'n'.\nChoice: ";
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
			cout << "\nGood job setting and saving your macro goals!\n\nTaking you back to the main menu...\n"; //return message
			quitProgramVerif = true; //exit loop
			return true; //keep in main menu
		}
		else
		{
			cout << "\nYou can only enter 'y' to exit the entire program or 'n' to go back to the main menu. Please try again.\n\n";
		}
	}
}