#include <iostream>
#include<string>
#include<stack>
using namespace std;
stack<int> st;
int solution(string s)
{
    int answer = -1;

    //스택이 비워져도 문자열 남아있으면 계속 진행
    for(int i=0;i<s.length();i++){
        if(st.empty()){
            st.push(s[i]);
            continue;
        }
        char c=st.top();
        if(c==s[i]){
            st.pop();
        }else{
            st.push(s[i]);
        }  
    }
    if(st.empty())
        answer=1;
    else answer=0;
    return answer;
}
