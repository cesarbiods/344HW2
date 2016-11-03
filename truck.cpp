#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "food.cpp"
using namespace std;

class truck {

    public:
    priority_queue<shrimp> sh;
    priority_queue<lobster> lo;
    priority_queue<crab> cr;
    priority_queue<swordfish> sw;

    void addShrimp(shrimp s) {
        sh.push(s);
    }
    void addLobster(lobster l) {
        lo.push(l);
    }
    void addCrab(crab c) {
        cr.push(c);
    }
    void addSwordfish(swordfish s) {
        sw.push(s);
    }

    void rmShrimp() {
        sh.pop();
    }
    void rmLobster() {
        lo.pop();
    }
    void rmCrab() {
        cr.pop();
    }
    void rmSwordfish() {
        sw.pop();
    }

    bool shrimpOpen(shrimp s) {
        return s.open;
    }
    bool lobsterOpen(lobster l) {
        return l.open;
    }
    bool crabOpen(crab c) {
        return c.open;
    }
    bool swordfishOpen(swordfish s) {
        return s.open;
    }

    
};