#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int graph[50][5];
int r1, r2, c1, c2;
int num = 1;
int firstR, firstC = 0;
int x[4] = {0, -1, 0, 1};
int y[4] = {1, 0, -1, 0};
void make();
bool check();
int main()
{
    cin >> r1 >> c1 >> r2 >> c2; // r2>r1 // c2>c1  -r1~ r1의 소용돌이를 만들어야겟다.
    make(); //소용돌이 만들기
    //출력형식 맞추기.
    int degree=0;
    while(num){ //자리수 크기만큼 degree를 ++시킴.
        num/=10;
        degree++;
    }
    for (int i = 0; i <= r2 - r1; i++)
    {
        for (int j = 0; j <= c2 - c1; j++)
        {
            printf("%*d ",degree, graph[i][j]);
        }
        cout << endl;
    }
}
bool check()
{
    if (graph[r2 - r1][0] && graph[0][0] && graph[0][c2 - c1] && graph[r2 - r1][c2 - c1]) // 꼭짓점 다 채워지면 종료
    {
        return true;
    }
    else
        return false;
}
void make()
{
    int cnt = 0;
    int dir = 0;
    int move = 1;
    while (1)
    {
        if (check())
        { // 꼭짓점이 다 채워졋나
            break;
        }
        else
        {
            if (firstR - r1 >= 0 && firstR - r1 <= r2 - r1 && firstC - c1 >= 0 && firstC - c1 <= c2 - c1)
            {
                graph[firstR - r1][firstC - c1] = num;
            }
            cnt += 1;
            num++;
            firstR += x[dir],firstC += y[dir]; // dir : 오, 위 , 왼, 아
            // 4방향으로 돌려야하기에,
            if (move == cnt)
            {
                cnt = 0;
                dir = (dir + 1) % 4;
                if (dir == 0 || dir == 2)
                {
                    move++;
                }
            }
        }
    }
}