/*
Problem Statement
You are given an integer array/list(ARR) of size N. It contains only Os, 1s and 2s. Write a solution to sort this array/list in a 'single scan'.
'Single Scan' refers to iterating over the array/list just once or to put it in other words, you will be visiting each element in the array/list just once.

Note:
You need to change in the given array/list itself. Hence, no need
to return or print anything.

Input Format:
The first line contains an Integer T which denotes the number of test cases or queries to be run. Then the test cases follow.
First line of each test case or query contains an integer 'N' representing the size of the array/list.

Output Format:
For each test case, print the sorted array/list elements in a row separated by a single space.
Output for every test case will be printed in a separate line.

Sample Input 1:
1
7
0 1 2 0 2 0 1
Sample Output 1:
0 0 0 1 1 2 2 

Sample Input 2:
2
5
2 2 0 1 1
7
0 1 2 0 1 2 0
Sample Output 2:
0 1 1 2 2 
0 0 0 1 1 2 2
*/

#include <iostream>
using namespace std;

void sort012(int arr[], int n) {
   int countZero = 0;
   int countOne = 0;
   int countTwo = 0;

   for (int i = 0; i < n; i++) {
       if (arr[i] == 0)
           countZero++;
       else if (arr[i] == 1)
           countOne++;
       else if (arr[i] == 2)
           countTwo++;
   }

   int index = 0;
   for (int i = 0; i < countZero; i++) {
       arr[index] = 0;
       index++;
   }

   for (int i = 0; i < countOne; i++) {
       arr[index] = 1;
       index++;
   }

   for (int i = 0; i < countTwo; i++) {
       arr[index] = 2;
       index++;
   }
}

int main() {
    int t;
    cin >> t;

    while (t > 0) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort012(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        t--;
    }
    return 0;
}