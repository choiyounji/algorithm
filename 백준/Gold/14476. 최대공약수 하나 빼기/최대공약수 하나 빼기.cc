#include<iostream>
#include<vector>

using namespace std;

int gcd(int a, int b) {
	if (a % b == 0) {
		return b;
	}
	return gcd(b, a % b);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> v(n + 2, 0),l(n + 2, 0),r(n + 2, 0);
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		v[i] = tmp;
	}
	l[1] = v[1];
	r[n] = v[n];
	for (int i = 2; i < n+1; i++) {
		l[i] = gcd(l[i - 1], v[i]);
	}
	for (int i = n - 1; i > 0; i--) {
		r[i] = gcd(v[i], r[i + 1]);
	}
	int maxG = -1,maxNum=-1;
	for (int i = 1; i <= n; i++) {
		int currentG = 0;
		if (l[i - 1] == 0) {
			currentG = r[i + 1];
		}
		else if (r[i + 1] == 0) {
			currentG = l[i - 1];
		}
		else {
			currentG = gcd(l[i - 1], r[i + 1]);
		}
		int currentNum = v[i];
		if (currentNum % currentG != 0) {
			if (maxG < currentG) {
				maxG = currentG;
				maxNum = currentNum;
			}
		}
	}
	if (maxG == -1) {
		cout << -1;
	}
	else {
		cout<<maxG<<" "<<maxNum;
	}
	return 0;
}
