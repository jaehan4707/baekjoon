#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int summax(int num[], int start, int finish);
int sum = 0;
int main()
{
	int N, m; // N=size, m=�������� �ֿ��� �ϴ� ���� 
	//2000������ ����(���밪)
	scanf("%d %d", &N, &m);
	int* jew;
	int* Max;
	int jewelMax = 0;
	int count = 0;
	int anum = 0;
	Max = (int*)malloc(sizeof(int) * N);
	int* max = (int**)malloc(sizeof(int*) * N);
	jew = (int*)malloc(sizeof(int) * N); //����
	for (int i = 0; i < N; i++)
	{
		max[i] = 0; //�ƽ����� �迭
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &jew[i]);
	}
	for (int i = 0; i < N-m+1; i++)
	{
		for (int j = i + 3; j < N; j++)
		{
			max[i] = summax(jew, i, j); //max�ּ��� �� ����	
			if (anum > max[i])
				anum = anum;
			else
				anum = max[i];
		}
	} 
	for (int i = 0; i < N; i++)
	{
		if (jewelMax > max[i])
		{
			jewelMax = jewelMax;
		}
		else
			jewelMax = max[i];
	}
	if (jewelMax < 0)
	{
		printf("0");
	}
	else
		printf("%d", jewelMax);
}
int summax(int num[], int start, int finish)
{
	sum = 0;
	for (int i = start; i <= finish; i++)
	{
		sum = sum + num[i]; //num = tresure �����߻� �ֳ�? summax(tresure,0,1)�϶� tresure[1]���� �𸣱⶧����
	}
	return sum;
}