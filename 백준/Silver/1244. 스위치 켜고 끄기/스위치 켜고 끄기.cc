#include<iostream>

using namespace std;

int status[101] = { 0, };
int switchcnt;

void execute(int sex, int num) {
	if (sex == 1) {
		for (int i = num; i <= switchcnt; i += num) {
			status[i] = !status[i];
		}
	}
	else if(sex==2){
		int p = 1;
		while (true) {
			if (num + p <= switchcnt && num - p >= 1) {
				if (status[num + p] == status[num - p]) {
					p++;
					continue;
				}
				else {
					status[num] = !status[num];
					for (int i = 1; i < p; i++) {
						status[num + i] = !status[num + i];
						status[num - i] = !status[num - i];
					}
					break;
				}
			}
			else {
				status[num] = !status[num];
				for (int i = 1; i < p; i++) {
					status[num + i] = !status[num + i];
					status[num - i] = !status[num - i];
				}
				break;
			}		
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> switchcnt;
	for (int i = 1; i <= switchcnt; i++) {
		cin >> status[i];
	}
	int studentcnt;
	cin >> studentcnt;
	for (int i = 0; i < studentcnt; i++) {
		int sex, num;
		cin >> sex >> num;
		execute(sex, num);
	}
	int c = 0;
	for (int i = 1; i <= switchcnt; i++) {
		cout << status[i] << " ";
		c++;
		if (c == 20) {
			cout << "\n";
			c = 0;
		}
	}
	return 0;
}