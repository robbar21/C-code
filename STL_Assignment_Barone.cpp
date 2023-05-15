// STL_Assignment_Barone.cpp
// Name: Roberto Barone
// Date: 4/25/23
// Class: CIT-245
// Assignment: STL Assignment
//

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // Create a map to store social security numbers by names
    map<string, string> ssnByName;
    ssnByName["Joe Michaels"] = "135-45-6823";
    ssnByName["Eli Ruth"] = "199-35-3661";
    ssnByName["Jake Farm"] = "122-48-6788";
    ssnByName["Janice Jasmine"] = "170-90-9214";

    // Iterate through the container and retrieve all names
    cout << "Person " << ssnByName["Joe Michaels"] << ": Joe Michaels" << endl;
    cout << "Person " << ssnByName["Eli Ruth"] << ": Eli Ruth" << endl;
    cout << "Person " << ssnByName["Jake Farm"] << ": Jake Farm" << endl;
    cout << "Person " << ssnByName["Janice Jasmine"] << ": Janice Jasmine" << endl;

    // Iterate through the container and retrieve all names
    cout << "\nIterating through list..." << endl;
    for (auto iter = ssnByName.begin(); iter != ssnByName.end(); ++iter) {
        cout << iter->second << ": " << iter->first << endl;
    }

    // Search for an individual name and print the ssn
    string nameToSearch = "Janice Jasmine";
    auto searchResult = ssnByName.find(nameToSearch);
    if (searchResult != ssnByName.end()) {
        cout << "\n" << nameToSearch << " found " << searchResult->second << endl;
    }
    else {
        cout << "\n" << nameToSearch << " not found" << endl;
    }

    // Search for a name that is not found
    nameToSearch = "Ralph Hawkwood";
    searchResult = ssnByName.find(nameToSearch);
    if (searchResult != ssnByName.end()) {
        cout << "\n" << nameToSearch << " found " << searchResult->second << endl;
    }
    else {
        cout << "\n" << nameToSearch << " not found" << endl;
    }

    return 0;
}

