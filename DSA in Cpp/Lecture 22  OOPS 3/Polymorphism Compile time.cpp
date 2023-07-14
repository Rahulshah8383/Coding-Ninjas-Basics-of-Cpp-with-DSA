// Polymorphism 
// 1. Compile time
// 2. Run time

// 1.compile time 
// I) Funciton overloading :
// II) operator overloading : 
// III) method/function overloading : 


// I) Funciton overloading 
/*
#include<iostream>
using namespace std;

int test(int a, int b){

}

int test(int a){

}

int test(){

}

// void test(){ //It is not function of overloading

// }

int main(){

}
*/


// method/function overloading
#include <iostream>
using namespace std;

class Vehicle {
	public :
		string color;

	void print() {
		cout << "Vehicle" << endl;
	}
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
    // v2 can aceess of vehicle class property because we decide at compile time v2 is vehicle class to it call vehicle class

	v1 -> print();  // vehicle class print function call
	v2 -> print();  // vehicle class print function call : compile time 
}

// Vehicle
// Car
// Vehicle
// Vehicle