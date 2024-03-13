#include <string>
#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    int p=1;
    int answer=0;
    for(int i=citations.size()-1;i>=0;i--){
        if(citations[i]>=p){
            answer=p;
            //break; 넣으면 안됨 왜;?
        }
        p++;
    }
    return answer;
}