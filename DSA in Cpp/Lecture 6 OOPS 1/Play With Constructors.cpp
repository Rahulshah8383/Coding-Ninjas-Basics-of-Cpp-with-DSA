#include <iostream>
using namespace std;

class Student {
public :
	int rollNumber;
private :
	int age;
public :
    ~Student() {
		cout << "Destructor called ! " << endl;
	}

    Student() {
		cout << "Constreuctor 1 called ! "<< endl;
	}

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
};

int main(){
    Student s1;  //constructor 1 called
    
    Student s2(101);   // sonstructor 2 called

    Student s3(20, 102);   // constructor 3 called

    Student s4(s3);   //  copy constructor called

    s1 = s2;         // copy assignment operator

    Student s5 = s4;   //  two step in one : - copy constructor called
                       // Student s5;  and s5 = s4; or Students5(s4)
}