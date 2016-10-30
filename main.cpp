#include <iostream>
#include "date.cpp"
#include "food.cpp"
#include "truck.cpp"

using namespace std;

int main() {
    date today(10,18,2016);
    shrimp first(today, 50);
    truck truck;
    truck.addBox(first);
    return 0;
}