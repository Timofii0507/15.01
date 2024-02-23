#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>

using namespace std;

template<typename T, typename Priority>
class PriorityQueue {
private:
    vector<pair<T, Priority>> elements;

public:
    bool IsEmpty() {
        return elements.empty();
    }

    bool IsFull() {
        return false;
    }

    void InsertWithPriority(T value, Priority priority) {
        elements.push_back({ value, priority });
        sort(elements.rbegin(), elements.rend(), [](const auto& lhs, const auto& rhs) {
            return lhs.second < rhs.second;
            });
    }

    void PullHighestPriorityElement() {
        if (!IsEmpty()) {
            elements.pop_back();
        }
    }

    T Peek() {
        if (!IsEmpty()) {
            return elements.back().first;
        }
        return T(); // Return default value if queue is empty
    }

    void Show() {
        if (!IsEmpty()) {
            for (const auto& element : elements) {
                cout << "Значення: " << element.first << ", Пріоритет: " << element.second << endl;
            }
        }
        else {
            cout << "Черга пуста" << endl;
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    PriorityQueue<int, int> queue;

    int value, priority;
    char operation;

    while (true) {
        cout << "Введіть операцію (i - вставити, p - видалити, h - peek, s - показати, q - вихід): ";
        cin >> operation;

        switch (operation) {
        case 'i':
            cout << "Введіть значення: ";
            cin >> value;
            cout << "Введіть пріоритет: ";
            cin >> priority;
            queue.InsertWithPriority(value, priority);
            break;
        case 'p':
            queue.PullHighestPriorityElement();
            break;
        case 'h':
            cout << "Найбільший за пріоритетом елемент: " << queue.Peek() << endl;
            break;
        case 's':
            queue.Show();
            break;
        case 'q':
            return 0;
        default:
            cout << "Невідома операція" << endl;
        }
    }

    return 0;
}
