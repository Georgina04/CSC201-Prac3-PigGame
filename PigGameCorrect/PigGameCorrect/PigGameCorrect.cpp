// PigGameCorrect.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <time.h> 
using namespace std;

class die {
	private:
		int value; 
	public: 
		die() { roll(); }
		void roll() {
			value = rand() % 6 + 1;
		}
		int getvalue() {
			return value;
		}
};

int main()
{
	srand(time(NULL));
	die die1;
	die die2;
	int die1val;
	int die2val;
	int compscr =0;
	int userscr=0;
	int roundscore;
	int rndno = 1;

	while (compscr < 100 & userscr < 100)
	{
		cout << "Round: " << rndno << "\n\n";
		char input;
		int count = 0;
		cout << "Press r to roll the dice; or p to pass the dice; or q to quit \n";
		cin >> input;
		while (input != 'p' & input != 'q')
		{
			die1.roll();
			die2.roll();
			die1val = die1.getvalue();
			die2val = die2.getvalue();
			cout << "You rolled: " << die1val << "  " << die2val << "\n";
			if (die1val == 1 | die2val == 1)
			{
				cout << "Threw 1 ! Round over. \n";
				break;
			}
			else {
				roundscore = die1val + die2val;
				cout << "Round score: " << roundscore << "\n";
				userscr += roundscore;
				cin >> input;
			}
		}
		if (input == 'q')
		{
			return 0;
		}
		
		cout << "Player score = " << userscr << "  Computer score = " << compscr << "\n\n";

		cout << "Computer goes: \n\n";
		while (count < 3)
		{
			die1.roll();
			die2.roll();
			die1val = die1.getvalue();
			die2val = die2.getvalue();
			cout << "Computer rolled: " << die1val << "  " << die2val << "\n";
			if (die1val == 1 | die2val == 1)
			{
				cout << "Threw 1 ! Round over. \n";
				break;
			}
			else {
				roundscore = die1val + die2val;
				cout << "Round score: " << roundscore << "\n";
				compscr += roundscore;
				count++;
			}
		}
		if (count == 3) {
			cout << "Computer passes . . . \n\n";
		}
		cout << "Player score = " << userscr << "  Computer score = " << compscr << "\n\n";
		rndno++;
	}

	
	if (userscr >= 100)
	{
		cout << "You win!!! \nPress q to quit\n\n";
	}
	else {
		cout << "You lose!!! \nPress q to quit\n\n";
	}
	

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
