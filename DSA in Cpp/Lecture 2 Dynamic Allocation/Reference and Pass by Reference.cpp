#include<iostream>
using namespace std;

// void increment(int n){
//     n++;
// }

void increment(int& n){
    n++;
}

int& f(int n){
    int a =n;
    retrn a;
}

int* f2(){
    int i=10;
    return &i;
}

int main(){
    int i =10;
    int j = i;

    int* p=f2();

    increment(i);
    cout<<i<<endl;

    int& k1 = f(i);

    i++;
    cout<<j<<endl;
    j++;
    cout<<i<<endl;

    int k = 100;
    j = k;
    cout<<i<<endl;
}