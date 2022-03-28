//��ǥ�� �پ �Է¹ް� �Է¹��� ���ڰ� Ż���� Ż������ �������� �ּ����� �湮�� �ؾ���.
//�ּ����� �湮�� ã�����ؼ��� BFS�� ���
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
queue<pair<int, int>>idx;
void move(vector<vector<int>>& maze, int i, int j,vector<vector<int>>&visit,vector<vector<int>>&cnt);
void bfs(vector<vector<int>>& maze, vector<vector<int>>& cnt);
int n, m,cnt=0;
int main()
{
    
    cin >> n >> m;
    vector<vector<int>>maze(n+1, vector<int>(m+1, 0)); 
    vector < vector<int>>cnt(n + 1, vector<int>(m + 1, 0)); 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", &maze[i][j]); //�پ��ִ��Է¹�������1d
        }
    }
    bfs(maze,cnt);
    cout << cnt[n][m];  //������ �湮���� ȣ��
 
}
void bfs(vector<vector<int>>& maze,vector<vector<int>>&cnt)
{
    //(1,1)���� ��� end�� (n,m)
    idx.push(make_pair(1, 1)); //����� push
    vector<vector<int>>visit(n + 1, vector<int>(m + 1, 0)); // �湮�� ���� ��������
    visit[1][1] = 1; //�湮�Ѱ��� 1�� ����.
    cnt[1][1] = 1;
    while (!idx.empty()) { //queue�� �������� �ݺ�
        move(maze, idx.front().first, idx.front().second,visit,cnt); //queue�� ����� row,col�� �־���.
        idx.pop();
    }
}
void move(vector<vector<int>>& maze, int i, int j, vector<vector<int>>& visit,vector<vector<int>>&cnt) // �����̴°�
{
    if (i + 1 <= n && maze[i + 1][j] == 1 && visit[i + 1][j] == 0)
    {
        idx.push(make_pair(i + 1, j));
        visit[i + 1][j] = 1;
        cnt[i + 1][j] = cnt[i][j] + 1;
    }
    if (i - 1 >= 1 && maze[i - 1][j] == 1 && visit[i - 1][j] == 0)
    {
        idx.push(make_pair(i - 1, j));
        visit[i - 1][j] = 1;
        cnt[i-1][j] = cnt[i][j] + 1;
    }
    if (j - 1 >= 1 && maze[i][j - 1] == 1 && visit[i][j - 1] == 0)
    {
        idx.push(make_pair(i, j - 1));
        visit[i][j - 1] = 1;
        cnt[i][j-1] = cnt[i][j] + 1;
    }
    if (j + 1 <= m && maze[i][j + 1] == 1 && visit[i][j + 1] == 0)
    {
        idx.push(make_pair(i, j + 1));
        visit[i][j + 1] = 1;
        cnt[i ][j+1] = cnt[i][j] + 1;
    }
}