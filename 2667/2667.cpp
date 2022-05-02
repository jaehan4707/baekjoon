#include <iostream>
#include <vector>

using namespace std;
vector<int> F;
vector<pair<int, int>> p;
int n, c = 0, C = 0;
void fibo(int n, int& a, int& b);
int main()
{
    F.push_back(0);
    F.push_back(1);
    p.push_back(make_pair(1, 0));
    p.push_back(make_pair(0, 1));
    cin >> n;
    int t, a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        fibo(t, a, b);
        cout << a << " " << b << endl;
    }
}
void fibo(int n, int& a, int& b)
{
    if (n < 2)
    {
        a = p[n].first;
        b = p[n].second;
    }
    else
    {
        for (int i = 2; i < n; i++)
        {
            F.push_back(F[i - 2] + F[i - 1]);
            p.push_back(make_pair(p[i - 1].first + p[i - 2].second, p[i - 1].second + p[i - 2].second));
        }
        a = p[n].first;
        b = p[n].second;
    }
}