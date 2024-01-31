#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i=1;i<n;i++){
        int temp=0;
        temp+=i;
        for(int j=i+1;j<=n;j++){
            if(temp>n)
                break;
            if(temp==n){
                answer++;
                break;
            }
            temp+=j;
        }
    }
    answer++;
    return answer;
}