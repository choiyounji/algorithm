#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    if(n%2!=0)
        n--;
    for(int i=n;i>0;i-=2){
        answer+=i;
    }
    return answer;
}