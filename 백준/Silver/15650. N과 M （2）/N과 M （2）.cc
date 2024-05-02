#include<iostream>

using namespace std;

int n, m;
int num[9] = { 0, };

void dfs(int cnt, int start) {
	if (cnt == m) {
		for (int i = 0; i < cnt; i++) {
			cout << num[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = start; i <= n; i++) {
		num[cnt] = i;
		dfs(cnt + 1, i + 1);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	dfs(0,1);
	return 0;
}