#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string solution(int n);
int main()
{
	int n;
	cin >> n;
   cout<<solution(n);
}
string solution(int n)
{
	string answer;
	string result;
	string s = "412";
	if (n <= 3)
	{
		answer = s[n % 3];
		return answer;
	}
	while (n!=0)
	{
		
		int r;
		r = n % 3;
		//나머지가 1이면 1, 나머지가 2이면 2, 나머지가 0이면 4
		answer += s[r];
		if (n % 3 == 0)
			n = (n / 3)-1;
		else
			n = n / 3;
	}
	reverse(answer.begin(), answer.end());
	return answer;
}