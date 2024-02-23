#ifndef LAB2_H
#define LAB2_H

#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue {
private:
    vector<pair<int, int>> elements;

public:
    bool IsEmpty();
    bool IsFull();
    void InsertWithPriority(int value, int priority);
    void PullHighestPriorityElement();
    int Peek();
    void Show();
};

#endif 
