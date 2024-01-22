#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    unordered_map<string, int> m;
    //1. 각종류별 몇개인지 확인
    for(int i=0;i<clothes.size();i++){
        m[clothes[i][1]]++;
    }
    //2. 각종류별 곱하고 아무것도 안입은것 제외
    int n=1;
    for(auto num:m){
        n*=(num.second+1);
    }
    answer=n-1;
    return answer;
}