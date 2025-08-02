#include <iostream>
#include <queue>
#include <string>
using namespace std;

constexpr int MAX_GRID_SIZE = 2001;

const int dx[7] = {-1, -1, 0, 0, 1, -1, 1};
const int dy[7] = {-1, 1, -1, 1, -1, 0, 1};

int grid[MAX_GRID_SIZE][MAX_GRID_SIZE]; // 0: 빈칸, 1: 장애물, 2: 시작점
bool visited[MAX_GRID_SIZE][MAX_GRID_SIZE];
int gridSize;
int reachableEmptyCells = 0;

void ExploreReachableCells(int startX, int startY) 
{
    queue<pair<int, int>> bfsQueue;
    bfsQueue.push({startX, startY});
    visited[startX][startY] = true;

    while (!bfsQueue.empty()) 
    {
        auto [x, y] = bfsQueue.front();
        bfsQueue.pop();

        for (int direction = 0; direction < 7; ++direction) 
        {
            int nextX = x + dx[direction];
            int nextY = y + dy[direction];

            if (nextX < 0 || nextY < 0 || nextX >= gridSize || nextY >= gridSize) continue;
            if (visited[nextX][nextY] || grid[nextX][nextY] == 1) continue;

            visited[nextX][nextY] = true;
            ++reachableEmptyCells;
            bfsQueue.push({nextX, nextY});
        }
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> gridSize;

    int startX = -1, startY = -1;

    for (int i = 0; i < gridSize; ++i) 
    {
        string row;
        cin >> row;

        for (int j = 0; j < row.size(); ++j) 
        {
            if (row[j] == '#') {
                grid[i][j] = 1;
            } else if (row[j] == '.') 
            {
                grid[i][j] = 0;
            } else {
                grid[i][j] = 2;
                startX = i;
                startY = j;
            }
        }
    }

    ExploreReachableCells(startX, startY);
    cout << reachableEmptyCells;
}
