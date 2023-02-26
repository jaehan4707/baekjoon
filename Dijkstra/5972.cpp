#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;
vector<pair<int, int> > graph[50001];
vector<int>dist;
priority_queue<pair<int,int>, vector<pair<int,int> >,greater<pair<int,int> > >pq;
int n, m;
int answer = 0;
void funct(int start);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m; // n : 정점 , m : 간선 개수
    int a, b, c;
    dist.resize(n+1,INT_MAX);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c)); // a -> b 의 값은 c 라는 뜻 , 기본적으로 undirect graph라서. 모두 처리
        graph[b].push_back(make_pair(a, c));
    }
    pq.push(make_pair(1,0));
    funct(1);
    cout << answer;
    return 0;
}
void funct(int start)
{
    // 모든 지점을 안들러도됨. 만약 행선지가 n이라면 거기서 종료를 하자.
    while (!pq.empty()) //pq에는 출발지와 그 비용이 들어감.
    {
        int start =pq.top().first;
        int cost = pq.top().second;
        pq.pop();
        if(start==n){ //도착지에 도착한다면 종료함.
            answer=cost;
            return;
        }
        for(int i=0; i< graph[start].size();i++){ //현재 출발지에서 갈 수 잇는 모든 경로를
            int next = graph[start][i].first;
            int nextcost = graph[start][i].second;

            if(dist[next]>cost+nextcost){ // 비용 업데이트 해주기.
                dist[next]=cost+nextcost;
                pq.push(make_pair(next,dist[next]));
            }
        }
    }
    
}