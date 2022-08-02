/* 9935 골드4 문자열 폭발
내가 처음에 하는 방식은 문자열 처음 부터 차근차근 비교해서 하는것 --> 시간초과가 남.
왜 시간초과가 나지? O(n[문자열길이]) *O(폭탄길이) 라서?
어떻게 해야할까?

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
    // cout<<str.size()<<endl<<bomb.size();

    for (int i = 0; i < str.length(); i++) //문자열을 더하다가 폭탄 만나면 터트려줌.
    {

        s.push_back(str[i]);
        //꼭 입력받은 문자열의 크기가 폭탄의 길이보다 작아야하는가? 그렇네
        if (s.size() >= bomb.size()) //작다면 폭발시킬 이유가 잇나? 없다.
        {
            bool flag = true;
            /*
            if(s[s.size()-1]==bomb[bomb.size()-1]) //끝에 폭탄이 걸렷다면 폭탄의 길이만큼 빼준다.
            {
                //cout<<s[s.size()-1]<<endl;
                for(int j=0; j<bomb.size();j++)
                {
                    if(s[s.size()-bomb.size()+j]==bomb[j]) //문자열의 끝에서 폭탄의 길이만큼 뺴준뒤 차근차근 더해서 폭탄이 있는지 없는지 체크함.
                    {
                        cout<<"내가찾고싶은것 "<<s[s.size()-bomb.size()+j];
                        flag=false;
                        break;
                    }
                    /*처음 짠 코드
                    {
                        if(s[s.size()-1-bomb.size()+j]==bomb[j])  //이렇게하면 4가 아닌 c를 검사하게됨.
                        {
                            flag=false;
                            break;
                        }
                    }
                }
            }
            */
            for (int j = 0; j < bomb.size(); j++)
            {
                if (s[s.size() - bomb.size() + j] != bomb[j])
                {
                    flag = false;
                    break;
                }
            }
            // flag가  true인 경우는 맨마지막문자가 폭탄을 만났지만 이전까지 검사해서 폭탄이 없엇기에 터트리지않음.
            if (flag == true)
            { //폭탄을 만났으면 해당하는 인덱스까지 빼준다.
                for (int k = 0; k < bomb.size(); k++)
                {
                    // cout << "내가 지금 뺴는것 " << s[s.size() - 1];
                    s.pop_back();
                }
                // cout << endl;
            }
        }
    }
    if (s.size() == 0)
    {
        cout << "FRULA";
    }
    else
    { //모든 원소 출력하기
        for (int i = 0; i < s.size(); i++)
        {
            cout << s[i];
        }
    }
}
