#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int k, n;
	cin >> k >> n;
	vector<int> v;
	for (int i = 0; i < k; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end(),greater<int>());

	long long s = 1;
	long long e = v[0];
	long long ans = 0;
	while (s <= e) {
		long long mid = (s + e) / 2;
		int cnt = 0;
		for (int i = 0; i < v.size(); i++) {
			cnt += v[i] / mid;
		}
		if (cnt >= n) {
			s = mid + 1;
			if (ans < mid) {
				ans = mid;
			}
		}
		else {
			e = mid - 1;
		}
	}
	cout <<ans;
	return 0;
}