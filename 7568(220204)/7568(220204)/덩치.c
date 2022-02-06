#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int height;
	int kg;
	int rank;
}people;
int main()
{
	int num;
	scanf("%d", &num);
	if (num < 2 || num>50)
	{
		exit(0);
	}
	people* p;
	p = (people*)malloc(sizeof(people) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d %d", &p[i].kg, &p[i].height);
		if (p[i].kg < 10 || p[i].height>200)
		{
			exit(0);
		}
		p[i].rank = 1;
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (p[i].kg < p[j].kg && p[i].height < p[j].height)
			{
				p[i].rank++;
			}
		}
	}
	for (int i = 0; i < num; i++)
	{
		printf("%d\n", p[i].rank);
	}
	return 0;
}
