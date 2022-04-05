#include <iostream>
#include <vector>

using namespace std;
int fibo(int n);
vector<int> f(0);
int main()
{
    int n;
    cin >> n;
    f.resize(n + 1, -1);
    cout << fibo(n);
}
int fibo(int n)
{
    if (n < 2)
    {
        f[n] = n;
    }
    else
    {
        if (f[n] == -1)
        {
            f[n] = fibo(n - 1) + fibo(n - 2);
        }
        else
            return f[n];
    }
    return f[n];
}