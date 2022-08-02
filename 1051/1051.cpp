#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> r;
vector<int> c;
vector<int> a, b;
int search(vector<vector<int>> &a, int row, int col);
int main()
{
	cin >> n >> m;
	vector<vector<int>> ary(n, vector<int>(m, 0));
	vector<int> Max;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &ary[i][j]);
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			int temp = search(ary, i, j);
			if (temp == 0)
				continue;
			else
				Max.push_back(temp);
		}
	}
	if (Max.size() == 0)
	{
		cout << 1;
	}
	else
	{
		sort(Max.begin(), Max.end());
		cout << Max[Max.size() - 1];
	}
}
int search(vector<vector<int>> &a, int row, int col) //?? ?? ??? ???.
{
	int edge = a[row][col];
	int size = 0, len = 0, idx = 0, ans = 0;
	for (int j = col + 1; j < m; j++)
	{
		if (edge == a[row][j])
			c.push_back(j);
	}
	size = c.size();

	while (size--)
	{
		len = c[idx] - col;
		idx++;
		if (row + len >= n || col + len >= m)
			continue;
		if (edge == a[row + len][col] && edge == a[row + len][col + len])
			if (ans < len + 1)
				ans = len + 1;
	}
	c.clear();
	return ans * ans;
}