// Chapter_16_Barone_Homework.cpp 
// Name: Roberto Barone
// Date: 4/12/23
// Class: CIT-245
// Assignment: Chapter 16 Homework
//

#include <iostream>
#include <string>
using namespace std;

template <typename T>
int binary_search(T arr[], int size, T value)
{
    int left = 0;
    int right = size - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (arr[middle] == value)
            return middle;
        else if (arr[middle] > value)
            right = middle - 1;
        else
            left = middle + 1;
    }
    return -1;
}

int main()
{
    int int_arr[] = { 0, 1, 1, 2, 3, 5, 6, 13, 21, 32, 55 };
    int int_size = sizeof(int_arr) / sizeof(int);
    int int_search[] = { -1, 0, 1, 2, 3, 4, 5, 6, 7 };

    cout << "Integer test array contains:" << endl;
    for (int i = 0; i < int_size; i++)
        cout << int_arr[i] << " ";
    cout << endl;
    for (int i = 0; i < sizeof(int_search) / sizeof(int); i++)
    {
        int result = binary_search(int_arr, int_size, int_search[i]);
        if (result == -1)
            cout << int_search[i] << " is not in the array." << endl;
        else
            cout << int_search[i] << " is at index " << result << endl;
    }

    string string_arr[] = { "head", "knees", "shoulders", "toes" };
    int string_size = sizeof(string_arr) / sizeof(string);
    string string_search[] = { "elbows", "knees" };
    cout << "String test array contains:" << endl;
    for (int i = 0; i < string_size; i++)
        cout << string_arr[i] << " ";
    cout << endl;
    for (int i = 0; i < sizeof(string_search) / sizeof(string); i++)
    {
        int result = binary_search(string_arr, string_size, string_search[i]);
        if (result == -1)
            cout << string_search[i] << " is not in the array." << endl;
        else
            cout << string_search[i] << " is at index " << result << endl;
    }
    return 0;
}


