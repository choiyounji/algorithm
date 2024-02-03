#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            answer+=s[i];
            continue;
        }
        if(s[i]>='A'&&s[i]<='Z'){
            if(s[i]+n>'Z')
                answer+=s[i]-26+n;
            else
                answer+=s[i]+n;
            continue;
        }
        if(s[i]>='a'&&s[i]<='z'){
            if(s[i]+n>'z')
                answer+=s[i]-26+n;
            else
                answer+=s[i]+n;
        }
    }
    return answer;
}