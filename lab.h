#ifndef LAB_H
#define LAB_H

#include <iostream>
#include <fstream> 

using namespace std;

template <class T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& data, Node* next = nullptr) {
            this->data = data;
            this->next = next;
        }
    };

    Node* front;
    Node* back;
    size_t size;

public:
    Queue() {
        front = nullptr;
        back = nullptr;
        size = 0;
    }

    ~Queue() {
        while (!IsEmpty()) {
            Dequeue();
        }
    }

    bool IsEmpty() const {
        return size == 0;
    }

    bool IsFull() const {
        return false;
    }

    void Enqueue(const T& data) {
        Node* newNode = new Node(data);
        if (IsEmpty()) {
            front = back = newNode;
        }
        else {
            back->next = newNode;
            back = newNode;
        }
        size++;
    }

    T Dequeue() {
        if (IsEmpty()) {
            cout << "Черга порожня!" << endl;
            exit(1);
        }

        T data = front->data;
        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            back = nullptr;
        }

        delete temp;
        size--;
        return data;
    }

    void Show() const {
        if (IsEmpty()) {
            cout << "Черга порожня!" << endl;
            return;
        }

        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

    size_t Size() const {
        return size;
    }
    void SaveToFile(const string& filename) const {
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "Помилка відкриття файлу для запису." << endl;
            return;
        }

        Node* current = front;
        while (current != nullptr) {
            file << current->data << " ";
            current = current->next;
        }

        file.close();
        cout << "Дані успішно збережено у файл " << filename << endl;
    }
};

#endif // QUEUE_H
