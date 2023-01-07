#include <iostream>
using namespace std;

class Student {
    public :
    int rollNumber;
    int age;
};

int main() {
    // Create objects statically
    Student s1;
    Student s2;

    s1.age = 24;
    s1.rollNumber = 101;

    cout << s1.age << endl;
    cout << s1.rollNumber << endl;

    s2.age = 30;

    // Create objects dynamicaaly
    Student *s5 = new Student;
    (*s5).age = 23;
    (*s5).rollNumber = 104;
    cout << (*s5).age << endl;
    cout << (*s5).rollNumber << endl;

    Student *s6 = new Student;
    s6 -> age = 23;
    s6 -> rollNumber = 104;
    cout << s6->age << endl;
    cout << s6->rollNumber << endl;
}
