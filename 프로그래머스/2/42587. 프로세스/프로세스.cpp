#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> q;
    for(int i=0;i<priorities.size();i++){
        q.push(priorities[i]);
    }
    sort(priorities.begin(),priorities.end(),greater<>());
    while(true){
        if(q.front()==priorities[0]){
            answer++;
            q.pop();
            priorities.erase(priorities.begin());
            if(location==0){
                return answer;
            }
            else location--;
        } else{
            q.push(q.front());
            q.pop();
            location--;
            if(location<0)
                location=q.size()-1;
            
        }
    }
}