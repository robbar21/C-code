// Chapter_4_Barone_Homework.cpp 
// Name: Roberto Barone
// Date: 2/8/23
// Class: CIT-245
// Assignment: Chapter 4 Homework
//

#include <iostream>

using namespace std;

int gcd(int number, int denom);
double reduce(int c, int de);

int main()
{
    double g, r;
    int num, den;
    char ans;

    cout << "This program takes a numerator and denominator "
        << "and reduces to lowest terms." << endl;

    do {
        cout << "Enter the numerator:" << endl;
        cin >> num;

        cout << "Enter the denominator: " << endl;
        cin >> den;

        g = gcd(num, den);

        r = reduce(num, den);

        cout << "Greatest common denominator is " << g << endl;
        cout << "Your fraction reduced is " << num / g 
            << "/" << den / g << endl;

        cout << "Try again? (y/n)" << endl;
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');


    return 0;
}
//Function that creates a fraction
//and returns the greatest common denominator
int gcd(int number, int denom) {
    
    if (denom == 0)
    return number;

    return gcd(denom, number % denom); //divide number by denom to make smaller number
}
//function that takes the greatest common denominator
//and reduces it to the lowest term
double reduce(int c, int de) {
    
    double g;
    double n, d;
    g = gcd(c, de); // calling the greatest common denom function
                    // and assigning it to g

    n = (c / g); // dividing the numerator by the gcd

    d = (de / g); // dividing the denominator by the gcd

    return n, d;

}

