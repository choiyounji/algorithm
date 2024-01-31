#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    for(int i=0;i<number.size()-2;i++){
        for(int j=i+1;j<number.size()-1;j++){
            for(int k=j+1;k<number.size();k++){
                int temp=number[i]+number[j]+number[k];
                cout<<temp<<"\n";
                if(temp==0)
                    answer++;
            }
        }
    }
    return answer;
}