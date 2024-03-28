#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int l=name.length();
    int minMove=l-1; //한 방향으로 쭉가면 최대니까 min값 초기값으로 설정
    for(int i=0;i<l;i++){
        if(name[i]-'A'>13){
            answer+='Z'-name[i]+1;
        } else{
            answer+=name[i]-'A';
        }
        
        int next=i+1;
        while(next<l&&name[next]=='A') next++;
        
        minMove=min(minMove, min(2*i+l-next,2*(l-next)+i));
    }
    answer+=minMove;
    return answer;
}