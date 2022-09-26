#include <iostream>
#include <vector>

using namespace std;
vector<int> a(8, 0);
int main(void)
{
    int n, x;
    cin >> n >> x;

    for (int i = 0; i < 8; i++)
    {
        if (n & 1 == 1)
        {
            a[i] = 1;
        }
        else
        {
            a[i] = 0;
        }
    }
    if (x == 0)
    {
        cout<<a[7];
    }
    else if(x==31){
        cout<<a[0];
    }
    else{
        cout<<a[x-1];
    }
    return 0;
}