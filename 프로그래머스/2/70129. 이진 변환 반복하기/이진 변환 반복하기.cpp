#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string toBinary(int l){
    string temp="";
    while(l!=0){
        temp+=to_string(l%2);
        l/=2;
    }
    reverse(temp.begin(),temp.end());
    return temp;
}

vector<int> solution(string s) {
    vector<int> answer;
    int cnt1=0, cnt2=0;
    string ans=s;
    while(true){
        string temp="";
        for(int i=0;i<ans.length();i++){
            if(ans[i]=='0'){
                cnt1++;
            }
            else{
                temp+=ans[i];
            }
        }
        ans=toBinary(temp.length());
        cout<<ans;
        if(ans.length()==1){
            cnt2++;
            break;
        }
        cnt2++;
    }
    answer.push_back(cnt2);
    answer.push_back(cnt1);
    return answer;
}