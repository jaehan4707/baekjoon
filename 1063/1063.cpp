/*
8X8 ü����. ���ĺ��� ���� ��¡, ���ڴ� ���� ��¡
���� ���� ���� A, ���� ������ ���� H
���� �Ʒ� ���� 1, ���� �� ���� 8�̴�.
������ 8���� �ִ�.
�̵��� ���� ��� �ǳʶ�.
ŷ�� ���� ���� ������ �̵��� �� ���� ŷ�� ������ ����� ���� �������� �� ĭ �̵���Ŵ.
ŷ, �� �����̴� Ƚ��
�����̴� ����
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
int x, y, Oldx, Oldy, oldx, oldy; //Old x Old y �� �����̱� �� ŷ��ǥ, oldx, oldy�� �����̤Ӥ� �� ������ǥ��
//������ ����.(0,0)����
void location(char a, char b, int& row, int& col);
void move(string s, int& x, int& y);
string change(int row, int col);
int main()
{
    int Row, Col, row, col; //Row,Col == ŷ , row,col= ��
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
    // chess[0]�� ���� ŷ�� ��ǥ.
    // chess[1]�� �� ��ǥ
    location(chess[0][0], chess[0][1], Row, Col); //ŷ�� ��ǥ�� ��ǥ������ ǥ����.
    location(chess[1][0], chess[1][1], row, col); //���� ��ǥ�� ��ǥ������ ǥ����.
    count = stoi(chess[2]);
    //�����̴� Ƚ�� ��Ȯ�ϰ� ����.
    for (int i = 0; i < count; i++) {
        string vertex;
        cin >> vertex; //���� �Է¹ް�
        Oldx = Row, Oldy = Col, oldx = row, oldy = col; //�����̱� �� ��ǥ.
        move(vertex, Row, Col); //������ ��������.
        if (Row == row && Col == col) // �������µ� �������� ���ٸ� 
        {
            move(vertex, row, col); //���� �� ������ ������.
            //���⼭ ���� ���� �Ѿ�� ŷ�� �����ΰ� �ٽ� ��������.
            if (row == oldx && col == oldy) { //���� ������ ��ǥ�� ������ ���ٸ� ���������ٴ� ����.
                Row = Oldx, Col = Oldy; //ŷ�� ������ǥ�� �����ش�.
            }
        }
    }
    cout << change(Row, Col) << endl; //��ǥ�� �ٽ� ����� ��ȯ
    cout << change(row, col) << endl; //��ǥ�� �ٽ� ����� ��ȯ
}
string change(int row, int col)
{
    string s;
    if (col == 0) {
        s = 'A';
    }
    if (col == 1) {
        s = 'B';
    }
    if (col == 2) {
        s = 'C';
    }
    if (col == 3) {
        s = 'D';
    }
    if (col == 4) {
        s = 'E';
    }
    if (col == 5) {
        s = 'F';
    }
    if (col == 6) {
        s = 'G';
    }
    if (col == 7) {
        s = 'H';
    }
    row = 8 - row;
    row = row + 48;
    s += row;
    return s;
}
void location(char a, char b, int& row, int& col) //A1 ��� �̷��� 
{
    if (a == 'A') {
        col = 0;
    }
    if (a == 'B') {
        col = 1;
    }
    if (a == 'C') {
        col = 2;
    }
    if (a == 'D') {
        col = 3;
    }
    if (a == 'E') {
        col = 4;
    }
    if (a == 'F') {
        col = 5;
    }
    if (a == 'G') {
        col = 6;
    }
    if (a == 'H') {
        col = 7;
    }
    //row=8-(int)b; //1�� index 7 row 8�� index 0
    b = b - 48;
    row = 8 - b;
}
void move(string str, int& x, int& y)
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
    if (x < 0 || x>7 || y < 0 || y>7) // ���� ü������ �Ѿ�ٸ� ���� ��ǥ�� �־���.
    {
        x = oldx, y = oldy;
    }
}