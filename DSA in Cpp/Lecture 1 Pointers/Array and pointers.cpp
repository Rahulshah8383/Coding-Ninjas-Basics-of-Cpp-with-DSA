#include<iostream>
using namespace std;

int main(){
    int a[10];
    cout<< a <<endl;
    cout<< &a <<endl;

    a[0]=5;
    a[1]=10;
    cout<< *a <<endl;
    cout<<a+1<<endl;
    cout<<*(a+1)<<endl;  //*(a+1)=a[i]=i[a]
    int *p=&a[0];

    cout<<a<<endl;
    cout<<p<<endl;

    cout<<&p<<endl;
    cout<<&a<<endl;

    cout<<sizeof(p)<<endl;
    cout<<sizeof(a)<<endl;

    p = p+1;
    // a = a+1; //error
    p = p+1;
}