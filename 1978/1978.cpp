/*
�־��� N�� �߿��� �Ҽ��� ����� ã�Ƽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�
�Է� ù�ٿ� ���� ���� N�� �־�����. N�� 100�����̴�. �������� N���� ���� �־����µ� ���� 1,000������ �ڿ���
�ҽ��� ������ ���

�Ҽ��� �ڱ��ڽŰ� 1���� ����� ������ ��.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool num(int n);
int main()
{
    int n, N, Cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int N;
        cin >> N;
        if (num(N) == 1) //�Ҽ����� �Ǵ��غ���.
        {
            //cout<<N<<endl;
            Cnt++;
        }
    }
    cout << Cnt;
}
bool num(int n) //�Ҽ����� �Ǵ��ϴ°�.
{
    bool flag = true;
    if (n == 1)
    {
        return false;
    }
    for (int i = 2; i < n; i++) // 1�� �ڱ��ڽ��� ������ ���δ� �������� �ȵ�.
    {
        if (n % i == 0) //����� �ϳ��� ������ �ȵ�.
        {
            flag = false;
            break;
        }
    }
    return flag;
}