#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "food.cpp"
using namespace std;

//class compare {
    //public:
    //bool operator()(const box& a, const box& b) {
        //return older(a.expirationDate, b.expirationDate);
    //}
//};

class truck {
    priority_queue<box> pq;

    public:
    void addBox(box b) {
        pq.push(b);
    }

    void rmBox() {
        //pq.pop();
    }

    int openBox(string n) {
        //TODO check whether a box is an instance of X and it its open
        return 0;
    }
};