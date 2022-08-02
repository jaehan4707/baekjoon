/*
M과 N사이의 소수를 찾아내자.
에라토스테네스의 체 이용
2의 배수 제거. 3의배수 제거. 어디까지
루트 N까지 제거
루트 N이 절반 나눳을때 마지막 약수

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int M, N;
int main()
{
	cin >> M >> N;
	vector<int> include(N + 1);
	for (int i = 2; i <= N; i++)
	{
		include[i] = 1;
	}
	include[1] = 0;
	for (int i = 2; i <= sqrt(N); i++) // 2부터 루트 N까지 검사함.
	{
		if (include[i] == 0) //만약 이미 소수가 아니라고 판별낫다면 검사할필요없음,
		{
			continue;
		}
		for (int j = i * i; j <= N; j = j + i) // i의 배수부터 N까지 배수를 싹 다지움.
		{
			include[j] = 0;
		}
	}
	for (int i = M; i <= N; i++) // M부터 N까지의 소수를 출력하는데 소수는 include값이 1인것.
	{
		if (include[i] == 1)
		{
			cout << i << "\n";
		}
	}
}