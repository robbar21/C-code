// Chapter_8_Barone_Homework.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Name: Roberto Barone
// Date: 2/23/23
// Class: CIT-245
// Assignment: Chapter 8 Homework
//

#include <iostream>
#include <cstdlib>

using namespace std;

class Money {

public:
    Money();
    Money(double amount);
    Money(int theDollars, int theCents);
    Money(int theDollars);
    double getPercent() const;
    double getAmount() const;
    int getDollars() const;
    int getCents() const;
    void input();
    void output() const;
    friend const Money operator + (const Money& amount1, const Money& amount2);
    friend const Money operator - (const Money& amount1, const Money& amount2);
    friend bool operator ==(const Money& amount1, const Money& amount2);
    friend bool operator >(const Money& amount1, const Money& amount2);
    friend bool operator <(const Money& amount1, const Money& amount2);
    friend const Money operator - (const Money& amount);

private:
    int dollars;
    int cents;
    int dollarsPart(double amount) const;
    int centsPart(double amount) const;
    int round(double number) const;
};

const Money operator +(const Money& amount1, const Money& amount2);
const Money operator -(const Money& amount1, const Money& amount2);
const Money operator -(const Money& amount);

bool operator ==(const Money& amount1, const Money& amount2);



int main()
{
    Money yourAmount, myAmount(23, 19);
    cout << "Enter an amount of money: ";
    yourAmount.input();
    cout << "Your amount is ";
    yourAmount.output();
    cout << endl;
    cout << "My amount is ";
    myAmount.output();
    cout << endl;

    if (yourAmount == myAmount) {
        cout << "We have the same amounts." << endl;
    }else{
        cout << "One of us is richer." << endl;
    }

    if (yourAmount > myAmount) {
        cout << "You have more money than me." << endl;
    }
    else {
        cout << "I have more money than you." << endl;
    }

    cout << "10% of your money is: $" << yourAmount.getPercent() << endl;

    Money ourAmount = yourAmount + myAmount;
    yourAmount.output(); cout << " + "; myAmount.output();
    cout << " equals "; ourAmount.output(); cout << endl;

    Money diffAmount = yourAmount - myAmount;
    yourAmount.output(); cout << " - "; myAmount.output();
    cout << " equals "; diffAmount.output(); cout << endl;

    return 0;
}

const Money operator +(const Money& amount1, const Money& amount2) {

    int allCents1 = amount1.getCents() + amount1.getDollars() * 100;
    int allCents2 = amount2.getCents() + amount2.getDollars() * 100;
    int sumAllCents = allCents1 + allCents2;
    int absAllCents = abs(sumAllCents);
    int finalDollars = absAllCents / 100;
    int finalCents = absAllCents % 100;

    if (sumAllCents < 0) {
        finalDollars = -finalDollars;
        finalCents = -finalCents;
    }

    return Money(finalDollars, finalCents);
}

const Money operator -(const Money& amount1, const Money& amount2){

    int allCents1 = amount1.getCents() + amount1.getDollars() * 100;
    int allCents2 = amount2.getCents() + amount2.getDollars() * 100;
    int diffAllCents = allCents1 - allCents2;
    int absAllCents = abs(diffAllCents);
    int finalDollars = absAllCents / 100;
    int finalCents = absAllCents % 100;

    if (diffAllCents < 0) {
        finalDollars = -finalDollars;
        finalCents = -finalCents;
    }

    return Money(finalDollars, finalCents);
}

const Money operator - (const Money& amount) {
    return Money(-amount.dollars, -amount.cents);
}

bool operator ==(const Money& amount1, const Money& amount2) {
    return ((amount1.getDollars() == amount2.getDollars())
        && (amount1.getCents() == amount2.getCents()));
}

bool operator >(const Money& amount1, const Money& amount2) {
    return ((amount1.getDollars() > amount2.getDollars())
        && (amount1.getCents() > amount2.getCents()));
}

bool operator <(const Money& amount1, const Money& amount2) {
    return ((amount1.getDollars() < amount2.getDollars())
        && (amount1.getCents() < amount2.getCents()));
}

Money::Money() : dollars(0), cents(0) {
    //default
}

Money::Money(double amount)
    : dollars(dollarsPart(amount)), cents(centsPart(amount))
{//empty
}

Money::Money(int theDollars, int theCents){

    if ((theDollars < 0 && theCents > 0) ||
        (theDollars > 0 && theCents < 0)) {
        cout << "Inconsistent money data." << endl;
        exit(1);
    }
    dollars = theDollars;
    cents = theCents;
}

Money::Money(int theDollars)
    : dollars(theDollars), cents(0)
{
}

double Money::getPercent() const
{
    return ((dollars + cents) * 0.10);
}

double Money::getAmount() const
{
    return (dollars + cents * 0.01);
}

int Money::getDollars() const
{
    return dollars;
}

int Money::getCents() const
{
    return cents;
}

void Money::input()
{
    char dollarSign;
    cin >> dollarSign;
    if (dollarSign != '$') {
        cout << "No dollar sign in money input." << endl;
        exit(1);
    }

    double amountAsDouble;
    cin >> amountAsDouble;
    dollars = dollarsPart(amountAsDouble);
    cents = centsPart(amountAsDouble);
}

void Money::output() const
{
    int absDollars = abs(dollars);
    int absCents = abs(cents);
    
    if (dollars < 0 || cents < 0) {
        cout << "$-";
    }
    else {
        cout << '$';
        cout << absDollars;
    }
    if (absCents >= 10) {
        cout << '.' << absCents;
    }
    else {
        cout << '.' << '0' << absCents;
    }
}

int Money::dollarsPart(double amount) const {
    return static_cast<int>(amount);
}

int Money::centsPart(double amount) const {
    return static_cast<int>(amount);
}

int Money::round(double number) const {
    return static_cast<int>(floor(number + 0.5));
}