#include <iostream>
#include <vector>


using namespace std;

int main()
{
	int n,start,finish;
	cin >> n;
	vector<int>x(n+1,0);
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i];
	}
	cin>> start >> finish;
	int range = finish - start;
	if (range < 0)
	{
		range = range * -1;
	}
	if (start < finish)
	{
		if (x[start] == 1)
			cout << 1;
		else
		{
			if (range % start == 0)
				cout << 1;
			else
				cout << -1;
		}
	}
	else //�Ųٷ� ����
	{
		if (x[start] == 1)
			cout << 1;
		else
		{
			if (range % x[start] == 0)
			{
				cout << 1;
			}
			else cout << -1;
		}
	}
}