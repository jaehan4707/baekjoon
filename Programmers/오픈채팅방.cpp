#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;
vector<string> record;
vector<string> result;
vector<string> ary;
map<string, string>m;
vector<string> solution(vector<string> record);
vector<pair<string, string>>p;
int main()
{
    record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan" };
    //record = { "Enter uid1234 Muzi","Leave uid1234" };
    result = solution(record);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    // int idx = 1;
    // open에 잘들어감
}
vector<string> solution(vector<string> record)
{
    vector<string> answer;
    vector<string> Record;
    vector<int> idx;
    vector<string>bb;
    for (int i = 0; i < record.size(); i++) //나갔다가 닉네임 바꾸고 들어오면 처음 기록도 닉네임 바꿔줘야함.
    {
        string token;
        stringstream ss(record[i]);
        while (ss >> token)
        {
            Record.push_back(token); //공백 단위로 Record에 넣어줌.
        }
        if (Record[0] == "Enter")
        {
            string s = "님이 들어왔습니다.";
            p.push_back(make_pair(Record[1], s)); //아이디 넣어줌
            m[Record[1]] = Record[2];
        }
        else if (Record[0] == "Leave")
        {
            string s = "님이 나갔습니다.";
            p.push_back(make_pair(Record[1], s));
        }
        else if (Record[0] == "Change")
        {
            m[Record[1]] = Record[2];
        }
        Record.resize(0);
    }
    for (int j = 0; j < p.size(); j++)
    {
        string b = m.find(p[j].first)->second + p[j].second;
        answer.push_back(b);
    }
    return answer;
}