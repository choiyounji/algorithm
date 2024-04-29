#include <iostream>

using namespace std;
char map[1001][1001];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	int hx = 0;
	int hy = 0;
	//머리위치구하기
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == '*') {
				hx = i;
				hy = j;
				break;
			}
		}
		if (hx != 0 && hy != 0) {
			break;
		}
	}
	//심장위치로변경
	hx += 1;
	cout << hx << " " << hy << "\n";
	int lal = 0;
	for (int j = hy-1; j > 0; j--) {
		int i = hx;
		if (map[i][j] == '*') {
			lal++;
		}
		else {
			break;
		}
	}
	int ral = 0;
	for (int j = hy + 1; j <=n; j++) {
		int i = hx;
		if (map[i][j] == '*') {
			ral++;
		}
		else {
			break;
		}
	}
	int wl = 0,wx=0,wy=0;
	for (int i = hx + 1; i <= n; i++) {
		int j = hy;
		if (map[i][j] == '*') {
			wl++;
			wx = i;
			wy = j;
		}
		else {
			break;
		}
	}
	int lll = 0;
	for (int i = wx + 1; i <= n; i++) {
		int j = wy - 1;
		if (map[i][j] == '*') {
			lll++;
		}
		else {
			break;
		}
	}
	int rll = 0;
	for (int i = wx + 1; i <= n; i++) {
		int j = wy + 1;
		if (map[i][j] == '*') {
			rll++;
		}
		else {
			break;
		}
	}
	cout << lal << " " << ral << " " << wl << " " << lll << " " << rll;
	return 0;
}