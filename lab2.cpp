#include "lab2.h"
#include <algorithm>

bool PriorityQueue::IsEmpty() {
    return elements.empty();
}

bool PriorityQueue::IsFull() {
    return false;
}

void PriorityQueue::InsertWithPriority(int value, int priority) {
    elements.push_back({ value, priority });
    sort(elements.rbegin(), elements.rend());
}

void PriorityQueue::PullHighestPriorityElement() {
    if (!IsEmpty()) {
        elements.pop_back();
    }
}

int PriorityQueue::Peek() {
    if (!IsEmpty()) {
        return elements.back().first;
    }
    return -1;
}

void PriorityQueue::Show() {
    if (!IsEmpty()) {
        for (const auto& element : elements) {
            cout << "Значення: " << element.first << ", Пріоритет: " << element.second << endl;
        }
    }
    else {
        cout << "Черга пуста" << endl;
    }
}
