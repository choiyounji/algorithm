#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int index=0;
    queue<int> q;
    int cbw=0;
    while(true){
        if(index==truck_weights.size()){
            answer+=bridge_length;
            break;
        }
        if(q.size()==bridge_length){
            cbw-=q.front();
            q.pop();
        }
        if(cbw+truck_weights[index]<=weight){
            q.push(truck_weights[index]);
            cbw+=truck_weights[index];
            index++;
        } else{
            q.push(0);
        }
        answer++;
    }
    return answer;
}