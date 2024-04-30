#include<iostream>
#include<queue>

using namespace std;
int map[1000][1000] = { 0, };
int visit[1000][1000] = { 0, };
int ans[1000][1000]={ 0, };
typedef pair<int, int> ii;
int n, m;
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };

bool isrange(int r, int c) {
	if (r >= 0 && r < n && c >= 0 && c < m) {
		return true;
	}
	return false;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	queue<ii> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans[i][j] = -1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp;
			cin >> tmp;
			map[i][j] = tmp;
			if (tmp == 2) {
				q.push({ i,j });
				ans[i][j] = 0;
				visit[i][j] = 1;
			}
			if (tmp == 0) {
				ans[i][j] = 0;
			}
		}
	}

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int cr = r + dr[i];
			int cc = c + dc[i];
			if (isrange(cr,cc)&&!visit[cr][cc]) {
				visit[cr][cc] = 1;
				if (map[cr][cc] == 1) {
					ans[cr][cc] = ans[r][c]+1;
					q.push({ cr,cc });
				}
				if (map[cr][cc] == 0) {
					ans[cr][cc] = 0;
				}

			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout<<ans[i][j]<<" ";
		}
		cout << "\n";
	}
	return 0;
}