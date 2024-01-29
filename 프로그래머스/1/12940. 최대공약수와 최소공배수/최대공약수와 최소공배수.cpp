#include <string>
#include <vector>
#include <iostream>

using namespace std;

int gcd(int a, int b){
    if(a%b==0)
        return b;
    return gcd(b,a%b);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    answer.push_back(gcd(n,m));
    answer.push_back(n*m/gcd(n,m));
    return answer;
}