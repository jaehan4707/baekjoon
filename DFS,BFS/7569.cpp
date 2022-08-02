/*
?? 7569 ??5
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n, m, h, day = 0; // N = ?? ?? ?? ? M = ?? ?? ?? ? H = ????
vector<vector<vector<int>>> tomato;
vector<vector<vector<int>>> date;
vector<vector<vector<int>>> visit;
queue<pair<int, int>> Tomato;
vector<int> x = {0, 1, -1, 0, 0, 0}, y = {1, 0, 0, -1, 0, 0}, z = {0, 0, 0, 0, 1, -1};
void tom();
int main()
{
    cin >> m >> n >> h;
    tomato.resize(n, vector<vector<int>>(m, vector<int>(h, 0)));
    visit.resize(n, vector<vector<int>>(m, vector<int>(h, 0)));
    date.resize(n, vector<vector<int>>(m, vector<int>(h, 0)));
    for (int k = 0; k < h; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int num = 0;
                cin >> num;
                tomato[i][j][k] = num;
                if (num == 1)
                {
                    Tomato.push(make_pair(i * m + j, k)); //?? ???? ??? ????? ??? ??, k? ???.
                    visit[i][j][k] = 0;
                }
            }
        }
    }
    if (Tomato.size() == m * n)
    {
        cout << 0;
        return 0;
    }
    tom();
    //???? ?? ??? queue? ???.
}
void tom()
{
    while (!Tomato.empty())
    { // tomato? ??? ?��?? ????.
        //???? ???.
        int xx = Tomato.front().first;  // x,y?? ????? i*m+j
        int zz = Tomato.front().second; // z??
        int col = xx % m, row = xx / m; //?? ??? ???.
        // cout << "?? ?? ?????? " << row << " " << col << " " << zz << endl;
        Tomato.pop(); //???? ??.
        //??? ? ? ?? ??? ? ? ?? ? ???? ?? 0?? 1? ?????.
        for (int i = 0; i < 6; i++)
        {
            int dx = row + x[i], dy = col + y[i], dz = zz + z[i]; //???? ??? ????.. ?? ?? ??? ????.
            if (dx < 0 || dx >= n || dy < 0 || dy >= m || dz < 0 || dz >= h)
            { //?? ???? ??? ~
              // cout << dx << " " << dy << " " << dz << " ?? ??? index? ??? ??? ????" << endl;
                continue;
            }
            //?? ? ? ????
            if (tomato[dx][dy][dz] == 0 && visit[dx][dy][dz] == 0)
            { //?? ??? ???? ????
                tomato[dx][dy][dz] = 1;
                visit[dx][dy][dz] = 1;
                date[dx][dy][dz] = date[row][col][zz] + 1;
                // cout << dx << " " << dy << " " << dz << " ??? ???! " << date[dx][dy][dz] << endl;
                if (day < date[dx][dy][dz])
                {
                    day = date[dx][dy][dz];
                }
                Tomato.push(make_pair(dx * m + dy, dz));
            }
        }
    }
    for (int k = 0; k < h; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (tomato[i][j][k] == 0) //?? ??? ???? ???? -1? ????.
                {
                    // cout << "??? ???? ????" << endl;
                    day = -1;
                    break;
                }
            }
        }
    }
    cout << day << endl;
}