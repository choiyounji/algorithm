#include<iostream>

using namespace std;
int check[20000] = { 0, };
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	string table;
	cin >> table;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (table[i] == 'P') {
			for (int j = i - k; j <= i + k; j++) {
				if (j >= 0 && j < n) {
					if (table[j] == 'H'&&check[j]!=1) {
						cnt++;
						check[j] = 1;
						break;
					}
				}
			}
		}
	}
	cout << cnt;
	return 0;
}