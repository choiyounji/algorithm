#include<iostream>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	if (n % 2 == 1) {
		cout << "SK";
	}
	else {
		cout << "CY";
	}
	return 0;
}