#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;
int x, y;
queue<pair<int, int>> q;
void funct();
int ans = 0;
int mintime = INT_MAX;
int main()
{
    cin >> x >> y;
    q.push(make_pair(0, x)); // {시간, 좌표} -> 를 q에 넣음.
    funct();
    cout << mintime << "\n" << ans << endl;
}
void funct()
{
    vector<int> visit(1000001, INT_MAX); //시간대를 계속 최소값으로 업데이트 해주기 위한 초기값 설정
    visit[x] = 0;
    while (!q.empty())
    {
        int time = q.front().first;
        int location = q.front().second;
        q.pop();
        if (time > mintime){ //도착했을때의 시간대보다 길다면 검사를 생략
            break;
        }
        if (visit[location] < time){ //방문한 지역이 이미 방문했다면 == 시간대가 더 크다면 생략.
            continue;
        }
        visit[location] = time; //방문 처리. 시간대를 기록.
        if (location == y && time <= mintime){ // 처음으로 도착햇다면, 그때의 시간을 기록해두자.
            ans++;
            mintime = time;
            continue;
        }
        //아래 코드는 모두 이동하는 위치가 범위를 벗어나지 않고, 시간을 업데이트 해줄 필요성이 있을 때의 작업.
        if (location * 2 <= 100000 && visit[location * 2] >= time + 1){
            q.push(make_pair(time + 1, location * 2));
            visit[location * 2] = time + 1;
        }
        if (location - 1 >= 0 && visit[location - 1] >= time + 1){
            q.push(make_pair(time + 1, location - 1));
            visit[location - 1] = time + 1;
        }
        if (location + 1 <= 100000 && visit[location + 1] >= time + 1){
            q.push(make_pair(time + 1, location + 1));
            visit[location + 1] = time + 1;
        }
    }
}