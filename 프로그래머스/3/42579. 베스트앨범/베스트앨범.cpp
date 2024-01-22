#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
bool compare(const pair<string, pair<int, vector<pair<int,int>>>>& a, const pair<string, pair<int, vector<pair<int,int>>>> &b){
    return a.second.first>b.second.first;
}
bool compare2(const pair<int, int> &a, const pair<int, int> &b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second>b.second;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, pair<int, vector<pair<int,int>>>> total;
    
    for(int i=0;i<genres.size();i++){
        total[genres[i]].first+=plays[i];
        total[genres[i]].second.push_back(make_pair(i,plays[i]));
    }
    vector<pair<string, pair<int, vector<pair<int,int>>>>> v(total.begin(),total.end());
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++){
        sort(v[i].second.second.begin(), v[i].second.second.end(),compare2);
        if(v[i].second.second.size()>1){
            for(int j=0;j<2;j++){
            answer.push_back(v[i].second.second[j].first);
            }
        }
        else{
            answer.push_back(v[i].second.second[0].first);
        }
    }
    return answer;
}