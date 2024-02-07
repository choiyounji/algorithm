#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	int tar;
	cin >> tar;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] == tar)
			ans++;
	}
	cout << ans;
	return 0;
}