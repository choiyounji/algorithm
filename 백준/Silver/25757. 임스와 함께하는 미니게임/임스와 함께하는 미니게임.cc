#include <iostream>
#include <set>

using namespace std;

int main() {
	int n;
	char c;
	cin >> n >> c;
	set<string> s;

	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		s.insert(tmp);
	}

	if (c == 'Y') {
		cout << s.size();
	}
	else if (c == 'F') {
		cout << s.size() / 2;
	}
	else if (c == 'O') {
		cout << s.size() / 3;
	}
	return 0;
}