#include <iostream>
using namespace std;

class Student {
    static int totalStudents;       // total number of students present

public :
    int rollNumber;
    int age;

    Student() {
        totalStudents++;
    }

    int getRollNumber() {
        return rollNumber;
    }

    static int getTotalStudent() {  // static function
    // static function can only access static variable and funtion
    // static function have not this pointer
        return totalStudents;
    }
};

int Student :: totalStudents = 0;   // initialze static data members

int main() {
    Student s1;
    Student s2;
    Student s3, s4, s5;

    cout << Student :: getTotalStudent() << endl;
}
