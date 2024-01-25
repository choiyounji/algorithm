#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(string a, string b){
    return a+b>b+a;
}
string solution(vector<int> numbers) {
    vector<string> nums;
    for(int i=0;i<numbers.size();i++){
        nums.push_back(to_string(numbers[i]));
    }
    sort(nums.begin(),nums.end(),cmp);
    string answer = "";
    for(int i=0;i<nums.size();i++){
        if(nums[0]=="0"){
            answer+="0";
            break;
        }
        answer+=nums[i];
    }
    
    return answer;
}