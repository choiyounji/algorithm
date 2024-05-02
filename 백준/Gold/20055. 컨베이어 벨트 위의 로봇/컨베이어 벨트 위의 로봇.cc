#include<iostream>
#include<vector>

using namespace std;
int n, k;
int belt[201] = { 0, };
int robot[201] = { 0, };
typedef pair<int, int> ii;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 1; i <= 2*n; i++) {
		cin >> belt[i];
	}

	int t = 1;
	while (true) {
		//벨트 회전
		int tmpb = belt[2 * n];
		int tmpr = robot[2 * n];
		for (int i = 2 * n; i > 1; i--) {
			belt[i] = belt[i - 1];
			robot[i] = robot[i - 1];
		}
		robot[n] = 0;
		belt[1] = tmpb;
		robot[1] = tmpr;

		//로봇들 회전
		for (int i = n-1; i >=1; i--) {
			if (robot[i]&&belt[i+1]>=1&&robot[i+1]==0) {
				robot[i] = 0;
				robot[i + 1] = 1;
				belt[i + 1]--;
			}
		}
		robot[n] = 0;

		//로봇 올려
		if (robot[1] == 0&&belt[1]>=1) {
			robot[1] = 1;
			belt[1]--;
		}

		int cnt = 0;
		for (int i = 1; i <= 2 * n; i++) {
			if (belt[i] <= 0) {
				cnt++;
			}
		}
	
		/*
		cout << t << "\n";
		for (int i = 1; i <= 2 * n; i++) {
			cout << belt[i] << " ";
		}
		cout << "\n";
		for (int i = 1; i <= 2 * n; i++) {
			cout << robot[i] << " ";
		}
		cout << "\n";
		*/
		
		if (cnt >= k) {
			cout << t;
			break;
		}
		t++;
	}

	return 0;
}