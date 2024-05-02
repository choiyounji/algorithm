#include<iostream>

using namespace std;

int n;
int column[15];
int l[30];
int r[30];
int cnt = 0;

void dfs(int row) {
	if (row == n) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!column[i] && !l[row + i] && !r[row - i + n]) {
			column[i] = 1;
			l[row + i] = 1;
			r[row - i + n] = 1;
			dfs(row + 1);
			column[i] = 0;
			l[row + i] = 0;
			r[row - i + n] = 0;
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	dfs(0);
	cout << cnt;
	return 0;
}