#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> st;
    st.push(arr[0]);
    for(int i=1;i<arr.size();i++){
        int num=st.top();
        if(num!=arr[i]){
            st.push(arr[i]);
        }
    }
    int size=st.size();
    for(int i=0;i<size;i++){
        int num=st.top();
        st.pop();
        answer.push_back(num);
    }
    reverse(answer.begin(),answer.end());
    return answer;
}