#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int j=0;
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            j=0;
            answer+=s[i];
            continue;
        }
        if(j%2==0){
            answer+=toupper(s[i]);
        }else{
            answer+=tolower(s[i]);
        }
        j++;
    }
    return answer;
}