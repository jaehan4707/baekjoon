#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int n, m, c;
int DP[51][51][51][51]; // 형, 열, 오락실최대번호, 오락실개수
map<pair<int, int>, int> M;
int graph[51][51];
int graphnumber[51][51];
int mod = 1000007;
void funct();
int main()
{
    cin >> n >> m >> c;
    int trow, tcol;
    DP[1][1][0][0] = 1;
    for (int i = 1; i <= c; i++)
    {
        cin >> trow >> tcol;
        if (trow == 1 && tcol == 1)
        {
            DP[1][1][i][1] = 1;
            DP[1][1][0][0] = 0;
        }
        M.insert(make_pair(make_pair(trow, tcol), i));
    }
    funct();
    for (int i = 0; i <= c; i++)
    { // 오락실 수.
        int sum = 0;
        for (int j = 0; j <= c; j++)
        { // 오락실 번호
            sum += DP[n][m][j][i];
            sum %= mod;
        }
        sum %= mod;
        cout << sum << "\n ";
    }
}

void funct()
{

    for (int i = 1; i <= n; i++)
    { // DP[행][열][오락실수][오락실넘버]
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)
            { // 출발점.
                continue;
            }
            if (M.find(make_pair(i, j)) != M.end()) // 만약 이곳이 오락실이라면?
            {
                int key = M.find(make_pair(i, j))->second; // 벙문한 오락실 넘버
                for (int k = 0; k < key; k++)
                { // 오락실넘버.
                    for (int x = 0; x <= k; x++)
                    { // 방문 갯수. 현재 오락실넘버 만큼 오락실을 방문할 수 있다.
                        DP[i][j][key][x + 1] += DP[i - 1][j][k][x] + DP[i][j - 1][k][x];
                        DP[i][j][key][x + 1] %= mod;
                    }
                }
            }
            else
            {
                for (int l = 0; l <= c; l++)
                {
                    for (int k = 0; k <= l; k++)
                    {
                        DP[i][j][l][k] = DP[i - 1][j][l][k] + DP[i][j - 1][l][k];
                        DP[i][j][l][k] %= mod;
                    }
                }
            }
        }
    }
}