#include <string>
#include <vector>

using namespace std;

string target="";
int cnt=-1,answer=0;
string aeiou="AEIOU";

void dfs(string s){
    cnt++;
    if(s==target){
        answer=cnt;
        return;
    }
    if(s.length()>=5){
        return;
    }
    for(int i=0;i<5;i++){
        dfs(s+aeiou[i]);
    }
}
int solution(string word) {
    target=word;
    dfs("");
    return answer;
}