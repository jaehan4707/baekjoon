#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int main()
{
	cin >> N >> K;
	vector<int>s;
	for (int i = 0; i < N; i++)
	{
		int S;
		cin >> S;
		s.push_back(S);
	}
	sort(s.begin(), s.end());
	vector<int>range(N - 1, 0);
	for (int i = 0; i < range.size(); i++)
	{
		range[i] = s[i + 1] - s[i];
	}
	sort(range.begin(), range.end());
	int sum = 0;
	for (int i = 0; i < N - K; i++)
	{
		sum = sum + range[i];
	}
	cout << sum;
}