#include <iostream>
#include <string>
#include "date.h"
#pragma once
using namespace std;
enum type {SHRIMP = 0, LOBSTER, CRAB, SWORDFISH};

class box {
    
    public:
    bool open;
    date* expirationDate;
    int num;
    
    box(date e, int n) {
        expirationDate = &e;
        num = n;
    }
    virtual int getType() = 0;
    friend bool operator <(const box& a, const box& b) {
        return older(a.expirationDate, b.expirationDate);
    }
};

class shrimp:public box {
    public:
    shrimp(date e, int n): box(e, n) {}
    int getType() {return SHRIMP;}
};

class lobster:public box {
    public:
    lobster(date e, int n): box(e, n) {}
    int getType() {return LOBSTER;}
};

class crab:public box {
    public:
    crab(date e, int n): box(e, n) {}
    int getType() {return CRAB;}
};

class swordfish:public box {
    public:
    swordfish(date e, int n): box(e, n) {}
    int getType() {return SWORDFISH;}
};