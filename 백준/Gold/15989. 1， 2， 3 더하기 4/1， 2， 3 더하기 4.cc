#include<iostream>

using namespace std;
int dp[10001] = { 0, };
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	dp[0] = 1;
	for (int i = 1; i <= 3; i++) {
		for (int j = i; j <= 10000; j++) {
			dp[j] += dp[j - i];
		}
	}
	while (t--) {
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}
	return 0;
}