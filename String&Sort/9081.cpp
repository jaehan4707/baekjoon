/*
백준 실버1 단어맞추기
해당 단어가 있으면 그 단어 다음에 바로 오는 단어를 출력
해당 단어가 마지막이면 그 단어를 출력

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> eng;
int check(string str);
int main()
{
    cin >> n;

    eng.resize(26, 0);
    for (int i = 0; i < n; i++)
    {
        string str;
        string answer;
        cin >> str;
        int idx = check(str);
        if (idx == -1)
        {
            cout << str;
            continue;
        }
        for (int x = 0; x < idx; x++)
        {
            answer += str[x];
        }
        for (int j = idx; j < str.length(); j++)
        {
            eng[str[j] - 65]++;
        }
        int cur = 999;
        //해당 idx의 알파벳보다 제일 가까운 큰수를 idx자리에 넣고 그 자리 뒤부터는 작은순서대로 쫘좌작 넣기.
        for (int k = idx; k < str.length(); k++)
        {
            if (eng[str[k] - 65] != 0 && cur > str[k] - 65)
            {
                if (str[idx] - 65 < str[k] - 65)
                    cur = str[k] - 65;
            }
        }
        answer += cur + 65;
        eng[cur]--;
        for (int i = 0; i < 26; i++)
        {
            if (eng[i] == 0)
            {
                continue;
            }
            while (eng[i] != 0)
            {
                answer += i + 65;
                eng[i]--;
            }
        }
        cout << answer << endl;
        eng.assign(26, 0);
        // cout << str << endl;
        // j-1부터 사전순으로 젤 빠른 문자열을 찾아야함.
    }
    //각 단어를 사전순으로 정렬할때 해당 단어 바로 다음에 오는 단어를 뽑아주기.
    /*
    A B C D E F G H I J K L M N O P Q
    R S T U V W X Y Z
    HELLO -> HELOL
    DRINK -> DRKIN
    n이랑 k를 비교하는데 n이 k보다 뒤에 있기에 nk는 바꿀수 없음. 그럼 그 다음으로 INK -> NK는 바꿀수 없기에
    두개중에서 I와 최대한 가까운것을 I자리에 넣고 KNI로 바꾸고 k로 시작하는 3자리중에서 가장 빠른건 KIN.
    SHUTILE -> SLEHTTU
    ZOO -> ZOO
    두 자리를 비교해서 뒤의 단어가 후순위라면 바꿔준다?
    앞에서 한글자씩 해서 뒤의 자리들이 최대의 경우인지 생각해준다?
    사전순으로 마지막이라면 가면 갈수록 작아져야함?
    마지막 순서가 출력되기 전단계에서 바꿔주면될듯
    ABC
    ACB
    CAB
    CBA
    */
}
int check(string str) //갈수록 아스키코드가 커져야함. 작아지는 구간이 있으면 거기서부터 바꿔줄수있음.
{
    int num = 0;
    int res = 0;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (num <= str[i])
        {
            num = str[i];
        }
        else
        {
            return i;
        }
    }
    return -1;
}