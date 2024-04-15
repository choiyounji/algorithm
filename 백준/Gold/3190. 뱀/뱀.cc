#include<iostream>
#include<queue>

using namespace std;
int n, k,l;
int map[101][101]; //비어있으면 0, 사과는 1, 뱀은 2
typedef pair<int, char> ic;
typedef pair<int, int>ii;
typedef pair<ii, int> iii;

int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
bool isrange(int r, int c) {
	if (r >= 1 && r <= n && c >= 1 && c <= n) {
		return true;
	}
	return false;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
	}
	cin >> l;
	queue<ic> q;
	queue<iii> taildir;
	for (int i = 0; i < l; i++) {
		int a;
		char c;
		cin >> a >> c;
		q.push( { a,c });
	}
	int dir = 0,t=0,tdir=0;
	int hr = 1, hc = 1,tr=1,tc=1;
	map[1][1] = 2;
	while (true) {
		t++;
		//cout << t << "\n";
		int nr = hr + dr[dir];
		int nc = hc + dc[dir];
		if (isrange(nr, nc)) {
			//cout << nr << " " << nc << "\n";
			//뱀 머리 이동한 곳에 사과 있는 경우
			if (map[nr][nc] == 1) {
				map[nr][nc] = 2;
				hr = nr;
				hc = nc;
			}
			//뱀 머리 이동한 곳이 뱀일 경우
			else if (map[nr][nc] == 2) {
				break;
			}
			//비어있을 경우
			else {
				map[tr][tc] = 0;
				if (!taildir.empty()) {
					int tnr = taildir.front().first.first;
					int tnc = taildir.front().first.second;
					if (tr == tnr && tc == tnc) {
						tdir = taildir.front().second;
						taildir.pop();
						//cout << "tail change\n";
					}
					//cout << "movet\n";
					tr += dr[tdir];
					tc += dc[tdir];
					//cout << tr << " " << tc << "\n";
				}
				else {
					//cout << "movet\n";
					tr += dr[tdir];
					tc += dc[tdir];
					//cout << tr << " " << tc << "\n";
				}
				map[nr][nc] = 2;
				hr = nr;
				hc = nc;
			}
		}
		else {
			break;
		}
		if (!q.empty()) {
			int time = q.front().first;
			char d = q.front().second;
			if (t == time) {
				//cout << "changedir ";
				if (d == 'L') {
					dir = (dir +3) % 4;
					taildir.push({ {hr,hc},dir});
					
					//cout << "push" << hr<< " " << hc<< "\n";
				}
				else {
					dir = (dir + 1) % 4;
					taildir.push({ {hr,hc},dir });
					//cout << "push" << hr<< " " << hc << "\n";
				}
				//cout << dir << "\n";
				q.pop();
			}
		}
	}
	cout << t;
	return 0;
}