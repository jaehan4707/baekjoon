/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int summax(int num[], int start,int finish);
int sum = 0;
int main()
{
	int N, m; // N=size, m=�������� �ֿ��� �ϴ� ���� 
	//2000������ ����(���밪)
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
	tresure = (int*)malloc(sizeof(int) * N); //Ž���ϴ� ���
	jew = (int*)malloc(sizeof(int) * N); //����
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
			if (Max[i] < max[i][j]&& j-i>=3) // �� ���������� �ְ��� ���� ã�� �ּ� 4���̻��� ������ �ֿ�����.
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
		sum = sum+num[i]; //num = tresure �����߻� �ֳ�? summax(tresure,0,1)�϶� tresure[1]���� �𸣱⶧����
	}
	return sum;
}
*/