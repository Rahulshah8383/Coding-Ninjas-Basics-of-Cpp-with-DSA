#include<iostream>
#include<string.h>
using namespace std;

int main(){
    char name[100];
    cin>>name;
    cout<<name<<endl;

    name[4]='P';
    cout<<name<<endl;

    for(int i=0;name[i]!='\0';i++){
        cout<<name[i];
    }
}