//백준 2579
//a[n]은 항상 n번째 계단값을 포함하는 최대값이어야한다
//a[4]는 a[2]+s[4] vs a[1]+s[3] +s[4]
//a[n]=a[n-2]+s[n] vs a[n-3]+s[n-1]+s[n]
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, count = 0;
    cin >> N;
    vector<int> s(N + 1, 0);
    vector<int> a(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        cin >> s[i];
    }
    //첫 계단을 밟고 시작할때
    a[1] = s[1];
    a[2] = a[1] + s[2];          // 2번째 까지 최대값은 1,2더하는것
    a[3] = max(s[1] + s[3], s[2] + s[3]);          // 3번째 까지 최대값은 1+3, 2+3중에 최대값
    for (int i = 4; i <= N; i++)
    {
        a[i] = max(a[i - 2] + s[i], a[i - 3] + s[i - 1] + s[i]);
    }

    cout << a[N];
}