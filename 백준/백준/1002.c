#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
    int N;
    scanf("%d", &N);
    int x1, y1, x2, y2, r1, r2;
    double distance;
    int sum, difference;
    int* count;
    count = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        sum = r1 + r2;
        difference = abs(r1 - r2);

        if (distance == sum || distance == difference)
            count[i] = 1;
        else if (distance > difference && distance < sum)
            count[i] = 2;
        else if (difference == 0 && r1 == r2)
            count[i] = -1;
        else
            count[i] = 0;
    }
    for (int i = 0; i < N; i++)
    {
        printf("%d\n", count[i]);
    }
    return 0;
}
