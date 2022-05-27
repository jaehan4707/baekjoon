#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(int i, int j)
{
    return i > j;
}
bool comp(pair<int, int>p, pair<int, int>q)
{
    return p.first > q.first;
}
string solution(vector<int> numbers)
{
    string answer = "";
    vector<string>a(numbers.size());
    vector<pair<string, int>>p;
    sort(numbers.begin(), numbers.end(), compare);
    if (numbers[0] == 0)
    {
        answer = '0';
        return answer;
    }
    cout << endl;
    for (int i = 0; i < numbers.size(); i++)
    {
        //a의 길이가 12가 될때까지 이어붙임.
        string str = to_string(numbers[i]);
        //cout<<str.length()<<endl;
        int size = 12 / str.length();
        //cout<<size<<endl;
        for (int j = 0; j < size; j++)
        {
            a[i] += to_string(numbers[i]);
        }
        p.push_back(make_pair(a[i], str.length()));
    }
    sort(a.begin(), a.end());
    sort(p.begin(), p.end());
    for (int i = a.size() - 1; i >= 0; i--)
    {
        int size;
        size = p[i].second;
        for (int j = 0; j < size; j++)
        {
            answer += a[i][j];
        }

    }
    return answer;
}