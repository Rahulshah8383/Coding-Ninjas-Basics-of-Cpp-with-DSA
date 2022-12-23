#include <iostream>
using namespace std;

// print1toN
/*
int main() {
	int m,n;
	cout << "Enter m & n" << endl;
	cin >> m >> n;

	for(;m <= n; m++) {
		cout << m << endl;
	}
}
*/


// Prime
int main() {
	int n;
	cin >> n;

	bool divided = false;
	for (int d = 2;d < n; d++) {
		if (n % d == 0) {
			divided = true;
		}
	}

	if (divided) {
		cout << "Not prime" << endl;
	} else {
		cout << "Prime" << endl;
	}
}


