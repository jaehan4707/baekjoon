#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;
int cut(int n, int m);
int main()
{
	int n, m;
	cin >> n >> m;
	cout <<cut(n, m);
}
int cut(int n,int m)
{
	if(n == 1)
		return m-1;
	if (n <= 0 || m <= 0)
	{
		return 0;
	}
	else{
		if (n > m)
		{
			if (n % m == 0)
			{
				return 0;
			}
			else {
				//cnt = cnt + m;
				cut(n-m,m);
			}
		}
		else if (n < m)
		{
			if (m % n == 0)
			{
				if (m % n == 0)
				{
					return 0;
				}
			}
		}
	}
}