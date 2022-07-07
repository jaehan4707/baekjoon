/*2503 ���ھ߱�
���ڴ� 1~9 , ���� �ٸ� 3����
���� �θ� ���ڿ� �ڸ��� ��ġ�ϴٸ� ��Ʈ����ũ
���ڴ� ��ġ�ѵ� �ڸ��� �ٸ��� ��
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
bool same(int num);
int baseball(int num, int cnum);
int c, s, b, n, Count = 0;
int main()
{
    cin >> n;
    vector<int> T(988, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> c >> s >> b;
        for (int j = 123; j <= 987; j++)
        {                //���� �ٸ� ���ڿ�����.
            if (same(j)) // 1�� ��µǸ� ���� ���ڴϱ� �ѱ�.
                continue;
            else
            {
                if (baseball(c, j))
                {                   //���� ������ s,b�� ��ġ�ϴٸ�?
                    if (T[j] == -1) //�ѹ��̶� �ɷ����� �ȵ�.
                        T[j] = 1;
                }
                else          //�ٸ��ٸ�?
                    T[j] = 0; //�ѹ��̶� ���ܵǸ� ��. �ؾ���.
            }
        }
    }
    for (int i = 123; i <= 987; i++)
    {
        if (T[i] == 1)
            Count++;
    }
    cout << Count;
    // count �ְ� strike ball �־���.
}
bool same(int num)
{
    int A, B, C;
    A = num / 100; //�����ڸ�
    num = num % 100;
    B = num / 10; // 10�� �ڸ�?
    C = num % 10;
    if (A == 0 || B == 0 || C == 0)
        return true;
    else if (A - B == 0 || A - C == 0 || B - C == 0)
        return true;
    else
        return false;
}
int baseball(int num, int cnum)
{
    int strike = 0, ball = 0;
    vector<int> old(3, 0), New(3, 0);
    old[0] = num / 100; //�����ڸ�
    num = num % 100;
    old[1] = num / 10;   // 10�� �ڸ�?
    old[2] = num % 10;   // 1�� �ڸ�
    New[0] = cnum / 100; //�����ڸ�
    cnum = cnum % 100;
    New[1] = cnum / 10; // 10�� �ڸ�
    New[2] = cnum % 10; // 1�� �ڸ�
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (old[i] == New[j])
            { //���ڰ� ���� ��
                if (i == j)
                { // �ڸ����� ���ٸ�?
                    strike++;
                }
                else
                    ball++;
            }
        }
    }
    if (s == strike && b == ball)
        return 1;
    else
        return 0;
}