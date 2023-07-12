/*
Code: Knapsack (Memoization and DP)
Send Feedback
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weighs wi and is of value vi. Considering the constraints of maximum weight that knapsack can carry, you have to find and return the maximum value that thief can generate by stealing items.
Note
Space complexity should be O(W).
Input Format :
The first line contains an integers, that denote the value of N. The following line contains N space separated integers, that denote the values of weight of items. The following line contains N space separated integers, that denote the values associated with the items. The following line contains an integer that denote the value of W. W denotes maximum weight that thief can carry.
Output Format :
The first and only line of output contains the maximum value that thief can generate, as described in the task. 
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Time Limit: 1 second
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output 1 :
13
*/

#include <cstring>
#include <iostream>
using namespace std;

int knapsackHelper(int* weight, int* value, int n, int maxWeight, int **output){
	// Base case
	if(n==0 || maxWeight==0){
		return 0;
	}

	// Check if ans already exists
	if(output[n][maxWeight]!=-1){
		return output[n][maxWeight];
	}

	// Recursive calls
	int ans;
	if(weight[0]>maxWeight){
		ans =  knapsackHelper(weight + 1, value + 1, n - 1, maxWeight, output);
		return ans;
	}

	int a = knapsackHelper(weight + 1, value + 1, n - 1, maxWeight - weight[0], output) + value[0];
	int b = knapsackHelper(weight + 1, value + 1, n - 1, maxWeight, output);
	ans = max(a, b);
	

	// Save your calculation
	output[n][maxWeight] = ans;

	// Return ans
	return ans;
}

int knapsack(int* weight, int* value, int n, int maxWeight) {
	// Write your code here
	int **output = new int*[n+1];
	for(int i=0;i<=n;i++){
		output[i] = new int[maxWeight+1];
		for(int j=0;j<=maxWeight;j++){
			output[i][j] = -1;
		}
	}

	int ans = knapsackHelper(weight, value, n, maxWeight, output);

	for(int i=0;i<=n;i++){
		delete []output[i];
	}
	delete []output;

	return ans;
}

int main() {
    int n;
    cin >> n;
    int* wt = new int[n];
    int* val = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++) {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
}