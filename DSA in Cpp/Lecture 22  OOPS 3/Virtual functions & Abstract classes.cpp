// Abstract classes :  function have a one Pure vitual function

// Pure virtual fumction


#include <iostream>
using namespace std;

class Vehicle {
	public :
		string color;

	virtual void print() = 0;
};

class Car : public Vehicle {
	public :
		int numGears;

		void print() {
			cout << "Car" << endl;
		}
};

int main() {
	// Vehicle v;   //Error  
    Car c;
}

