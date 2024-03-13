#include <iostream>
#include <string>
using namespace std;

class Car {
    public:
        string model;
        int year;
        Car(string model, int year) {
            this->model = model;
            this->year = year;
        };

        virtual ~Car() {
            cout << "car destroyed\n";
        };

        virtual void startEngine() {
            cout << "engine starts!\n";
        }
};

int main()
{

    Car myCar("toyota AE86", 1983);

    myCar.startEngine();


    

    return 0;
}