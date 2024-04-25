#include<iostream>

using namespace std;
typedef pair<int, int> ii;
ii person[50];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		person[i].first = x;
		person[i].second = y;
	}
	for (int i = 0; i < n; i++) {
		int cx = person[i].first;
		int cy = person[i].second;
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}
			else {
				if (cx < person[j].first && cy < person[j].second) {
					cnt++;
				}
			}
		}
		cout << cnt + 1 << " ";
	}
	return 0;
}