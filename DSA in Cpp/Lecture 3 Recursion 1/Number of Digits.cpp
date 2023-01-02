#include<iostream>
using namespace std;

int count(int n){
    if(n==0){  //Base case
        return 0;
    }
    int smalloutput=count(n/10);  //recursive call
    int output=1+smalloutput;  // small calculation
    return output;
}


int main(){
    int n;
    cin >> n;
  
    cout << count(n) << endl;
}