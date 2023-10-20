#include <iostream>
#include <queue>

using namespace std;

int N, M;
int map[51][51];
//bool isVisited[51][51];
int dx[8] = { 0, 0, -1, 1, -1, -1, 1, 1 };
int dy[8] = { -1, 1, 0, 0, -1, 1, -1, 1 };


int BFS(int x, int y)
{
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < M; j++)
	//	{
	//		isVisited[i][j] = false;
	//	}
	//}
	bool isVisited[51][51] = {false,};

	queue<pair<pair<int, int>,int>> q;
	int length = 0;

	q.push(make_pair(make_pair(x, y),0));
	isVisited[x][y] = true;

	while (!q.empty())
	{
		int curX = q.front().first.first;
		int curY = q.front().first.second;
		int curLength = q.front().second;
		q.pop();

		if (map[curX][curY] == 1)
		{
			return curLength;
		}

		for (int d = 0; d < 8; d++)
		{
			int nx = curX + dx[d];
			int ny = curY + dy[d];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (isVisited[nx][ny]) continue;

			isVisited[nx][ny] = true;
			q.push(make_pair(make_pair(nx, ny),curLength+1));
		}
	}
	return 0;
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

	int answer = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 1) continue;
			int curDist = BFS(i, j);
			answer = answer > curDist ? answer : curDist;
		}
	}

	cout << answer;

	return 0;
}