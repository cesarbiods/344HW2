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
        date* dat1 = new date(month, day, year);

        if (command == "stock") {
            if (type == "shrimp") {
                while (count > 0) {
                    t.addShrimp(shrimp(dat1, 50));
                    count--;
                }
                printf("Adding seafood to stockpile\n");
                t.printShrimp(t.sh);
            } else if (type == "lobster") {
                while (count > 0) {
                    t.addLobster(lobster(dat1, 4));
                    count--;
                }
                printf("Adding seafood to stockpile\n");
                t.printLobster(t.lo);
            } else if (type == "crab") {
                while (count > 0) {
                    t.addCrab(crab(dat1, 6));
                    count--;
                }
                printf("Adding seafood to stockpile\n");
                t.printCrab(t.cr);
            } else if (type == "swordfish") {
                while (count > 0) {
                    t.addSwordfish(swordfish(dat1, 8));
                    count--;
                }
                printf("Adding seafood to stockpile\n");
                t.printSwordfish(t.sw);
            }
        } else if (command == "buy") {
            if (type == "shrimp") {
                if (t.sh.top().open) {
                    if (count < t.sh.top().num) {
                        printf("Selling some product from stockpile\n");
                        shrimp temp = t.sh.top();
                        t.rmShrimp();
                        temp.updateNum(temp.num - count);
                        t.addShrimp(temp);
                        t.printShrimp(t.sh);
                    } else if (count == t.sh.top().num) {
                        printf("Selling some product from stockpile\n");
                        t.rmShrimp();
                        t.printShrimp(t.sh);
                    } else {

                    }
                } else {
                    shrimp temp = t.sh.top();
                    t.rmShrimp();
                    temp.open = true;
                    t.addShrimp(temp);
                    if (count < t.sh.top().num) {
                        printf("Selling some product from stockpile\n");
                        shrimp temp = t.sh.top();
                        t.rmShrimp();
                        temp.updateNum(temp.num - count);
                        t.addShrimp(temp);
                        t.printShrimp(t.sh);
                    } else if (count == t.sh.top().num) {
                        printf("Selling some product from stockpile\n");
                        t.rmShrimp();
                        t.printShrimp(t.sh);
                    } else {

                    }
                }
                
            } else if (type == "lobster") {
                if (t.lo.top().open) {
                    if (count < t.lo.top().num) {
                        printf("Selling some product from stockpile\n");
                        lobster temp = t.lo.top();
                        t.rmLobster();
                        temp.updateNum(temp.num - count);
                        t.addLobster(temp);
                        t.printLobster(t.lo);
                    } else if (count == t.lo.top().num) {
                        printf("Selling some product from stockpile\n");
                        t.rmLobster();
                        t.printLobster(t.lo);
                    } else {

                    }
                } else {
                    lobster temp = t.lo.top();
                    t.rmLobster();
                    temp.open = true;
                    t.addLobster(temp);
                    if (count < t.lo.top().num) {
                        printf("Selling some product from stockpile\n");
                        lobster temp = t.lo.top();
                        t.rmLobster();
                        temp.updateNum(temp.num - count);
                        t.addLobster(temp);
                        t.printLobster(t.lo);
                    } else if (count == t.lo.top().num) {
                        printf("Selling some product from stockpile\n");
                        t.rmLobster();
                        t.printLobster(t.lo);
                    } else {

                    }
                }
            } else if (type == "crab") {
                if (t.cr.top().open) {
                    if (count < t.cr.top().num) {
                        printf("Selling some product from stockpile\n");
                        crab temp = t.cr.top();
                        t.rmCrab();
                        temp.updateNum(temp.num - count);
                        t.addCrab(temp);
                        t.printCrab(t.cr);
                    } else if (count == t.cr.top().num) {
                        printf("Selling some product from stockpile\n");
                        t.rmCrab();
                        t.printCrab(t.cr);
                    } else {

                    }
                } else {
                    crab temp = t.cr.top();
                    t.rmCrab();
                    temp.open = true;
                    t.addCrab(temp);
                    if (count < t.cr.top().num) {
                        printf("Selling some product from stockpile\n");
                        crab temp = t.cr.top();
                        t.rmCrab();
                        temp.updateNum(temp.num - count);
                        t.addCrab(temp);
                        t.printCrab(t.cr);
                    } else if (count == t.cr.top().num) {
                        printf("Selling some product from stockpile\n");
                        t.rmCrab();
                        t.printCrab(t.cr);
                    } else {

                    }
                }
            } else if (type == "swordfish") {
                if (t.sw.top().open) {
                    if (count < t.sw.top().num) {
                        printf("Selling some product from stockpile\n");
                        swordfish temp = t.sw.top();
                        t.rmSwordfish();
                        temp.updateNum(temp.num - count);
                        t.addSwordfish(temp);
                        t.printSwordfish(t.sw);
                    } else if (count == t.sw.top().num) {
                        printf("Selling some product from stockpile\n");
                        t.rmSwordfish();
                        t.printSwordfish(t.sw);
                    } else {

                    }
                } else {
                    swordfish temp = t.sw.top();
                    t.rmSwordfish();
                    temp.open = true;
                    t.addSwordfish(temp);
                    if (count < t.sw.top().num) {
                        printf("Selling some product from stockpile\n");
                        swordfish temp = t.sw.top();
                        t.rmSwordfish();
                        temp.updateNum(temp.num - count);
                        t.addSwordfish(temp);
                        t.printSwordfish(t.sw);
                    } else if (count == t.sw.top().num) {
                        printf("Selling some product from stockpile\n");
                        t.rmSwordfish();
                        t.printSwordfish(t.sw);
                    } else {

                    }
                }
            }
        }
    } while (command != "quit");

    return 0;
}