//���� 9095�� ����
// dp�� Ǯ���� �� ����Ǽ��� ������� ã�ƾ���. ��ȭ�� ���
//4�� ������� �Ҷ� 1 + 3 2 + 2 3 + 1  ==> a[1]+a[2]+a[3] a[2]�� ��� a[2]�� ���� ���� +2 �� �ϸ� 4�� ���� �� �ִ�.
//�׷��� ���� 3�� ������ ���ҿ��� 1�� �����ش�. �� a[i]=a[i-1]+a[i-2]+a[i-3]�̴�.
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T, c = 0, num; // testcase ����
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