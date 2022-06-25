#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int cut(vector<int>& ary, vector<int>& c, vector<int>& result) //ary가 array c가 comannds
{
    int start, finish, stop, Cnt = 0;
    start = c[0] - 1;
    finish = c[1] - 1;
    stop = c[2] - 1; //3이면 stop-1을 리런해줘야함.
    for (int i = start; i <= finish; i++)
    {
        result.push_back(ary[i]);
        Cnt++;
    }
    sort(result.begin(), result.end());
    return result[stop];
}
vector<int> solution(vector<int> array, vector<vector<int>> commands) {

    vector<int>Sort;
    vector<int>result;
    vector<int> answer;
    for (int i = 0; i < commands.size(); i++)
    {
        for (int j = 0; j < commands[0].size(); j++)
        {
            Sort.push_back(commands[i][j]);
        }
        answer.push_back(cut(array, Sort, result)); //result에 배열들어감.
        Sort.resize(0, 0);
        result.resize(0, 0);
    }
    return answer;
}