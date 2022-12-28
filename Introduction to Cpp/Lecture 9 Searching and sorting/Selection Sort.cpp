#include <iostream>
using namespace std;

//Time: - O(n^2) Space: - O(1)
void selectionSort(int arr[], int n)
{
    for(int i=0;i<n-1;i++){
        int mid_ind=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[mid_ind]){
                mid_ind=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[mid_ind];
        arr[mid_ind]=temp;
    }
}

int main()
{
    int arr[] = {4, 2, 7, 1, 6, 6, 1};
    selectionSort(arr, 7);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}