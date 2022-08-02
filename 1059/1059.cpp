#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//첫째줄은 S의 크기가 주어지고, 둘 째 줄에는 집합의 원소 셋째줄에는 n이주어진다.
// n을 포함한 좋은 구간의 개수를 출력   A<=x<=B일떄 모든 정수 x가 집합 S에 속하지 않는다.
int main()
{

    int t, n, num, start, finish;
    cin >> t;
    vector<int> ary;
    for (int i = 0; i < t; i++)
    {
        cin >> num;
        ary.push_back(num);
    }
    cin >> n;
    for (int i = 0; i < ary.size(); i++)
    {
        if (ary[i] == n)
        {
            cout << 0;
            return 0;
        }
    }
    // n을 포함한 좋은 구간의 개수를 출력해야함. 그러면 n이 어딨는지 판별해야함.
    ary.push_back(n);

    sort(ary.begin(), ary.end()); //이러면 ary에서 n에 위치를 알게될거임.
    start = n;
    for (int i = 0; i < ary.size(); i++)
    {
        if (ary[i] == n)
        {
            start = ary[i - 1];
            finish = ary[i + 1];
        }
    }
    // start finish 뽑고. 그 안에서 n을 포함하는 좋은 구간을 찾아야 하지요.
    int count = 0;
    // cout<<start<<" "<<finish<<endl;
    for (int i = start + 1; i <= n; i++)
    {
        for (int j = n; j <= finish - 1; j++)
        {
            if (i == j)
                continue;
            count++;
        }
    }
    cout << count;
}