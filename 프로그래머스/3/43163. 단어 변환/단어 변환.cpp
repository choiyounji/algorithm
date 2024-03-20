#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

bool visited[50]={0,};
int answer = 50;

bool check(string a, string b){
    int cnt=0;
    for(int i=0;i<a.length();i++){
        if(a[i]!=b[i])
            cnt++;
    }
    if(cnt==1){
        return true;
    }
    return false;
}

void dfs(string current, string target, vector<string> words, int step){
    if(step>=answer){
        return;
    }
    if(current==target){
        answer=min(answer,step);
        return;
    }
    for(int i=0;i<words.size();i++){
        if(check(words[i],current)==1&&visited[i]==0){
            visited[i]=1;
            //cout<<"in"<<i<<"\n";
            dfs(words[i],target,words,step+1);
            //cout<<"out"<<i<<"\n";
            visited[i]=0;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    dfs(begin, target, words, 0);
    if(answer==50){
        return 0;
    }
    return answer;
}