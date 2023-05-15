// Chapter_1_Homework_Barone.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Name: Roberto Barone
// Date: 1/31/23
// Class: CIT-245
// Assignment: Chapter 1 (Homework)

#include <iostream>
#include<string>
#include<stdlib.h>
#include<time.h>

using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);

    //declaring variables
    double input, guess, r, prevGuess;

    //prompting user to enter a number they want the square root of
    cout << "Enter a number and I will apply the "
        << " Babylonain square root algorithm " <<endl
        << " until I am within .001 of the correct answer." << endl;

    //user's input
    cin >> input;

    cout << "You entered: " << input << endl;

    //Step 1
    guess = (input / 2);

    //Step 2 (where loop begins)
    do {
        r = (input / guess);

        //stores previous guess into the new guess
        prevGuess = guess;

        //Step 3
        guess = ((guess + r) / 2);

        cout << "guessing: " << guess << endl;

    } while (prevGuess - guess > 0.001 * prevGuess); // repeat until guess is within .001 of the input

    double check = (guess * guess);

    //display output with correct guess
    cout << "The Babylons algorithm gives: " << guess << endl;
    cout << "Checking: " << guess << " * " << guess  << ": " 
        << check << endl;

    system("pause");
    return 0;
}

