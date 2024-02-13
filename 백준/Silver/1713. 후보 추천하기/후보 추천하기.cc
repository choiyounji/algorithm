#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[1001] = { 0, };
vector<int> v;

int main() {
	int n;
	cin >> n;
	int totalNomi;
	cin >> totalNomi;
	for (int i = 0; i < totalNomi; i++) {
		int nomi;
		cin >> nomi;
		
		// 번호 추천 횟수>0이라는 것은 사진틀에 올라와있다는 것을 의미
		if (arr[nomi] > 0) {
			arr[nomi]++;
			continue;
		}
		else {
			//아직 사진틀이 다 안찼을 경우
			if (v.size() < n) {
				arr[nomi]++;
				v.push_back(nomi);
			} //사진틀이 다 찼으면 조건에 따라 사진 제거해야함
			else {
				int max = 2000;
				int index = 0;
				//추천받은 횟수 최소인 학생 찾기
				for (int j = 0; j < n; j++) {
					if (arr[v[j]] < max) {
						max = arr[v[j]];
						index = j;
					}
				}
				arr[v[index]] = 0;
				v.erase(v.begin() + index);
				v.push_back(nomi);
				arr[nomi]++;
			}
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	return 0;
}
