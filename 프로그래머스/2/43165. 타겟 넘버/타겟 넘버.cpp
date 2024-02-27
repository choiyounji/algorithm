#include <string>
#include <vector>

using namespace std;
int answer=0;
void dfs(int index, int size, int current, int target, vector<int> &numbers){
    if(index==size){
        if(current==target){
            answer++;
        }
        return;
    }
    dfs(index+1,size,current+numbers[index],target, numbers);
    dfs(index+1,size,current-numbers[index],target,numbers);
}
int solution(vector<int> numbers, int target) {
    dfs(0,numbers.size(),0,target,numbers);
    return answer;
}