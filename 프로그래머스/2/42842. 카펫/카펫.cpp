#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total=brown+yellow;
    for(int i=total-1;i>=sqrt(total);i--){
        if(total%i==0){
            int r=i;
            int c=total/i;
            if((r+c)*2-4==brown){
                answer.push_back(r);
                answer.push_back(c);
                break;
            }
        }
    }
    return answer;
}