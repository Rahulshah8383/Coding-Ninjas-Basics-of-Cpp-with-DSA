/*
Code : No. of balanced BTs using DP
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Time complexity should be O(h).
Input Format :
The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.
Output Format :
The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.
Constraints :
1 <= h <= 10^6
Time Limit: 1 sec
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315
*/

#include <iostream>
#include <cmath>
using namespace std;

int balancedBTs(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 3;
    }

    int *ans = new int[n + 1];
    ans[1] = 1;
    ans[2] = 3;

    int mod = (int) (pow(10, 9)) + 7;
    for (int i = 3; i <= n; i++)
    {
        int x = (int)(((long long)ans[i - 1] * ans[i - 1]) % mod);
        int y = (int)((2 * (long long)ans[i - 1] * ans[i - 2]) % mod);
        ans[i] = (int)(((long long)x + y) % mod);
    }
    int output = ans[n];
    delete[] ans;
    return output;
}

int main()
{
    int n;
    cin >> n;
    cout << balancedBTs(n);
}