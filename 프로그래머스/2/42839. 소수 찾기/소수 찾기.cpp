#include <string>
#include <vector>
#include <math.h>
#include <string.h>
#include <set>

using namespace std;
set<int> s;

bool checkP(int n){
    if(n==0||n==1)
        return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
void combination(string current, string numbers){
    if(current!=""){
        s.insert(stoi(current));
    }
    for(int i=0;i<numbers.size();i++){
        combination(current+numbers[i],numbers.substr(0,i)+numbers.substr(i+1));
    }
    
}
int solution(string numbers) {
    int answer = 0;
    combination("",numbers);
    for(int num:s){
        if(checkP(num)){
            answer++;
        }
    }
    return answer;
}