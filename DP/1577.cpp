/*
����� ����� ������� 0,0 -> N,M���� �ϵ� ���۶ո� ������ ��ġ�� �� Ư���ؼ� �־������.
���� ��ǥ�� x,y�� ���� �ٲ��ָ��.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long int n, m, T, finishx, finishy, startx, starty;
int main()
{
    cin >> n >> m;
    int road[m + 1][n + 1][2];
    long long int DP[m + 1][n + 1]; //������ ������ ����.
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            DP[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                road[i][j][k] = 0;
            }
        }
    }
    // location(finishx, finishy);                             //�������� ����
    // startx = n, starty = 0;                                 //������� ����
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        //����� ȸ����ų���� �׷��� x,y ��ǥ�� �ݴ밡 �ǿ�.
        //(a,b)->(c,d)
        // DP���� 3���� ��ǥ�� 0�� ���� �� ����. 1�� �������� ����. 2�� �Ʒ��� ���� �� ����.
        if (a == c)
        { // x��ǥ�� ���ٸ� �Ʒ����� ���� �� ����
            if (b > d)
                road[b][c][1] = -1;
            else
                road[d][c][1] = -1;
            // cout<<"�Ʒ�  "<<d<<c<<endl;
        }
        if (b == d)
        { // y��ǥ�� ���ٸ� ���ʷ� ���� �� ����
            if (a > c)
                road[d][a][0] = -1;
            else
                road[d][c][0] = -1;
            // cout<<"�� "<<d<<c<<endl;
        }
        // cout<<d<<" "<<c<<endl;
        // location(a, b); //
        // location(c, d);
    }

    // DP[i][j] =DP[i-1][j]+DP[i][j-1]�� �ּ��� ��ΰ���?
    //�ٵ� ���� �� ������ ũ�ٸ�? �׶��� ������ ��ΰ� �ƴϾ�
    DP[0][0] = 1;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i - 1 >= 0 && road[i][j][1] != -1) //�Ʒ��� ���� ��ȸ���������)
            {
                DP[i][j] = DP[i][j] + DP[i - 1][j];
            }
            if (j - 1 >= 0 && road[i][j][0] != -1) //���� �ȸ���������)
            {
                DP[i][j] = DP[i][j] + DP[i][j - 1];
            }
        }
    }
    // int x,y;
    // cin>>x>>y;
    // cout << DP[x][y];
    cout << DP[m][n];
}