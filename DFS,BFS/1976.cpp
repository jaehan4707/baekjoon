#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m; //n은 도시의 수 , m은 여행 계획에 속한 도시
vector<vector<int> >graph;
bool funct(int cur, int next);
int main(){
    cin>>n>>m;
    graph.resize(n+1,vector<int>(n+1,0));
    vector<int>finish(m+1,0);
    for(int i=1; i<=n;i++){
        for(int j=1; j<=n;j++){
            //i->j 연결이면 1, 연결 아니면 0
            cin>>graph[i][j];
        }
    }
    for(int i=0; i<m; i++){
        cin>>finish[i];
    }
    for(int i=0; i<m-1; i++){  
        if(finish[i]== finish[i+1]){ //같은 지역을 연달아 방문하는 경우
            continue;
        }
        if(!funct(finish[i],finish[i+1])){
            cout<<"NO";
            return 0;
        }
    }
    //걸리는게 없다면 도착 가능임.
    cout<<"YES";
}
bool funct(int cur,int next){
    queue<int>q;
    vector<int>Visit(n+1,0);
    q.push(cur); //현재 출발 지역을 큐에 넣어줌.
    while(!q.empty()){
        int start = q.front(); //큐에 맨 위를 추출함.
        q.pop();
        if(start == next){ //만약 현재 큐에 원소가 다음 도착지역이라면 그만둠.
            return true;
        }
        if(Visit[start]==1){ //여러번 방문하는건 전체 경로에 한해서지 탐색을 한번 시행하는데는 여러번 방문하면 안됨.
            continue;
        }
        Visit[start]=1; //방문처리
        for(int i=1; i<=n;i++){
            if(graph[start][i]==1){ //경로가 있다면 큐에 넣어줌.
                q.push(i);
            }
        }
    }
    return false; //다 돌았는데 return에 걸리는게 없다면 경로가 없다는 뜻임.
}