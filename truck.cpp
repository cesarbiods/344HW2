#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "food.cpp"
using namespace std;



class truck {

    public:
    
    priority_queue<shrimp, vector<shrimp>, compare1> sh;
    priority_queue<lobster, vector<lobster>, compare2> lo;
    priority_queue<crab, vector<crab>, compare3> cr;
    priority_queue<swordfish, vector<swordfish>, compare4> sw;

    void addShrimp(shrimp s) {
        sh.push(s);
    }
    void addLobster(lobster l) {
        lo.push(l);
    }
    void addCrab(crab c) {
        cr.push(c);
    }
    void addSwordfish(swordfish s) {
        sw.push(s);
    }

    void rmShrimp() {
        sh.pop();
    }
    void rmLobster() {
        lo.pop();
    }
    void rmCrab() {
        cr.pop();
    }
    void rmSwordfish() {
        sw.pop();
    }

    void printShrimp(priority_queue<shrimp, vector<shrimp>, compare1> sh) {
        printf("Shrimp: ");
        while (!sh.empty()) {
            shrimp largest = sh.top();
            sh.pop();
            char s;
            if (largest.open) {
                s = 'o';
            } else {
                s = 'c';
            }
            string line = largest.expirationDate->print() + ":" + to_string(largest.num) + ":" + s;
            cout << line << (!sh.empty() ? ", " : "");
        }
        cout << endl;
    }

    void printLobster(priority_queue<lobster, vector<lobster>, compare2> lo) {
        printf("Lobster: ");
        while (!lo.empty()) {
            lobster largest = lo.top();
            lo.pop();
            char s;
            if (largest.open) {
                s = 'o';
            } else {
                s = 'c';
            }
            string line = largest.expirationDate->print() + ":" + to_string(largest.num) + ":" + s;
            cout << line << (!lo.empty() ? ", " : "");
        }
        cout << endl;
    }

    void printCrab(priority_queue<crab, vector<crab>, compare3> sh) {
        printf("Crab: ");
        while (!sh.empty()) {
            crab largest = sh.top();
            sh.pop();
            char s;
            if (largest.open) {
                s = 'o';
            } else {
                s = 'c';
            }
            string line = largest.expirationDate->print() + ":" + to_string(largest.num) + ":" + s;
            cout << line << (!sh.empty() ? ", " : "");
        }
        cout << endl;
    }

    void printSwordfish(priority_queue<swordfish, vector<swordfish>, compare4> sh){
        printf("Swordfish: ");
        while (!sh.empty()) {
            swordfish largest = sh.top();
            sh.pop();
            char s;
            if (largest.open) {
                s = 'o';
            } else {
                s = 'c';
            }
            string line = largest.expirationDate->print() + ":" + to_string(largest.num) + ":" + s;
            cout << line << (!sh.empty() ? ", " : "");
        }
        cout << endl;
    }
    
};