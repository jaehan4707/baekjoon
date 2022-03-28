//좌표를 붙어서 입력받고 입력받은 숫자가 탈출점 탈출점을 갈때까지 최소한의 방문을 해야함.
//최소한의 방문을 찾기위해서는 BFS를 사용
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
            scanf("%1d", &maze[i][j]); //붙어있는입력받을때는1d
        }
    }
    bfs(maze,cnt);
    cout << cnt[n][m];  //누적된 방문값을 호출
 
}
void bfs(vector<vector<int>>& maze,vector<vector<int>>&cnt)
{
    //(1,1)에서 출발 end는 (n,m)
    idx.push(make_pair(1, 1)); //출발점 push
    vector<vector<int>>visit(n + 1, vector<int>(m + 1, 0)); // 방문한 곳을 지정해줌
    visit[1][1] = 1; //방문한곳은 1로 해줌.
    cnt[1][1] = 1;
    while (!idx.empty()) { //queue가 빌때까지 반복
        move(maze, idx.front().first, idx.front().second,visit,cnt); //queue에 저장된 row,col을 넣어줌.
        idx.pop();
    }
}
void move(vector<vector<int>>& maze, int i, int j, vector<vector<int>>& visit,vector<vector<int>>&cnt) // 움직이는거
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