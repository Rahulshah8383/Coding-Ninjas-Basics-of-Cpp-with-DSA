#include<iostream>
#include<string.h>
using namespace std;

class Student {
public:
    int age;
    char *name;

public:
    Student(int age, char *name){
        this->age=age;
        // Shallow copy
        // this -> name = name;
    
        // Deep copy
        this -> name = new char[strlen(name) + 1];
        strcpy(this -> name, name);
    }

    //copy constructor
    Student(Student const &s){
        this->age=s.age;
        // this->name=s.name; // shallow copy

        //Deep copy
        this->name=new char[strlen(s.name)+1];
        strcpy(this->name,s.name);
    }

    void Display(){
        cout<<name<<" "<<age<<endl;
    }
};

int main() {
    char name[]="abcd";
    Student s1(20,name);
    s1.Display();

    Student s2(s1); 
    s2.name[0]='x';
    s1.Display();
    s2.Display();
}
