// Chapter_2_Homework_Barone.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Name: Roberto Barone
// Date: 1/31/23
// Class: CIT-245
// Assignment: Chapter 2 (Homework)

#include <iostream>
#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>

using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    //Variables
    double pi = 3.141592;
    double sphWeight; //sphere weight
    double waterDensity = 62.4; //lbs per cubic foot
    double radius; //radius of Sphere
    double bForce; //Buoyant Force
    double calc = static_cast<double>(4) / 3; //helping to calculate the volume
    int rCal; //for recaluation
    
        //Intro to user
        cout << "This program computes the Buoyant Force in water "
            << "given sphere radius." << endl
            << "Based on the weight of the sphere, "
            << "it determines whether the sphere floats or sinks." << endl;
        
        //Start of a do/while loop
        do {
            //Asking user for radius of sphere
            cout << "Enter the radius of the sphere." << endl;

            cin >> radius;
            //User's radius input
            cout << "You entered: " << radius << endl;
            //Asking user for weight of sphere
            cout << "Enter the weight of the sphere." << endl;

            cin >> sphWeight;
            //User's sphere weight
            cout << "You entered: " << sphWeight << endl;

            //calculating buoyant force
            double volume = calc * pi * radius * radius * radius;
            //cout << volume << endl; (to help fix an error I had with the volume)
            bForce = waterDensity * volume;

            cout << "Buoyant Force = " << bForce << endl;

            if (sphWeight <= 100) {
                cout << "The sphere is light enough to float!" << endl;
            }
            else {
                cout << "The sphere is to heavy to float! It sank!" << endl;
            }

            //Asking to loop program
            cout << "Recalculate? (1 = yes, 0 = exit)" << endl;
            //User's input on whether to loop or not
            cin >> rCal;
        } while (rCal == 1);

    system("pause");
    return 0;
}


