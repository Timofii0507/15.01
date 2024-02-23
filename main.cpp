#include <Windows.h>
#include "lab.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Queue<int> queue;

    int choice;
    int value;

    while (true) {
        cout << "1. ������ �������" << endl;
        cout << "2. �������� �������" << endl;
        cout << "3. ���������, �� ������� �����" << endl;
        cout << "4. �������� �� ��������" << endl;
        cout << "5. �������� ���������� � ����" << endl;
        cout << "6. �����" << endl;

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "������ ��������: ";
            cin >> value;
            queue.Enqueue(value);
            break;
        case 2:
            if (queue.IsEmpty()) {
                cout << "����� �������!" << endl;
            }
            else {
                cout << "��������: " << queue.Dequeue() << endl;
            }
            break;
        case 3:
            cout << (queue.IsEmpty() ? "���" : "ͳ") << endl;
            break;
        case 4:
            queue.Show();
            break;
        case 5: {
            string filename;
            cout << "������ ��'� �����: ";
            cin >> filename;
            queue.SaveToFile(filename);
            break;
        }
        case 6:
            return 0;
        default:
            cout << "������������ ����!" << endl;
        }
    }

    return 0;
}
