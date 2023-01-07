// copy constructor 

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

	Student(int a, int r) {
		this -> age = a;
		this -> rollNumber = r;
	}

	void display() {
		cout << age << " " << rollNumber << endl;
	}
};


int main() {
// Copy assignment operator(=)
    Student s1(10, 1001);
	Student s2(20, 2001);
    // create dynamically
	Student *s3 = new Student(30, 3001); 

	s2 = s1;
	*s3 = s1;
	s2 = *s3;
    cout << "S1 : ";
	s1.display();

    cout << "S2 : ";
	s2.display();

    cout << "S3 : ";
	s3->display();
    delete s3;

// copy constructor
    /*
    // Statically
	Student s1(10, 1001);
	cout << "S1 : ";
	s1.display();

	Student s2(s1);
	cout << "S2 : ";
	s2.display();

    // dynamically
    Student *s3 = new Student(20, 2001);
	cout << "S3 : ";
	s3 -> display();

	Student s4(*s3);
    cout << "S4 : ";
	s4.display();

	Student *s5 = new Student(*s3);
    cout << "S5 : ";
	s5 -> display();
	Student *s6 = new Student(s1);
    cout << "S6 : ";
	s6 -> display();
    */
}


