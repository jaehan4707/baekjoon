//���� 1052�� �����ű��
// K=1 �϶� N=2->0 N=3->1 N=4->
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, k, bottle=0, m = 0, result = 0, count = 1,buy;
	cin >> n >> k; //��������=n , ���ִ� ������ ����=k
	bottle = n;
	if (n <= k)
	{
		cout << 0;
	}
	else
	{
		while (result <= k)
		{
			if (n % 2 == 0) //¦��
			{
				n= n / 2;
				count = count*2; //��ĥ������ ��L ũ��
				//result = n;
			}
			else //Ȧ��
			{
				n = n / 2;
				//m = 1;
				count = count*2;
				//result = n+ m;
			}
			if (n == 0)
			{
				count = count / 2;
				n = bottle - count;
				bottle = n;
				buy = count - n;
				result = result+1;
				count = 1;
			}
		}
		cout << result;
	}
	
}
