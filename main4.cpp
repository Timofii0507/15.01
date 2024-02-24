#include <iostream>
#include <queue>
#include <random>
#include <Windows.h>

using namespace std;

class Passenger {
public:
    Passenger(int arrivalTime) : arrivalTime(arrivalTime) {}

    int getArrivalTime() const { return arrivalTime; }

private:
    int arrivalTime;
};

class Bus {
public:
    Bus(int arrivalTime, int capacity) : arrivalTime(arrivalTime), capacity(capacity) {}

    int getArrivalTime() const { return arrivalTime; }

    int getCapacity() const { return capacity; }

    void setCapacity(int newCapacity) { capacity = newCapacity; }

    bool operator>(const Bus& other) const {
        return arrivalTime > other.arrivalTime;
    }

private:
    int arrivalTime;
    int capacity;
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int meanPassengerArrivalTime, meanBusArrivalTime, maxPeopleOnStop;
    bool isFinalStop;

    cout << "Введіть середній час між появою пасажирів: ";
    cin >> meanPassengerArrivalTime;

    cout << "Введіть середній час між появою маршруток: ";
    cin >> meanBusArrivalTime;

    cout << "Введіть максимальну кількість людей на зупинці: ";
    cin >> maxPeopleOnStop;

    cout << "Чи є зупинка кінцевою? (1 - так, 0 - ні): ";
    cin >> isFinalStop;

    random_device rd;
    mt19937 gen(rd());
    exponential_distribution<> passengerArrivalDist(1.0 / meanPassengerArrivalTime);
    exponential_distribution<> busArrivalDist(1.0 / meanBusArrivalTime);
    uniform_int_distribution<> busCapacityDist(1, 10);

    queue<Passenger> passengers;
    priority_queue<Bus, vector<Bus>, greater<Bus>> buses;

    int currentTime = 0;
    int totalWaitTime = 0;
    int numPassengersServed = 0;

    while (currentTime < 10000) {
        int nextPassengerArrivalTime = currentTime + passengerArrivalDist(gen);
        while (currentTime <= nextPassengerArrivalTime) {
            passengers.push(Passenger(currentTime));
            currentTime = nextPassengerArrivalTime;
            nextPassengerArrivalTime = currentTime + passengerArrivalDist(gen);
        }

        if (!isFinalStop) {
            int nextBusArrivalTime = currentTime + busArrivalDist(gen);
            while (currentTime <= nextBusArrivalTime) {
                int capacity = busCapacityDist(gen);
                buses.push(Bus(currentTime, capacity));
                currentTime = nextBusArrivalTime;
                nextBusArrivalTime = currentTime + busArrivalDist(gen);
            }
        }

        while (!passengers.empty() && !buses.empty()) {
            Passenger passenger = passengers.front();
            Bus bus = buses.top();

            if (bus.getCapacity() >= maxPeopleOnStop) {
                totalWaitTime += currentTime - passenger.getArrivalTime();
                numPassengersServed += maxPeopleOnStop;
                passengers = queue<Passenger>();
                buses.pop();
            }
            else {
                int numPassengersOnBus = bus.getCapacity();
                totalWaitTime += currentTime - passenger.getArrivalTime();
                numPassengersServed += numPassengersOnBus;

                for (int i = 0; i < numPassengersOnBus; i++) {
                    passengers.pop();
                }

                bus.setCapacity(0);
                buses.pop();
            }
        }

        currentTime++;
    }

    cout << "Середній час очікування на зупинці: " << (double)totalWaitTime / numPassengersServed << endl;

    int optimalBusArrivalInterval = (totalWaitTime / numPassengersServed) / maxPeopleOnStop;
    cout << "Достатній інтервал між приїздом автобусів: " << optimalBusArrivalInterval << endl;

    return 0;
}