#include<iostream>

using namespace std;
int map[100][100];
int n;
int rblock[13][4] = { {0,0,0,0},{0,1,2,3},{0,0,1,1},{0,1,1,2},{0,0,0,1},{0,1,2,2},{0,1,1,1},{0,0,1,2},{0,0,0,1},{0,1,1,2},{0,1,1,1},{0,1,1,2} ,{0,0,1,1} };
int cblock[13][4] = { {0,1,2,3},{0,0,0,0},{0,1,1,2},{0,-1,0,-1},{0,1,2,2},{0,0,0,-1},{0,0,1,2},{0,1,0,0},{0,1,2,1},{0,-1,0,0},{0,-1,0,1},{0,0,1,0} ,{0,1,0,1} };
bool isrange(int r, int c) {
	return r >= 0 && r < n&& c >= 0 && c < n;
}
int calc(int n) {
	int m = -2000000000;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 13; k++) {
				int sum = 0;
				bool ok = true;
				for (int l = 0; l < 4; l++) {
					int cr = i + rblock[k][l];
					int cc = j + cblock[k][l];
					if (isrange(cr, cc)) {
						sum += map[cr][cc];
					}
					else {
						ok = false;
					}
				}
				if (ok) {
					if (m < sum) {
						m = sum;
					}
				}
				
			}
		}
	}
	return m;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t = 1;
	while (true) {
		cin >> n;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		int ans = calc(n);

		cout << t << ". " << ans << "\n";
		t++;
	}
	return 0;
}