#include<iostream>
using namespace std;

bool isSorted(int *input,int size){
    if(size==0 || size==1){
        return true;
    }

    bool SmallSorted=isSorted(input+1,size-1);
    if(!SmallSorted){
        return false;
    }
    
    if(input[0]>input[1]){
        return false;
    }
    else{
        return true;
    }
}

/*
bool isSorted(int *input,int size){
    if(size==0 || size==1){
        return true;
    }

    if(input[0]>input[1]){
        return false;
    }

    bool SmallSorted=isSorted(input+1,size-1);

    // if(SmallSorted){
    //     return true;
    // }
    // else{
    //     return false;
    // }

    return SmallSorted;
}
*/

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    if(isSorted(input, n)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}