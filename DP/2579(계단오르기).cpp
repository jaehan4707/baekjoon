//���� 2579
//a[n]�� �׻� n��° ��ܰ��� �����ϴ� �ִ밪�̾���Ѵ�
//a[4]�� a[2]+s[4] vs a[1]+s[3] +s[4]
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
    //ù ����� ��� �����Ҷ�
    a[1] = s[1];
    a[2] = a[1] + s[2];          // 2��° ���� �ִ밪�� 1,2���ϴ°�
    a[3] = max(s[1] + s[3], s[2] + s[3]);          // 3��° ���� �ִ밪�� 1+3, 2+3�߿� �ִ밪
    for (int i = 4; i <= N; i++)
    {
        a[i] = max(a[i - 2] + s[i], a[i - 3] + s[i - 1] + s[i]);
    }

    cout << a[N];
}