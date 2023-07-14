// Polymorphism 
// 1. Compile time
// 2. Run time

// 2. Run Time

#include <iostream>
using namespace std;

class Vehicle {
	public :
		string color;

	// virtual void print() {
	// 	cout << "Vehicle" << endl;
	// }
};

class Car : public Vehicle {
	public :
		int numGears;

		void print() {
			cout << "Car" << endl;
		}
};

int main() {
	Vehicle v;
	Car c;

	v.print();   // vehicle class print function call
	c.print();   // Car class print function call


	Vehicle *v1 = new Vehicle; //v1 pointing to v
            
	Vehicle *v2; // v2 is created
	// v2 = &v;  // v2 poitinng to v

	v2 = &c;   // Base class pointer can point to derive class point but vice-versa is not true

	v1 -> print();  // vehicle class print function call
    // when car class have not print function then it call vehicle class print function
    /*
    Vehicle
    Vehicle
    Vehicle
    Vehicle
    */


	v2 -> print();  // Car class print function call : compile run 
     // v2 can aceess of vehicle class property because we decide at compile time v2 is vehicle class to it call vehicle class
    // By adding virtual keyboard at vehicle class we call car class print functon 
    /*
    Vehicle
    Car
    Vehicle
    Car
    */
    
    // Also when vehicle class have not print function(car have print function) then it show error
    /*
    Show Error
    */
}

