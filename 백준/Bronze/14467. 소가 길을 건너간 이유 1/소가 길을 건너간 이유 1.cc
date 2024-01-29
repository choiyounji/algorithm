#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main() {
	int n;
	vector<vector<int>> v(11,vector<int>());
	cin >> n;
	while (n--) {
		int cow, pos;
		cin >> cow >> pos;
		if (v[cow].empty())
			v[cow].push_back(pos);
		else if(v[cow][v[cow].size()-1]!=pos)
			v[cow].push_back(pos);
	}
	int count = 0;
	for (int i = 1; i < 11; i++) {
		if (v[i].size() > 1)
			count += v[i].size() - 1;
	}
	cout << count;
	
	return 0;
}