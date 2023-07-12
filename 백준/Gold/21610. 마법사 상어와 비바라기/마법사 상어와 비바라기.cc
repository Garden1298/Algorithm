#include <iostream>
#include <queue>

using namespace std;

int map[51][51];
int N, M;

int dir = 1;
int dx[9] = { 0, 0,-1,-1,-1,0,1,1,1 };
int dy[9] = { 0, -1,-1,0,1,1,1,0,-1 };

queue<pair<int, int>> cloud;

int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
		}
	}

	//처음 구름 위치 추가
	cloud.push(make_pair(N, 1));
	cloud.push(make_pair(N, 2));
	cloud.push(make_pair(N - 1, 1));
	cloud.push(make_pair(N - 1, 2));

	int d, s;
	for (int i = 0; i < M; i++)
	{
		cin >> d >> s;

		int size = cloud.size();
		bool isVisited[51][51] = { false, };
		queue < pair<int, int>> curClould;

		// 1. d 방향으로 s번 이동
		for (int j = 0; j < size; j++)
		{
			int x = cloud.front().first;
			int y = cloud.front().second;

			for (int k = 0; k < s; k++)
			{
				x += dx[d];
				y += dy[d];

				if (x < 1) x = N;
				if (x > N) x = 1;
				if (y < 1) y = N;
				if (y > N) y = 1;

			}

			// 2. 구름이 있는 곳 물 1 증가
			map[x][y]++;
			// 3. 구름 삭제
			cloud.pop();

			isVisited[x][y] = true;
			curClould.push(make_pair(x,y));
		}


		// 4. 물 복사
		for (int j = 0; j < size; j++)
		{
			int x = curClould.front().first;
			int y = curClould.front().second;
			curClould.pop();

			for (int k = 2; k < 9; k += 2)
			{
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (nx < 1 && ny < 1 && nx >= N && nx >= N) continue;
				if (map[nx][ny]==0) continue;

				map[x][y]++;
			}
		}

		//5. 구름 생성
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (map[i][j] < 2) continue;
				if (isVisited[i][j]) continue;

				cloud.push(make_pair(i, j));
				map[i][j] -= 2;
			}
		}

	}

	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			answer += map[i][j];
		}
	}

	cout << answer;
}