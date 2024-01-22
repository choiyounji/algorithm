#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    //1.hashmap만들기
    unordered_map<string, int> m;
    for(int i=0;i<participant.size();i++){
        m[participant[i]]++;
    }
    //2.hashmap에서 완주한 선수들 빼기
    for(int i=0;i<completion.size();i++){
        m[completion[i]]--;
    }
    //3.value가 0이 아닌 애 반환
    for(int i=0;i<participant.size();i++){
        if(m[participant[i]]!=0){
            answer=participant[i];
        }
    }
    return answer;
}