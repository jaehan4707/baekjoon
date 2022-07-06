/*12865*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> profit, weight, include;
int n, w, NowWeight, Maxprofit;
void knapsack(int i, int totweight, int totprofit);
vector<vector<int>>bag;
int main()
{
    cin >> n >> w;
    profit.resize(n + 1, 0), weight.resize(n + 1, 0), bag.resize(n + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i] >> profit[i];
    }
    //���� �������Ժ��� �������� ������ �ߴµ�,DP���������� ���� �������Ժ��� ������ ���ص� �ȴٴ� ����� �˾���.
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if ((double)profit[i] / weight[i] < (double)profit[j] / weight[j])
            {
                swap(profit[i], profit[j]);
                swap(weight[i], weight[j]);
            }
        }
    }
    knapsack(0, 0, 0);
}
void knapsack(int i, int totweight, int totprofit)
{
    /*DP�� ����ؼ� ��������� �ȴ������ �� ���� ���Ը� ��.
    ���� ���� �ʾ��� ��� P[i-1][totweight]�� �ǰ���
    ���� ����� ��� P[i][W]= P[i-1]+[totweight-wegiht[i]]�ΰ�?
    */
    for (int i = 1; i <= n; i++) //n�� ���° ����
    {
        for (int j = 1; j <= w; j++) //j�� ���Ը� ���Ѵ�. �� P[2][30]�� 2��° �賶���� Ž���ϰ� �׶��� ����Ǵ� ���Դ� 30�̶�� ��.
        {
            totweight = weight[i], totprofit = profit[i];
            if (totweight > j) //����Ǵ� ���Ժ��� totweight�� �Ѵ´ٸ�? --> �� ���������� �̶����� ��Ҵ� ���� ��������ָ��.
            {
                bag[i][j] = bag[i - 1][j];
            }
            else if (totweight <= j)//����Ǵ� ���Ժ��� totweight�� �۴ٸ� -> �� ���� �� �ִٸ�?
            {
                //�������� �ȴ�����츦 ���ؼ� ū ���� ����. 
                //����� ��� ���� ����Ǵ� ���Կ��� ���� ���Ը� ���� �� ���Կ� ���� ��ġ�� bag[i][j]�� �־��ش�.
                bag[i][j] = max(bag[i - 1][j], bag[i - 1][j - totweight] + totprofit);
            }
        }
    }
    cout << bag[n][w]; // ���� �츮�� ���ϰ��� �ϴ� ���̴�.
}