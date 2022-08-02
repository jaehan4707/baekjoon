/* 2800 괄호 제거
괄호를 제거해서 만들수  있는 수식을 모두 만들기
stack에 넣기
만들수 있는  경우의 수는 2^(괄호의수)-1이다.
왼쪽에서 가장 뒤에 있는 괄호와 오른쪽에서 앞에 있는 괄호룰 지워준다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;
stack<char> S;
vector<int> l, r;
vector<char> c;
vector<int> temp;
bool big(int a, int b);
string str;
vector<int> symbol;
vector<pair<int, int>> p;
vector<int> visit;
void check(int i, int Count);
vector<string> answer;
map<string, int> m;
int main()
{
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            symbol.push_back(i);
        }
        else if (str[i] == ')')
        {
            int num = symbol[symbol.size() - 1]; //가장 최근에  저장된 왼쪽괄호와 처음등장한 오른쪽 괄호가 대응됨.
            symbol.pop_back();                   //빼주고.
            p.push_back(make_pair(num, i));      //최근 왼쪽위치와 오른쪽 위치를 pair에 넣어줌
        }
    }
    visit.resize(str.length(), 0);
    check(0, 0);
    for (auto iter = m.begin(); iter != m.end(); iter++)
    {
        cout << iter->first << endl;
    }
    //괄호 대응되는 위치 넣어주기 성공. 이제 경우의 수를 계산해서 제거하면됨.
}
void check(int i, int Count)
{ //
    // cout<<3<<endl;
    if (Count > 0)
    {
        //일단 넣어보기
        // cout<<3<<endl;
        string s = "";
        for (int j = 0; j < visit.size(); j++)
        {
            if (visit[j] == true)
                continue; // true면 그때의 괄호 위치를 포함하지 않음.
            else
            {
                s += str[j]; //
            }
        }
        //여기서 중복된 문자열을 뺴줘야할거가틍ㅁ.
        m.insert(make_pair(s, 1));
    }
    // cout<<4<<endl;
    for (int k = i; k < p.size(); k++)
    {
        if (visit[p[k].first] == true && visit[p[k].second] == true)
        { //이미 사용한 괄호라면
            continue;
        }
        visit[p[k].first] = true;
        visit[p[k].second] = true;
        check(k, Count + 1);
        visit[p[k].first] = false;
        visit[p[k].second] = false;
    }
}