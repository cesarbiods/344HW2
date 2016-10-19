#include <iostream>
#include <string>
#include "date.cpp"
#pragma once
using namespace std;

class box {
    private:
    bool open;
    date* expirationDate;
    int num;
    
    public:
    box(date e, int n) {
        expirationDate = &e;
        num = n;
    }
};

class shrimp:public box {
    public:
    shrimp(date e, int n);
};

class lobster:public box {
    public:
    lobster(date e, int n);
};

class crab:public box {
    public:
    crab(date e, int n);
};

class swordfish:public box {
    public:
    swordfish(date e, int n);
};