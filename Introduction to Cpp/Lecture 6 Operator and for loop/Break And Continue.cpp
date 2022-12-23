#include <iostream>
using namespace std;

// Prime : shile-break
/*
int main() {
	int n;
	cin >> n;
	int d = 2;
	bool divided = false;
	while (d < n) {
		if (n % d == 0) {
			divided = true;
			break;
		}
		d++;
	}
	if (divided) {
		cout << "Not prime" << endl;
	} else {
		cout << "Prime" << endl;
	}
}
*/

// Patten : while-break
/*
int main() {
	int n;
	cin >> n;

	int i = 1;
	while(i  <= n) {
		int j = 1;
		while (j <= n) {
			cout << j;
			j++;
			if (j > i) {
				break;
			}
		}
		cout << endl;
		i++;
	}
}
*/

// prime : for - break
int main() {
	int n;
	cin >> n;
	bool divided = false;
	for (int d = 2; d < n; d++) {
		if (n % d == 0) {
			divided = true;
			break;
		}
	}
	if (divided) {
		cout << "Not Prime" << endl;
	} else {
		cout << "Prime" << endl;
	}
}