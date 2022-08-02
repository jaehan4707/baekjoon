/*
���� 2573 ���4 ����
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
int n, m, day = 0, Icenum = 0, answer = 0;
vector<vector<int>> ice;
vector<vector<int>> visit;
vector<vector<int>> fact;
queue<pair<int, int>> q;
vector<int> result;
vector<int> x = {0, 0, 1, -1}, y = {1, -1, 0, 0};
void bfs();
void checkice(int row, int col);
int main()
{
    cin >> n >> m;
    ice.resize(n, vector<int>(m, 0));
    visit.resize(n, vector<int>(m, 0));
    fact.resize(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int num;
            cin >> num;
            ice[i][j] = num;
            if (num != 0)
            {
                q.push(make_pair(i, j));
                visit[i][j] = 1; //������ �ִ� ���� 1�� �־���.
            }
        }
    }
    bfs();
}
void bfs()
{
    int size = q.size();
    int Size = 0;
    while (q.empty() == 0)
    { //�􋚱��� �ݺ�

        int row, col;
        row = q.front().first, col = q.front().second;
        q.pop();
        Size++; //�����ϳ� ó���ߴ�.
        for (int i = 0; i < 4; i++)
        {
            int dx = row + x[i], dy = col + y[i];
            if (dx < 0 || dx >= n || dy < 0 || dy >= m) //������ ���� continue
            {
                continue;
            }
            if (ice[dx][dy] == 0 && ice[row][col] != 0 && visit[dx][dy] == 0)
            {                    //�̵��Ѱ��� �ٴٰ�, �ش� ������ �����϶�,visit�� ���ʿ� �� ��Ұ� �������� �ٴ������� ����.
                ice[row][col]--; //������ ��´�.
            }
        }
        if (ice[row][col] != 0) //�ٶ��� �Ҿ��µ� ������ ��Ƴ��Ҵٸ� ť�� �־���.
        {
            q.push(make_pair(row, col));
        }

        if (Size == size) //���� �ʱ� ť�� �ִ� ������ ������ŭ ���ٸ� ������ �ٲ�����.
        {
            day++;           //��������
            size = q.size(); //���� �م����� ������ �ٽ� �ʱ�ȭ����.
            Size = 0;
            // cout << "now year : " << day << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (ice[i][j] == 0)
                    {
                        visit[i][j] = 0;
                        continue;
                    }
                    if (fact[i][j] == 0)
                    {
                        checkice(i, j);
                        Icenum++;
                    }
                }
            }
            if (Icenum >= 2)
            {
                answer = day;
                break;
            }
            fact.assign(n, vector<int>(m, 0));
            Icenum = 0;
        }
    }
    cout << answer << endl;
}
void checkice(int row, int col)
{
    if (fact[row][col] == 0)
    { //�˻���ߴ�.
        fact[row][col] = 1;
        for (int i = 0; i < 4; i++)
        {
            int dx = row + x[i], dy = col + y[i];
            if (dx < 0 || dx >= n || dy < 0 || dy >= m)
            {
                continue;
            }

            if (ice[dx][dy] != 0 && fact[dx][dy] == 0)
            { //������ �ִ�.
                checkice(dx, dy);
            }
        }
    }
}