#include <iostream>
using namespace std;

/*
int main() {
	int k = 1;
	while (k < 100) {
		int k2 = 1002;
		cout << k2 << endl;
		k++;
	}
	// cout << k2 << endl; // Error : k2 is not available here

	int i = 10;
	cout << i << endl;

	if (i == 10) {
		int j = 12;
		cout << j << endl;
	} else {
		int j = 122;
		cout << j << endl;
	} 
	// cout << j << endl; //Error : J is not available here
}
*/

/*
int main() {
	int i = 1;
	while (i < 10) {
		int j = 1;
		while (j < i) {
			int k = 10;
			cout << j;
			j++;
		}
		//cout <<k << endl; //error : k is not available here
		i++;
	}
}
*/

int main() {
	int i = 10;

	// not allowed int i = 22;
	cout << i << endl;

	if (i == 10) {
		int i = 23;
		cout << i << endl;
	}
	cout << i << endl;

	int k = 0;
	for (; k < 10; k++) {
		cout << k << endl;
	}
	cout << k << endl;
}
