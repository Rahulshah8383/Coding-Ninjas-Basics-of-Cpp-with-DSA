#include <iostream>
using namespace std;

class Vehicle {
    private :
        int maxSpeed;
    public:
	/*
		Vehicle() {
		cout << "Vehicle's default constructor " << endl;
	}*/

	void print() {
		cout << "Vehicle" << endl;
	}

	Vehicle(int z) {
	cout << "Vehicle's Parametrized constructor " << z << endl;
		maxSpeed = z;
	}

	~Vehicle() {
		cout << "Vehicle's Destructor " << endl;
	}

};

class Car : virtual public Vehicle {
    public:
		Car() : Vehicle(3){
			cout << "Car's default constructor " << endl;
		}
		~Car() {
			cout << "Car's Destructor " << endl;
		}
};

class Truck : virtual public Vehicle {
	public :
		Truck() : Vehicle(4) {
			cout << "Truck's constructor " << endl;
		}
};


class Bus : public Car, public Truck {
	public :
		Bus() : Vehicle(5) {
			cout << "Bus's constructor " << endl;
		}

};


int main() {
	Bus b;

	b.print();
	//b.Car :: print(); 
}

