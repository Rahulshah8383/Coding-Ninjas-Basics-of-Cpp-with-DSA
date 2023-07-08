#include <iostream>
#include<cmath>
#include<climits>
using namespace std;

//Memoization
int minCountHelper(int n, int *ans){
    // Base case
    if(n == 0){
        return 0;
    }

    // check if outpur already exists
    if(ans[n] != -1){
        return ans[n];
    }

    // calculate outpur 
    int x = INT_MAX;
    for(int i=1; i*i<=n;i++){
        x = min(x, minCountHelper(n-(i*i), ans));
    }

    // save output for future value
    ans[n] = x +1;

    return ans[n];
}

int minCount(int n)
{
	int *ans = new int[n+1];

    for(int i=0;i<=n;i++){
        ans[i]=-1;
    }

    return minCountHelper(n, ans);
}

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}