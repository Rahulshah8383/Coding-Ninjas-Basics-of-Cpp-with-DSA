#include<iostream>
#include<unordered_map>
#include<strin>
using namespace std;

int main()
{
    unordered_map<string, int> ourmap;

    // insert 1 way
    pair<string, int> p("abc",1);
    ourmap.insert(p);

    // insert 2nd way
    ourmap["def"]=2;

    // find or access 1st way
    cout<<ourmap["abc"]<<endl;
    // find or access 2nd way
    cout<<ourmap.at("abc")<<endl;
    cout<<"Size : "<<ourmap.size()<<endl;

    // different b/w [] and at 
    //cout<<ourmap.at("ghi")<<endl; //error 
    cout<<ourmap["ghi"]<<endl;      //  0

    // size
    cout<<"Size : "<<ourmap.size()<<endl;

    // check presense
    if(ourmap.count("ghi")>0){
        cout<<"ghi is present"<<endl;
    }

    // erase 
    ourmap.erase("ghi");
    
    cout<<"Size : "<<ourmap.size()<<endl;
    
    if(ourmap.count("ghi")>0){
        cout<<"ghi is present"<<endl;
    }
}