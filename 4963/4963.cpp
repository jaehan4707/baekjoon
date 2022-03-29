#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int row = 1, col = 1, num = 0;
queue<pair<int, int>> q;
void bfs(vector<vector<int>>& island, vector<vector<int>>& visit);
void move(vector<vector<int>>& island, int i, int j, vector<vector<int>>& visit);
int main()
{
    //����� ���������� ������ +1
    while (1)
    {
        cin >> row >> col; // row �Է¹ް�
        if (row == 0 && col == 0)
        {
            break;
        }
        vector<vector<int>> island(col + 1, vector<int>(row + 1, 0)); // island[col+1][row+1] ������ �迭�� ���� row=5 col=4
        vector<vector<int>> visit(col + 1, vector<int>(row + 1, 0));
        for (int i = 1; i <= col; i++)
        {
            for (int j = 1; j <= row; j++)
            {
                cin >> island[i][j];
            }
        }
        for (int i = 1; i <= col; i++)
        {
            for (int j = 1; j <= row; j++)
            {
                if (island[i][j] == 1 && visit[i][j] == 0)
                {
                    q.push(make_pair(i, j));
                    num++;
                    bfs(island, visit);
                }
            }
        }
        cout << num << "\n";
        num = 0; // num�ʱ�ȭ
    }
}
void bfs(vector<vector<int>>& island, vector<vector<int>>& visit)
{

    while (!q.empty()) // q�� ��������� ����
    {
        int Row, Col;
        Row = q.front().first;
        Col = q.front().second;
        visit[Row][Col] = 1;
        move(island, Row, Col, visit);
        q.pop();
        if (!q.empty())
        {
            Row = q.front().first;
            Col = q.front().second;
        }
        else
            continue;
        bfs(island, visit);
    }
}
void move(vector<vector<int>>& island, int i, int j, vector<vector<int>>& visit) // �����̴°�
{
    if (i + 1 <= col && island[i + 1][j] == 1 && visit[i + 1][j] == 0) //�Ʒ�
    {
        q.push(make_pair(i + 1, j));
        visit[i + 1][j] = 1;
    }
    if (i - 1 >= 1 && island[i - 1][j] == 1 && visit[i - 1][j] == 0) //��
    {
        q.push(make_pair(i - 1, j));
        visit[i - 1][j] = 1;
    }
    if (j - 1 >= 1 && island[i][j - 1] == 1 && visit[i][j - 1] == 0) //����
    {
        q.push(make_pair(i, j - 1));
        visit[i][j - 1] = 1;
    }
    if (j + 1 <= row && island[i][j + 1] == 1 && visit[i][j + 1] == 0) //������
    {
        q.push(make_pair(i, j + 1));
        visit[i][j + 1] = 1;
    }
    if (i - 1 >= 1 && j + 1 <= row && island[i - 1][j + 1] == 1 && visit[i - 1][j + 1] == 0) //���� �밢��
    {
        q.push(make_pair(i - 1, j + 1));
        visit[i - 1][j + 1] = 1;
    }
    if (i + 1 <= col && j + 1 <= row && island[i + 1][j + 1] == 1 && visit[i + 1][j + 1] == 0) //�޾Ʒ� �밢��
    {
        q.push(make_pair(i + 1, j + 1));
        visit[i + 1][j + 1] = 1;
    }
    if (i - 1 >= 1 && j - 1 >= 1 && island[i - 1][j - 1] == 1 && visit[i - 1][j - 1] == 0) //���� �밢��
    {
        q.push(make_pair(i - 1, j - 1));
        visit[i - 1][j - 1] = 1;
    }
    if (i + 1 <= col && j - 1 >= 1 && island[i + 1][j - 1] == 1 && visit[i + 1][j - 1] == 0) //�޾Ʒ� �밢��
    {
        q.push(make_pair(i + 1, j - 1));
        visit[i + 1][j - 1] = 1;
    }
}