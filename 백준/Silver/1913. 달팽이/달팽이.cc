#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() 
{
    int N, target;
    cin >> N >> target;

    vector<vector<int>> board(N, vector<int>(N));
    int x = N / 2, y = N / 2;
    board[x][y] = 1;

    int number = 2;
    int step = 1;
    int dir = 0;
    int tx = x, ty = y;

    while (number <= N * N) 
    {
        for (int i = 0; i < 2; i++) 
        {
            for (int j = 0; j < step; j++) 
            {
                x += dx[dir];
                y += dy[dir];
                
                if (x < 0 || y < 0 || x >= N || y >= N)
                {
                    continue;
                }

                board[x][y] = number;
                if (number == target) {
                    tx = x;
                    ty = y;
                }
                number++;
            }
            dir = (dir + 1) % 4;
        }
        step++;
    }

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    cout << tx + 1 << " " << ty + 1 << endl;
}