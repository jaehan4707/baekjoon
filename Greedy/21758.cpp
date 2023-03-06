//백준 골드5 꿀따기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
int n;
vector<int>graph;
vector<vector<int> >honey;
int main(){
    
    int big = 0,bidx=0,sum1,sum2,sum3=0,total=0;
    cin>>n;
    graph.resize(n,0);
    honey.resize(n,vector<int>(2,0)); //열이 0인 경우는 왼쪽합, 열이 1인 경우는 오른쪽합
    for(int i=0; i<n; i++){
        cin>>graph[i];
        total+=graph[i]; //전체 꿀의 양을 total에 저장.
    }
    int tempsum=0;
    for(int i=0; i<n; i++){
        honey[i][1]= total -tempsum-graph[i];
        honey[i][0]=tempsum;
        tempsum+=graph[i];
    }
    for(int i=1; i<n-1;i++){ //벌통이 맨 오른쪽에 있는 경우
        if(sum1<honey[0][1]+honey[i][1]-graph[i]){ //0은 오른쪽 끝단으로 고정시키고, 나머지 벌의 위치를 i로 돌려서 최대값을 찾음.
            sum1 = honey[0][1]+honey[i][1]-graph[i]; //0번 위치에서 오른쪽 합 + i위치에서 오른쪽 합 - i위치 꿀 양
        }    
    }
    for(int i= n-2; i>0; i--){ //벌통이 맨 왼쪽에 있는 경우 
        if(sum2<honey[n-1][0]+honey[i][0]-graph[i]){ //n-1은 오른쪽 끝단으로 고정시키고, 나머지 벌의 위치를 i로 돌려서 최대값을 찾음.
            sum2=honey[n-1][0]+honey[i][0]-graph[i]; //n-1 위치에서 왼쪽 합 + i 위치에서 왼쪽 합 - i 위치에 해당하는 꿀 양
        }
    }
    for(int i=1; i<n-1; i++){
        if(big<graph[i]){
            big=graph[i];
            bidx=i;
        }
    }
    sum3 = honey[0][1]-(honey[bidx][1])+honey[n-1][0]-(honey[bidx][0]); //0번 위치에서 오른쪽 합 - 벌통에서 오른쪽합 + n-1 위치에서 왼쪽합 - 벌통위치에서 왼쪽합
    int answer= max(max(sum1,sum2),sum3); //3가지 경우의 수중에서 최대값을 구합니다.
    cout<<answer;

}