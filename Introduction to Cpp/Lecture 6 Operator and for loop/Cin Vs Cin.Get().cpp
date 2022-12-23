#include<iostream>
using namespace std;

/*
int main(){
    char c;
    cin>>c;  // not count space, tab and newline
    int count = 0;
    while(c !='$'){
        count++;
        cin>>c;
    }
    cout<<count<<endl;
}
// Output
// a
// s
// d

// g
// h
// o
// 4
// $
// 7
*/

int main(){
    char c;
    c = cin.get();  
    int count = 0;
    while(c !='$'){
        count++;
        cin>>c;
    }
    cout<<count<<endl;
}

// Output
// a
// b
// c

// e
// r
// \n
// e
// $
// 8