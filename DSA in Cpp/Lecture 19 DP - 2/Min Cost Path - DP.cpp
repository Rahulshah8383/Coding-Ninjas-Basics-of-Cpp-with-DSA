#include <iostream>
using namespace std;
#include <climits>

int minCostPath_DP(int **input, int m, int n) {
    int **ans = new int*[m];
    for(int i=0;i<m;i++){
        ans[i] = new int[n];
    }

    //  Last row and column
    ans[m-1][n-1] = input[m-1][n-1];

    // Last row
    for(int j=n-2; j>=0; j--){
        ans[m-1][j] = ans[m-1][j+1] + input[m-1][j];
    }

    // Last column
    for(int i=m-2; i>=0; i--){
        ans[i][n-1] = ans[+1][n-1] + input[i][n-1];
    }

    for(int i=m-2; i>=0; i--){
        for(int j=n-2; j>=0; j--){
            ans[i][j] = input[i][j] + min(ans[i][j+1], min(ans[i+1][j+1], ans[i+1][j]));
        }
    }

    return ans[0][0];
}

int main() {
    int m, n;
    cin >> m >> n;
    int **input = new int*[m];
    for(int i = 0; i < m; i++) {
        input[i] = new int[n];
        for(int j = 0; j < n; j++) {
            cin >> input[i][j];
        }	
    }
    cout << minCostPath_DP(input, m, n) << endl;
}