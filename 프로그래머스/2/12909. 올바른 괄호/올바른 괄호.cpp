#include<string>
#include <iostream>
#include <stack>

using namespace std;
bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            st.push(s[i]);
        }
        else{
            if(st.empty())
                answer=false;
            else{
                st.pop();
            }

        }
        
    }
    if(!st.empty())
        answer=false;
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}