#include<iostream>

using namespace std;
int arr[26] = { 0, };
int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		arr[s[i] - 'A']++;
	}
	string ans1 = "";
	string ans2 = "";
	string ans3 = "";
	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (arr[i] % 2 == 1) {
			cnt++;
		}
	}
	if (cnt > 1) {
		cout << "I'm Sorry Hansoo";
	}
	else {
		for (int i = 0; i < 26; i++) {
			if (arr[i] % 2 == 0) {
				for (int j = 0; j < arr[i] / 2; j++) {
					ans1 += char(i + 'A');
					ans3 = char(i + 'A') + ans3;
				}
			}
			if (arr[i] % 2 == 1) {
				for (int j = 0; j < arr[i] / 2; j++) {
					ans1 += char(i + 'A');
					ans3 = char(i + 'A') + ans3;
				}
				ans2 += char(i + 'A');
			}
		}
		cout << ans1 + ans2 + ans3;
	}
	return 0;
}