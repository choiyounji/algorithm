#include <string>
#include <vector>

using namespace std;

int solution(int n, int k) {
    int answer = 0;
    int m=n/10;
    if(m<=k)
        k-=m;
    return n*12000+k*2000;
}