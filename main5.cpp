#include <iostream>
#include <queue>
#include <string>
#include <ctime>
#include <Windows.h>

using namespace std;

class PrintJob {
public:
    string user;
    time_t timeRequested;

    PrintJob(string user) : user(user) {
        time(&timeRequested);
    }
};

class ComparePriority {
public:
    bool operator()(const PrintJob& a, const PrintJob& b) {
        return a.timeRequested > b.timeRequested;
    }
};

class PrinterQueue {
private:
    priority_queue<PrintJob, vector<PrintJob>, ComparePriority> jobQueue; 
    queue<PrintJob> printHistory; 

public:
    void addJob(const PrintJob& job) {
        jobQueue.push(job);
    }

    void printStatistics() {
        cout << "Статистика друку:" << endl;
        while (!printHistory.empty()) {
            PrintJob job = printHistory.front();
            printHistory.pop();
            char timeBuffer[26];
            ctime_s(timeBuffer, sizeof(timeBuffer), &job.timeRequested);
            cout << "Користувач: " << job.user << ", Час: " << timeBuffer;
        }
    }

    void processJobs() {
        while (!jobQueue.empty()) {
            PrintJob job = jobQueue.top();
            jobQueue.pop();
            cout << "Друк для користувача: " << job.user << endl;
            printHistory.push(job);
        }
    }
};

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    PrinterQueue printer;

    int numJobs;
    cout << "Введіть кількість робіт друку: ";
    cin >> numJobs;

    for (int i = 0; i < numJobs; ++i) {
        string user;
        cout << "Введіть користувача для роботи друку " << i + 1 << ": ";
        cin >> user;
        PrintJob job(user);
        printer.addJob(job);
    }

    printer.processJobs();
    printer.printStatistics();

    return 0;
}
