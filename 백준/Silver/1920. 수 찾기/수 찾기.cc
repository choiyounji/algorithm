#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v;
int n;

bool find(int tmp) {
	int s = 0, e = n - 1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (v[mid] == tmp) {
			return true;
		}
		if (v[mid] < tmp) {
			s = mid + 1;
		}
		else if (v[mid] > tmp) {
			e = mid - 1;
		}
	}
	return false;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());  //이분탐색 할거임. 정렬

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		if (find(tmp)) {
			cout << 1 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}
	return 0;
}
