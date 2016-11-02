#include <iostream>
#include <string>
#include "date.h"
#pragma once
using namespace std;

    date::date(int m, int d, int y) {
        month = m;
        day = d;
        year = y;
    }

    void date::print() {
        printf("%d/%d/%d\n", month, day, year);
    }

bool older(date* const a, date* const b) {
    if (a->year < b->year) {
        return true;
    } else if (a->month < b->month) {
        return true;
    } else if (a->day < b->day) {
        return true;
    } else {
        return false;
    }
}