/* 9935 ??4 ??? ??
?? ??? ?? ??? ??? ?? ?? ???? ???? ??? --> ????? ?.
? ????? ??? O(n[?????]) *O(????) ???
??? ?????
---??? ..,
?? ? ?????? ?????? ???? ??? ??????? ????? ? ????? ??? ???????.
??? ???.. ???? ???? ?�m??? ???,.,
?? ?? c4? ??? ca4? ??? ?? ???? ?? ? ???? ?????. ??? ?????? ?? ??? ???? ?? ??? ????? ?????,,
??? ???.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;
string str, bomb;
vector<char> s;
string answer;
int idx = 0;
int main()
{
    cin >> str >> bomb;
    for (int i = 0; i < str.length(); i++)
    { //???? ???? ?? ??? ????.
        s.push_back(str[i]);
        //? ???? ???? ??? ??? ???? ???? ???? ??? ??.
        if (s.size() >= bomb.size())
        {
            bool flag = true;
            if (s[s.size() - 1] == bomb[bomb.size() - 1])
            { //?? ??? ???? ? ?? ??? ?? ?? ???? ????.
                for (int j = 0; j < bomb.size(); j++)
                {
                    if (s[s.size() - bomb.size() + j] != bomb[j])
                    {                 //???? ??? ??? ???? �?? ???? ??? ??? ??? ??? ???.
                        flag = false; //?????? false ????? true
                        break;
                    }
                }
                if (flag == true)
                { //??? ???? ???? ????? ???.
                    for (int k = 0; k < bomb.size(); k++)
                    {
                        s.pop_back();
                    }
                }
            }
        }
    }
    if (s.size() == 0)
    { //?? size? 0??? ?? ???? ????.
        cout << "FRULA";
    }
    else
    {
        for (auto v : s)
        {
            cout << v;
        }
    }
}