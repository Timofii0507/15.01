#include <Windows.h>
#include "lab.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Queue<int> queue;

    int choice;
    int value;

    while (true) {
        cout << "1. Додати елемент" << endl;
        cout << "2. Видалити елемент" << endl;
        cout << "3. Перевірити, чи порожня черга" << endl;
        cout << "4. Показати всі елементи" << endl;
        cout << "5. Зберегти інформацію у файл" << endl;
        cout << "6. Вихід" << endl;

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введіть значення: ";
            cin >> value;
            queue.Enqueue(value);
            break;
        case 2:
            if (queue.IsEmpty()) {
                cout << "Черга порожня!" << endl;
            }
            else {
                cout << "Видалено: " << queue.Dequeue() << endl;
            }
            break;
        case 3:
            cout << (queue.IsEmpty() ? "Так" : "Ні") << endl;
            break;
        case 4:
            queue.Show();
            break;
        case 5: {
            string filename;
            cout << "Введіть ім'я файлу: ";
            cin >> filename;
            queue.SaveToFile(filename);
            break;
        }
        case 6:
            return 0;
        default:
            cout << "Неправильний вибір!" << endl;
        }
    }

    return 0;
}
