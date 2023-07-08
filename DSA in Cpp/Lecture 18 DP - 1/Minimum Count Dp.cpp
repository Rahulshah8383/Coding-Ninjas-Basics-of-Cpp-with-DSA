#include <iostream>
#include<cmath>
#include<climits>
using namespace std;

//Dp
int minCount(int n)
{
    if (n <= 1)
    {
        return 0;
    }
	int *ans = new int[n+1];

	ans[1] = 1;
	ans[2] = 2;
	ans[3] = 3;	

	for(int i = 4;i<=n;i++){
		int x = n;
		for(int i=1;i*i<=n;i++){
			x = min(x,minCount(n-(i*i)));
		}
		ans[n] = x+1;
	}
	int output = ans[n];
    delete[] ans;
    return output;
}

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}