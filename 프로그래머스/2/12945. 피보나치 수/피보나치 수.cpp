#include <string>
#include <vector>

using namespace std;
#define MAX 100001
int arr[MAX]={0,};

int solution(int n) {
    int answer = 0;
    arr[1]=1;
    for(int i=2;i<MAX;i++){
        arr[i]=(arr[i-2]+arr[i-1])%1234567;
    }
    return arr[n];
}