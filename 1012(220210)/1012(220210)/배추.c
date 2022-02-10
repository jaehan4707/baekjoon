#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Maxrow,Maxcol;
int dfs(int x, int y);
int ary[50][50];
int main()
{
	int t=0,Obj=0,Row=0,Col=0,count=0;
	scanf("%d",&t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d %d %d",&Maxrow,&Maxcol,&Obj);
		if (Maxrow > 50 || Maxrow <1 || Maxcol<1 || Obj<0 ||Maxcol > 50 || Obj > 2500)
			exit(1);
		memset(ary, 0, sizeof(ary));// 최대 가로길이,세로길이 배추개수 
		for (int j = 0; j < Obj; j++) 
		{
			scanf("%d %d",&Row,&Col);
			ary[Row][Col] = 1; // 배추 잇는 곳은 1로 초기화
		}
		for (int x = 0; x< Maxrow; x++)
		{
			for (int y = 0; y < Maxcol; y++)
			{
				if (ary[x][y] == 1)
				{
					dfs(x, y);
					count++;
				}
			}
		}
		printf("%d\n", count);
		count = 0;
	}
	return 0;
}
/*
int dfs(int row, int col)
{
	ary[row][col] = 0;
	if (row-1>=0&& ary[row - 1][col] == 1) //up 
		dfs(row-1, col);
	if (row+1<Maxrow && ary[row + 1][col] == 1) //down
		dfs(row+1, col);
	if (Maxcol-1>=0&& ary[row][col - 1]==1) //left
		dfs(row, col-1);
	if (col+1<Maxcol&& ary[row][col + 1] == 1) //right
		dfs(row, col+1); 
	return 0;
}
*/
int dfs(int x, int y) {

    ary[x][y] = 0;
	if (x + 1 < Maxrow && ary[x + 1][y] == 1)
	{
		dfs(x + 1, y);
	}
	if (x - 1 >= 0 && ary[x - 1][y] == 1)
	{
		dfs(x - 1, y);
	}
	if (y + 1 < Maxcol && ary[x][y + 1] == 1) {
		dfs(x, y + 1);
	}
	if (y - 1 >= 0 && ary[x][y - 1] == 1) {
		dfs(x, y - 1);
	}
    return 0;
}