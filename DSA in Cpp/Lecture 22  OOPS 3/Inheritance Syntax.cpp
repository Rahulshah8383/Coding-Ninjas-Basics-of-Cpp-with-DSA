
// Single inheritance
#include <iostream>
using namespace std;

class Vehicle {
	private :
		int maxSpeed;

	protected :
		int numTyres;

	public :
		string color;
};

class Car : public Vehicle {
	public :
		int numGears;

		void print() {
			cout << "NumTyres : " << numTyres << endl;
			cout << "Color : " << color << endl;
			cout << "Num gears : " << numGears << endl;
	//		cout << "Max Speed : " << maxSpeed << endl;
		}
};

int main() {
	Vehicle v;

	v.color = "Blue"; 
	// v.maxSpeed = 100; //Error
	// v.numTyres = 4; //Error


	Car c;
	c.color = "Black";
//	c.numTyres = 4; //error 
	c.numGears = 5;
}