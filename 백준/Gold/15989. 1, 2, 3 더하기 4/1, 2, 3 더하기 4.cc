#include<iostream>

using namespace std;
int dp[10001] = { 0, };
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;

	//1을 1단독으로 만드는 경우의 수는 1
	dp[1] = 1;
	//i-1를 만드는 모든 경우의 수에 +1을 하면 i를 만들 수 있으니까 i에 i-1의 경우의 수들을 모두 더 더해줌
	for (int i = 2; i <= 10000; i++) {
		dp[i] += dp[i - 1];
	}

	//2를 2단독으로 만드는 경우의 수 더해줌
	dp[2]++;
	//i-2를 만드는 모든 경우의 수에 +2를 하면 i를 만들 수 있으니까 i에 i-2의 경우의 수들을 모두 더 더해줌
	for (int i = 3; i <= 10000; i++) {
		dp[i] += dp[i - 2];
	}

	//3을 3단독으로 만드는 경우의 수 더해줌
	dp[3]++;
	//i-3을 만드는 모든 경우의 수에 +3를 하면 i를 만들 수 있으니까 i에 i-3의 경우의 수들을 모두 더 더해줌
	for (int i = 4; i <= 10000; i++) {
		dp[i] += dp[i - 3];
	}

	while (t--) {
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}
	return 0;
}
