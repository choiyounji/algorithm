#include <string>
#include <vector>
#include<algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(),times.end());
    long long min=1,max=(n/times.size())*times.back();
    long long answer = 0;
    while(min<=max){
        long long mid=(min+max)/2;
        long long sum=0;
        for(int i=0;i<times.size();i++){
            sum+=mid/times[i];
        }
        if(sum>=n){
            answer=mid;
            max=mid-1;
        }else{
            min=mid+1;
        }
    }
    return answer;
}