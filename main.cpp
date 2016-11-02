#include <iostream>
#include "date.cpp"
#include "food.cpp"
#include "truck.cpp"

using namespace std;

int main() {
    truck t;

    date today(10,18,2016);
    shrimp first(today, 50);
    t.addShrimp(first);
    return 0;
}