// Chapter_9_Barone_Homework.cpp
// Name: Roberto Barone
// Date: 3/1/23
// Class: CIT-245
// Assignment: Chapter 9 Homework
//

#include <iostream>
#include <cstdlib>
#include <stack>
#include <string>

using namespace std;

void newLine();//Discards all the input remaining on the line

void reverseChar(string& str)//converts the string the user input, into reverse order using stack
{
    stack<int> stk;

    for (char ch : str) stk.push(ch);

    for (int i = 0; i < str.length(); i++) {
        str[i] = stk.top();
        stk.pop();
    }
}

char* s = (char*)malloc(81);

int main()
{
    
    char ans; // variable to allow user to repeat the program
    do {

        cout << "This program reverses a string using the STL stack"
            << endl;
        cout << "Enter your string of less than 80 characters followed by an ENTER"
            << endl;
        cin.getline(s, 81, '\n');

        cout << "Original string: " << s << endl;

        string str = s;
        reverseChar(str);
        cout << "Reversed String: " << str << endl;
        
        cout << "Enter y to repeat the program, any other letter to leave."
            << endl;
        cin >> ans;

        newLine();
        char symbol;
        cin.get(symbol);

    } while (ans == 'y' || ans == 'Y');

    return 0;
}

void newLine()
{
    char symbol;
    do {
        cin.get(symbol);
    } while (symbol != '\n');
}
