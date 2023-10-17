#include <iostream>

using namespace std;

int N,student;
int arr[401][4];
int map[20][20];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int CountLike(int x, int y, int curStudent)
{
	int cnt = 0;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

		for (int j = 0; j < 4; j++)
		{
			if (map[nx][ny] == arr[curStudent][j])
			{
				cnt++;
				break;
			}
		}
	}

	return cnt;
}

int CountEmpty(int x, int y)
{
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

		if (map[nx][ny] == 0) cnt++;
	}

	return cnt;
}


void Find(int curStudent)
{
	int likeMax = 0, emptyMax = -1, x = 0, y = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j]!=0) continue;

			int likeCnt = CountLike(i, j, curStudent);
			int emptyCnt = CountEmpty(i, j);

			if (likeMax < likeCnt)
			{
				likeMax = likeCnt;
				emptyMax = emptyCnt;
				x = i;
				y = j;
			}
			else if (likeMax == likeCnt)
			{
				if (emptyMax < emptyCnt)
				{
					emptyMax = emptyCnt;
					x = i;
					y = j;
				}
			}
		}
	}

	map[x][y] = curStudent;
}

int Calculate() 
{
	int result = 0;
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			int curStudent = map[i][j];
			int cnt = 0;
			for (int k = 0; k < 4; k++) 
			{
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

				for (int l = 0; l < 4; l++) 
				{
					if (map[nx][ny] == arr[curStudent][l]) 
					{
						cnt++;
						break;
					}
				}
			}
			if (cnt == 2) result += 10;
			else if (cnt == 3) result += 100;
			else if (cnt == 4)result += 1000;
			else result += cnt;
		}
	}

	return result;
}

int main()
{
	cin >> N;

	student = N * N;

	int curStudent;
	for (int i = 1; i <= student; i++)
	{
		cin >> curStudent;

		for (int j = 0; j < 4; j++)
		{
			cin >> arr[curStudent][j];
		}
		Find(curStudent);
	}

	cout << Calculate();
}