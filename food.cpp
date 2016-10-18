#include <iostream>
#include <string>
using namespace std;

//TODO Figure out how to build date class

class box {
    public:
    bool open;
    string expirationDate;
    int num;
    box(string e, int n) {
        expirationDate = e;
        num = n;
    }
};

class shrimp:public box {
    shrimp(string e, int n);
};

class lobster:public box {
    lobster(string e, int n);
};

class crab:public box {
    crab(string e, int n);
};

class swordfish:public box {
    swordfish(string e, int n);
};