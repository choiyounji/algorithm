#include <iostream>
#include <vector>

using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	vector<bool> arr(n+1, 0);
	int cnt = 0;
	int num = 0;
	for (int i = 2; i <= n; i++) {
		if (arr[i]!=0)
			continue;
		for (int j = i; j <= n; j += i) {
			if (arr[j]!=0)
				continue;
			else {
				arr[j] = 1;
				cnt++;
				if (cnt == k) {
					num = j;
				}
					
			}
		}
	}
	cout << num;
	return 0;
}