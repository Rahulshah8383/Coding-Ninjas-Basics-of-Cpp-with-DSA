#include<iostream>
using namespace std;

int main(){
    string s1="abc";
    string s2;
    s2="def";

    string *sp=new string;
    *sp="ghi";

    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<*sp<<endl;

    string s3;
    // input coding ninjas
    cin>> s3;
    cout<<s3<<endl; // ouput:  coding

    string s4;
    // input coding ninjas
    getline(cin, s4);
    cout<<s4<<endl; // coding ninjas

    // it behave like array 
    // change of string 
    s1="abcdefghij";
    cout<<s1[0];
    cout<<s1[1];

    s2=s1+s3;
    cout<<s2;

    cout << s1 << endl;
	cout << s2 << endl;

	cout << s2.size() << endl;
	cout << s2.substr(3) << endl;	
	cout << s2.substr(3, 3) << endl;	

	cout << s2.find("def") << endl;


    cout<<"subcrit of "<<s1.find("")<<endl;
}
