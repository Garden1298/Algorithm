#include <iostream>

using namespace std;

int n, m, r;//가로, 세로, 회전 수
int map[301][301] = { 0, };
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0,0 };

int main()
{
	cin >> n >> m >> r;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	while (r--)
	{
		//배열의 가장 자리 점 찾기
		int x1 = 0;
		int y1 = 0;

		int x2 = 0;
		int y2 = m - 1;

		int x3 = n - 1;
		int y3 = m - 1;

		int x4 = n - 1;
		int y4 = 0;

		//배열 돌리기
		while (x1 < x4 && y1 < y2)
		{
			//시작 값 저장
			int tmp = map[x1][y1];

			for (int i = y1; i < y2; i++)
			{
				map[x1][i] = map[x1][i + 1];
			}

			for (int i = x2; i < x3; i++)
			{
				map[i][y2] = map[i + 1][y2];
			}

			for (int i = y3; i > y4; i--)
			{
				map[x3][i] = map[x3][i - 1];
			}

			for (int i = x4; i > x1; i--)
			{
				map[i][y4] = map[i - 1][y4];
			}

			//마지막 위치에 시작 값 넣기

			map[x1+1][y4] = tmp;

			//시작 위치 바꾸기

			x1 +=1;
			y1 += 1;

			x2 += 1;
			y2 -= 1;

			x3 -= 1;
			y3 -= 1;

			x4 -= 1;
			y4 += 1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}