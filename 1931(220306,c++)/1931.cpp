#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
struct room
{
    int start;
    int finish;
};
bool compare(room& a, room& b)
{
    if (a.start == b.start)
    {
        return a.finish < b.finish; //��������
    }
    else
        return a.start < b.start;
}
int main(void)
{
    int cnum, cnt = 0;
    cin >> cnum;
    struct room S[cnum];
    int count[cnum];
    for (int i = 0; i < cnum; i++)
    {
        cin >> S[i].finish >> S[i].start; //���۽ð� ���ð� �Է¹ޱ�
    }
    sort(S, S + cnum, compare);
    int savetime = 0, result = 0;
    for (int i = 0; i < cnum; i++)
    {
        if (savetime <= S[i].finish)
        {
            savetime = S[i].start;
            result++;
        }
    }
    printf("%d", result);
    return 0;
}