#include<iostream>
#include<algorithm>

using namespace std;

int rail[30001];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, d, k, c;
	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++) {
		cin >> rail[i];
	}
	int m = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		bool check[3001] = { 0, };
		for (int j = i; j < i + k; j++) {
			if (!check[rail[j%n]]) {
				cnt++;
			}
			check[rail[j%n]]=true;
		}
		if (!check[c]) {
			cnt++;
		}
		//cout << cnt << "\n";
		m = max(cnt, m);
	}
	cout << m;
	return 0;
}