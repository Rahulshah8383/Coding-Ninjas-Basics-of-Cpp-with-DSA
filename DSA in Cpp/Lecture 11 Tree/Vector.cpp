#include<iostream>
#include<vector>
using namespace std;

int main()
{
    // vector<int> *vp = new vector<int>() dynamically 

    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    
    cout<<endl;
    cout<<v[0]<<endl;
    cout<<v[1]<<endl;
    cout<<v[2]<<endl;

    v[1] = 100;
    cout<<v[0]<<endl;
    cout<<v[1]<<endl;
    cout<<v[2]<<endl;

    cout<<endl;
    // don't user [] for inserting elements
    // v[4] = 1234;

    v.push_back(23);
    v.push_back(234);

    // cout<<v[0]<<endl;
    // cout<<v[1]<<endl;
    // cout<<v[2]<<endl;
    // cout<<v[3]<<endl;
    // cout<<v[4]<<endl;
    // cout<<v[5]<<endl;
    // cout<<v[6]<<endl;

    // cout<<"Size : " v.size<<endl;

    // cout<<v.at(2);
    // cout<<v.at(6);

    // for(int i=0;v.size();i++){
    //     cout<<v[i]<<endl;
    // }

    v.pop_back()
}