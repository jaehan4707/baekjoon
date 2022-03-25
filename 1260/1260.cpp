#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
void bfs(int v, vector<vector<int>>& node);
void dfs(int v, vector<int> visit, vector<vector<int>>& node);
stack<int> s;
queue<int> q;
int n, m, V; // n은 꼭지점 개수 m은 간선 개수 v는 출발점
int main()
{

    cin >> n >> m >> V;
    vector<vector<int>> node(m, vector<int>(m, 0));
    int start, end;
    vector<int> visit(m);
    for (int i = 0; i < m; i++)
    {
        cin >> start >> end;
        node[start][end] = 1;
        node[end][start] = 1;
    }
    // bfs짜기
    dfs(V, visit, node);
    cout << "\n";
    bfs(V, node);
}
void bfs(int v, vector<vector<int>>& node)
{
    q.push(v); //첫 노드를 넣어준다.
    vector<int> visit(m);
    visit[v] = 1; //방문했다는 표시

    int begin;
    while (!q.empty()) // queue가 비엇으면 끝
    {                  //방문안했고 node[][]값이 1인것을 push해줘야함.
        begin = q.front();
        cout << q.front() << " ";
        q.pop();
        for (int i = 0; i < m; i++)
        {
            if (visit[i] == 0 && node[begin][i] == 1) // begin에서 시작해서 도착점을 쭈욱 탐색
            {
                q.push(i);
                visit[i] = 1;
            }
        }
    }
}
void dfs(int V, vector<int> visit, vector<vector<int>>& node)
{
    // 초기화
    // 시작 (방문 표시, stack 추가)
    s.push(V);
    int top = s.top();
    s.pop();
    while (!s.empty())
    {
        if (visit[top])
            continue;

        // ?노드 방문 표시
        visit[top] = true;
        cout << top << " ";

        for (int i = 0; i < m; i++)
        {
            if (visit[i] == 0 && node[top][i])
            {
                s.push(i);
                top = s.top();
                s.pop();
            }
        }
    }
}

