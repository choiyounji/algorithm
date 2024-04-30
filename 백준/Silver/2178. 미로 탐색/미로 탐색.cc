#include<iostream>
#include<queue>

using namespace std;

int map[101][101];
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};
int cnt[101][101] = { 0, };
int visit[101][101] = { 0, };
typedef pair<int, int>ii;
int n, m;

bool isrange(int r, int c) {
	if (r >= 1 && r <= n && c >= 1 && c <= m) {
		return true;
	}
	return false;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++) {
			map[i][j] = s[j - 1]-'0';
		}
	}

	queue<ii> q;
	q.push({ 1,1 });
	cnt[1][1] = 1;
	visit[1][1] = 1;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int cr = r + dr[i];
			int cc = c + dc[i];
			if (!visit[cr][cc]) {
				visit[cr][cc] = 1;
				if (map[cr][cc] == 1 && isrange(cr, cc)) {
					cnt[cr][cc] = cnt[r][c] + 1;
					q.push({ cr,cc });
				}
			}
		}
	}
	cout << cnt[n][m];
	return 0;
}