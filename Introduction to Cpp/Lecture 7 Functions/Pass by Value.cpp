#include <iostream>
using namespace std;

// void increase(int x, int y) // formal parameters
// {
//     x++;
//     y += 2;
//     cout << x << ":" << y << endl;
// }

void increment(int a){
    a = a + 1;
}

int main(){
    int n = 10;
    increment(n);
    cout<< n << endl;
}

// int main(){
//     int n = 10;
//     int a = 10, b = 20;
//     increase(a, b);
//     cout << a << ":" << b;
//     return 0;
// }