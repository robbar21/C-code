// Chapter_3_Barone_Homework.cpp
// Name: Roberto Barone
// Date: 2/7/2023
// Class: CIT - 245
// Assignment : Chapter 3 HW
//
#include <iostream>
#include<string>
#include<stdlib.h>
#include<time.h>
#include <cstdlib>
#include <iomanip>

using namespace std;
//To get the multiplier on the odds take 
//#rolls/36 = multiplier 
//then multiply this times the odds for 36.
//ex: rolls 3600 / 36 = 100 so all odds are times 100.

int diceRoll(int numberOfRolls); // rolls a die to get a 1-6 result
double die_sum_chance(int sum); // calculates the dies odds


int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    //declare variables
    int rolls;
    int die1, die2;
    int sum;
    int store[13];  //need 12 but the 0 will not be used
    double odds;
    int s = 0;
    char ans; //the user's response for trying again

    do {

        cout << "This program rolls two dice and tabulates the results."
            << endl;
        cout << "Please enter the number of rolls you want: ";
        cin >> rolls;

        cout << setw(10) << "Sum:";
        cout << setw(15) << "#Rolled:";
        cout << setw(20) << "Odds:";
        cout << setw(25) << "%Error:" << endl;

        for (s = 0; s < 13; s++) {
            store[s] = 0;
        }

        srand(rand());
        for (int i = 0;i < rolls;i++)//loop for the number of rolls
        {
            //outputing the random rolls of die one
            die1 = diceRoll(rolls);
            //outputing the random rolls of die two
            die2 = diceRoll(rolls);

            sum = die1 + die2;//Getting the sum of the 2 dice.

            store[sum]++;
            
            
        }//end for loop

        for (s = 2; s <= 12; s++) {
            odds = die_sum_chance(s) * rolls;
            cout << setw(10) << s << ":" << setw(10) << store[s] 
                << setw(23) << odds << setw(27) 
                << (abs(store[s] - odds) / odds) * 100 
                << "%" << endl;
        }


        cout << "Try again? (y/n)" << endl;//Asking user to repeat
        cin >> ans;
        cout << endl;
    } while (ans == 'y' || ans == 'Y');


    return 0;
}

int diceRoll(int numberOfRolls) {
    int roll;
    int min = 1; //min amount a die has on it
    int max = 6; //max amount a die has on it

    roll = rand() % (max - min + 1) + min;
    return roll;
}

double die_sum_chance(int sum)
{ //generating the odds of the roll using the sum of the two dice
    if (sum < 2 || sum > 12)
        return 0;
    if (sum <= 7)
        return double(sum - 1) / 36;
    else
        return double(12 - (sum - 1)) / 36;
}

