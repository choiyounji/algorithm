#include<iostream>
#include<string>
#include<stack>
#include<map>

using namespace std;

map<char, char> m;

bool isBalanced(string& s) {
	stack<int> st;
	m[']'] = '[';
	m[')'] = '(';
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '[' || s[i] == '(') {
			st.push(s[i]);
			continue;
		}
		if (s[i] == ']' || s[i] == ')') {
			if (st.empty() || st.top() != m[s[i]]) {
				return false;
			}
			st.pop();
			continue;
		}
	}
	return st.empty();
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s;
	while (getline(cin, s)) {
		if (s == ".") {
			break;
		}
		if (isBalanced(s)) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}

	}
	return 0;
}