/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;
#define Max 5000000
vector<int>include(Max+1);
int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	//vector<int> num(N, 0);
	int num=0;
	/*
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
		//if (max < num[i])
			//max = num[i];
	}
	
	for (int i = 2; i <= Max; i++)
	{
		include[i] = i;
	}
	include[0], include[1] = -1;
	for (int j = 2; j*j <= Max; j++)
	{
		if (include[j] == j) //j�� �Ҽ��϶� ���� include[j]�� j�� �ƴ϶�� �װ� �Ҽ��� �ƴ�.
		{
			for (int k = j * j; k <= Max; k += j) //max���� ������� �� �Ҽ��� �ʱ�ȭ������
			{
				if (include[k] == k) //���� ���� �ȵ��ٸ� ���μ��� �־���.
				{
					include[k] = j;
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		vector<int>ary;
		while (num>1)
		{
			//printf("%d ", include[num]);
			printf("%d ", include[num]);
			num = num / include[num];
		}
		printf("\n");
	}
}
/*
for (int i = 0; i < N; i++)
{
    int n = num[i];
    //�Ҽ��� �̾ƺ���.
    vector<int>include(n + 1, 1);
    for (int j = 2; j <= sqrt(num[i]); j++)
    {
        if (include[j] == 0)
        {
            continue;
        }
        for (int k = j * j; k <= num[i]; k += j)
        {
            include[k] = 0;
        }
    }
    //include���� 1�ΰ͸� �Ҽ���.
    for (int j = 2; j <= n; j++) //2���� ��Ʈ n������ �Ҽ��� �̿��ϰ������.
    {
        if (include[j] == 0) //include���� 0�̸� �Ҽ��� �ƴѰ�.
        {
            continue;
        }
        else
        {
            while (1)
            {
                if (num[i] == 1)
                {
                    break;
                }
                if (num[i] % j == 0)
                {
                    num[i] = num[i] / j;
                    cout << j << " ";
                }
                else if (num[i] % j != 0)
                {
                    break;
                }
            }
        }
    }
    cout << endl;

    //num�� ���μ��� ��� ���
}
*/

// dp?
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;
#define Max 5000000
vector<string>dp(Max+1);
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int>num(N, 0);
	for (int k = 2; k <= 1000;k++)
	{
		dp[k] = to_string(k);
	}

	for ( int x = 2; x <= sqrt(Max); x++)
	{
		//dp[2]=2, dp[3]=3, dp[4]=dp[2]*dp[2], dp[5]=dp[5];
		for (int j = x * x; j <=Max; j= x + j)
		{
			//dp[j]=dp[x] * �ƹ��ų�
			int y;
			y = j / x;
			dp[j] = dp[x] + dp[y];
			//sort(dp[j].begin(), dp[j].end());
			///������������ �־����. ���?  //dpy�� dpx�߿� �����ͺ��� �־�����
			//sort(dp[j].begin, dp[j].end);
			//4,6,8
		}
	}
	for (int k = 0; k < N; k++)
	{
		int a=0;
		cin >> a;
		sort(dp[a].begin(), dp[a].end());
		cout << dp[a] << endl;
	}
}
	
/*
	for (int i = 0; i < N; i++)
	{
		int n = num[i];
		//�Ҽ��� �̾ƺ���.
		vector<int>include(n + 1, 1);
		for (int j = 2; j <= sqrt(num[i]); j++)
		{
			if (include[j] == 0)
			{
				continue;
			}
			for (int k = j * j; k <= num[i]; k += j)
			{
				include[k] = 0;
			}
		}
		//include���� 1�ΰ͸� �Ҽ���.
		for (int j = 2; j <= n; j++) //2���� ��Ʈ n������ �Ҽ��� �̿��ϰ������.
		{
			if (include[j] == 0) //include���� 0�̸� �Ҽ��� �ƴѰ�.
			{
				continue;
			}
			else
			{
				while (1)
				{
					if (num[i] == 1)
					{
						break;
					}
					if (num[i] % j == 0)
					{
						num[i] = num[i] / j;
						cout << j << " ";
					}
					else if (num[i] % j != 0)
					{
						break;
					}
				}
			}
		}
		cout << endl;

		//num�� ���μ��� ��� ���
	}

	//dp?

*/