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

    box(date* e, int n) {
        expirationDate = e;
        num = n;
    }

    void updateNum(int a) {
        num = a;
    }
};

class shrimp:public box {
    public:
    shrimp(date* e, int n): box(e, n) {}

    void updateNum(int a) {
        num = a;
    }
};

struct compare1 {
    bool operator()(shrimp a, shrimp b) { 
        if (a.open) {
            return false; 
        } else if (!a.open && b.open) {
            return true;
        } else {
            return older(a.expirationDate, b.expirationDate);
        }
    }
};

class lobster:public box {
    public:
    lobster(date* e, int n): box(e, n) {}

    void updateNum(int a) {
        num = a;
    }
};

struct compare2 {
    bool operator()(lobster a, lobster b) { 
        if (a.open) {
            return false; 
        } else if (!a.open && b.open) {
            return true;
        } else {
            return older(a.expirationDate, b.expirationDate);
        }
    }
};

class crab:public box {
    public:
    crab(date* e, int n): box(e, n) {}

    void updateNum(int a) {
        num = a;
    }
};

struct compare3 {
    bool operator()(crab a, crab b) { 
        if (a.open) {
            return false; 
        } else if (!a.open && b.open) {
            return true;
        } else {
            return older(a.expirationDate, b.expirationDate);
        }
    }
};

class swordfish:public box {
    public:
    swordfish(date* e, int n): box(e, n) {}

    void updateNum(int a) {
        num = a;
    }
};

struct compare4 {
    bool operator()(swordfish a, swordfish b) { 
        if (a.open) {
            return false; 
        } else if (!a.open && b.open) {
            return true;
        } else {
            return older(a.expirationDate, b.expirationDate);
        }
    }
};