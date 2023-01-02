#include<iostream>
using namespace std;

int factorial(int n){
    if(n==1){   // Base case
        return 1;
    }
    int smalloutput=factorial(n-1);  // Assume or recursive call
    int output= n*smalloutput;       // small calculation
    return output;
}

int main(){
    int n, result;

    cout << "Enter a non-negative number: ";
    cin >> n;

    result = factorial(n);
    cout << "Factorial of " << n << " = " << result;
    return 0;
}