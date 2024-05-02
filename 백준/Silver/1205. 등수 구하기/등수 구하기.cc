#include<iostream>
#include<vector>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, ns, p;

	cin >> n >> ns >> p;
	vector<int> v;
	v.assign(p, 0);
	if (n == 0) {
		cout << 1;
		return 0;
	}
	else {
		int rank = 1;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			if (ns < tmp) {
				rank++;
			}
			else if (ns == tmp) {
				continue;
			}
			else {
				cout << rank;
				return 0;
			}
		}
		if (n>=p) {
			cout << -1;
		}
		else {
			cout << rank;
		}
	}
	
	return 0;
}