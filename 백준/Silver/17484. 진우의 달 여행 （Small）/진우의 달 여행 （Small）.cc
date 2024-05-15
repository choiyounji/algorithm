#include<iostream>
#include<queue>

using namespace std;

int n, m;
int dc[3] = { -1,0,1 };
int map[6][6] = { 0, };
int ans = 10000;

bool inRange(int r, int c) {
	if (r >= 0 && r < n && c >= 0 && c < m) {
		return true;
	}
	return false;
}
void dfs(int cost, int r, int c, int pre) {
	if (r+1 == n) {
		if (cost < ans) {
			ans = cost;
		}
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (inRange(r+1, c + dc[i])) {
			if (i != pre) {
				dfs(cost + map[r + 1][c + dc[i]], r + 1, c + dc[i], i);
			}
		}
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	
	for (int i = 0; i < m; i++) {
		int cost = map[0][i];
		dfs(cost, 0, i, -1);
	}
	cout << ans;
	return 0;
}