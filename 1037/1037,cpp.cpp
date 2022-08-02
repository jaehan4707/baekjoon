/*
��� ���ϱ�
��� A�� N�� ��¥ ����� �Ƿ��� N�� A�� ����̰�, A�� 1�� N�� �ƴϾ���Ѵ�. � �� N�� ��¥ ����� ��� �־��� ��, N�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

ù°�ٿ� N�� ��¥ ����� ������ �־�����. �� ������ 50���� �۰ų� ���� �ڿ����̴�. ��° �ٿ��� N�� ��¥ ����� �־�����. �ߺ����� �ʴ´�.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int com(int i, int j)
{
    return i < j;
}
int main()
{
    int n, result;
    cin >> n;
    vector<int> num;
    for (int i = 0; i < n; i++)
    {
        int N;
        cin >> N;
        num.push_back(N);
    }
    //�Է� ���� num�� ������������ ����
    sort(num.begin(), num.end(), com);
    if (num.size() != 1) //
    {
        result = num[0] * num[num.size() - 1];
    }
    else
    { //����� ������ Ȧ �����
        result = num[0] * num[0];
    }
    cout << result;
}