#include <iostream>
#include <vector>

using namespace std;
int threshold;
void tromino(vector<vector<int>> &maze, int row, int col);
void printmaze(vector<vector<int>> &maze);
void partition(vector<vector<int>> &maze, vector<vector<int>> &maze1, vector<vector<int>> &maze2, vector<vector<int>> &maze3, vector<vector<int>> &maze4); //��и����� ������
void fillmaze(vector<vector<int>> &maze, int row, int col);
void combine(vector<vector<int>> &maze, vector<vector<int>> &maze1, vector<vector<int>> &maze2, vector<vector<int>> &maze3, vector<vector<int>> &maze4);
int hole(vector<vector<int>> &maze, int row, int col); // row col�� �����ִ� ��ġ
void tile(vector<vector<int>> &maze, int n, int &row, int &col);
int n, row, col, cnt = 1, H = 0, N = 0;

int main()
{

    cin >> n >> row >> col;
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        cnt = cnt * 2;
    }
    vector<vector<int>> maze(cnt, vector<int>(cnt, 0)); // n*n�� �迭�� \1���� �ʱ�ȭ��Ŵ
    maze[maze.size() - col][row - 1] = -1;
    tromino(maze, maze.size() - col, row - 1);
    maze[maze.size() - col][row - 1] = -1;
    printmaze(maze);
    return 0;
}
void tile(vector<vector<int>> &maze, int n, int &row, int &col) // row col �Է¹޴� ��
{
    int a = 0, b = 0;
    a = row, b = col;
    b = row - 1; //���������� �� col
    a = n - col;
    row = a;
    col = b;
}
void printmaze(vector<vector<int>> &maze) //����Լ�
{
    for (int i = 0; i < maze.size(); i++)
    {
        for (int j = 0; j < maze.size(); j++)
        {
            if (j < maze.size() - 1)
            {
                printf("%2d ", maze[i][j]);
                // cout << maze[i][j] << " ";
            }
            else
                printf("%2d ", maze[i][j]);
        }
        if (i < maze.size() - 1)
        {
            cout << "\n";
        }
    }
}
void tromino(vector<vector<int>> &maze, int row, int col) // row col ������ǥ
{
    H++;
    n = maze.size() / 2;

    int ROW = 0, COL = 0;
    int location = 0;

    vector<vector<int>> maze1(n, vector<int>(n, 0)); // 1��и�
    vector<vector<int>> maze2(n, vector<int>(n, 0)); // 2��и�
    vector<vector<int>> maze3(n, vector<int>(n, 0)); // 3��и�
    vector<vector<int>> maze4(n, vector<int>(n, 0)); // 4��и�
    if (n <= 1)
    {
        fillmaze(maze, row, col);
    }
    else
    {
        partition(maze, maze1, maze2, maze3, maze4); //�迭4���� ū�迭�� 4�� �Ҵ������.
        location = hole(maze, row, col);             //���۶ո� ��и� ��ġ�� ���� 5,5  size=8
        if (location == 1)                           // 1��и鿡 �ִٸ�
        {
            maze2[maze2.size() - 1][0] = H;
            maze3[0][maze3.size() - 1] = H;
            maze4[0][0] = H;
            tromino(maze1, row, col);
            tromino(maze2, maze2.size() - 1, 0);
            tromino(maze3, 0, maze3.size() - 1);
            tromino(maze4, 0, 0);
        }
        if (location == 2)
        {

            maze1[maze1.size() - 1][maze1.size() - 1] = H;

            maze3[0][maze3.size() - 1] = H;
            maze4[0][0] = H;
            //��¥����
            tromino(maze1, maze1.size() - 1, maze1.size() - 1);
            tromino(maze2, row, col - maze2.size()); //��¥����
            tromino(maze3, 0, maze3.size() - 1);
            tromino(maze4, 0, 0);
        }
        if (location == 3)
        {

            maze1[maze1.size() - 1][maze1.size() - 1] = H;
            maze2[maze2.size() - 1][0] = H;

            maze4[0][0] = H;
            tromino(maze1, maze1.size() - 1, maze1.size() - 1);
            tromino(maze2, maze2.size() - 1, 0);
            tromino(maze3, row - maze3.size(), col);
            tromino(maze4, 0, 0);
        }
        if (location == 4)
        {
            maze1[maze1.size() - 1][maze1.size() - 1] = H;
            maze2[maze2.size() - 1][0] = H;
            maze3[0][maze3.size() - 1] = H;

            tromino(maze1, maze1.size() - 1, maze1.size() - 1);
            tromino(maze2, maze2.size() - 1, 0);
            tromino(maze3, 0, maze3.size() - 1);
            tromino(maze4, row - maze4.size(), col - maze4.size());
        }
        combine(maze, maze1, maze2, maze3, maze4); // combine if�� ������ �ִ°� ���ƤѤ���
    }
}
int hole(vector<vector<int>> &maze, int row, int col) // row col�� �����ִ� ��ġ row1 col 2 size=4
{
    int size;
    size = maze.size();
    if (row < size / 2 && col < size / 2) //������ 1��и鿡 �ִ�
    {
        return 1;
    }
    else if (row >= size / 2 && col < size / 2)
    {
        return 3;
    }
    else if (row < size / 2 && col >= size / 2)
    {
        return 2;
    }
    else if (row >= size / 2 && col >= size / 2)
    {
        return 4;
    }
}
void combine(vector<vector<int>> &maze, vector<vector<int>> &maze1, vector<vector<int>> &maze2, vector<vector<int>> &maze3, vector<vector<int>> &maze4)
{
    int m = maze.size() / 2;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            maze[i][j] = maze1[i][j];
            maze[i][j + m] = maze2[i][j];
            maze[i + m][j] = maze3[i][j];
            maze[i + m][j + m] = maze4[i][j];
        }
    }
}
void partition(vector<vector<int>> &maze, vector<vector<int>> &maze1, vector<vector<int>> &maze2, vector<vector<int>> &maze3, vector<vector<int>> &maze4) //��и����� ������
{
    int m = maze.size() / 2; // 2����n����
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            maze1[i][j] = maze[i][j];
            maze2[i][j] = maze[i][j + m];
            maze3[i][j] = maze[i + m][j];
            maze4[i][j] = maze[i + m][j + m];
        }
    }
}
void fillmaze(vector<vector<int>> &maze, int row, int col) // row,col�� ���� 0,1
{
    N = H;
    for (int i = 0; i < maze.size(); i++)
    {
        for (int j = 0; j < maze.size(); j++)
        {
            //��¥�����϶� ��¥������ h�� �آZ�� H==1
            if (i == row && j == col)
            {
                continue;
            }
            else
                maze[i][j] = N;
        }
    }
}