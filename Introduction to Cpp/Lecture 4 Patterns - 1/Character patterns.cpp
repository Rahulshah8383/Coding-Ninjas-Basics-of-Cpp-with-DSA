#include <iostream>
using namespace std;

int main()
{
    int n, i;
    cin >> n;
    i = 1;
    while (i <= n)
    {
        int j=1;
        while(j <= n){
            /*
            cout << char('A' + j - 1);
            // Output
            // 4
            // ABCD
            // ABCD
            // ABCD
            // ABCD
            */
           cout << char('A' + i + j - 2);
            //  Output
            // 5
            // ABCDE
            // BCDEF
            // CDEFG
            // DEFGH
            // EFGHI
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}

// 4
// ABCD
// ABCD
// ABCD
// ABCD
