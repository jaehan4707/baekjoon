#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, a, b;
int main()
{
	int cc = 1;
	cin >> n >> a >> b;
	bool flag = false;
	while (n != 1)
	{


		if ((a + 1) / 2 == (b + 1) / 2)
		{
			flag = true;
			break;
		}

		if (n % 2 == 0)
			n = n / 2;
		else
			n = n / 2 + 1;
		if (a % 2 == 0)
		{
			a = a / 2;
		}
		else
			a = a / 2 + 1;
		if (b % 2 == 0)
		{
			b = b / 2;
		}
		else
			b = b / 2 + 1;
		cc++;
	}
	if (flag == true)
	{
		cout << cc;
	}
	else
		cout << -1;

}