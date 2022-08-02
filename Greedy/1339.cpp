/* 백준 1339 골드4 단어수학
우선 자리수를 비교해서 자리수가 가장 큰 문자열부터 숫자를 결정함.


*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;
int n;
vector<string> voca;
vector<int> bulk;
vector<pair<int, char>> p;
map<char, int> m;
vector<string> math;
vector<string> ans_string;
bool comp(int a, int b)
{
    return a > b;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        voca.push_back(s);
        bulk.push_back(voca[i].size());
    }
    // size별로 정렬함.
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (bulk[i] < bulk[j])
            {
                swap(bulk[i], bulk[j]);
                swap(voca[i], voca[j]);
            }
        }
    }
    //이러면 길이가 긴순서대로 문자열을 정렬함.
    // size[0]을 하나씩 깎으면서 size[1]과 같아질떄까지 반복함.
    //모든 문자열을 가장 size가 큰 길이로 맞춰준다.

    for (int i = 1; i < n; i++)
    {
        string s = voca[i];
        voca[i].erase(); //이러면 voca[i]가 비나?-> 빈다.
        int Size = bulk[0] - bulk[i];
        // cout<<Size<<endl;
        int idx = 0;
        while (idx != Size)
        {
            // cout<<1<<endl;
            voca[i] += "a";
            idx++;
        }
        voca[i] += s;
        // cout<<voca[i]<<" "<<voca[i].size()<<endl;
    }
    int Max_size = voca[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < Max_size; j++)
        {
            p.push_back(make_pair(pow(10, Max_size - j - 1), voca[i][j]));
        }
    }
    sort(p.begin(), p.end());
    // pair 의 first는 자리수, second는문자
    // map의 첫번쨰는 문자, second는 숫자
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i].second == 'a') //공백이 아니라면
        {
            continue;
        }
        else
        {
            if (m.find(p[i].second) == m.end()) //못찾는다면 처음 자리의 우선순위를 넣어줌.
            {
                m.insert(make_pair(p[i].second, p[i].first));
            }
            else
            { //찾앗다면?
                int value = m.find(p[i].second)->second;
                m[p[i].second] = value + p[i].first;
            }
        }
    }
    vector<pair<int, char>> jaehan;
    for (auto iter = m.begin(); iter != m.end(); iter++)
    {
        jaehan.push_back(make_pair(iter->second, iter->first));
    }
    for (int i = 0; i < jaehan.size(); i++)
    {
        for (int j = i + 1; j < jaehan.size(); j++)
        {
            if (jaehan[i].first < jaehan[j].first)
            {
                swap(jaehan[i], jaehan[j]);
            }
        }
    }
    /*
    for (auto a : jaehan)
    {
        cout << a.first << " " << a.second << " ";
    }
    */
    m.clear();
    //문자열을 이제 숫자로 매핑해야함.
    int answer = 9;
    for (int i = 0; i < jaehan.size(); i++)
    {
        if (m.find(jaehan[i].second) == m.end())
        {
            m.insert(make_pair(jaehan[i].second, answer));
            answer--;
        }
    }
    /*
    for(auto iter=m.begin(); iter!=m.end();iter++){
        cout<<iter->first<<" "<<iter->second<<" ";
    }
    */
    for (int i = 0; i < n; i++)
    {
        string s;
        for (int j = 0; j < Max_size; j++)
        {
            int num = m.find(voca[i][j])->second;
            s += to_string(num);
        }
        ans_string.push_back(s);
    }
    int sum = 0;
    for (auto a : ans_string)
    {
        int num = stoi(a);
        sum += num;
    }
    cout << sum;
}