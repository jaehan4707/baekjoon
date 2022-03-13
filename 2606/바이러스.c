#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int graph[1001];
int virous[1001][1001];
void dfs(int start, int size);
int main()
{
	int test, computer, s, f, count = 0;
	scanf("%d", &computer);
	scanf("%d", &test);

	for (int i = 1; i <= computer; i++)
	{
		for (int j = 1; j <= computer; j++)
		{
			virous[i][j] = 0;
		}
	}
	for (int i = 0; i < test; i++)
	{
		scanf("%d %d", &s, &f);

		virous[s][f] = 1;
		virous[f][s] = 1;
	}
	dfs(1, computer);
	for (int i = 2; i <= computer; i++)
		if (graph[i] == 1)
			count++;
	printf("%d", count);
	return 0;
}
void dfs(int start, int size)
{
	graph[start] = 1;
	for (int i = 1; i <= size; i++)
	{
		if (virous[start][i] == 1 && graph[i] == 0)
			dfs(i, size);
	}
}