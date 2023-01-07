#include<iostream>
using namespace std;

class Student {
public :
	int rollNumber;
private :
	int age;
public :
	// Default constructor
	/*
	Student() {
		cout << "Constreuctor called ! "<< endl;
	}
	*/

	// Parameterized constructor
	/*
	Student(int r) {
		cout << "Constructor 2 called !" << endl;
		rollNumber = rollNumber;
	}

	Student(int a, int r) {
		cout << "Constructor 3 called ! " << endl;
		age = a;
		rollNumber = r;
	}
	*/

	// Parameterized constructor with this keyboard
	Student(int rollNumber) {
		cout << "Constructor 2 called !" << endl;
	
		this -> rollNumber = rollNumber;
	}

	Student(int a, int r) {
		cout << "this : " << this << endl;
		cout << "Constructor 3 called ! " << endl;
		this -> age = a;
		this -> rollNumber = r;
	}

	void display() {
		cout << age << " " << rollNumber << endl;
	}
};

int main() {
// default constructor
	/*
	Student s1;
	s1.display();

	Student s2;

	Student *s3 = new Student;
	s3 -> display();
	*/

// parametric constructor
	cout << "Parametrized constructors Demo" << endl;
	Student s4(10);

	s4.display();

	Student *s5 = new Student(101);
	s5 -> display();

	Student s6(20, 1002);
	s6.display();
}
