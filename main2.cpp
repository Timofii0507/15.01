#include "lab2.h"
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    PriorityQueue queue;

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
