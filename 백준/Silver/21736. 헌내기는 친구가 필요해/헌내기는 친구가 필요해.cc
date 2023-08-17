#include <iostream>
#include <queue>

using namespace std;

char map[601][601] = { 0, };
bool isVisited[601][601];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
int n, m;
int startX, startY;
int ans = 0;

void bfs()
{
	queue<pair<int, int>> q;
	q.push(make_pair(startX, startY));
	isVisited[startX][startY] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (isVisited[nx][ny]) continue;

			if (map[nx][ny] == 'X')
			{
				continue;
			}
			if (map[nx][ny] == 'P')
			{
				ans++;
			}

			isVisited[nx][ny] = true;
			q.push(make_pair(nx, ny));
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			// 시작 위치 찾기
			if (map[i][j] == 'I')
			{
				startX = i;
				startY = j;
			}
		}
	}

	bfs();

	if (ans == 0)
	{
		cout << "TT" << endl;
	}
	else
	{
		cout << ans << endl;
	}
}