#include <iostream>

using namespace std;

class Car {
    int wheels;
    string engine;
    int doors;

public:
    Car(int wheels, string engine, int doors) {
        this->wheels = wheels;
        this->engine = engine;
        this->doors = doors;
    };

    friend std::ostream& operator<< (std::ostream& stream, const Car& car) {
        stream << "wheels: " << car.wheels << endl;
        stream << "engine: " << car.engine << endl;
        stream << "doors: " << car.doors << endl;
        stream << "------------------------------------" << endl;
    }

    string toString() {
        cout << "printing car: " << this << endl;
        cout << "wheels: " << wheels << endl;
        cout << "engine: " << engine << endl;
        cout << "doors: " << doors << endl;
        cout << "---------------------------------" << endl;
    }

    void setWheels(int numWheels) {
        this->wheels = numWheels;
    }
};

void doChangeCarWheels(Car& car, int numWheels){
    car.setWheels(numWheels);
}

int main() {
    Car* aCar = new Car(4, "v6", 2);
    Car carInStack = Car(10, "v10", 4);
    cout << aCar->toString() << endl;
    cout << carInStack << endl;

    doChangeCarWheels(carInStack, 6);
    cout << carInStack << endl;

    doChangeCarWheels(*aCar, 8);
    cout << aCar->toString() << endl;
    
    delete aCar;
    aCar = NULL;
}