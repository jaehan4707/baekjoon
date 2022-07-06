// 11053
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> ary, cnt, include;
vector<vector<int>>DP;
#define MAX 1001
int main()
{
    cin >> n;
    ary.resize(n + 1, 0);
    vector<int>dp(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> ary[i];
    }
    //�����ϰ� ���Ծ��ϰ� ������.
    // DP[i][j]���� i�� ���� Ž���� ������ ���� �ϰ�, j�� ���� ���� ���� �����߿��� ���� ū���� �ұ�?
    // �׷� DP[i][j]�� ���� ���̷� �ϸ� �ǰٴ�.!
    int nowV = 0, Cnt = 0, oldV = 0, CurV = 0;
    for (int i = 0; i < n; i++) //i�� ������ �Ǵ� ����
    {
        for (int j = 0; j < i; j++) //j�� 0~���� ������ ã�°�.
        {
            if (ary[i] > ary[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int max = 0;
    for (auto a : dp)
    {
        if (max < a)
        {
            max = a;
        }
    }
    cout << max + 1;
}