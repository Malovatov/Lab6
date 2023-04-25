#include <iostream>
#include <string>

using namespace std;

class Transport {
public:
    string make;
    string model;
    int year;
    int max_speed;

    Transport(string make, string model, int year, int max_speed) {
        this->make = make;
        this->model = model;
        this->year = year;
        this->max_speed = max_speed;
    }

    void move(int speed) {
        cout << make << " " << model << " moves at speed " << speed << " km/h" << endl;
    }
};

class Car : public Transport {
public:
    int num_passengers;

    Car(string make, string model, int year, int max_speed, int num_passengers) : Transport(make, model, year, max_speed) {
        this->num_passengers = num_passengers;
    }

    void park() {
        cout << make << " " << model << " is parked." << endl;
    }
};

class Train : public Transport {
public:
    int num_cars;

    Train(string make, string model, int year, int max_speed, int num_cars) : Transport(make, model, year, max_speed) {
        this->num_cars = num_cars;
    }

    void decouple() {
        cout << make << " " << model << " has decoupled a car." << endl;
    }
};

class Taxi : public Car {
public:
    string company_name;

    Taxi(string make, string model, int year, int max_speed, int num_passengers, string company_name) : Car(make, model, year, max_speed, num_passengers) {
        this->company_name = company_name;
    }

    void calculate_fare(int distance) {
        double fare = distance * 2.5;
        cout << "The fare for this " << make << " " << model << " taxi ride is $" << fixed << fare << "." << endl;
    }
};

int main() {
    Car car("Toyota", "Corolla", 2020, 180, 5);
    car.move(100);
    car.park();

    Train train("Siemens", "Desiro", 2010, 160, 8);
    train.move(120);
    train.decouple();

    Taxi taxi("Hyundai", "Elantra", 2022, 160, 5, "Uber");
    taxi.move(50);
    taxi.calculate_fare(10);

    return 0;
}
