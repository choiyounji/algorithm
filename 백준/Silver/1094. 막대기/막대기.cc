#include<iostream>

using namespace std;
int arr[7] = { 1,2,4,8,16,32,64 };
int main() {
	int x;
	cin >> x;
	int ans = 0;
	for (int i = 6; i >= 0; i--) {
		if (x >= arr[i]) {
			ans++;
			x -= arr[i];
		}
	}
	cout << ans;
	return 0;
}