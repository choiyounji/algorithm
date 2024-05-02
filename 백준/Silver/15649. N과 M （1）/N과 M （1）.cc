#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<int> num(9);
vector<bool> check(9);

void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << num[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			num[cnt] = i;
			check[i] = 1;
			dfs(cnt+1);
			check[i] = 0;
		}
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m;
	dfs(0);

	return 0;
}