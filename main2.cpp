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
        cout << "������ �������� (i - ��������, p - ��������, h - peek, s - ��������, q - �����): ";
        cin >> operation;

        switch (operation) {
        case 'i':
            cout << "������ ��������: ";
            cin >> value;
            cout << "������ ��������: ";
            cin >> priority;
            queue.InsertWithPriority(value, priority);
            break;
        case 'p':
            queue.PullHighestPriorityElement();
            break;
        case 'h':
            cout << "��������� �� ���������� �������: " << queue.Peek() << endl;
            break;
        case 's':
            queue.Show();
            break;
        case 'q':
            return 0;
        default:
            cout << "������� ��������" << endl;
        }
    }

    return 0;
}
