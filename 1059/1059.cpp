//ù°���� S�� ũ�Ⱑ �־�����, �� ° �ٿ��� ������ ���� ��°�ٿ��� n���־�����.
// n�� ������ ���� ������ ������ ���   A<=x<=B�ϋ� ��� ���� x�� ���� S�� ������ �ʴ´�.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
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
    // n�� ������ ���� ������ ������ ����ؾ���. �׷��� n�� ������� �Ǻ��ؾ���.
    ary.push_back(n);

    sort(ary.begin(), ary.end()); //�̷��� ary���� n�� ��ġ�� �˰Եɰ���.
    start = n;
    for (int i = 0; i < ary.size(); i++)
    {
        if (ary[i] == n)
        {
            start = ary[i - 1];
            finish = ary[i + 1];
        }
    }
    //start finish �̰�. �� �ȿ��� n�� �����ϴ� ���� ������ ã�ƾ� ������.
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