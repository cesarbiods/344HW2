#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include "date.cpp"
#include "food.cpp"
#include "truck.cpp"

using namespace std;

//found this algorythm in http://stackoverflow.com/questions/236129/split-a-string-in-c?page=1&tab=votes#tab-top
void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

int main() {
    truck t;

    cout << "Enter your command: ";
    string input;
    cin >> input;
    vector<string> line;                //initialize a vector of strings for every line of input
    split(input, ' ', line);            //split the user input by spaces and add it to the vector
    for (int i=0; i < line.size(); i++) {
        cout << line[i] << ' ';
    }
    
    //while(line[0] != "quit") {
        if (line[0] == "stock") {

        } else if (line[0] == "buy") {

        }
    //}

    return 0;
}