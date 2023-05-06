#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct pos {
	int r, c;
};

int N;
int r1, c1, r2, c2;
int visited[201][201];
int dir[6][2] = { {-2,-1},{-2,1},{0,-2},{0,2},{2,-1},{2,1} };

void bfs()
{
	queue<pos> q;

	q.push({ r1,c1 });
	visited[r1][c1] = 0;

	while (!q.empty())
	{
		int cr = q.front().r;
		int cc = q.front().c;

		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nr = cr + dir[i][0];
			int nc = cc + dir[i][1];

			if (nr < 0 || nr >= N || nc < 0 || nc >= N)continue;
			if (visited[nr][nc] == -1 || (visited[nr][nc] > visited[cr][cc] + 1))
			{
				visited[nr][nc] = visited[cr][cc] + 1;
				q.push({ nr,nc });
			}
		}
	}
}

int main()
{
	cin >> N;

	cin >> r1 >> c1 >> r2 >> c2;

	memset(visited, -1, sizeof(visited));

	bfs();

	cout << visited[r2][c2] << endl;
}