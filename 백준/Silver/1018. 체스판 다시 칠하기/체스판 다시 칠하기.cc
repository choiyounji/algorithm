#include<iostream>
#include<algorithm>

using namespace std;
char chess[50][50];
char white[50][50];
char black[50][50];

int check(int x, int y) {
	int a = 0, b = 0;
	for (int i = x; i < x+8; i++) {
		for (int j = y; j < y+8; j++) {
			if (chess[i][j] != black[i][j]) {
				a++;
			}
			if (chess[i][j] != white[i][j]) {
				b++;
			}
		}
	}
	return min(a, b);
}

int main() {
	//초기화
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			if ((i + j) % 2 == 0) {
				white[i][j] = 'W';
			}
			else {
				white[i][j] = 'B';
			}
		}
	}
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			if ((i + j) % 2 == 0) {
				black[i][j] = 'B';
			}
			else {
				black[i][j] = 'W';
			}
		}
	}
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> chess[i][j];
		}
	}
	int ans = 2500;
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			int tmp = check(i, j);
			if (tmp < ans) {
				ans = tmp;
			}
		}
	}
	cout << ans;
	return 0;
}