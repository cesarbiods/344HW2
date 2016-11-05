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
        if (command == "quit") {
            break;
        }
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
                while (!t.sh.empty()) {
                if (t.sh.top().open) {                      //if box is open carry out as usual
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
                        if (count <= (((t.sh.size() - 1) * 50) + t.sh.top().num)) {
                            while (count > 0) {
                                if (count < t.sh.top().num) {
                                    int remain = t.sh.top().num - count;
                                    shrimp temp = t.sh.top();
                                    t.rmShrimp();
                                    temp.updateNum(remain);
                                    t.addShrimp(temp);
                                    count = 0;
                                    if (count == 0) {
                                        break;
                                    }
                                } else if (count == t.sh.top().num) {
                                    t.rmShrimp();
                                    count -= 50;
                                    if (count == 0) {
                                        break;
                                    }
                                } else {
                                    count -= t.sh.top().num;
                                    t.rmShrimp();
                                }
                            }
                            printf("Selling some product from stockpile\n");
                            t.printShrimp(t.sh);
                        } else {
                            printf("Insufficient inventory, please try again another time\n");
                        }
                    }
                } else {                                    //if not then open the top box and then carry out transcation
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
                        if (count <= (((t.sh.size() - 1) * 50) + t.sh.top().num)) {
                            while (count > 0) {
                                if (count < t.sh.top().num) {
                                    int remain = t.sh.top().num - count;
                                    shrimp temp = t.sh.top();
                                    t.rmShrimp();
                                    temp.updateNum(remain);
                                    temp.open = true;
                                    t.addShrimp(temp);
                                    count = 0;
                                    if (count == 0) {
                                        break;
                                    }
                                } else if (count == t.sh.top().num) {
                                    t.rmShrimp();
                                    count -= 50;
                                    if (count == 0) {
                                        break;
                                    }
                                } else {
                                    count -= t.sh.top().num;
                                    t.rmShrimp();
                                }
                            }
                            printf("Selling some product from stockpile\n");
                            t.printShrimp(t.sh);
                        } else {
                            printf("Insufficient inventory, please try again another time\n");
                        }
                    }
                }
                }
                
            } else if (type == "lobster") {
                if (t.lo.top().open) {
                    if (count < t.lo.top().num) {           //if box is open carry out as usual
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
                        if (count <= (((t.lo.size() - 1) * 4) + t.lo.top().num)) {
                            while (count > 0) {
                                if (count < t.lo.top().num) {
                                    int remain = t.lo.top().num - count;
                                    lobster temp = t.lo.top();
                                    t.rmLobster();
                                    temp.updateNum(remain);
                                    t.addLobster(temp);
                                    count = 0;
                                    if (count == 0) {
                                        break;
                                    }
                                } else if (count == t.lo.top().num) {
                                    t.rmLobster();
                                    count -= 4;
                                    if (count == 0) {
                                        break;
                                    }
                                } else {
                                    count -= t.lo.top().num;
                                    t.rmLobster();
                                }
                            }
                            printf("Selling some product from stockpile\n");
                            t.printLobster(t.lo);
                        } else {
                            printf("Insufficient inventory, please try again another time\n");
                        }
                    }
                } else {                                    //if not then open the top box and then carry out transcation
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
                        if (count <= (((t.lo.size() - 1) * 4) + t.lo.top().num)) {
                            while (count > 0) {
                                if (count < t.lo.top().num) {
                                    int remain = t.lo.top().num - count;
                                    lobster temp = t.lo.top();
                                    t.rmLobster();
                                    temp.updateNum(remain);
                                    temp.open = true;
                                    t.addLobster(temp);
                                    count = 0;
                                    if (count == 0) {
                                        break;
                                    }
                                } else if (count == t.lo.top().num) {
                                    t.rmLobster();
                                    count -= 4;
                                    if (count == 0) {
                                        break;
                                    }
                                } else {
                                    count -= t.lo.top().num;
                                    t.rmLobster();
                                }
                            }
                            printf("Selling some product from stockpile\n");
                            t.printLobster(t.lo);
                        } else {
                            printf("Insufficient inventory, please try again another time\n");
                        }
                    }
                }
            } else if (type == "crab") {
                if (t.cr.top().open) {                              //if box is open carry out as usual
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
                        if (count <= (((t.cr.size() - 1) * 6) + t.cr.top().num)) {
                            while (count > 0) {
                                if (count < t.cr.top().num) {
                                    int remain = t.cr.top().num - count;
                                    crab temp = t.cr.top();
                                    t.rmCrab();
                                    temp.updateNum(remain);
                                    t.addCrab(temp);
                                    count = 0;
                                    if (count == 0) {
                                        break;
                                    }
                                } else if (count == t.cr.top().num) {
                                    t.rmCrab();
                                    count -= 6;
                                    if (count == 0) {
                                        break;
                                    }
                                } else {
                                    count -= t.cr.top().num;
                                    t.rmCrab();
                                }
                            }
                            printf("Selling some product from stockpile\n");
                            t.printCrab(t.cr);
                        } else {
                            printf("Insufficient inventory, please try again another time\n");
                        }
                    }
                } else {                                            //if not then open the top box and then carry out transcation
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
                        if (count <= (((t.cr.size() - 1) * 6) + t.cr.top().num)) {
                            while (count > 0) {
                                if (count < t.cr.top().num) {
                                    int remain = t.cr.top().num - count;
                                    crab temp = t.cr.top();
                                    t.rmCrab();
                                    temp.updateNum(remain);
                                    temp.open = true;
                                    t.addCrab(temp);
                                    count = 0;
                                    if (count == 0) {
                                        break;
                                    }
                                } else if (count == t.cr.top().num) {
                                    t.rmCrab();
                                    count -= 6;
                                    if (count == 0) {
                                        break;
                                    }
                                } else {
                                    count -= t.cr.top().num;
                                    t.rmCrab();
                                }
                            }
                            printf("Selling some product from stockpile\n");
                            t.printCrab(t.cr);
                        } else {
                            printf("Insufficient inventory, please try again another time\n");
                        }
                    }
                }
            } else if (type == "swordfish") {
                if (t.sw.top().open) {                                  //if box is open carry out as usual
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
                        if (count <= (((t.sw.size() - 1) * 8) + t.sw.top().num)) {
                            while (count > 0) {
                                if (count < t.sw.top().num) {
                                    int remain = t.sw.top().num - count;
                                    swordfish temp = t.sw.top();
                                    t.rmSwordfish();
                                    temp.updateNum(remain);
                                    t.addSwordfish(temp);
                                    count = 0;
                                    if (count == 0) {
                                        break;
                                    }
                                } else if (count == t.sw.top().num) {
                                    t.rmSwordfish();
                                    count -= 8;
                                    if (count == 0) {
                                        break;
                                    }
                                } else {
                                    count -= t.sw.top().num;
                                    t.rmSwordfish();
                                }
                            }
                            printf("Selling some product from stockpile\n");
                            t.printSwordfish(t.sw);
                        } else {
                            printf("Insufficient inventory, please try again another time\n");
                        }
                    }
                } else {                                                //if not then open the top box and then carry out transcation
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
                        if (count <= (((t.sw.size() - 1) * 8) + t.sw.top().num)) {
                            while (count > 0) {
                                if (count < t.sw.top().num) {
                                    int remain = t.sw.top().num - count;
                                    swordfish temp = t.sw.top();
                                    t.rmSwordfish();
                                    temp.updateNum(remain);
                                    temp.open = true;
                                    t.addSwordfish(temp);
                                    count = 0;
                                    if (count == 0) {
                                        break;
                                    }
                                } else if (count == t.sw.top().num) {
                                    t.rmSwordfish();
                                    count -= 8;
                                    if (count == 0) {
                                        break;
                                    }
                                } else {
                                    count -= t.sw.top().num;
                                    t.rmSwordfish();
                                }
                            }
                            printf("Selling some product from stockpile\n");
                            t.printSwordfish(t.sw);
                        } else {
                            printf("Insufficient inventory, please try again another time\n");
                        }
                    }
                }
            }
        }
    } while (command != "quit");

    return 0;
}