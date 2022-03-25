#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
void bfs(int v, vector<vector<int>>& node);
void dfs(int v, vector<int> visit, vector<vector<int>>& node);
stack<int> s;
queue<int> q;
int n, m, V; // n�� ������ ���� m�� ���� ���� v�� �����
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
    // bfs¥��
    dfs(V, visit, node);
    cout << "\n";
    bfs(V, node);
}
void bfs(int v, vector<vector<int>>& node)
{
    q.push(v); //ù ��带 �־��ش�.
    vector<int> visit(m);
    visit[v] = 1; //�湮�ߴٴ� ǥ��

    int begin;
    while (!q.empty()) // queue�� ������� ��
    {                  //�湮���߰� node[][]���� 1�ΰ��� push�������.
        begin = q.front();
        cout << q.front() << " ";
        q.pop();
        for (int i = 0; i < m; i++)
        {
            if (visit[i] == 0 && node[begin][i] == 1) // begin���� �����ؼ� �������� �޿� Ž��
            {
                q.push(i);
                visit[i] = 1;
            }
        }
    }
}
void dfs(int V, vector<int> visit, vector<vector<int>>& node)
{
    // �ʱ�ȭ
    // ���� (�湮 ǥ��, stack �߰�)
    s.push(V);
    int top = s.top();
    s.pop();
    while (!s.empty())
    {
        if (visit[top])
            continue;

        // ?��� �湮 ǥ��
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

