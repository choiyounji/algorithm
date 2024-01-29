#include<iostream>

using namespace std;

int gcd(int a, int b) {
	int r = a % b;
	if (r == 0)
		return b;
	return gcd(b, r);
}
int main() {
	int n, m;
	cin >> n >> m;
	cout << gcd(n, m) << "\n";
	int lsm = 0;
	int nn = n / gcd(n, m);
	int mm = m / gcd(n, m);
	lsm = gcd(n, m) * nn * mm;
	cout << lsm;

	return 0;
}