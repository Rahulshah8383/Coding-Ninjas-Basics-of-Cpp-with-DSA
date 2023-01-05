#include<iostream>
using namespace std;

int length(char input[]){
    if(input[0]=='\0'){
        return 0;
    }

    int smallStringLength = length(input+1);
    return 1+smallStringLength;
}

int main(){
    char input[1000];
    cin>>input;

    int l = length(input);
    cout<<l<<endl;
}

// abcd
// 4