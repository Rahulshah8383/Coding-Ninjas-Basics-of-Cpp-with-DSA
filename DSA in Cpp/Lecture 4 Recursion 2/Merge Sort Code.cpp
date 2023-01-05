/*
Merge Sort Code
Sort an array A using Merge Sort.
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
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5 
*/

#include <iostream>
using namespace std;

void mergeSort(int input[], int size){
    int n=size;
	if(  n == 0 || n == 1)
    {
        return;
    }
    int si =0;
    int ei = n -1;
    int mid = ( si + ei)/2;
    mergeSort( input,  mid + 1 );// ( input, si, mid +1) in terms of indexes  // here the length mid is calculated including 0 // (input, mid )  which means you are excluding mid element and hence mid element will be passed to the right sub array. You have done mid+1 which means you are including mid and hence its to the left side of sub array.  0 to mid actually means till (mid - 1) index
    mergeSort( input + 1 + mid, n - mid -1 ); //( input, mid +1, ei) in terms of indexes

    int i=0 , j = mid +1 , k = 0;
    int ans[n];
    while( i <= mid && j <= n -1 ) // When you merge 2 arrays, you will need another array, because if you merge them in the same array then some data/ values will be lost because you will be overwriting them with some other values in some certain cases.
    {
        if( input[i] < input[j])
        {
             ans[k] = input[i];
             i++;
             k++;
        }
        else
        {
           ans[k]= input[j];
           j++;
           k++;
        }
    }
    while ( i <= mid )
    {
        ans[k] = input[i];
        i++;
        k++;
    }
    while( j <= n -1 )
    {
        ans[k] = input[j];
        j++;
        k++;
    }
      for( int i =0; i < k; i++ )
    {
          input[i] = ans[i];
    }        
}

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}