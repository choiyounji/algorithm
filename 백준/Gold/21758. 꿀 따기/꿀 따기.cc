#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int honey[100001] = { 0, };
int sum[100001] = { 0, };
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> honey[i];
		sum[i] = sum[i - 1] + honey[i];
	}

	int ans = 0;

	//벌 벌 통
	for (int i = 2; i < n; i++) {
		int m = sum[n] - sum[1] - honey[i] + sum[n] - sum[i];
		ans = max(ans, m);
	}
	//벌 통 벌
	for (int i = 2; i < n; i++) {
		int m = sum[i] - honey[1] + sum[n - 1] - sum[i - 1];
		ans = max(ans, m);
	}
	//통 벌 벌
	for (int i = 2; i < n; i++) {
		int m = sum[i - 1] + sum[n - 1] - honey[i];
		ans = max(ans, m);
	}
	cout << ans;
	
	return 0;
}