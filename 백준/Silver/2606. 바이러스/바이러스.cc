#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int n, vector<vector<int>>& adj_list) {
	int count = 0;
	queue<int> que;
	vector<bool> visited(n + 1, false);

	que.push(1);
	visited[1] = true;

	while (!que.empty()) {
		int curr = que.front();
		que.pop();
		for (int i = 0; i < adj_list[curr].size(); i++) {
			if (visited[adj_list[curr][i]]) {
				continue;
			}
			visited[adj_list[curr][i]] = true;
			que.push(adj_list[curr][i]);
			count++;
		}
	}
	return count;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj_list(n + 1, vector<int>());
	int a, b;
	while (m--) {
		cin >> a >> b;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}
	cout << bfs(n, adj_list);
	return 0;
}