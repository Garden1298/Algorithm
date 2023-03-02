#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool isVisited[101][101];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
int M, N, K;//가로길이, 세로길이, 사각형 개수
int answer = 0;
vector<int> area;

void bfs(int posA, int posB)
{
	queue<pair<int, int>> q;

	q.push(make_pair(posA, posB));
	isVisited[posA][posB] = true;

	int size = 1;

	while (!q.empty())
	{
		int curB = q.front().first;
		int curA = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextA = curA + dx[i];
			int nextB = curB + dy[i];

			if (nextA >= N || nextA < 0 || nextB >= M || nextB < 0) continue;
			if (isVisited[nextB][nextA]) continue;

			q.push(make_pair(nextB, nextA));
			isVisited[nextB][nextA] = true;
			size++;
		}
	}

	area.push_back(size);
}


int main()
{

	cin >> M >> N >> K;

	//사각형 방문 처리
	for (int i = 0; i < K; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int j = b; j < d; j++)
		{
			for (int k = a; k < c; k++)
			{
				isVisited[j][k] = true;
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!isVisited[i][j])
			{
				bfs(i, j);
				answer++;
			}
		}
	}

	cout << answer << endl;
	sort(area.begin(), area.end());
	for (int i = 0; i < area.size(); i++)
	{
		cout << area[i] << " ";
	}
	
}