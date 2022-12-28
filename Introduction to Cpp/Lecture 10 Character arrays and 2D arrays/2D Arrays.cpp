#include<iostream>
using namespace std;

int main(){
    // Declaring 2D array
    int arr[100][100];

    //Input row and column
    int n, m;
    cin>>n>>m;

    //Input of 2D array
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    //Print 2D array
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    //print 2D array column wise
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
