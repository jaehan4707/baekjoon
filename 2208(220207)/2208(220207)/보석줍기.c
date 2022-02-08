/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int summax(int num[], int start,int finish);
int sum = 0;
int main()
{
	int N, m; // N=size, m=연속으로 주워야 하는 개수 
	//2000이하의 정수(절대값)
	scanf("%d %d", &N, &m);
	int* jew;
	int* tresure;
	int* Max;
	int jewelMax = 0;
	Max = (int*)malloc(sizeof(int) * N);
	int** max = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++)
	{
		max[i] = (int*)malloc(sizeof(int) * N);
	}
	tresure = (int*)malloc(sizeof(int) * N); //탐색하는 사람
	jew = (int*)malloc(sizeof(int) * N); //보석
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			max[i][j]= 0;
		}
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &jew[i]);
		tresure[i] = jew[i];
	}
	for (int i = 0; i < N; i++)
	{
		
		for (int j = i; j < N; j++)
		{
			max[i][j] = summax(tresure,i,j);
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf(" %2d ", max[i][j]);
		printf("\n");
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Max[i] = max[i][j];
			if (Max[i] < max[i][j]&& j-i>=3) // 각 시작점에서 최고의 합을 찾고 최소 4개이상의 보석을 주워야함.
			{
				Max[i] = max[i][j];
			}
			else Max[i] = Max[i];
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (jewelMax > Max[i])
		{
			jewelMax = jewelMax;
		}
		else
			jewelMax = Max[i];
	}
	printf("%d", jewelMax);
}
int summax(int num[],int start,int finish)
{
	sum = 0;
	for (int i = start; i <=finish; i++)
	{
		sum = sum+num[i]; //num = tresure 오류발생 왜냐? summax(tresure,0,1)일때 tresure[1]값은 모르기때문에
	}
	return sum;
}
*/