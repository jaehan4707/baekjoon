//BFS는 너비우선탐색 DFS는 깊이 우선탐색
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
int n, m, start,s,f;
int idx = 99999;
stack<int>S;
queue<int>Q;
void dfs(vector<vector<int>>& ary, int begin, vector<int>& visit);
void bfs(vector<vector<int>>& ary, int begin, vector<int>& visit);
int main()
{
	cin >> n >> m >> start;
	vector<vector<int>>graph(n+1, vector<int>(n+1, 0));
	vector<int>visit(n + 1, 0);
	for (int i = 0; i < m; i++)
	{
		cin >> s >> f;
		graph[s][f] = 1;
		graph[f][s] = 1;
	}
	dfs(graph, start,visit);
	cout << endl;
	for (int i = 0; i < visit.size(); i++)
	{
		visit[i] = 0;
	}
	bfs(graph, start, visit);
}
void dfs(vector<vector<int>>&ary,int begin, vector<int>&visit)
{
	visit[begin] = 1;
	S.push(begin);
	while (S.empty() == 0)
	{
		int begin = S.top();
		cout << begin << " ";
		S.pop();
		for (int i = 1; i <= n; i++)
		{
			if (ary[begin][i] == 1 && visit[i] == 0)
			{
				visit[i] = 1;
				dfs(ary, i, visit);
			}
		}
	}
}
void bfs(vector<vector<int>>& ary, int begin, vector<int>& visit)
{
	Q.push(begin);
	visit[begin] = 1;
	while (Q.empty()==0)
	{
		int begin= Q.front(); // 출발점을 begin으로 잡는다.
		cout << begin << " ";
		Q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (ary[begin][i] == 1 && visit[i] == 0)
			{
				visit[i] = 1;
				Q.push(i);
			}
		}
	}
}