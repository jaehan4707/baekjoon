#include <iostream>
#include <vector>

using namespace std;
int N,c=0;
vector<int>a(N);
int dp(int n);
int main()
{
    int N; // 설탕 그램수
    //3이면 3키로 한개 4키로 한개
    cin >> N;
    a.resize(N+1, 0);
    cout << dp(N);
}
int dp(int n)
{
    //a[3] = 1;
    //a[0] = 1;
    /*
    if(n%3==0&&n%5==0) //3의 배수,5의 배수가 일 때
    {
        a[n]=n/5;
    }
    else if(n%3==0 &&n%5!=0)//3의 배수,5의 배수가 아닐 때
    {
        a[n]=n/3;
    }
    */
    if (n<3)
    {
        a[n] = 0;
    }
    else //n>3
    {
        if (n == 3 || n == 5)
        {
            c++;
            a[n] = 1;
            return c+ a[n];
        }
        else if (n == 4)
        {
            a[n] = dp(n - 3);
        }
        else
        {
            a[n] = dp(n - 3) + dp(n - 5);
            //a[n] = a[n] + a[n - 3] + a[n - 5];
        }
    }
    return a[n];
}