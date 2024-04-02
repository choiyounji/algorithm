#include <string>
#include <vector>

using namespace std;

string target="";
int cnt=0,answer=0;
string aeiou="AEIOU";

void dfs(string s){
    if(s==target){
        answer=cnt;
        return;
    }
    if(s.length()>=5){
        return;
    }
    for(int i=0;i<5;i++){
        cnt++;
        dfs(s+aeiou[i]);
    }
}
int solution(string word) {
    target=word;
    dfs("");
    return answer;
}