/*
Array Intersection
You have been given two integer arrays/list(ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.
Note :
Input arrays/lists can contain duplicate elements.

The intersection elements printed would be in ascending order.


Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains an integer 'N' representing the size of the first array/list.

The second line contains 'N' single space separated integers representing the elements of the first the array/list.

The third line contains an integer 'M' representing the size of the second array/list.

The fourth line contains 'M' single space separated integers representing the elements of the second array/list.
Output format :
For each test case, print the intersection elements in a row, separated by a single space.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^6
0 <= M <= 10^6

Time Limit: 1 sec 
Sample Input 1 :
2
6
2 6 8 5 4 3
4
2 3 4 7 
2
10 10
1
10
Sample Output 1 :
2 3 4
10

Sample Input 2 :
1
4
2 6 1 2
5
1 2 3 4 2
Sample Output 2 :
1 2 2
Explanation for Sample Output 2 :
Since, both input arrays have two '2's, the intersection of the arrays also have two '2's. The first '2' of first array matches with the first '2' of the second array. Similarly, the second '2' of the first array matches with the second '2' if the second array.
*/

#include <iostream>
#include <algorithm>
using namespace std;

void mergeArray(int input[], int start, int end, int mid)
{
    int *p = new int[end - start + 1];
    int i = start;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end)
    {
        if (input[i] <= input[j])
        {
            p[k] = input[i];
            i++;
            k++;
        }
        else
        {
            p[k] = input[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        p[k] = input[i];
        i++;
        k++;
    }
    while (j <= end)
    {
        p[k] = input[j];
        j++;
        k++;
    }
    for (int l = 0; l < k; l++)
    {
        input[start] = p[l];
        start++;
    }

    delete[] p;
}

void mergeSortHelper(int input[], int start, int end)
{
    if (start >= end)
        return;

    int mid = (start + end) / 2;
    mergeSortHelper(input, start, mid);
    mergeSortHelper(input, mid + 1, end);

    mergeArray(input, start, end, mid);
}

void mergeSort(int input[], int size)
{

    mergeSortHelper(input, 0, size - 1);
}

void intersection(int *arr1, int *arr2, int n, int m) 
{
    mergeSort(arr1, n);
    mergeSort(arr2, m);
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		int size1, size2;

		cin >> size1;
		int *input1 = new int[size1];

		for (int i = 0; i < size1; i++)
		{
			cin >> input1[i];
		}

		cin >> size2;
		int *input2 = new int[size2];

		for (int i = 0; i < size2; i++)
		{
			cin >> input2[i];
		}

		intersection(input1, input2, size1, size2);
		
		delete[] input1;
		delete[] input2;
		
		cout << endl;
	}
	return 0;
}