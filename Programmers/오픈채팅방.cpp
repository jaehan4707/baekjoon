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
    // open�� �ߵ�
}
vector<string> solution(vector<string> record)
{
    vector<string> answer;
    vector<string> Record;
    vector<int> idx;
    vector<string>bb;
    for (int i = 0; i < record.size(); i++) //�����ٰ� �г��� �ٲٰ� ������ ó�� ��ϵ� �г��� �ٲ������.
    {
        string token;
        stringstream ss(record[i]);
        while (ss >> token)
        {
            Record.push_back(token); //���� ������ Record�� �־���.
        }
        if (Record[0] == "Enter")
        {
            string s = "���� ���Խ��ϴ�.";
            p.push_back(make_pair(Record[1], s)); //���̵� �־���
            m[Record[1]] = Record[2];
        }
        else if (Record[0] == "Leave")
        {
            string s = "���� �������ϴ�.";
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