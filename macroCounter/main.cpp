//macro counter v1, make into mobile app after
#include <string>
#include <iostream>
#include "Meal.h"
#include "Days.h"
#include "MacroLogger.h"

using namespace std; 

void StartScreen(bool *ptrBool);

int main()
{
	system("color 17");
	bool programOn = true; //keeps user inside of program, exit if false
	while (programOn == true)
	{
		StartScreen(&programOn);
		Days dayT;
		dayT.SetDate();
	}

	system("pause");
	return 0;
}

void StartScreen(bool *ptrBool) //description and title, also menu options
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
				mainMenu = false;
				break;
			case 2: //log meal
				break;
			case 3: //log daily
				mainMenu = false;
				*ptrBool = false;
				break;
			case 4: //see meals
				break;
			case 5: //see daily
				break; 
			case 6: //quit option
				mainMenu = false;
				*ptrBool = false;
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