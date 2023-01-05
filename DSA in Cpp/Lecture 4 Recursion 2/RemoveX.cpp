#include<iostream>
using namespace std;

void RemoveX(char input[]){
    if(input[0]=='\0'){
        return;
    }

    if(input[0]!='x'){
        RemoveX(input+1);
    }
    else{
        int i=0;
        for(;input[i]!='\0';i++){
            input[i]=input[i+1];
        }
        input[i]='\0';
        RemoveX(input);
    }
}

int main(){
    char input[1000];
    cin>>input;

    RemoveX(input);
    cout<<input;
}