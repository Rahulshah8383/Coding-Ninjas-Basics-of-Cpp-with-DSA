#include <iostream>
using namespace std;

class Student {
    public :
    int rollNumber;
    private:
    int age;
    public:
    int getAge(int a){
        age=a;
        return age;
    }
};

int main() {
    Student s1,s2;    
    s1.rollNumber=101;
    s2.rollNumber=102;

    cout<<"S1 age :"<<s1.getAge(18)<<endl;
    cout<<"S1 Roll Number : "<<s1.rollNumber<<endl;
    cout<<"\n";
    cout<<"S2 age :"<<s2.getAge(19)<<endl;
    cout<<"S2 Roll Number : "<<s2.rollNumber<<endl;

    Student *s3=new Student;
    Student *s4=new Student;    
    s3->rollNumber=101;
    (*s4).rollNumber=102;

    cout<<"S1 age :"<<s3->getAge(18)<<endl;
    cout<<"S1 Roll Number : "<<s3->rollNumber<<endl;
    cout<<"\n";
    cout<<"S2 age :"<<(*s4).getAge(19)<<endl;
    cout<<"S2 Roll Number : "<<(*s4).rollNumber<<endl;

}
