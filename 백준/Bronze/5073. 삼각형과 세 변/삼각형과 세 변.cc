#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (true) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) {
			break;
		}
		vector<int> v;
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		sort(v.begin(), v.end());
		if (v[2] >= v[0] + v[1]) {
			cout << "Invalid\n";
			continue;
		}
		if (a == b && b == c) {
			cout << "Equilateral\n";
		}
		else if (a == b || b == c || c == a) {
			cout << "Isosceles\n";
		}
		else {
			cout << "Scalene\n";
		}
	}
	return 0;
}