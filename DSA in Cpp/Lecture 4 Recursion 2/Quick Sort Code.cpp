/*
Quick Sort Code
Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.

Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 10^3
Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
1 5 2 7 3
Sample Output 2 :
1 2 3 5 7 
*/
#include<iostream>
using namespace std;

int partitionfunc( int input[], int n )
{
    int pivot = input[0];
    int num = 0;
    for( int i = 1; i < n; i++ ) //YOU HAD FORGOTTEN TO WRITE THIS FOR LOOP
    {
        if( input[i] <= pivot )
        {
            num++;
        }
    }

    int temp = input[0];
    input[0] = input[num];
    input[num] = temp;
    int i;
    int j= n - 1;
    for( i =0; i < num && j > num ;  )
{
    if( input[i] <= pivot )
    {
     i++;
    }
    else if( input[j] > pivot )
    {
        j--;
    }
    else
    {
      int temp1 = input[i];
      input[i] = input[j];
      input[j] = temp1;
      i++;
      j--;
    }
  }
  return num; // We are returning the index of the pivot element.
}

void quickSort(int input[], int size) {
    int n=size;
  if( n == 0 ||  n == 1) // REMEMBER-  You cant use NULL in INTEGER ARRAYS
    {
        return;
    }
    int catching = partitionfunc(   input, n );
    quickSort(input,catching); // understand why its only catching in the arguments. Refer to merge sort code in CB, your notes and recordings for more info //( input , si, catching ) in terms of indexes // see here in the formal arguments n is the size of the array, so in actual arguments also you should pasa size ONLY. You cant pass the index.
    quickSort( input +1 + catching, n - catching -1  ); //( input , 1+ catching, ei ) in terms of indexes // see here these arguments are your arrays and the size of those arrays.

}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}