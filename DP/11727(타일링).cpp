#include <iostream>
#include <vector>

using namespace std;
#define Max 10007

int main()
{
	int n;
	cin >> n;
	vector<int>a(1); //a[0]=0;
	a.push_back(1); //a[1]=1;  //�����Ѱ� 2*1
	a.push_back(3); //a[2] = 3; //�����Ѱ� 2*1 2�� 1*2 2�� 2*2 1�� =3��
	for (int i = 3; i <= n; i++)
	{
		a.push_back((a[i - 1] + a[i - 2]*2)%Max);
	}
	cout << a[n];
	//
}