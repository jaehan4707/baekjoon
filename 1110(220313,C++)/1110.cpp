#include <iostream>

using namespace std;

int main()
{
    int n, z = 0, sum = 0, cnt = 0, Num = 0;
    cin >> n;
    int ary[2];
    Num = n;
    ary[0] = n / 10;
    ary[1] = n % 10;
    while (1)
    {
        if (ary[0] == 0)
        {
            z = ary[0];
            n = ary[1];
            sum = z + n;
            ary[0] = n;
            ary[1] = sum;
        }
        else
        {
            sum = ary[0] + ary[1];
            ary[0] = ary[1];
            ary[1] = sum % 10;
        }
        cnt++;
        if (Num / 10 == ary[0] && Num % 10 == ary[1])
        {
            break;
        }
    }
    cout << cnt;
    return 0;
}