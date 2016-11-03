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
    bool backOrder;
       
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
            year = stoi(rawDate.substr(0, 4)); // Extracts year part from date string
            rawDate = rawDate.substr(finish+1);
        }
        date date(month, day, year);

        if (command == "stock") {
            if (type == "shrimp") {
                while (count > 0) {
                    t.addShrimp(shrimp(date, 50));
                    count--;
                }
            } else if (type == "lobster") {
                while (count > 0) {
                    t.addLobster(lobster(date, 4));
                    count--;
                }
            } else if (type == "crab") {
                while (count > 0) {
                    t.addCrab(crab(date, 6));
                    count--;
                }
            } else if (type == "swordfish") {
                while (count > 0) {
                    t.addSwordfish(swordfish(date, 8));
                    count--;
                }
            }
        } else if (command == "buy") {
            if (type == "shrimp") {
                if (t.sh.top().open) {
                    if (count < t.sh.top().num) {
                        shrimp temp = t.sh.top();
                        t.rmShrimp();
                        temp.updateNum(temp.num - count);
                        t.addShrimp(temp);
                    } else if (count == t.sh.top().num) {
                        t.rmShrimp();
                    }
                } else {
                    shrimp temp = t.sh.top();
                    t.rmShrimp();
                    temp.open = true;
                    t.addShrimp(temp);
                    if (count < t.sh.top().num) {
                        shrimp temp = t.sh.top();
                        t.rmShrimp();
                        temp.updateNum(temp.num - count);
                        t.addShrimp(temp);
                    } else if (count == t.sh.top().num) {
                        t.rmShrimp();
                    }
                }
                
            } else if (type == "lobster") {
                if (t.lo.top().open) {
                    if (count < t.lo.top().num) {
                        lobster temp = t.lo.top();
                        t.rmLobster();
                        temp.updateNum(temp.num - count);
                        t.addLobster(temp);
                    } else if (count == t.lo.top().num) {
                        t.rmLobster();
                    }
                } else {
                    lobster temp = t.lo.top();
                    t.rmLobster();
                    temp.open = true;
                    t.addLobster(temp);
                    if (count < t.lo.top().num) {
                        lobster temp = t.lo.top();
                        t.rmLobster();
                        temp.updateNum(temp.num - count);
                        t.addLobster(temp);
                    } else if (count == t.lo.top().num) {
                        t.rmLobster();
                    }
                }
            } else if (type == "crab") {
                if (t.cr.top().open) {
                    if (count < t.cr.top().num) {
                        crab temp = t.cr.top();
                        t.rmCrab();
                        temp.updateNum(temp.num - count);
                        t.addCrab(temp);
                    } else if (count == t.cr.top().num) {
                        t.rmCrab();
                    }
                } else {
                    crab temp = t.cr.top();
                    t.rmCrab();
                    temp.open = true;
                    t.addCrab(temp);
                    if (count < t.cr.top().num) {
                        crab temp = t.cr.top();
                        t.rmCrab();
                        temp.updateNum(temp.num - count);
                        t.addCrab(temp);
                    } else if (count == t.cr.top().num) {
                        t.rmCrab();
                    }
                }
            } else if (type == "swordfish") {
                if (t.sw.top().open) {
                    if (count < t.sw.top().num) {
                        swordfish temp = t.sw.top();
                        t.rmSwordfish();
                        temp.updateNum(temp.num - count);
                        t.addSwordfish(temp);
                    } else if (count == t.sw.top().num) {
                        t.rmSwordfish();
                    }
                } else {
                    swordfish temp = t.sw.top();
                    t.rmSwordfish();
                    temp.open = true;
                    t.addSwordfish(temp);
                    if (count < t.sw.top().num) {
                        swordfish temp = t.sw.top();
                        t.rmSwordfish();
                        temp.updateNum(temp.num - count);
                        t.addSwordfish(temp);
                    } else if (count == t.sw.top().num) {
                        t.rmSwordfish();
                    }
                }
            }
        }
    } while (command != "quit");

    return 0;
}