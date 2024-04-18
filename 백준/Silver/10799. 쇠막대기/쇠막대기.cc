#include<iostream>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;

	int ans = 0;
	int cnt = 0;
	bool check = false;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			cnt++;
			check = true;
		}
		else {
			if (check) {
				cnt--;
				ans += cnt;
				check = false;
			}
			else {
				ans++;
				cnt--;
				check = false;
			}
		}

	}
	cout << ans;
	return 0;
}