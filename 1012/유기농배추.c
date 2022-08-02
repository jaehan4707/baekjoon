#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Maxrow, Maxcol;
int dfs(int x, int y);
int ary[50][50];
int main()
{
	int i, j, k, h;
	int t = 0, Obj = 0, Row = 0, Col = 0, count = 0;
	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%d %d %d", &Maxrow, &Maxcol, &Obj);
		if (Maxrow > 50 || Maxrow < 1 || Maxcol < 1 || Obj < 0 || Maxcol > 50 || Obj > 2500)
			exit(1);
		memset(ary, 0, sizeof(ary));
		for (j = 0; j < Obj; j++)
		{
			scanf("%d %d", &Row, &Col);
			ary[Row][Col] = 1;
		}
		for (k = 0; k < Maxrow; k++)
		{
			for (h = 0; h < Maxcol; h++)
			{
				if (ary[k][h] == 1)
				{
					dfs(k, h);
					count++;
				}
			}
		}
		printf("%d\n", count);
		count = 0;
	}
	return 0;
}

int dfs(int x, int y)
{

	ary[x][y] = 0;
	if (x + 1 < Maxrow && ary[x + 1][y] == 1)
	{ // down
		dfs(x + 1, y);
	}
	if (x - 1 >= 0 && ary[x - 1][y] == 1)
	{ // up
		dfs(x - 1, y);
	}
	if (y + 1 < Maxcol && ary[x][y + 1] == 1)
	{ // right
		dfs(x, y + 1);
	}
	if (y - 1 >= 0 && ary[x][y - 1] == 1)
	{ // left
		dfs(x, y - 1);
	}
	return 0;
}