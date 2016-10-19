#include <iostream>
#include <string>
#include <vector>
#include "food.cpp"
#pragma once
using namespace std;

class truck {
    private:
    truck() {
        std::vector<box> stockpile;
    }

    void addBox(box b) {
        stockpile.push_back(b);
    }

    void rmBox(int i) {
        stockpile.erase(stockpile.begin() + i);
    }

    int openBox() {
        //TODO check whether a box is an instance of X and it its open
    }
};