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
    vector<int> CC; //??? ?? ??? ???.
    vector<int> answer;
    string S;
    int cnt = 0;
    bool flag = false;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{') //{???
        {
            flag = true; //{? ??? ?? ????.
        }
        else if (s[i] == '}') //} ??? ??? ???? ????.
        {
            str.push_back(S);
            CC.push_back(cnt);
            // cout<<"S?"<<" "<<S<<endl;
            S = "";
            cnt = 0;
            flag = false;
        }
        else if (flag == true)
        {
            // cout<<"? ??"<<endl;
            S += s[i];
            cnt++; //?? ?? ?? ?? conut?++
        }
    }
    CC.pop_back();                      //? ??? ??? ?? ? ?? ???? ????? ???.
    str.pop_back();                     //? ??? ??? ?? ? ?? ???? ????? ???.
    for (int i = 0; i < CC.size(); i++) //??? ??? ?????? ??? ????.
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

            if (str[i][j] == ',') //?????.
            {
                int num = stoi(b);
                if (m.find(num) == m.end()) //?? ?? ????.
                {
                    m.insert(make_pair(num, index));
                    answer.push_back(num);
                    index++;
                }
                b = "";
                // b? ????
                // b? ???
                continue;
            }
            else //??? ??? ??
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
    // m.second?? ??  ???? ???? ?.
    vector<int> num;
    cout << endl;
    return answer;
}

int main()
{
    string s = "{{4,2,3},{3},{2,3,4,1},{2,3}}";
    solution(s);
}