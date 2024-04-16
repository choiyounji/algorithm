#include<iostream>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	long long n;
	cin >> n;
	long long a = 1;
	long long idx = 1;
	long long cnt = 2;
	while (true) {
		a += idx * 6 ;
		idx++;
		if (a<n) {
			cnt++;
		}
		else {
			break;
		}
	}
	if (n == 1) {
		cout << 1;
	}
	else {
		cout << cnt;
	}
	return 0;
}