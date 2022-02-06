/*
�� ������ ������ �ð��� ���� �ɷǴ�. ������ ����� ��� ã�� ã�ƺ��� ���� ���ؿ����� ������ ã�� ���� ��� ��� ����� ��(�� �߿��� �� �ڸ��� ���ڰ� �ٸ� ���)�� 
�� test case�� ���ڿ� ��Ʈ����ũ ���� �˻��ؼ� ��Ʈ����ũ ���� ��ġ�ϸ� count�� �÷��� ���־���. 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct
{
	int num[3];
	int Strike;
	int Ball;
}numbaseball;
int dnumber(int num[], int n);
int baseball(int num1[], numbaseball* ary, int size);
int main()
{
	numbaseball *a;
	int qnum, num1,num, Tnum[3],count = 0,s=0,b=0;

	scanf("%d", &qnum);
	a = (numbaseball*)malloc(sizeof(numbaseball) * qnum);

	for (int i = 0; i < qnum; i++)
	{
		scanf("%d %d %d", &num1, &a[i].Strike, &a[i].Ball);
		a[i].num[0] = num1 / 100;
		num1 = num1 % 100;
		a[i].num[1] = num1 / 10;
		num1 = num1 % 10;
		a[i].num[2] = num1;
	}
	for (num = 123; num <= 987; num++) //��� ����Ǽ� ã��
	{
		if (dnumber(Tnum, num)) //���� ���ڰ� �ٸ� �� 1��ȯ
		{
			if (baseball(Tnum, a, qnum)) {
				count++;
			}
		}
	}
	printf("%d", count);

	return 0;
}
int dnumber(int num[], int n)
{
	num[0] = n / 100;
	n = n % 100;
	num[1] = n / 10;
	n = n % 10;
	num[2] = n;
	if (num[0] != num[1] && num[0] != num[2] && num[1] != num[2]) {
		if (num[0] != 0 && num[1] != 0 && num[2] != 0)
			return 1;
		else
			return 0;
	}
	else 
		return 0;
}
int baseball(int num1[],numbaseball *ary,int size) //��Ʈ����ũ,��,����
{
	for (int i = 0; i < size; i++)
	{
		int s = 0,b = 0;
		for (int j = 0; j < 3; j++)
		{
			if (num1[j] == ary[i].num[j])//testcase�� �Է¹��� ���ڸ� ���ϴ°�(�ѱ��ھ�)
				s++;
		}
		for (int x = 0; x < 3; x++)
		{
			for (int q = 0; q < 3; q++)
			{
				if (num1[x] == ary[i].num[q] && x != q) //���ڰ� �ֱ� �ִµ� 
					b++;
			}
		}
		if (ary[i].Strike != s || ary[i].Ball != b)
			return 0;
	}
	return 1;
}