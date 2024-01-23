#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> remaining_days;
    for(int i=0;i<progresses.size();i++){
        int num=0;
        if((100-progresses[i])%speeds[i]==0)
            num=(100-progresses[i])/speeds[i];
        else
            num=(100-progresses[i])/speeds[i]+1;
        remaining_days.push(num);
    }
    
    int d=remaining_days.front();
    remaining_days.pop();
    int count=1;
    while(!remaining_days.empty()){
        if(remaining_days.front()<=d){
            count++;
            remaining_days.pop();
            continue;
        }
        answer.push_back(count);
        count=1;
        d=remaining_days.front();
        remaining_days.pop();
    }
    answer.push_back(count);
    return answer;
}