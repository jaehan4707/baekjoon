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
        stringstream s(r); //��������� ���
        string s1;
        while (s >> s1)//s1�� �ְ�
        {
            //cout<<s1<<endl;
            user.push_back(s1); //�� s1�� user�� �ְ� user[0]�� �Ű��ѻ�� ,user[1]�� �Ű���ѻ��
        }
        //cout<<user[0]<<" "<<user[1]<<endl;
        M[user[1]].insert(user[0]);  // user[0]->user[1] �Ű�. 
        user.resize(0);
    }
    for (auto iter : M)// iter->first�� �Ű���ѻ��. iter->seocnd�� �Ű��� ����� .
    {
        if (iter.second.size() >= k) //iter->second.size()�� �Ű��� ����� ���� ����.
        {
            for (auto itter : iter.second)
            {
                answer[m.find(itter)->second]++;
            }
        }
    }
    return answer;
}