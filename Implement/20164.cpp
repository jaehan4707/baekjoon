/*
규칙
1 : 숫자에서 홀수의 개수를 종이에 적는다.
2 : 수가 한자리면 종료
3 : 수가 두자리면 두 자리 합쳐서 새로운 수를 만듬.
4 : 수가 세자리 이상이면 임의의 숫자 위치에서 3개 끊어서 분할하고, 3개를 더한 값을 새로운 수로 생각*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits.h>
using namespace std;
string str;
int answer = 0, small = INT_MAX;
int findnum(string n);
string addnum(string n);
void funct(string number, int total);
int main()
{
    cin >> str;
    funct(str, 0);
    cout<<small<<" "<<answer<<endl;
}
void funct(string number, int total)
{
    if (number.length() == 1) //수가 한자리 일 때
    {
        total += findnum(number);
        answer = max(answer, total); //최대값 저장
        small = min(small, total); //최소값 저장
        return;
    }
    else if (number.length() == 2) //숫자가 2자리 일 때
    {
        total += findnum(number);
        funct(addnum(number), total); // 두 자리를 더한 숫자를 temp에 넣어줌.
    }
    else if (number.length() >= 3) //숫자가 3자리 이상일 때
    {
        total += findnum(number);
        // 3자리를 쪼개야함.
        for (int i = 1; i < number.length() - 1; i++)
        {
            string first, second, third;
            for (int j = i + 1; j < number.length(); j++)
            {
                first = number.substr(0, i);                   // 0~i까지 짜르기.
                second = number.substr(i, j - i);              // i~ i+j-i
                third = number.substr(j, number.length() - j); // j~ 끝까지.
                int num = stoi(first) + stoi(second) + stoi(third);
                funct(to_string(num), total); // 세 개를 더한 수를 새로운 문자열로 탐색시작
            }
        }
    }
}
int findnum(string n)
{
    int temp = 0;
    int tempans = 0;
    for (int i = 0; i < n.size(); i++)
    {
        temp = n[i] - '0';
        if (temp % 2 != 0) // 홀수면
        {
            tempans++;
        }
    }
    return tempans;
}
string addnum(string n) //두 자리면 두개 더하는 함수.
{ 
    int tempnum = 0;
    for (int i = 0; i < n.size(); i++)
    {
        tempnum += n[i] - '0';
    }
    return to_string(tempnum);
}