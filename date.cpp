#include <iostream>
#include <string>
#pragma once
using namespace std;

class date {
    public:
    int day,month,year;
    
    date(int m, int d, int y) {
        month = m;
        day = d;
        year = y;
    }

    void print() {
        printf("%d/%d/%d\n", month, day, year);
    }
};

bool older(date a, date b) {
    if (a.year < b.year) {
        return true;
    } else if (a.month < b.month) {
        return true;
    } else if (a.day < b.day) {
        return true;
    } else {
        return false;
    }
}