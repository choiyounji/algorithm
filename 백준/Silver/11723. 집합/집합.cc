#include<iostream>

using namespace std;
bool arr[21];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int m;
	cin >> m;
	string s;
	int n;
	while (m--) {
		cin >> s;
		if (s == "empty") {
			for (int i = 1; i < 21; i++) {
				arr[i] = 0;
			}
		}
		else if (s == "all") {
			for (int i = 1; i < 21; i++) {
				arr[i] = 1;
			}
		}
		else {
			cin >> n;
			if (s == "add") {
				arr[n] = 1;
			}
			else if (s == "remove") {
				arr[n] = 0;
			}
			else if (s == "check") {
				if (arr[n]) {
					cout << 1 << "\n";
				}
				else {
					cout << 0 << "\n";
				}
			}
			else if (s == "toggle") {
				arr[n] = !arr[n];
			}
		}
	}
	return 0;
}