#include <string>
#include <vector>

using namespace std;

int toBinaryNum(int n){
    int num=0;
    while(n>0){
        if(n%2==1)
            num++;
        n/=2;
    }
    return num;
}

int solution(int n) {
    int answer = 0;
    int n1=toBinaryNum(n);
    while(true){
        n++;
        int n2=toBinaryNum(n);
        if(n1==n2)
            break;
        
    }
    return n;
}