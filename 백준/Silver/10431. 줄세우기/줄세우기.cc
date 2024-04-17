#include<iostream>
#include<vector>

using namespace std;
int arr[20];
int move(vector<int> v) {
	int cnt = 0;
	vector<int> tmp;
	tmp.push_back(v[0]);
	for (int i = 1; i < 20; i++) {
		int idx = tmp.size();
		for (int j = 0; j < tmp.size(); j++) {
			if (v[i] < tmp[j]) {
				idx = j;
				break;
			}
		}
		cnt += tmp.size() - idx;
		//cout<<cnt;
		tmp.insert(tmp.begin()+idx, v[i]);
	}
	return cnt;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int p;
	cin >> p;
	int n;
	while (p--) {
		cin >> n;
		vector<int> v;
		for (int i = 0; i < 20; i++) {
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
		}
		cout << n << " " << move(v) << "\n";
	}
	return 0;
}