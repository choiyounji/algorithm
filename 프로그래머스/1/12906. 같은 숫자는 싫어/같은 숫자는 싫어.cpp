#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    queue<int> q;
    q.push(arr[0]);
    for(int i=1;i<arr.size();i++){
        int num=q.back();
        if(num!=arr[i]){
            q.push(arr[i]);
        }
    }
    int size=q.size();
    for(int i=0;i<size;i++){
        int num=q.front();
        q.pop();
        answer.push_back(num);
    }
    return answer;
}