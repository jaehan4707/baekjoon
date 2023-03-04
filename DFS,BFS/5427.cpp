#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int t, n, m;
vector<vector<char> > graph;
bool check = false;
int answ = 0;
int x[4] = {0, 0, 1, -1};
int y[4] = {-1, 1, 0, 0};
void funct(queue<pair<int,int> >people,queue<pair<int,int> >fire);
int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        graph.assign(m, vector<char>(n, 0));
        queue<pair<int, int> > people;
        queue<pair<int, int> > fire;
        check = false;
        answ = 0;
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cin >> graph[j][k];
                if (graph[j][k] == '*'){ // 불
                    fire.push(make_pair(j, k));
                }
                else if (graph[j][k] == '@'){ // 시작 위치.
                    people.push(make_pair(j, k));
                }
            }
        }
        funct(people,fire);
        if (check == true){ // 탈출 가능.
            cout << answ << endl;
        }
        else{ //탈출 불가능.
            cout << "IMPOSSIBLE" << endl;
        }
    }
}
void funct(queue<pair<int,int> >people,queue<pair<int,int> >fire)
{
    bool flag = false;
    int time = 0;
    while (!people.empty())
    {
        time++;
        int cnt = 0, size = fire.size();
        while (size != cnt) // 불이동
        {
            int row = fire.front().first,col = fire.front().second;
            fire.pop();
            for (int d = 0; d < 4; d++){
                int temprow = row + x[d];
                int tempcol = col + y[d];

                if (temprow < 0 || temprow >= m || tempcol < 0 || tempcol >= n){
                    continue;
                }
                if (graph[temprow][tempcol] != '.'){
                    continue;
                }
                graph[temprow][tempcol] = '*';
                fire.push(make_pair(temprow, tempcol));
            }
            cnt++;
        }
        int psize = people.size(), cnt2 = 0;
        while (psize != cnt2) //상근이 이동
        {
            int px = people.front().first,py = people.front().second;
            people.pop();
            for (int i = 0; i < 4; i++)
            { 
                int px2 = px + x[i], py2 = py + y[i];
                if (px2 < 0 || py2 < 0 || px2 >= m || py2 >= n){ // 배열 밖으로 나갔으면 탈출임
                    check = true;
                    answ = time;
                    return;
                }
                if (graph[px2][py2] == '.'){
                    people.push(make_pair(px2, py2));
                    graph[px2][py2] = '@';
                }
                else
                    continue;
            }
            cnt2++;
        }
    }
}
