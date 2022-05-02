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
			scanf("%1d", &graph[i][j]); //���� �ϳ��� �ֱ�
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (graph[i][j] == 1 && visit[i][j] == 0) //���� �ְ�,�湮���� ������
			{
				cnt++; //���� ���� ��Ÿ��.
				s.push(0); //�ܼ� ���� ä���� push, �ȿ� ���ڴ� �� ���� ����
				move(i, j, graph, visit);
				while (s.empty() == 0) //stack size�� ���� �� ���� ��
				{
					s.pop();
					c++;
				}
				house.push_back(c); //pop�� Ƚ���� ���� �� ���� ���� �迭�� ����.
				c = 0;
			}
		}
	}
	cout << cnt << endl; // ���� �� ���
	sort(house.begin(), house.end()); //house�迭�� ������������ ����
	for (int i = 0; i < house.size(); i++)
	{
		cout << house[i] << endl; //house�迭�� ���
	}
}
void move(int row, int col, vector<vector<int>>& graph, vector<vector<int>>& visit)
{
	visit[row][col] = 1; //���� ��ǥ�� �湮�ߴٰ� ǥ��
	//�� ��ǥ���� �� �� �ִ��� �˻��� ��������.
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