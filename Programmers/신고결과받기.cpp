#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    answer.resize(id_list.size(), 0);
    vector<string> user;
    map <string, int>m;
    map<string, set<string>>M;
    for (int i = 0; i < id_list.size(); i++)
    {
        m.insert(make_pair(id_list[i], i));
    }
    for (auto r : report)
    {
        stringstream s(r); //공백단위로 끊어서
        string s1;
        while (s >> s1)//s1에 넣고
        {
            //cout<<s1<<endl;
            user.push_back(s1); //그 s1을 user에 넣고 user[0]이 신고한사람 ,user[1]이 신고당한사람
        }
        //cout<<user[0]<<" "<<user[1]<<endl;
        M[user[1]].insert(user[0]);  // user[0]->user[1] 신고. 
        user.resize(0);
    }
    for (auto iter : M)// iter->first는 신고당한사람. iter->seocnd는 신고한 사람수 .
    {
        if (iter.second.size() >= k) //iter->second.size()가 신고한 사람의 수를 뜻함.
        {
            for (auto itter : iter.second)
            {
                answer[m.find(itter)->second]++;
            }
        }
    }
    return answer;
}