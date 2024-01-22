#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int, int> ci;

int bfs(int n, int m, int count, vector<vector<int>>& matrix, queue<ci>& que) {
	int dr[] = { -1,+1,0,0 };
	int dc[] = { 0,0,-1,+1 };
	int time = 0;
	while (!que.empty()) {
		int r = que.front().first;
		int c = que.front().second;
		que.pop();
		time = matrix[r][c];
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr >= 0 && nc >= 0 && nr < n && nc < m && matrix[nr][nc] == 0) {
				que.push({ nr,nc });
				matrix[nr][nc] = time + 1;
				count--;
			}
		}
	}
	return (count == 0 ? time - 1 : -1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int m, n;
	cin >> m >> n;
	vector<vector<int>> matrix(n, vector<int>(m, 0));
	queue<ci> que;

	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
			if (matrix[i][j] == 1) {
				que.push({ i,j });
			}
			else if (matrix[i][j] == 0) {
				count++;
			}
		}
	}
	cout << bfs(n, m, count, matrix, que);
	return 0;
}