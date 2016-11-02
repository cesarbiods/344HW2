#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include "date.cpp"
#include "food.cpp"
#include "truck.cpp"

using namespace std;

int main() {
    truck t;

    cout << "Enter your command: ";
    string command;
    string rawDate;
    string type;
    int count;
       
    do {
        cin >> command;
        cin >> rawDate;
        cin >> type;
        cin >> count;

        //got this spliter from http://stackoverflow.com/questions/28545031/take-input-of-date-in-format-mm-dd-yyyy-and-split-into-3-separate-variables
        string delimiter = "/"; 
        int month,day,year;
        auto start = rawDate.begin(); // iterator at beginning of string
        auto finish = rawDate.find(delimiter); // gives position of first occurrence of delimiter
        if (finish == rawDate.npos) {
            // delimiter does not exist in string.
        } else {
            month = stoi(rawDate.substr(0, finish)); // Extracts month part from date string
            rawDate = rawDate.substr(finish+1);
            day = stoi(rawDate.substr(0, finish)); // Extracts day part from date string
            rawDate = rawDate.substr(finish+1);
            year = stoi(rawDate.substr(0, finish)); // Extracts year part from date string
            rawDate = rawDate.substr(finish+1);
        }
        cout << month;
        cout << day;
        cout << year;

        if (command == "stock") {

        } else if (command == "buy") {

        }
    } while (command != "quit");

    return 0;
}