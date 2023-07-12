#include <iostream>
using namespace std;
#include <climits>

/*
int minCostPath_Mem(int **input, int m, int n, int i, int j, int **output) {
    if(i == m- 1 && j == n- 1) {
        return input[i][j];
    }
    
    if(i >= m || j >= n) {
        return INT_MAX;
    }
    
    // Check if ans already exists
    if(output[i][j] != -1) {
        return output[i][j];
    }
    
    // Recursive calls
    int x = minCostPath_Mem(input, m, n, i, j+1, output);
    int y = minCostPath_Mem(input, m, n, i+1, j+1, output);
    int z = minCostPath_Mem(input, m, n, i+1, j, output);
    
    // Small Calculation
    int a = min(x, min(y, z)) + input[i][j];
    
    // Save the answer for future use
    output[i][j] = a;
    
    return a;
}

int minCostPath_Mem(int **input, int m, int n, int i, int j) {
    int **output = new int*[m];
    for(int i = 0; i < m; i++) {
        output[i] = new int[n];
        for(int j = 0; j < n; j++) {
            output[i][j] = -1;
        }
    }
    
    return minCostPath_Mem(input, m, n, i, j, output);
}
*/

int minCostPath_Better(int **input, int m, int n, int i, int j, int **ans) {
	if(i == m- 1 && j == n- 1) {
		return input[i][j];
	}

	if(i >= m || j >= n) {
		return INT_MAX;
	}

	if(ans[i][j] != -1) {
		return ans[i][j];
	}

	int x = minCostPath_Better(input, m, n, i+1, j, ans);
	if(x < INT_MAX) {
		ans[i+1][j] = x;
	}
	int y = minCostPath_Better(input, m, n, i+1, j+1, ans);
	if(y < INT_MAX) {
		ans[i+1][j+1] = y;
	}
	int z = minCostPath_Better(input, m, n, i, j+1, ans);
	if(z < INT_MAX) {
		ans[i][j+1] = z;
	}

	ans[i][j] = min(x, min(y, z)) + input[i][j];
	return ans[i][j];
}

int minCostPath_Better(int **input, int m, int n) {
	int **ans = new int*[m];
	for(int i = 0; i < m; i++) {
		ans[i] = new int[n];
		for(int j = 0; j < n; j++) {
			ans[i][j] = -1;
		}
	}
	return minCostPath_Better(input, m, n, 0, 0, ans);
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
    // cout << minCostPath_Mem(input, m, n, 0, 0) << endl;
    cout << minCostPath_Better(input, m, n) << endl;
}