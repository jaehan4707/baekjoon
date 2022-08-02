#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
int n, x, y, N, cnt = 0, answer = -1;
vector<vector<int>> graph;
vector<int> visit;
void dfs(int s);
vector<int> path;
int main()
{
    cin >> n;
    cin >> x >> y;
    cin >> N;
    graph.resize(n + 1, vector<int>(n + 1, 0));
    visit.resize(n + 1, 0);
    for (int i = 0; i < N; i++)
    {
        int c, p;
        cin >> c >> p;
        graph[c][p] = 1;
        graph[p][c] = 1;
    }
    // cout<<x<<endl;
    dfs(x);
    /*
    for(auto a :path){
        cout<<a<<" ";
    }
    cout<<endl;
    */
    cout << answer;
}
//부모를 찾아야함. 그러면 [x][y]에서 x의 연결고리를 찾아야함.
//무작정 연결고리를 찾앗다고 증가시켜주면 안됨. 정확환 관계일때만 해줘야함.
void dfs(int s) // s에서 시작해서 f까지 루트를 몇개 만나는지 체크하면 될듯.
{
    visit[s] = 1;
    if (s == y)
    {
        answer = cnt;
        return;
    }
    cnt++;
    for (int i = 1; i <= n; i++)
    {
        if (visit[i] == 1)
        {
            continue;
        }
        if (graph[s][i] == 0)
        {
            continue;
        }
        dfs(i);
    }
    cnt--;
}