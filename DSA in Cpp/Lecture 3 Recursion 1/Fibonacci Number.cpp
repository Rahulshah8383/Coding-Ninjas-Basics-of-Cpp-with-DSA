#include<iostream>
using namespace std;

int Fibonacci(int n){
    if(n==0){ 
        return 0;  //Base case
    }
    if(n==1){ 
        return 1; //Base case
    }

    int smalloutput1=Fibonacci(n-1);
    int smalloutput2=Fibonacci(n-2);
    
    return smalloutput1+smalloutput2;
}

int main(){
    int n;
    cin >> n;
  
    cout << Fibonacci(n) << endl;
}