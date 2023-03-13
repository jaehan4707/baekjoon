#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

long long dis = 0;
int lim = 0;
void funct(vector<int> &deliveries, vector<int> &pickups);
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
    long long answer = -1;
    lim = cap;
    for (int i = n - 1; i >= 0; i--)
    {
        if (deliveries[i] == 0)
            deliveries.pop_back();
        else
            break;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (pickups[i] == 0)
            pickups.pop_back();
        else
            break;
    }
    while (!(deliveries.empty() && pickups.empty()))
    { // 수거, 배달이 모두 0일때 종료함
        funct(deliveries, pickups);
    }
    answer = dis;
    return answer;
}
void funct(vector<int> &deliveries, vector<int> &pickups)
{
    int tempD = 0; // 배달상자.
    int tempP = 0;
    bool check = false;
    dis += max(deliveries.size() * 2, pickups.size() * 2);
    for (int i = deliveries.size() - 1; i >= 0; i--)
    { // 거꾸로 시작.
        if (deliveries[i] == 0 && check == false)
        {
            deliveries.pop_back();
            continue;
        }
        if (tempD == lim) //꽉 채운 경우
        {
            break;
        }
        if (deliveries[i] != 0)
        { // 배달할 상자가 있다면.
            check = true;
            if (lim < tempD + deliveries[i])
            { // 현재 트럭에 있는 상자수보다 더 필요하다면.
                deliveries[i] -= lim - tempD;
                tempD += lim - tempD; //
            }
            else // 현재 트럭에 있는 상자수로 해결된다면
            {
                tempD += deliveries[i];
                deliveries[i] = 0;
            }
            if (deliveries[i] == 0)
            {        
                deliveries.pop_back();
                check = false;
            }
        }
    }
    check = false;
    for (int i = pickups.size() - 1; i >= 0; i--)
    {
        if (check == false && pickups[i] == 0)
        { // 아직 한번도 방문안하고, 0개라면 그냥 빼줌.
            pickups.pop_back();
            continue;
        }
        if (tempP == lim)
        { // 꽉꽉채웟음.
            break;
        }
        if (pickups[i] != 0)
        { // 픽업할 상자가 있다면.
            check = true;
            if (tempP + pickups[i] > lim)
            {
                // 현재 트럭에 있는 상자수 + 수거한 상자수가 크다면. 일단 할 수 있는 만큼 담는다.
                pickups[i] -= (lim - tempP); // 담은 만큼 빼준다.
                tempP = lim; // 최대로 찻음.
            }
            else
            { // 방문한곳에서 전부다 수거 할 수 있으면.
                tempP += pickups[i];
                pickups[i] = 0;
            }
            if (pickups[i] == 0)
            {
                pickups.pop_back(); // 픽업을 했는데 , 만약 맨 위가 아니라면.
                check = false;
            }
        }
    }
}