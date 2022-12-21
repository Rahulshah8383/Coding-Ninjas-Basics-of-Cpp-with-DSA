#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i = 1;
    while (i <= n)
    {
        int j = 1;
        while (j <= n)
        {
            /*
            cout << i;
            j++;
            output:
            // 4      
            // 1111
            // 2222
            // 3333
            // 4444
            */

            /*
            cout << j;
            j++;
            // output:
            // 4      
            // 1234
            // 1234
            // 1234
            // 1234
            */

            cout << n - j + 1;
            j++;
            // output
            // 4      
            // 4321
            // 4321
            // 4321
            // 4321
        }
        cout << endl;
        i++;
    }
    return 0;
}
