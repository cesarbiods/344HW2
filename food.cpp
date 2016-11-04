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

    /*friend bool operator <(const box& a, const box& b) {
        if (a.open) {
            return true;
        } else if (a.open == false && b.open == true) {
            return false;
        } else {
            return older(a.expirationDate, b.expirationDate);
        }
    }*/
};

class shrimp:public box {
    public:
    shrimp(date* e, int n): box(e, n) {}

    void updateNum(int a) {
        num = a;
    }

    /*friend bool operator <(const shrimp& a, const shrimp& b) {
        if (a.open) {
            return true;
        } else if (a.open == false && b.open == true) {
            return false;
        } else {
            return older(a.expirationDate, b.expirationDate);
        }
    }*/
};

struct compare1 
{
    bool operator()(shrimp a, shrimp b)
    { 
        if (a.open)
            return true; 
        else if (!a.open && b.open)
            return false;
        else
            return older(a.expirationDate, b.expirationDate);
    }
};

class lobster:public box {
    public:
    lobster(date* e, int n): box(e, n) {}

    void updateNum(int a) {
        num = a;
    }

    /*friend bool operator <(const lobster& a, const lobster& b) {
        if (a.open) {
            return true;
        } else if (a.open == false && b.open == true) {
            return false;
        } else {
            return older(a.expirationDate, b.expirationDate);
        }
    }*/
};

struct compare2 
{
    bool operator()(lobster a, lobster b)
    { 
        if (a.open)
            return true; 
        else if (!a.open && b.open)
            return false;
        else
            return older(a.expirationDate, b.expirationDate);
    }
};

class crab:public box {
    public:
    crab(date* e, int n): box(e, n) {}

    void updateNum(int a) {
        num = a;
    }

    /*friend bool operator <(const crab& a, const crab& b) {
        cout << "Sort: " << a.expirationDate->print() << endl;
        if (a.open) {
            return true;
        } else if (a.open == false && b.open == true) {
            return false;
        } else {
            return older(a.expirationDate, b.expirationDate);
        }
    }*/
};

struct compare3 
{
    bool operator()(crab a, crab b)
    { 
        if (a.open)
            return true; 
        else if (!a.open && b.open)
            return false;
        else
            return older(a.expirationDate, b.expirationDate);
    }
};

class swordfish:public box {
    public:
    swordfish(date* e, int n): box(e, n) {}

    void updateNum(int a) {
        num = a;
    }
    
    /*friend bool operator <(const swordfish& a, const swordfish& b) {
        if (a.open) {
            return true;
        } else if (a.open == false && b.open == true) {
            return false;
        } else {
            return older(a.expirationDate, b.expirationDate);
        }
    }*/
};

struct compare4 
{
    bool operator()(swordfish a, swordfish b)
    { 
        if (a.open)
            return true; 
        else if (!a.open && b.open)
            return false;
        else
            return older(a.expirationDate, b.expirationDate);
    }
};