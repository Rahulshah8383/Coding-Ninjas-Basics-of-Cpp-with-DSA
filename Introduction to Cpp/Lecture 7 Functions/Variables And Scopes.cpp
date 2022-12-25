#include <iostream>
using namespace std;

int fact(int n) {
	// cout<<a<<endl; //Error : outside the scope
	int ans = 1;
	for(int i=1;i<=n;i++){
        ans = ans * i;
    }
	return ans;
}

int main(){
    int a;
    cin>>a;
    int output = fact(a);
    // cout<<ans<<endl; //Error : outside the scope
    // cout<<n<<endl; //Error : outside the scope
    cout<<output<<endl;
}