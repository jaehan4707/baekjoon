/*
백준 실버3 돌 게임3
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> cost = {1, 3, 4};
// vector<vector<int>>DP;
vector<int> DP;
int main()
{
    cin >> n;
    DP.resize(n + 1, 0);
    DP[1]=1; //1은 상근이 승, 0은 찬영이 승
    DP[2]=0; 
    DP[3]=1;
    DP[4]=1;
    for(int i=5; i<=n;i++){
        //5부터 갈 수 있는 경우의 수는 3가지 DP[4], DP[2], DP[1]? 일단 여기서
        DP[i]=min(min(DP[i-1], DP[i-3]),DP[i-4]);
        if(DP[i]==1){
            DP[i]=0;
        } 
        else{
            DP[i]=1;
        }
        //한번 뽑으면 찬영이 차례임.
        //나는 상근이가 이기는 경우의 수를 골라야하니 각각 이전 단계에서는 max를 뽑아서 찬영이가 이기는 경우의 수가 있는지 찾아야함.
        //하나라도 DP[i-1], DP[i-3], DP[i-4]가 하나라도 1이 된다면 상근이가 완벽하게 이길 수 있음.
        //i에서 뽑았으니 i에 기록되는건 min?
    }
    //DP[i]는 돌이 i개일떄 먼저 뽑는 사람이 이기면 1, 후공이 이기면 0을 의미함.
    if(DP[n]==1){
        cout<<"SK"<<endl;
    }
    else{
        cout<<"CY"<<endl;
    }
}