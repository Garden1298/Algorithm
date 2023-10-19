#include <iostream>

using namespace std;

int R, C, T, answer = 0;
char map[6][6];
bool isVisited[6][6];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int start[2], house[2];

void DFS(int x, int y, int depth)
{
	if (depth == T)
	{
		if (x == house[0] && y == house[1])
		{
			answer++;
		}

		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
		if (isVisited[nx][ny]) continue;
		if (map[nx][ny] == 'T') continue;

		isVisited[nx][ny] = true;
		DFS(nx, ny, depth + 1);
		isVisited[nx][ny] = false;
	}

}

int main()
{
	cin >> R >> C >> T;

	start[0] = R - 1;
	start[1] = 0;
	house[0] = 0;
	house[1] = C - 1;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
		}
	}

	isVisited[start[0]][start[1]] = true;
	DFS(start[0], start[1], 1);

	cout << answer;
}