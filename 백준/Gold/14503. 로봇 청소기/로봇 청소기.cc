#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int n, m;//방의 크기
int r, c, d;//처음 로봇 청소기의 좌표와 바라보고 있는 방향
int map[50][50] = { 0, };
bool isVisited[50][50] = { 0, };
int answer;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void dfs(int x, int y, int dir, int sum)
{
	//다음 방향 확인
	for (int i = 0; i < 4; i++)
	{
		int nextDir = (dir + 3 - i) % 4;
		int nextX = x + dx[nextDir];
		int nextY = y + dy[nextDir];

		if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) continue;
		if (map[nextX][nextY] == 1) continue;

		if (isVisited[nextX][nextY] == 0 && map[nextX][nextY] == 0)
		{
			isVisited[nextX][nextY] = 1;
			dfs(nextX, nextY, nextDir, sum+1);
		}
	}

	//이전 인덱스에서 확인
	int backIndex, backX, backY;

	if (dir + 2 < 4)
	{
		backIndex = dir + 2;
	}
	else
	{
		backIndex = dir - 2;
	}

	backX = x + dx[backIndex];
	backY = y + dy[backIndex];

	if (backX < 0 || backX >= n || backY < 0 || backY >= m) return;

	if (map[backX][backY] == 0)
	{
		dfs(backX, backY, dir, sum);
	}
	else
	{
		cout << sum << endl;
		exit(0);
	}
}

int main()
{
	cin >> n >> m;
	cin >> r >> c >> d;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];

		}
	}

	isVisited[r][c] = 1;
	dfs(r, c, d, 1);

	return 0;
}