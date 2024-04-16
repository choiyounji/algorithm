#include<iostream>

using namespace std;
int alpha[26];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;
	string tmp = "";
	for (int i = 0; i < s.length(); i++) {
		tmp += toupper(s[i]);
	}
	//cout << tmp;
	for (int i = 0; i < tmp.length(); i++) {
		alpha[tmp[i] - 'A']++;
	}
	int max = 0;
	int maxcnt = 1;
	int idx = 0;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] > max) {
			max = alpha[i];
			idx = i;
			maxcnt = 1;
			//cout << "new " << max;
		}
		else if (max!=0&&alpha[i] == max) {
			maxcnt++;
			//cout << "+1";
		}
	}
	if (maxcnt != 1) {
		cout << "?";
	}
	else {
		char c = idx + 'A';
		cout << c;
	}
	return 0;
}