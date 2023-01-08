#include <iostream>
#include<string.h>
using namespace std;

/*
class Student {
public:
    int age;
    const int Roll_Number;
};

int main() {
    Student s1; 
    s1.age=20;
    s1.Roll_Number=101; // error because we try to change value of Roll_Number which is const
}
*/

// using constructor
/*
class Student {
    public :
    
        int age;
        const int rollNumber;

        Student(int r) {
            rollNumber = r; // error because we override the value of roolNUmber
        }   
};

int main() {
    Student s1(101);
    s1.age = 20;
}
*/

// use Initialisation List
class Student {
    public :
        int age;
        const int rollNumber;

        Student(int r) : rollNumber(r) {
        }   
};

int main() {
    Student s1(101);
    s1.age = 20;
}


