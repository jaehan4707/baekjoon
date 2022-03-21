#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void maketomato(int row, int col, vector<vector<int>>& S);
void pushtomato(queue<pair<int, int>>& q, vector<vector<int>>& S, vector<vector<int>>& day);
int m, n, cnt = 0;

int main()
{
    int max = 0;
    cin >> m >> n;
    vector<vector<int>>day(n, vector<int>(m, -1)); //2���� �迭�� -1�� �ʱ�ȭ
    vector<vector<int>> tomato(n, vector<int>(m, 0)); // n*m�迭�ϼ�
    maketomato(n, m, tomato); //�迭�� ���� �־���
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (tomato[i][j] == 1)
            {
                q.push(make_pair(i, j));
                day[i][j] = 0; //ó������ �丶�䰡 �ִ� ���� 0������ ����
            }
        }
    }
    pushtomato(q, tomato, day);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (max < day[i][j])
                max = day[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (tomato[i][j] == 0) //�丶�䰡 ���� �ʴ� ���
            {
                max = -1;
            }
        }
    }
    cout << max;
}
void maketomato(int row, int col, vector<vector<int>>& S)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> S[i][j];

        }
    }
}
void pushtomato(queue<pair<int, int>>& q, vector<vector<int>>& S, vector<vector<int>>& day)
{
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        if (row - 1 >= 0 && S[row - 1][col] == 0 && day[row - 1][col] == -1) //��
        {
            day[row - 1][col] = day[row][col] + 1;
            S[row - 1][col] = 1;
            q.push(make_pair(row - 1, col));
        }
        if (row + 1 < n && S[row + 1][col] == 0 && day[row + 1][col] == -1) //�Ʒ�
        {
            day[row + 1][col] = day[row][col] + 1;
            S[row + 1][col] = 1;
            q.push(make_pair(row + 1, col));
        }
        if (col + 1 < m && S[row][col + 1] == 0 && day[row][col + 1] == -1) //������
        {
            day[row][col + 1] = day[row][col] + 1;
            S[row][col + 1] = 1;
            q.push(make_pair(row, col + 1));
        }
        if (col - 1 >= 0 && S[row][col - 1] == 0 && day[row][col - 1] == -1) //����
        {
            day[row][col - 1] = day[row][col] + 1;
            S[row][col - 1] = 1;
            q.push(make_pair(row, col - 1));
        }
    }
}