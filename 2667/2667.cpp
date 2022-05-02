#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
stack<int>s;
int n, cnt = 0, c = 0;
void move(int row, int col, vector<vector<int>>& graph, vector<vector<int>>& visit);
int main()
{
	cin >> n;
	vector<vector<int>> graph(n, vector<int>(n, 0));
	vector<vector<int>>visit(n, vector<int>(n, 0));
	vector<int>house;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%1d", &graph[i][j]); //숫자 하나씩 넣기
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (graph[i][j] == 1 && visit[i][j] == 0) //집이 있고,방문하지 않은곳
			{
				cnt++; //단지 수를 나타냄.
				s.push(0); //단순 스택 채우기용 push, 안에 숫자는 별 내용 없음
				move(i, j, graph, visit);
				while (s.empty() == 0) //stack size가 단지 내 집의 수
				{
					s.pop();
					c++;
				}
				house.push_back(c); //pop한 횟수가 집의 수 집의 수를 배열에 저장.
				c = 0;
			}
		}
	}
	cout << cnt << endl; // 단지 수 출력
	sort(house.begin(), house.end()); //house배열을 오름차순으로 정렬
	for (int i = 0; i < house.size(); i++)
	{
		cout << house[i] << endl; //house배열을 출력
	}
}
void move(int row, int col, vector<vector<int>>& graph, vector<vector<int>>& visit)
{
	visit[row][col] = 1; //현재 좌표를 방문했다고 표시
	//각 좌표마다 갈 수 있는지 검사후 움직여줌.
	if (row + 1 < n)
	{
		if (graph[row + 1][col] == 1 && visit[row + 1][col] == 0)
		{
			s.push(0);
			move(row + 1, col, graph, visit);

		}
	}
	if (row - 1 >= 0)
	{
		if (graph[row - 1][col] == 1 && visit[row - 1][col] == 0)
		{
			s.push(0);
			move(row - 1, col, graph, visit);

		}
	}
	if (col + 1 < n)
	{
		if (graph[row][col + 1] == 1 && visit[row][col + 1] == 0)
		{
			s.push(0);
			move(row, col + 1, graph, visit);
		}
	}
	if (col - 1 >= 0)
	{
		if (graph[row][col - 1] == 1 && visit[row][col - 1] == 0)
		{
			s.push(0);
			move(row, col - 1, graph, visit);
		}
	}

}