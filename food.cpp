#include <iostream>
#include <string>
#include "date.h"
#pragma once
using namespace std;

class box {
    
    public:
    bool open;
    date* expirationDate;
    int num;
    
    box(date e, int n) {
        expirationDate = &e;
        num = n;
    }

    void updateNum(int a) {
        num = a;
    }

    friend bool operator <(const box& a, const box& b) {
        return older(a.expirationDate, b.expirationDate);
    }
};

class shrimp:public box {
    public:
    shrimp(date e, int n): box(e, n) {}

    void updateNum(int a) {
        num = a;
    }

    friend bool operator <(const shrimp& a, const shrimp& b) {
        return older(a.expirationDate, b.expirationDate);
    }
};

class lobster:public box {
    public:
    lobster(date e, int n): box(e, n) {}

    void updateNum(int a) {
        num = a;
    }

    friend bool operator <(const lobster& a, const lobster& b) {
        return older(a.expirationDate, b.expirationDate);
    }
};

class crab:public box {
    public:
    crab(date e, int n): box(e, n) {}

    void updateNum(int a) {
        num = a;
    }

    friend bool operator <(const crab& a, const crab& b) {
        return older(a.expirationDate, b.expirationDate);
    }
};

class swordfish:public box {
    public:
    swordfish(date e, int n): box(e, n) {}

    void updateNum(int a) {
        num = a;
    }
    
    friend bool operator <(const swordfish& a, const swordfish& b) {
        return older(a.expirationDate, b.expirationDate);
    }
};