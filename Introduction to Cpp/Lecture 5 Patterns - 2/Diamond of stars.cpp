/*
Code : Diamond of stars
Print the following pattern for the given number of rows.
Note: N is always odd.

Pattern for N = 5

 
The dots represent spaces.

Input format :
N (Total no. of rows and can only be odd)
Output format :
Pattern in N lines
Constraints :
1 <= N <= 49
Sample Input 1:
5
Sample Output 1:
  *
 ***
*****
 ***
  *
Sample Input 2:
3
Sample Output 2:
  *
 ***
  *

*/
#include<iostream>
using namespace std;


int main() {
    int n;
    cin >> n;
    int i = 1;
    int up = (n + 1) / 2, down = (n - 1) / 2;
    while (i <= up){
        int j = 1;
        while (j <= up - i){
            cout << " ";
            j++;
        }
        j = 1;
        while (j <= 2 * i - 1){
            cout << "*";
            j++;
        }
        cout << endl;
        i++;
    }
    i = down;
    while (i >= 1){
        int j = 1;
        while (j <= down - i + 1){
            cout << " ";
            j++;
        }
        j = 1;
        while(j <= 2 * i - 1){
            cout << "*";
            j++;
        }
        cout << endl;
        i--;
    }
    return 0;
}
