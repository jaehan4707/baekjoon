/*
모든 나라를 탐색할려면 끝 지점이 w여야한다 모든 곳을 탐색하는 그래프 : Spanning tree
*/
#include <iostream>
#include <vector>
#include <Queue>
using namespace std;
int bfs(int w, vector<vector<int>>& m);
int main()
{
    int t, w, a, s, f;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> w >> a;
        vector<vector<int>> m(w + 1, vector<int>(w + 1, 0));
        for (int j = 0; j < a; j++)
        {
            cin >> s >> f;
            m[s][f] = 1;
            m[f][s] = 1;
        }
        cout << bfs(w, m) << "\n";
        m.resize(w + 1, vector<int>(w + 1, 0));
    }
}
void path(vector<vector<int>>& m, int c)
{
    for (int i = 1; i < m.size(); i++)
    {
        if (m[c][i] == 1 || m[i][c] == 1)
        {
            path(m, i);
        }
    }
}
int bfs(int w, vector<vector<int>>& m)
{
    vector<int> visit(w + 1, 0);
    queue q;
    q.push(1);
    visit[1] = 1;
    int ans = 0;
    while (!q.empty())
    {
        for (int i = 1; i < w + 1; i++)
        {
            int j = q.front();
            q.pop();
            if (m[j][i] == 1 && visit[i] != 1)
            {
                q.push(j);
                visit[j] = 1;
                ans++;
            }
        }
    }
    return ans;
}