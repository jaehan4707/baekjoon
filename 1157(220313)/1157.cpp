#include <iostream>
#include <string>
//#include <cctype>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int big = 0;
    char result = { 0 };
    string str1;
    cin >> str1;
    int num[10000];
    int cnt[10000] = { 0 };
    // cout << str1 << "\n";
    for (int i = 0; i < str1.length(); i++)
    {
        str1[i] = toupper(str1[i]);
    }
    //sort(str1.begin(), str1.end());
    for (int j = 0; j < str1.length(); j++)
    {
        for (char i = 'A'; i <= 'Z'; i++)
        {
            if (i == str1[j])
            {
                cnt[i]++;
            }
        }
    }
    for (char i = 'A';i <= 'Z'; i++)
    {
        if (cnt[result] < cnt[i])
            result = i;
    }
    for (char i = 'A'; i <= 'Z'; i++)
    {
        if (cnt[result] == cnt[i])
            big++;
    }
    if (big > 1)
    {
        cout << '?';
    }
    else
        cout << result;
}