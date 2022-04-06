//백준 9095번 문제
// dp를 풀때는 각 경우의수와 관계식을 찾아야함. 점화식 사용
//4를 만들려고 할때 1 + 3 2 + 2 3 + 1  ==> a[1]+a[2]+a[3] a[2]인 경우 a[2]의 원소 개수 +2 를 하면 4를 만들 수 있다.
//그러한 경우로 3도 각자의 원소에서 1을 더해준다. 즉 a[i]=a[i-1]+a[i-2]+a[i-3]이다.
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T, c = 0, num; // testcase 개수
    vector<int> a(0);
    a.push_back(0);
    cin >> T;
    c++;

    for (int k = 0; k < T; k++)
    {
        a.push_back(1);
        a.push_back(2);
        a.push_back(4);
        cin >> num;
        for (int i = 4; i <= num; i++)
        {
            a.push_back(a[i - 1] + a[i - 2] + a[i - 3]);
        }
        cout << a[num] << "\n";
        a.resize(1, 0);
    }
}