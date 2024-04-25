#include<iostream>

using namespace std;

bool checks(string s) {
	int vowel = 0;
	if (s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') {
		vowel++;
	}
	//이전 글자
	char fs = s[0];
	int flag = 0;
	if (vowel == 1) {
		flag = 1;
	}
	int cnt = 1;
	//첫글자 모음이면 flag=1로 시작, 자음이면 flag=0으로 시작
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
			vowel++;
			//모음인데 모음 나온거
			if (flag) {
				cnt++;
				if (cnt >= 3) {
					return false;
				}
			}
			//모음이었는데 자음 나온거
			else {
				cnt = 1;
				flag = 1;
			}
		}
		else {
			//모음이었는데 자음 나온거
			if (flag) {
				cnt = 1;
				flag = 0;
			}
			//자음이었는데 자음 나온거
			else {
				cnt++;
				if (cnt >= 3) {
					return false;
				}
			}
		}
		//이전 글자와 현재 글자 같음
		if (s[i] == fs) {
			//e아니면 o는 ㄱㅊ
			if (s[i] == 'e' || s[i] == 'o') {
				fs = s[i];
				continue;
			}
			else {
				return false;
			}
		}
		else {
			fs = s[i];
		}
	}
	if (vowel == 0) {
		return false;
	}
	else {
		return true;
	}
}

int main() {
	string s;
	while (true) {
		cin >> s;
		if (s == "end") {
			break;
		}
		else {
			if (checks(s)) {
				cout << "<" << s << "> is acceptable.\n";
			}
			else {
				cout << "<" << s << "> is not acceptable.\n";
			}
		}
	}
	return 0;
}