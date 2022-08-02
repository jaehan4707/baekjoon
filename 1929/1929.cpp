/*
M? N??? ??? ????.
???????? ? ??
2? ?? ??. 3??? ??. ????
?? N?? ??
?? N? ?? ?�?? ??? ??
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
	for (int i = 2; i <= sqrt(N); i++) // 2?? ?? N?? ???.
	{
		if (include[i] == 0) //?? ?? ??? ???? ????? ???????,
		{
			continue;
		}
		for (int j = i * i; j <= N; j = j + i) // i? ???? N?? ??? ? ???.
		{
			include[j] = 0;
		}
	}
	for (int i = M; i <= N; i++) // M?? N??? ??? ????? ??? include?? 1??.
	{
		if (include[i] == 1)
		{
			cout << i << "\n";
		}
	}
}