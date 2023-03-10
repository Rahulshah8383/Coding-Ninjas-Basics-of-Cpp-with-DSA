/*
Binary to decimal

Given a binary number as an integer N, convert it into decimal and print.

Input format :
An integer N in the Binary Format
Output format :
Corresponding Decimal number (as integer)

Constraints :
0 <= N <= 10^9

Sample Input 1 :
1100
Sample Output 1 :
12

Sample Input 2 :
111
Sample Output 2 :
7
*/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int bin, decimal = 0, i = 0;
    cin >> bin;
    while (bin > 0)
    {
        decimal += pow(2, i) * (bin % 10);
        bin=bin/10;
        i++;
    }
    cout << decimal;
}
