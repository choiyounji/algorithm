#include <string>
#include <vector>

using namespace std;
int st1(vector<int> answers){
    int i=0, ans=0;
    while(i<answers.size()){
        if(i%5==0){
            if(answers[i]==1){
                ans++;
            }
        }
        if(i%5==1){
            if(answers[i]==2){
                ans++;
            }
        }
        if(i%5==2){
            if(answers[i]==3){
                ans++;
            }
        }
        if(i%5==3){
            if(answers[i]==4){
                ans++;
            }
        }
        if(i%5==4){
            if(answers[i]==5){
                ans++;
            }
        }
        i++;
    }
    return ans;
}
int st2(vector<int> answers){
    int i=0,ans=0;
    while(i<answers.size()){
        if(i%2==0){
            if(answers[i]==2){
                ans++;
            }
        }
        if(i%8==1){
            if(answers[i]==1){
                ans++;
            }
        }
        if(i%8==3){
            if(answers[i]==3){
                ans++;
            }
        }
        if(i%8==5){
            if(answers[i]==4){
                ans++;
            }
        }
        if(i%8==7){
            if(answers[i]==5){
                ans++;
            }
        }
        i++;
    }
    return ans;
}
int st3(vector<int> answers){
    int i=0,ans=0;
    while(i<answers.size()){
        if(i%10==0||i%10==1){
            if(answers[i]==3){
                ans++;
            }
        }
        if(i%10==2||i%10==3){
            if(answers[i]==1){
                ans++;
            }
        }
        if(i%10==4||i%10==5){
            if(answers[i]==2){
                ans++;
            }
        }
        if(i%10==6||i%10==7){
            if(answers[i]==4){
                ans++;
            }
        }
        if(i%10==8||i%10==9){
            if(answers[i]==5){
                ans++;
            }
        }
        i++;
    }
    return ans;
}
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int max=0;
    if(st1(answers)>st2(answers)){
        if(st3(answers)>st1(answers)){
            answer.push_back(3);
        }
        else if(st3(answers)==st1(answers)){
            answer.push_back(1);
            answer.push_back(3);
        }
        else{
            answer.push_back(1);
        }
        
    } else if(st1(answers)==st2(answers)){
        if(st3(answers)>st1(answers)){
            answer.push_back(3);
        }
        else if(st3(answers)==st1(answers)){
            answer.push_back(1);
            answer.push_back(2);
            answer.push_back(3);
        }
        else{
            answer.push_back(1);
            answer.push_back(2);
        }
    } else{
        if(st3(answers)>st2(answers)){
            answer.push_back(3);
        }
        else if(st3(answers)==st2(answers)){
            answer.push_back(2);
            answer.push_back(3);
        }
        else{
            answer.push_back(2);
        }
    }
    
    return answer;
}