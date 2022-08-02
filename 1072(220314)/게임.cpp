/*
8X8 체스판. 알파벳은 열을 상징, 숫자는 행을 상징
가장 왼쪽 열은 A, 가장 오른쪽 열은 H
가장 아래 행은 1, 가장 위 행은 8이다.
방향은 8개가 있다.
이동을 못할 경우 건너뜀.
킹이 돌과 같은 곳으로 이동할 때 돌을 킹이 움직인 방향과 같은 방향으로 한 칸 이동시킴.
킹, 돌 움직이는 횟수
움직이는 방향
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
int x, y, Oldx, Oldy, oldx, oldy; // Old x Old y 는 움직이기 전 킹좌표, oldx, oldy는 움직이ㅣㄱ 전 도로자표ㅕ
//정지는 없다.(0,0)제외
void location(char a, char b, int &row, int &col);
void move(string s, int &x, int &y);
string change(int row, int col);
int main()
{
    int Row, Col, row, col; // Row,Col == 킹 , row,col= 돌
    string s, word;
    vector<string> chess;
    int count;
    getline(cin, s);
    stringstream ss(s);
    ss.str(s);
    while (ss >> word)
    {
        chess.push_back(word);
    }
    // chess[0]이 현재 킹의 좌표.
    // chess[1]이 돌 좌표
    location(chess[0][0], chess[0][1], Row, Col); //킹의 좌표를 좌표상으로 표현함.
    location(chess[1][0], chess[1][1], row, col); //돌의 좌표를 좌표상으로 표현함.
    count = stoi(chess[2]);
    //움직이는 횟수 정확하게 나옴.
    for (int i = 0; i < count; i++)
    {
        string vertex;
        cin >> vertex;                                  //방향 입력받고
        Oldx = Row, Oldy = Col, oldx = row, oldy = col; //움직이기 전 좌표.
        move(vertex, Row, Col);                         //방향대로 움직여줌.
        if (Row == row && Col == col)                   // 움직엿는데 돌쪽으로 갔다면
        {
            move(vertex, row, col); //돌도 그 방향대로 움직임.
            //여기서 만약 돌이 넘어가면 킹도 움직인걸 다시 물러야함.
            if (row == oldx && col == oldy)
            {                           //돌의 움직인 좌표가 예전과 같다면 못움직엿다는 뜻임.
                Row = Oldx, Col = Oldy; //킹도 예전좌표로 돌려준다.
            }
        }
    }
    cout << change(Row, Col) << endl; //좌표를 다시 영어로 변환
    cout << change(row, col) << endl; //좌표를 다시 영어로 변환
}
string change(int row, int col)
{
    string s;
    if (col == 0)
    {
        s = 'A';
    }
    if (col == 1)
    {
        s = 'B';
    }
    if (col == 2)
    {
        s = 'C';
    }
    if (col == 3)
    {
        s = 'D';
    }
    if (col == 4)
    {
        s = 'E';
    }
    if (col == 5)
    {
        s = 'F';
    }
    if (col == 6)
    {
        s = 'G';
    }
    if (col == 7)
    {
        s = 'H';
    }
    row = 8 - row;
    row = row + 48;
    s += row;
    return s;
}
void location(char a, char b, int &row, int &col) // A1 등등 이런거
{
    if (a == 'A')
    {
        col = 0;
    }
    if (a == 'B')
    {
        col = 1;
    }
    if (a == 'C')
    {
        col = 2;
    }
    if (a == 'D')
    {
        col = 3;
    }
    if (a == 'E')
    {
        col = 4;
    }
    if (a == 'F')
    {
        col = 5;
    }
    if (a == 'G')
    {
        col = 6;
    }
    if (a == 'H')
    {
        col = 7;
    }
    // row=8-(int)b; //1은 index 7 row 8은 index 0
    b = b - 48;
    row = 8 - b;
}
void move(string str, int &x, int &y)
{
    int oldx, oldy;
    oldx = x, oldy = y;
    if (str == "L")
    {
        x += 0, y += -1;
    }
    else if (str == "R")
    {
        x += 0, y += 1;
    }
    else if (str == "T")
    {
        x = x - 1, y += 0;
    }
    else if (str == "B")
    {
        x = x + 1, y += 0;
    }
    else if (str == "RT")
    {
        x = x - 1, y += 1;
    }
    else if (str == "LT")
    {
        x = x - 1, y = y - 1;
    }
    else if (str == "RB")
    {
        x = x + 1, y = y + 1;
    }
    else if (str == "LB")
    {
        x = x + 1, y = y - 1;
    }
    if (x < 0 || x > 7 || y < 0 || y > 7) // 만약 체스판이 넘어간다면 원래 좌표를 넣어줌.
    {
        x = oldx, y = oldy;
    }
}