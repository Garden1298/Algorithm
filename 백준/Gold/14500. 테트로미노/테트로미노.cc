#include <iostream>
#include <algorithm>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int map[500][500];
bool visited[500][500];
int N, M, answer = 0;

int dfs(int x, int y, int cnt)
{
	//마지막 위치면 현재 점수 반환
	if (cnt == 4) return map[x][y];

	int sum = 0;

	for (int dir = 0; dir < 4; dir++)
	{
		//다음 위치
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M)continue;//범위체크
		if (visited[nx][ny])continue;//방문체크

		visited[nx][ny] = true;
		sum = max(sum, map[x][y] + dfs(nx, ny, cnt + 1));
		visited[nx][ny] = false;
	}

	return sum;
}

int dir5(int x, int y)
{
	int sum = 0;

	//ㅗ
	if (x >= 1 && y >= 1 && y < M - 1)
	{
		sum = max(sum, map[x][y - 1] + map[x][y] + map[x - 1][y] + map[x][y + 1]);
	}

	//ㅏ
	if (x >= 1 && x < N - 1 && y < M - 1)
	{
		sum = max(sum, map[x - 1][y] + map[x][y] + map[x][y + 1] + map[x + 1][y]);
	}

	//ㅜ
	if (x >= 0 && x < N - 1 && y < M - 1)
	{
		sum = max(sum, map[x][y - 1] + map[x][y] + map[x + 1][y] + map[x][y + 1]);
	}

	//ㅓ
	if (x >= 1 && x < N - 1 && y >= 1)
	{
		sum = max(sum, map[x - 1][y] + map[x][y] + map[x][y - 1] + map[x + 1][y]);
	}

	return sum;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visited[i][j] = true;

			answer = max(answer, dfs(i, j, 1));
			answer = max(answer, dir5(i, j));

			visited[i][j] = false;
		}
	}

	cout << answer;

	return 0;
}