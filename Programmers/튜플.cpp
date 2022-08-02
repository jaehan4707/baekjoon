#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> solution(string s)
{
    map<int, int> m;
    vector<string> str;
    vector<int> CC; //집합의 원소 개수를 측정함.
    vector<int> answer;
    string S;
    int cnt = 0;
    bool flag = false;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{') //{일때는
        {
            flag = true; //{를 만나면 넣기 시작한다.
        }
        else if (s[i] == '}') //} 괄호가 닫히면 문자들을 넣어준다.
        {
            str.push_back(S);
            CC.push_back(cnt);
            // cout<<"S는"<<" "<<S<<endl;
            S = "";
            cnt = 0;
            flag = false;
        }
        else if (flag == true)
        {
            // cout<<"값 넣기"<<endl;
            S += s[i];
            cnt++; //문자 넣을 떄 마다 conut값++
        }
    }
    CC.pop_back();                      //맨 마지막 괄호가 하나 더 있기 떄문에 쓰레기값을 뺴준다.
    str.pop_back();                     //맨 마지막 괄호가 하나 더 있기 떄문에 쓰레기값을 뺴준다.
    for (int i = 0; i < CC.size(); i++) //원소의 개수를 오름차순으로 튜플을 정렬해줌.
    {
        for (int j = i + 1; j < CC.size(); j++)
        {
            if (CC[i] > CC[j])
            {
                swap(str[i], str[j]);
                swap(CC[i], CC[j]);
            }
        }
    }
    int index = 0;
    for (int i = 0; i < str.size(); i++)
    {
        string b;
        for (int j = 0; j < str[i].size(); j++)
        {

            if (str[i][j] == ',') //끊어줘야함.
            {
                int num = stoi(b);
                if (m.find(num) == m.end()) //없을 경우 넣어준다.
                {
                    m.insert(make_pair(num, index));
                    answer.push_back(num);
                    index++;
                }
                b = "";
                // b를 넣어주고
                // b를 초기화
                continue;
            }
            else //연속된 숫자의 경우
            {
                b += str[i][j];
            }
        }
        int num = stoi(b);
        if (m.find(num) == m.end())
        {
            m.insert(make_pair(num, index));
            answer.push_back(num);
            index++;
        }
    }
    // m.second값이 작은  순서대로 넣어주면 됨.
    vector<int> num;
    cout << endl;
    return answer;
}

int main()
{
    string s = "{{4,2,3},{3},{2,3,4,1},{2,3}}";
    solution(s);
}