#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    //1.nums의 종류 개수 파악
    unordered_map<int, int> m;
    for(int i=0;i<nums.size();i++){
        m[nums[i]]++;
    }
    //2.nums사이즈의 절반만 가져갈 수 있음
    if(m.size()>nums.size()/2){
        answer=nums.size()/2;
    }else{answer=m.size();}
    return answer;
}