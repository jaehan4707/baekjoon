/*
���� 2606 �ǹ�1 ���̷���
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,t,ans=0;
vector<vector<int>>graph;
vector<int>visit;
void bfs(int vir);
int main()
{
    cin>>n>>t;
    visit.resize(n+1,0);
    graph.resize(n+1,vector<int>(n+1,0));
    for(int i=0; i<t;i++){
        int s,f;
        cin>>s>>f;
        graph[s][f]=1,graph[f][s]=1;
    }
    visit[1]=1;
    bfs(1);
    cout<<ans;
}
void bfs(int vir) //������ 1�� ��ǻ�Ͱ� ���̷������ ������.
{
    for(int j=0; j<=n;j++){
        if(graph[vir][j]==1 && visit[j]==0){ //0�� �湮 ���� ����
            visit[j]=1;
            ans++;
            bfs(j);
        }
    }
}