#include <iostream>
#include <vector>
#include <algorithm>
/*
���� ���Ը� ū ������� �����Ѵ�.
�׸��� ���濡 ū ������� ��� �������Ѵٸ� ������ ��� �׷��� �ϴ½����� Ǯ�� �ɰŰ�����?
*/
using namespace std;
int big(int i, int j)
{
    return i > j;
}
int N, W, totweight = 0;
vector<int> profit;
vector<int>include;
int Count = 0;
int bag = 0;
int main()
{
    cin >> N;
    cin >> W;
    profit.resize(N, 0);
    include.resize(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> profit[i];
    }
    sort(profit.begin(), profit.end(), big); //������ ���԰� ū ������� ������.
    int begin = 0;
    int end = N - 1;
    for (int i = 0; i < N; i++) 
    {
        for (int j = N-1; j >=0; j--)
        {
            if (profit[i] + profit[j]<=W) //���� ū ���Կ� ���� ���� ���Ը� ���� �� �ִٸ� �־���.
            {
                bag++;
                N = N - 1; //��Ҵٸ� ���� ���� ���� ���ܽ��Ѿ��ϱ⶧���� ���� �ϳ� ����.
                break;
            }
            else if (profit[i] <= W) //���� ���� ū ���Կ� ���� ���� ���Ը� ���� �� ������, ���� ū �͸� ������ �ִٸ�? �����.
            {
                bag++;
                break;
            }
        }
    }
    cout << bag;
}