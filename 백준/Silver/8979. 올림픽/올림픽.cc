#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct country {
	int num;
	int g, s, b;
};
vector<country> v;
bool cmp(country f, country l) {
	if (f.g == l.g) {
		if (f.s == l.s) {
			if (f.b == l.b) {
				return f.num < l.num;
			}
			return f.b > l.b;
		}
		return f.s > l.s;
	}
	return f.g > l.g;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	v.assign(n, {0,0,0});
	int q,w,e,r;
	for (int i = 0; i < n; i++) {
		cin >> q >> w >> e >> r;
		v[q - 1].num = q;
		v[q - 1].g = w;
		v[q - 1].s = e;
		v[q - 1].b = r;
	}
	sort(v.begin(), v.end(), cmp);
	//for (int i = 0; i < n; i++) {
		//cout << v[i].num;
	//}
	for (int i = n - 1; i >= 0; i--) {
		if (v[i].num == k) {
			int cg, cb, cs;
			cg = v[v[i].num].g;
			cs = v[v[i].num].s;
			cb = v[v[i].num].b;
			int cnt = 0;
			for (int j = i-1; j >= 0; j--) {
				if (cg == v[j].g && cs == v[j].s && cb == v[j].b) {
					cnt++;
				}
				else {
					break;
				}
			}
			cout << i - cnt + 1;

		}
	}
	return 0;
}