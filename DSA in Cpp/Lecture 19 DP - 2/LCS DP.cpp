#include<iostream>
using namespace std;

int lcs_DP(string s, string t){
    int m = s.size();
    int n = t.size();

	int **output = new int*[m+1];
	for(int i = 0;i <= m; i++){
		output[i]=new int[n+1];
	}

	// fill first row
	for(int j = 0;j <= n;j++){
		output[0][j] = 0;
	}

	// fill first column
	for(int i=0;i<=m;i++){
		output[i][0] = 0;
	}

	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s[m-i]==t[n-j]){
				output[i][j] = 1 + output[i-1][-1];
			}
			else{
				int a = output[i-1][j];
				int b = output[i][j-1];
				int c = output[i-1][j-1];
				output[i][j] = max(a, max(b,c));
			}
		}
	}
	return output[m][n];
}

int main(){
    string s, t;
    cin>>s>>t;

    cout << lcs_DP(s,t) << endl;
}